#include<iostream>
#include<cmath>
using namespace std;

bool isPalindrome(int x)
{
    //O(1)
    if (x < 0) return false;
    int tmp = x;
    int len = 0;
    int head = 0;
    int rear = 0;
    bool flag = true;
    while (tmp > 0){
        len++;
        tmp = tmp/10;
    }
    //cout<<"len:"<<len<<endl;
    if (len == 1) return true;
    while (len > 1){
        head = x/(pow(10,len-1));
        rear = x%10;
        x = x - head*(pow(10,len-1));
        x = x /10;
        //cout<<"head: "<<head<<" rear: "<<rear<<" x: "<<x<<endl;

        if (head != rear){
            break;
        }
        len = len - 2;
    }
    if (len < 2) return true;
    else return false;
}
int main()
{
    int x;
    cin>>x;
    cout<<isPalindrome(x);
}
