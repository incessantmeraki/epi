
/* First Method: BruteForce  */

//Adds value of each bit(0|1) to result and returns result % 2
//Time Complexity : O(n) where n = number of bits

short Parity(unsigned long x) 
{
  short result = 0;
  while (x) {
    result += (x & 1);
    x >>= 1;
  }
  return result % 2;
}


/* Second Method: Refined Brute Force */

//Uses trick: x & (x-1) removes the set bit as least position
//Time Complexity : 0(k) where k = number of 1's

short Parity(unsigned long x) 
{
  short result = 0;
  while (x) {
    result ^= 1;
    x &= (x-1);
  }
  return result;
}

/* Third Method: Uses cache */

//Cache stores parity of 16 bits 
//64 bit = 4 16 bits words
//parity of 64 bits words = XORs of parity of 4 16 bits words
//Time Complexity: 64/16 i.e 0(n/L) n = word size; L = width of words cached

short Parity(unsigned long x) 
{
  const int kWordSize = 16;
  const int kBitMask = 0xFFFF;
  return precomputed_parity[x >> (3 * kWordSize)] ^
         precomputed_parity[(x >> (2 * kWordSize)) & kBitMask] ^
         precomputed_parity[(x >> kWordSize) & kBitMask] ^
         precomputed_parity[x & kBitMask];
}

/* Fourth Method: Associtivity property of Xors */

//XOR of group of bits is its parity
//Example: To find parity of 4 bits XOR first 2 bit with next 2
//Now with result (2 bit value) xor first 1 bit with next 1 bit == result

short Parity(unsigned long x) 
{
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}


