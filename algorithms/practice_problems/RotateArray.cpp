
// arr - input array
// size - size of array
// d - array to be rotated by d elements
void Rotate(int arr[], int d, int size) {
	int a[1000];
	int i = 0;
	while(i < d) {
	    a[i] = arr[i];
	    i++;
	}
	while(i < size) {
	    int j = i-d;
	    arr[j] = arr[i];
	    i++;
	}
	int j = size-d;
	int k = 0;
	while(j < size) {
	    arr[j] = a[k];
	    k++;
	    j++;
	}

}
