//prints
//55555
//54444
//54333
//54322
//54321
//
#include<iostream>
using namespace std;

int main() {
    int N = 0;
    cin >> N;


    for(int i = 5; i > 0; i --) {
        int j = 5;
        while(j > 0) {
            if(j > i) {
                cout << j;
            } else {
                cout << i;
            }

            j--;
        }
        cout << endl;
    }
    return 0;
}
