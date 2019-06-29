// Given two sorted arrays find the path among two having the maximum sum.
// example : 1 3 5 6 7 and
//           2 3 6 7 8 9
// max sum  path would be 2+3+5+6+7+8+9 
// can switch at common value points

// Trick her is finding the itersection point
using namespace std;
int main()
{
    int i,j,a[20],b[20],n1,n2,currentsum1=0,currentsum2=0,finalsum=0;
    cin>>n1;
    i=0;
    while (i<n1) {
        cin>>a[i];
        i++;
    }
    cin>>n2;
    j=0;
    while (j<n2) {
        cin>>b[j];
        j++;
 }
    i=0;
    j=0;
    while (i<n1 && j<n2) {

        if (a[i]>b[j]) {
            currentsum1+=b[j];
            j++;
        }
        else if (b[j]>a[i])
        {
            currentsum2+=a[i];
            i++;

            }
        else if (a[i]==b[j]) {
            currentsum1+=a[i];
            currentsum2+=b[j];
            finalsum=finalsum+max(currentsum1,currentsum2);
            currentsum1=0;
            currentsum2=0;
            i++;
            j++;
        }
    }
    while (i<n1) {
        currentsum1+=a[i];
        i++;
    }
    while (j<n2) {
        currentsum2+=b[j];
        j++;
    }
    if (currentsum1>currentsum2) {
        finalsum+=currentsum1;
    }
    else
        finalsum+=currentsum2;
    cout<<finalsum<<endl;


}
