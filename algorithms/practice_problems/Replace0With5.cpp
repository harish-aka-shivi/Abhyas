// replace all the ‘0’ present in the number with ‘5’. Print the updated number.
// sample input : 10009
// sample outut : 15559
#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int divi = N;
	int a = N;
	int rem = 0;
	long long int ans = 0;
	int count = 0;

  //cout << "count is " << count << endl;
	while (divi > 0) {
	    rem = divi%10;

	    int temp = count;
	    long long int multipleTen = 1;
	    while(temp > 0) {
	        multipleTen = multipleTen*10;
	        temp = temp - 1;
	    }
	    ans = ans + multipleTen*rem;
	    if(rem == 0) {
	        ans = ans + multipleTen*5;
	    }
	    divi = divi/10;
	    count = count + 1;
			//cout << " ans is " << ans << endl;
	}
	cout << ans;
}
