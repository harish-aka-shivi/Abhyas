//reveres of a number
// inut 12340
//output 4321
#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int N;
	cin >> N;
	int ans = 0;
	int rem = 1;
	int divi = N;
	while (divi != 0) {
	    rem = divi%10;
	    ans = ans + rem;
	    ans = ans*10;
	    divi = divi/10;
	}
	cout << ans/10;
	
}

