#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s)
{
    stack<int> paren;
    //0-( 1-) 2-{ 3-} 4-[ 5 -]
    int len = s.size();
    for (int i = 0; i < len; ++i){
        int value = -1;
        switch(s[i]){
                case '(':
                    value = 0;
                    break;
                case ')':
                    value = 1;
                    break;
                case '{':
                    value = 2;
                    break;
                case '}':
                    value = 3;
                    break;
                case '[':
                    value = 4;
                    break;
                case ']':
                    value = 5;
                    break;
            }
        if (paren.empty()){
            if (value%2) return false;
            else {
                //cout<<"push: "<<value<<endl;
                paren.push(value);
            }
        }
        else {
            int top = paren.top();
            //cout<<"get: "<<value<<" pop: "<<top<<endl;
            if (top == value - 1)
                paren.pop();
            else {
                if (value%2) return false;
                else{
                    paren.push(value);
                }
            }
        }
    }
    if (paren.empty()) return true;
    else return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<isValid(s);
}
