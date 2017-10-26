//Input format :
//Line 1 : n
//Line 2 : Choice (1 or 2)

//Output
// 1 : Print sum of 1 to n numbers
// 2 : Print product of 1 to n numbers
/// Any other number : print -1

Input format :

#include<iostream>
using namespace std;

int main() {
	int N,choice;
	cin >> N;
	cin >> choice;
	int ans;
	if(choice == 1) {
	    int sum = 0;
	    int i = N;
	    while (i > 0) {
	        sum = sum + i;
	        i--;
	    }
	    ans = sum;
	} else if (choice == 2) {
	    int product = 1;
	    int i = N;
	    while(i>0) {
	        product = product*i;
	        i--;
	    }
	    ans = product;
	} else {
	    ans = -1;
	}
	cout << ans;
	return 0;
}

