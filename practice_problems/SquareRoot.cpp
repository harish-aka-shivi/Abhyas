#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int square = 1;
    int ans = 1;
	while(square <= N) {
	    ans = ans +1;
	    square = ans*ans;
	   
	}
	ans = ans-1;
	cout << ans;
}

