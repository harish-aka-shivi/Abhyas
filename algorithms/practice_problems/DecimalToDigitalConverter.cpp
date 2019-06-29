#include<iostream>
using namespace std;

int main() {
	long long int N;
	cin >> N;
	long long int rem = 0;
	long long int divi = N;
	int counter = 0;
	long long int ans = 0;
	
	while(divi > 0) {
	    long long int a = 0;
	    rem = divi%2;
	    int num = counter;
	    long long int multipleTen = 1;
	    while(num > 0) {
	        multipleTen = multipleTen*10;
	        num = num-1;
	    }
	    //cout << "counter == " << counter << "multipleTen == " << multipleTen;
	    
	    a = rem*multipleTen;
	    //cout << "  a ==> " << a;
	    ans =ans + a;
	    
	    counter = counter + 1;
	    divi = divi/2;
	    //cout << "ans" << ans;
	}
	cout << ans;
	
}

