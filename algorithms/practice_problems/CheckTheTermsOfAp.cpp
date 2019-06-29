//input
//6
//2 6 10 14 18 22
//Output
// true
#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int count;
	cin >> count;
	int a,b;
	int diff;
	int previousDiff;
	if(count >=2) {
	    cin >> a;
	    cin >> b;
	    previousDiff = b-a;
	}
	count = count -2;
	while (count > 0) {
	    a = b;
	    cin >> b;
	    diff = b-a;
	    if(diff != previousDiff) {
	        cout << "false";
	        break;
	    }
	    count = count -1 ;
	}
	cout << "true";
	return 0;

}
