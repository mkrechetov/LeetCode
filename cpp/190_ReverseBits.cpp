#include <iostream>
#include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n) {
  std::bitset<32> num(n);
  std::cout << "n =    " << num << '\n';

  uint32_t rmask = 1;
  uint32_t lmask = 2147483648;

  for (uint32_t i=0; i<16; ++i, rmask <<= 1, lmask >>= 1) {
    std::bitset<32> t(lmask+rmask);
    std::cout << "mask = " << t << '\n';

    if ((n & (lmask | rmask)) == lmask) {
      n += rmask;
      n -= lmask;
    } else if ((n & (lmask | rmask)) == rmask) {
      n -= rmask;
      n += lmask;
    }
  }

  std::bitset<32> res(n);
  std::cout << "n =    " << res << '\n';

  return n;
}

int main(int argc, char* argv[]) {

  cout << reverseBits(1) << endl;
  cout << reverseBits(1248924) << endl;

  return 1;
}
