class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse_bits = 0;
        
        for (int i = 0; i < 32; i++){
            reverse_bits = reverse_bits << 1 | (n & 1);
            n = n >> 1;
        }
    }
};
