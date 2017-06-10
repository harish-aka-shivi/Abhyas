// arr - input array
// n - size of array
void SelectionSort(int arr[], int n) {
	// Write your code here
	int min = 0;
	int curent  = 0;
	int i = 0;
	int j = 0;
	for(i = 0; i < n-1; i++) {
	   min  = i;
	    for (j = i+1; j< n;j++) {
	        if(arr[j] < arr[min]) {
	            min = j;
	        }
	    }
	    if(arr[i] > arr[min]) {
	        //swap
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
	    }
	}
}

