/* Same weight minimum Difference */

// Weight = no of 1's in binary representation
// Problem: For i find j with same weight and minimum |i-j|
// BruteForce: check if weight of i-1,i+1,i-2,i+2...... till found
// First thought : swap lsb with bit that's different from it
//                 while moving from lsb to msb
// Above logic : Not valid 
// Working logic: swap two righmost consecutive bits that differ

const int kNumUnsignBits = 64;

unsigned long ClosestIntSameBitCount(unsigned long x) 
{
  for (int i = 0; i < kNumUnsignedBits -1; ++i) {
    if (((x >> i) & 1) != ((x >> (i+1)) & 1)) {
      x ^= (1UL << i) | (1UL << (i+1));
      return x;
    }
  }
  throw invalid_argument("All bits are 0 or 1")
}
