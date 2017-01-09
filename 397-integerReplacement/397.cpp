#include<iostream>
#define INT_MAX  2147483647

using namespace std;
int integerReplacement(int n)
{
    //consider the binary expression of integers
    //its last two bits can be 00, 01, 10, 11
    //for 00, just >> 2bits, for 01 the best choice is to minus 1
    //for 10 the best choice is >>1bit, and 11, plus 1
    if (n==1){
        return 0;
    }
    if (n==INT_MAX){
        return 32;
    }
    int cnt = 0;
    while (n!=1){
        //cout<<n<<endl;
        if (n%2==0){
            n=n>>1;
        }
        else {
            if (n==3){
                n--;
            }
            else if ( (n>>1)&1 == 1){
                n++;
            }
            else n--;
        }
        cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<integerReplacement(n);
}
