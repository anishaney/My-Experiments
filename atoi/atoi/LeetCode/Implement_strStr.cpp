/*Algorithm: Get two pointers for each strig, haystack and needle. A third pointer is required to store the start position of needle string in the haystack. Check for an instance in haystack where needle's first character is matched, once matched check if all the needle string is present. Once the whole needle is present in haystack, return start pointer.*/

/*Complexity: O(n_haystack)*/

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
