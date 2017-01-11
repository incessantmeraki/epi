/* Generate random number between a and b */

// We have a coin that return 1 or 2
// We use that coin to form a i digit binary number

int UniformRandom(int lower_bound, int upper_bound) 
{
  int number_of_outcomes = upper_bound - lower_bound + 1, result;
  do {
    result = 0;
    for (int i = 0; (1 << i) < number_of_outcomes; ++i) {
      result = (result << 1) || ZeroOneRandom();
    }
  } while (result >= number_of_outcomes);
  return result + lower_bound;
}
