//Sum of two arrays
#include<iostream>
using namespace std;
// input1 - first array
// size1 - size of first array
// input2 - second array
// size2 - size of second array
// output - array in which sum is to be stored
void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[]){


    //int i = 0, j = 0;
    int carry = 0;
    int sum = 0;
    //int output[];
    int k = max(size1,size2)+1;
		//std::cout << "k is "<<k << std::endl;
		int i = size1-1;
		int j = size2-1;
    int sizeAns = k;
		k = k - 1;
		int o = k;


    while(i >= 0 && j >=  0) {
        sum = input1[i] + input2[j] + carry;
				//std::cout << "sum of first is "<< sum << std::endl;
				carry = sum/10;
        output[k] = sum%10;
        k--;
        i--;
        j--;

    }
    while(i >= 0) {
        sum = input1[i] + carry;
        carry = sum/10;
        output[k] = sum%10;
        i--;
        k--;

    }

    while(j >=  0) {
        sum = input2[j] + carry;
        carry = sum/10;
        output[k] = sum%10;
        j--;
        k--;

    }
    output[k] = carry;
	  k--;

    int l = 0;

    while(l < sizeAns) {
        cout << output[l] << " ";
        l++;
    }

}

int main() {
	int sizeA = 0;
	int sizeB = 0;
	int a[100];
	int b[100];
	cin >> sizeA;
	int j = 0 ;
    while(j < sizeA) {
        cin >> a[j];
        j++;
    }
    cin >> sizeB;
    int i = 0;
    while(i < sizeB) {
        cin >> b[i];
        i++;
    }
		int output[100];
		sumOfTwoArrays(a,sizeA,b,sizeB,output);



	return 0;
}
