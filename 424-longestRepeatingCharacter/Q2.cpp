#include<iostream>
#include<string>

using namespace std;

int characterReplacement(string s, int k)
{
    int res = 0;
    int len = s.length();
    int *str = new int [len];
    for (int i = 0; i < len; ++i){
        str[i] = s[i] - 'A';
    }
    int alphabet[26] = {0};
    int start = 0;
    int end = 0;
    int maxCharAppear = 0;
    for (end = 0; end < len; ++end){

        alphabet[str[end]]++;
        maxCharAppear = max(alphabet[str[end]], maxCharAppear);
        //cout<<start<<" "<<end<<" "<<maxCharAppear<<endl;
        //every time move the end pointer, update the maximum appearance
        if (end - start + 1 - maxCharAppear <= k){
            //slide is legal, update
            res = max(res, end - start + 1);
        }
        else {
            //if(end - start + 1 - maxCharAppear > k){ // 出现这种情况的时候最多是K+1, 不可能更大
            alphabet[str[start++]]--;
            //move the left slide
            //update
            maxCharAppear = 0;
            for (int i = 0; i < 26; ++i){
                maxCharAppear = max(maxCharAppear, alphabet[i]);
            }
        }
    }
    return res;
}
int main()
{
    string s;
    int k;
    cin>>s>>k;
    cout<<characterReplacement(s,k);
}
