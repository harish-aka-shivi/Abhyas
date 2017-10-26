// arr - input array
// n - size of array
// val - element to be searched
int BinarySearch(int arr[], int n, int val){
    int start = 0;
    int end = n-1;
    int mid = 0;
    int i=0;
    while(start <= end){
        mid = (start + end)/2;
        
        if(arr[mid] == val) {
            return mid ;
        
        } else if( arr[mid] < val) {
            start = mid+1;
        } else if(arr[mid] > val) {
            end = mid-1;
        }
        i++;
    }
    return -1;
	


// arr - input array
// n - size of array
// val - element to be searched
int linearSearch(int arr[], int n ,int val){
    for (int i = 0; i < n; i ++) {
        if(arr[i] == val) {
            //cout << i << endl;
            return i;
        }
    }
    return -1;
}




