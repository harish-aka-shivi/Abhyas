//Terms of Ap 
// 3N+2;

#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i = 1;
	int count = 0;
	while(count < N) {
	    int j = 3*i + 2;
	    
	    if(j%4 != 0) {
	        count = count+1;
	        cout << j << " ";
	    }
	    i++;
	    
	    
	}
	return 0;
	
}

