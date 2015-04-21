void rotateArray(int nums[], int n, int k){
	int start = 0, end = n-1;

	k = n%k;

	while (start < end){
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}

	start = 0;
	end = k-1;
	while (start < end){
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}

	start = k;
	end = n-1;
	while (start < end){
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}
