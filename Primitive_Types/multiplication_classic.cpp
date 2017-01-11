/* Multiplication of x and y using bit-wise operation */

// This is how multiplication is impemented in MicroProcessors
// BruteForce - add x y times => Inefficient O(2^n) where n = no. of bits of y
// Efficient Method - normal paper-multiplication method but for bits
// Multiplication = Shift left x (by ith bit value of y) and add them
// Addition logic = full adder logic -> Look LOGIC GATES diagram

unsigned Multiply(unsigned x, unsigned y) 
{
  unsigned sum = 0;
  while (x) {
    if (x & 1) {
      sum = Add(sum , y);
    }
    x >>= 1, y <<=1;
  }
  return sum;
}


unsigned Add(unsigned a, unsigned b) {
  unsignd sum = 0, carryin = 0, k = 1, temp_a = a, temp_b = b;
  while (temp_a || temp_b) {
    unsigned ak = a & k, bk = b & k;
    unsigned carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
    sum |= (ak ^ bk ^ carryin);
    carryin = carryout << 1, k <<= 1, temp_a >>= 1, temp_b >>= 1;
  }
  return sum|carryin;
}
