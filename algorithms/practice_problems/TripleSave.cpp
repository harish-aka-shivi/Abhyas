//Given a random integer array and a number x. Find and print the triplets of elements in the 
//array which sum to x.
//While printing a triplet, print the smallest element first.



void printSorted(int arr[],int n ) {
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

void printArray(int arr[], int n) {
    int i = 0;
    while( i < n) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}

// arr - input array
// size - size of array
// x - sum of triplets
void FindTriplet(int arr[], int size, int x) {
    int a[3];
	for(int i = 0; i < size-2;i++) {
	    for(int j = i+1;j<size-1;j++) {
	        for(int k = j+1;k < size;k++) {
                if(arr[i]+arr[j]+arr[k] == x) {
                    a[0] = arr[i];
                    a[1] = arr[j];
                    a[2] = arr[k];
                    printSorted(a,3);
                    printArray(a,3);
                }	            
	        }
	    }
	}
	
}

