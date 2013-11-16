/*Longest substring in a string where all the characters are unique.*/

/*Algorithm:
Use two pointers, one for start of substring and one for the current position. For each character in the given string update the corresponding position in the integer array for the position of the character i.e. if current character is (say) 'l' then update the integer array position corresponding to 'l' ((int)'l' - (int)'a') with the index of the character in the string. 
If you find that the element in the integer array at a given index is already present(filled), check if that index is below the starting position of the current substring. If yes, no need to change anything but update its value with the current index.
If it is between the starting pointer and the current pointer, then  calculate the difference in the positions of the pointers and store the length in 'max_length' variable and put the starting pointer to the next position of the repeated character.
*/

/*Complexity: O(n)*/

/*Assumption: All the characters in the string are small alphabets i.e. a-z*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i, j; //'i' contains the starting point of the substring while 'j' contains the current element
    	int charstr[26]; //Contains the index of the given variable
    	int index = 0;
    
    	int max_length = 0, length = 0; //Contains the length of the longest substring with unique characters
    
    	for (index = 0; index < 26; index++)
    		charstr[index] = -1;
    
    	i = j = 0;
    
    	for (j = 0; j < s.length(); j++){
    		index = (int)s.at(j) - (int)'a';
    		//cout << index << endl;
    		if (charstr[index] >= i){
    			length = j-i;
    			if (max_length < length)
    				max_length = length;
    			i = charstr[index]+1;
    		}
    		charstr[index] = j;
    	}

	/*Check for the last character since it may not have appeared for the firt time*/
    	if (charstr[index] >= i){
	    	length = j-i;
		    if (max_length < length)
			    max_length = length;
    	}

    	return max_length;
    }
};
