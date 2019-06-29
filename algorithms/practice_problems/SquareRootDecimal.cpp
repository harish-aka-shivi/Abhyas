//First number is the number whose square root is to be finded
// second number is the the accuracy of decimal places.
//Sample input : 10 4
// sample output : 3.1622
#include<iostream>
using namespace std;
int main() {
	int n,d;
	cin >> n >> d; 
	//cin >> d;
	int ans = 0;
	int increment = 1;
	int currentDecimalPoint = 0;
	
	while(currentDecimalPoint <= d) {
	    while(ans*ans <= n){
	        ans = ans + increment;    
	    }
	    ans = ans - increment;
	    increment = increment * 0.1;
	    currentDecimalPoint = currentDecimalPoint + 1;
	    //cout << currentDecimalPoint; 
	}
	cout << ans;
}
