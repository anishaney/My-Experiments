int hammingWeight(uint32_t n) {
        uint32_t multipleoftwo = 1, nobits = 32;
        int rslt = 0;
        while (nobits--){
            if (n & multipleoftwo)
                rslt++;
            multipleoftwo *= 2;
        }
        return rslt;
    }
