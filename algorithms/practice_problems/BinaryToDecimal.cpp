//Input format : Binary number (int)
//Output format : Corresponding Decimal number (int)
// Binary to decimal

#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int rem;
    int divi = N;
    int iteration = 0;
	int sum = 0;
	while(divi != 0) {
	    rem = divi % 10;
	    int num = 1;
	    for (int j = 0; j <iteration; j++) {
	        num = num*2;
	    }
	    sum = sum + num*rem;
	    iteration = iteration+1;
	    divi = divi/10;
	}
	cout << sum;
	
}

