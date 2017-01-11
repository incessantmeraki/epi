/* Check if an integer is palindrome */

// First approach : Convert into string and check first and last and move inwards
// Above approach disadvantage -> O(n) space complexity for storing string
// Avoding O(n) space complexity by operating on integer directly
// Extracting LSB = num % 10
// Exttracting MSB = num / 10 ^(n-1) where n= no. of digits
// n= floor(log10(num)) + 1

bool IsPalindromeNumber(int x) 
{
  if (x < 0) {
    return false;
  } else if (x == 0) {
    return true;
  }

  const int num_digits = static_cast<int> (floor(log10(x))) + 1;
  int msd_mask = static_cast<int>(pow(10, num_digits - 1));
  for (int i  = 0; i < (num_digits / 2); ++i) {
    if (x / msd_mask != x % 10) {
      return false;
    }
    x %= msd_mask;
    x /= 10;
    msd_mask /= 100;
  }
  return true;
}
