bool isPalindrome(char* s) {
    char *start = s, *end = s;

	if (*s == '\0')
		return 1;

	while (*(end+1) != '\0')
		end++;

	while (start <= end){
		if (!(*start >= '0' && *start <= '9') && !(*start >= 'A' && *start <= 'Z') && !(*start >= 'a' && *start <= 'z')){
			start++;
			continue;
		}
		if (!(*end >= '0' && *end <= '9') && !(*end >= 'A' && *end <= 'Z') && !(*end >= 'a' && *end <= 'z')){
			end--;
			continue;
		}

		if (*start >= 'A' && *start <= 'Z')
			*start = *start + 32;

		if (*end >= 'A' && *end <= 'Z')
			*end = *end + 32;

		if (*start != *end)
			return 0;

		start++;
		end--;
	}

	return 1;
}
