uint32_t reverseBits(uint32_t n) {
    uint32_t bits[32], reverse_bits = 0;
    int i, j;
    
    for (i = 0; i < 32; i++){
        bits[i] = (n >> i) & 1;
    }
    
    for (j = 0; j < 32; j++){
        reverse_bits |= (1 << (31-j)) * bits[j]
    }
    
    return reverse_bits;
}
