#include<iostream>
#include<stack>
using namespace std;

int longestValidParentheses(string s)
{
    // Two pointer in the front, one paren.top indicate the conservationist starter point,
    //and the other last_valid_index indicate the valid stater, only used when the left-parentheses are poped out
    int res = 0;
    int len = s.size();
    stack<int> paren;
    int last_valid_index=0;
    for (int i = 0; i < len; ++i){
        if (s[i]=='('){
            paren.push(i);
        }
        else {
            if (paren.empty()){
                last_valid_index = i+1;
            }
            else {
                paren.pop();
                if (paren.empty()){
                    res = max(res, i - last_valid_index+1);
                }
                else {
                    res = max(res, i - paren.top());
                }
            }
        }
    }
    return res;
}
int main()
{
    string s="()(())";
    cout<<longestValidParentheses(s);
}
//int longestValidParentheses1(string s) {
//    int res = 0;
//    int cnt = 0;
//    stack<int> paren;
//    for (int i = 0; i < s.size();++i){
//        //cout<<s[i]<<" ";
//
//        if (s[i]==')'){
//            if (paren.empty()){
//                res = max(cnt, res);
//                cnt = 0;
//                continue;
//            }
//            else if (paren.top()==0){
//                paren.pop();
//                cnt+=2;
//            }
//        }
//        else if (s[i]=='('){
//            if (paren.empty()){
//
//            }
//            paren.push(0);
//        }
//    }
//    if (paren.empty())
//        res = max(res, cnt);
//    else
//    return res;
//}
