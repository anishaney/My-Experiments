class Solution {
public:
    int CharToInt (char ch){
        switch (ch){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        unsigned int result = CharToInt (s[0]);
        int i = 0;
        for (i = 1; i < s.length(); i++){
            if (CharToInt(s[i]) > CharToInt(s[i-1]))
                result += (CharToInt(s[i]) - (2*CharToInt(s[i-1])));
            else
                result += CharToInt(s[i]);
        }
        return result;
    }
};
