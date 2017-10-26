//Given an integer array of size 2N + 1. In this given array, N numbers are present twice
// and one number is present only once in the array.
// Take input
// arr - input array
// size - size of array

int FindDuplicate(int arr[], int size){
	// Write your code here
	int i = 0;
	//boolean dupli = true;
	int ans;
	while(i < size) {
	    int j = 0;
	    while(j < size) {
	        if(i != j && arr[i] == arr[j]) {
	            break;
	        }
	        j++;
	    }
	    if(j >= size) {
	        ans = arr[i];
	        break;
	    }
	    i++;
	}
	return ans;

}
