/* Find quotient of x/y */

// Naive approach: subtract y from x until result < y and quotient = no. of subtraction
// Above inefficient if x = 2^31 - 1 and y = 1 
// Efficient approach : subtract 2^k * y from x  and add 2^k to quotient

unsigned Divide(unsigned x, unsigned y) {
  unsigned result = 0;
  int power = 32;
  unsigned long long y_power = static_cast<unsigned long long>(y) << power;
  while (x >= y) {
    while (y_power > x) {
      y_power >>= 1;
      --power;
    }
    result += 1U << power;
    x -= y_power;
  }
  return result;
}
