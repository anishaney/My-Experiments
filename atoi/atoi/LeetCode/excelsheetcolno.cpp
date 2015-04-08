class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty())
            return 0;
        
        int i = s.length()-1, colnum = 0, product = 1;
        
        while (i >= 0){
            if (product == 1)
                colnum = (s[i]-'A'+1);
            else
                colnum += (product)*(s[i]-'A'+1);
            product *= 26;
	        i--;
        }
        
        return colnum;
    }
};
