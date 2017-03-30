#include<iostream>
#include<cmath>
using namespace std;

int findComplement(int n)
{
    int tmp = n;
    int len = 0;
    while (n >= 1){
        n = n/2;
        len++;
    }
    //cout<<len<<endl;
    return pow(2,len)-1-tmp;
}
int main()
{
    int n;
    cin>>n;
    cout<<findComplement(n);
}
