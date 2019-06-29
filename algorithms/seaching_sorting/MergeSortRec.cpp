// Not passing all the test 
// error is time out check it.
void mergeSortRec(int input[],int size, int start, int end) {
    int mid = (start +  end)/2;
    if(end != start) {
        mergeSortRec(input,size,start,mid);
        mergeSortRec(input,size,mid+1,end);
    }
    int i = start;
    int j = mid+1;
    int demo[100];
    int k = 0;
    while(i <=mid && j <= end) {
        if(input[j] < input[i]) {
            /*//swap
            int temp = input[j];
            input[j] = input[i];
            input[i] = temp;*/
            demo[k] = input[j];
            k++;
            j++;
        } else{
            demo[k] = input[i];
            i++;
            k++;
        }
    }
    
    while(i <= mid) {
        demo[k] = input[i];
        i++;
        k++;
    }
    while(j <= end) {
        demo[k] = input[j];
        j++;
        k++;
    }
    int m =0;
    for(int l = start; l <= end; l++) {
        input[l] = demo[m];
        m++;
    }
}

void mergeSort(int input[], int size){

    mergeSortRec(input,size,0,size-1);
	
        
}

