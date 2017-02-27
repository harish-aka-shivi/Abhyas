//Sum of digits (recursive)
int sumOfDigits(int n) {
    if(n < 10) {
        return n;
    }
    int sum = n%10 + sumOfDigits(n/10);
    return sum;
}

// multiply recursively
int multiplyNumbers(int m, int n) {
    if(n>0) {
        n = n-1;
        return m+multiplyNumbers(m,n);
    } else  {
        return 0;
    }
}

//count zeros
int countZeros(int n) {
    if(n > 0 ) {
        int rem = n%10;
        int sum;
        if(rem == 0) {
            sum = 1+ countZeros(n/10);
        } else {
            sum = 0 + countZeros(n/10);
        }
        return sum;
    }
}

//geometric sum
// input : 3
// output :- 1 + 1/2 + 1/4 + 1/2^k
//output 1.875
double geometricSum(int k) {
    if(k >= 0) {
    float prod = 1;
    int n = k;
    while(n > 0) {
        prod = prod*1/2;
        n--;
    }

    float sum = prod + geometricSum(k-1);
    return sum;
    } else {
        return 0.0f;
    }
}


// checking for pallindrome using recursion

bool checkPalindrome(char input[]) {
    int i = 0;

    while(input[i] != '\0') {
        i++;
        //cout << "input arr is "<< input[i] << endl;
    }
    i = i-1;
    if(i > 0) {
        if(input[0] != input[i]) {
            return false;
        }

        else{
            int j = 0;
            while(j <= i) {
                input[j] = input[j+1];
                j++;
            }
            input[j-2] = '\0';
            checkPalindrome(input);
        }
    } else {
        return true;
    }

    //cout << i << endl;
}
