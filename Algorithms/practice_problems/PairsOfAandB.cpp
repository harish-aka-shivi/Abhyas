//Input format : A
//Output format :
//Line 1 : Pair 1 (a & b separated by space)
//Line 2 : Pair 2 (a & b separated by space)
//Line 3 : and so on


#include<iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max = 1;
    while(max*max <= N) {
        max = max+1;
    }

    for (int i=0; i <= max;i++) {
        for(int j=0;j <= max; j++) {
            if(i*i + j*j == N && i <= j) {
                cout << i << " " << j << endl;
            }
        }
    }

}
