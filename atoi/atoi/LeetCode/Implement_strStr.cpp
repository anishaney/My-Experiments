class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (strlen(needle) == 0 && strlen(haystack) == 0){
            return needle;
        }
        else if (strlen(haystack) == 0){
            return NULL;
        }
        else if (strlen(needle) == 0){
            return haystack;
        }
        
        char *n, *h, *start;
        h = haystack;
        n = needle;
        
        while(*h != '\0'){
            if (*h == *n){
                start = h;
                while(*n == *h && *n!='\0' && *h != '\0'){
                    n++;
                    h++;
                }
                if (*n == '\0'){
                    return start;
                }
                else if (*h == '\0'){
                    return NULL;
                }
                else{
                    h = start;
                    n = needle;
                }
            }
            h++;
        }
        return NULL;
    }
};
