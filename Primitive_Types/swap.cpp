/* Swapping 2 bits */

// First approach : fiddling with bitmask and bitwise operator
// Clever approach : Use of ^ 1 to flip 1 ^ 1 = 0, 0 ^ 1 = 1

long SwapBits(long x, int i, int j) 
{
  //Extract ith bit and jth and see if they differ
  if (((x >> i) & 1) != ((x >> j) & 1)) {
    unsigned long bit_mask = (1L << i) | (1L << j);
    x ^= bit_mask
  }
  return x;
}

