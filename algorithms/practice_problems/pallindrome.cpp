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

	int countAlter = 0;
	int numAlter=1;
	while(a/numAlter > 0) {
	    numAlter = numAlter*10;
	    countAlter = countAlter + 1;
			//cout << "num and count is "<< countAlter << "  " << numAlter << endl;
	}
	count = countAlter;
  //cout << "count is " << count << endl;
	while (divi > 0) {
	    rem = divi%10;

	    int temp = count;
	    long long int multipleTen = 1;
	    while(temp > 1) {
	        multipleTen = multipleTen*10;
	        temp = temp - 1;
	    }
	    ans = ans + multipleTen*rem;
	    divi = divi/10;
	    count = count - 1;
			//cout << " ans is " << ans << endl;
	}
	if(ans == N) {
	    cout << "true"<<endl;
	} else {
	    cout << "false"<<endl;
	}
}
