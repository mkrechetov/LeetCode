#include <iostream>
#include <functional>
#include <thread>
#include <atomic>

using namespace std;

class H2O {
public:
    int n=5;
    atomic<int> h;

    H2O() {
        n = 5;
        h = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
      while (h>=2) {};
      releaseHydrogen();
      h++;
    }

    void oxygen(function<void()> releaseOxygen) {
      while (h!=2) {};
      releaseOxygen();
      h-=2;
    }
};

void h(H2O& obj) {
  for (int i = 0; i < 2*obj.n; i++) {
    obj.hydrogen([]{ cout << "H"; });
  }
}

void o(H2O& obj) {
  for (int i = 0; i < obj.n; i++) {
    obj.oxygen([]{ cout << "O"; });
  }
}

int main() {

  H2O obj;

  thread t1(o, ref(obj));
  thread t2(h, ref(obj));
  t1.join();
  t2.join();
  cout << endl;
  return 1;
}
