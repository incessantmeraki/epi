/* Reverse given 64 bits */

//Use of caches: Caches stores reverse of 16 bits
//Divide 64 bits into 4 16 bits chunks
//Use cache to find reverse of each 16 bits and combine them
//Time Complexity : O(n/L) n= bit of integers, l = bits of cached int

long ReverseBits(long x) {
  const int kWordSize = 16;
  const int kBitMask = 0xFFFF;
  return precomputed_reverse[x & kBitMask] << (3 * kWordSize) |
         precomputed_reverse[(x >> kWordSize) & kBitMask] << (2 * kWordSize) |
         precomputed_reverse[((x >> (2 * kWordSize)) & kBitMask] << kWordSize |
         precomputed_reverse[((x >> (3 * kWordSize)) & kBitMask];
}

