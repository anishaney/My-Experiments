int majorityElement (int* nums, int numSize){
	int maj = *nums, i, count = 0;

	for (i = 0; i < numSize; i++){

		printf ("element at %d is %d\n", i, *(nums+i));
		if (count == 0){
			maj = *(nums+i);
			count = 1;
		}
		else if (maj == *(nums+i)){
			count++;
		}
		else
			count--;
	}

	return maj;
}
