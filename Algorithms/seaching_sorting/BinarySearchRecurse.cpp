
// Binary search using recursion.
int binarySearchRec(int input[], int size, int element, int start,int finish) {
    if(start == finish && input[start] != element) {
        return -1;
    }
    int mid = (start+finish)/2;
    if(input[mid] == element) {
        return mid;
    } else if (input[mid] > element) {
        return binarySearchRec(input,size,element,start,mid-1);
    } else if(input[mid] < element) {
        return binarySearchRec(input,size,element,mid+1,finish);
    }
}


// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[], int size, int element) {
    binarySearchRec(input,size,element,0,size-1);
    
}

