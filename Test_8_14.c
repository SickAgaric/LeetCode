int hammingDistance(int x, int y) {
        int xor_number = x^y;
        int count = 0;   
        while(xor_number > 0){
            count += xor_number & 1;
            xor_number = xor_number >> 1;
        }
        return count;
        
    }