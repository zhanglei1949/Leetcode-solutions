#include<iostream>
#include<vector>
using namespace std;

vector<string> res;
int work(int left, int right, string tmp)
{
    if (!(left+right)) res.push_back(tmp);
    if (left > right) return 0;

    if (left > 0){
        work(left-1, right, tmp+'(');
    }
    if (right > left){
        work(left, right-1, tmp+')');
    }
}
vector<string> generateParenthesis(int n)
{
    // number of left parenthesis should be bigger or greater than rights
    int left = n;
    int right = n;
    work(n,n,"");
    //recursive
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<endl;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    generateParenthesis(n);

}
