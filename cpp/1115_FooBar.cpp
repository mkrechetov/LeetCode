#include <iostream>
#include <functional>
#include <thread>
#include <mutex>

using namespace std;
mutex mutf, mutb;

class FooBar {
private:
    int n;
public:

    FooBar(int n) {
        this->n = n;
        mutb.lock();
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
          mutf.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
          mutb.unlock();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
          mutb.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
          mutf.unlock();
        }
    }
};


// void printfoo() {cout << "foo";}
// void printbar() {cout << "bar";}

int main() {

  FooBar obj(10);

  thread t1(&FooBar::foo, obj, []{ cout << "foo"; });
  thread t2(&FooBar::bar, obj, []{ cout << "bar"; });
  // thread t1(&FooBar::foo, obj, printfoo);
  // thread t2(&FooBar::bar, obj, printbar);
  t1.join();
  t2.join();
  cout << endl;
  return 1;
}
