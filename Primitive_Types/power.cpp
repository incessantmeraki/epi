/* Compute x power y*/

// Normal Approach : Multiply x y times.
// Above approach : x^15 results in 14 multiplication
// Can be done better yes x^8 = (x^4)^2 = (x^2)^2^2 ..reduces no. of multiplication
// Time Complexity: O(n) where n = no. of bits

double Power(double x, int y) 
{
  double result = 1.0;
  long long power = y;
  if (y < 0) {
    power = -power , x = 1.0 / x;
  }
  while (power) {
    if (power & 1) {
      result = *x;
    }
    x *= x, power >>= 1;
  }
  return result;
}
