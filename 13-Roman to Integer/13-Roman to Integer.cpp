#include<iostream>

using namespace std;

int toInt(char ch)
{
    switch(ch){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
int romanToInt(string s)
{
    //MMMCCCXXIII
    int res = 0;
    int len = s.size();
    int cur = 0;
    int occur = 0;
    while (cur < len){
        occur = 1;
        while (s[cur+occur] == s[cur+occur-1]){
            occur++;
        }
        cout<<cur<<" "<<occur<<endl;
        if (occur==1){
            if (s[cur]=='I' && s[cur+1]=='V'){
                res+=4;
                cur+=2;
            }
            else if (s[cur]=='X' && s[cur+1]=='L'){
                res+=40;
                cur+=2;
            }
            else if (s[cur]=='C' && s[cur+1]=='D'){
                res+=400;
                cur+=2;
            }
            else if (s[cur]=='I' && s[cur+1]=='X'){
                res+=9;
                cur+=2;
            }
            else if (s[cur]=='X' && s[cur+1]=='C'){
                res+=90;
                cur+=2;
            }
            else if (s[cur]=='C' && s[cur+1]=='M'){
                res+=900;
                cur+=2;
            }
            else {
                res += toInt(s[cur]);
                cur+=1;
            }
        }
        else {
            res += toInt(s[cur])*occur;
            cur = cur + occur;
        }
    }

    return res;
}
int main()
{
    string s;
    cin>>s;
    cout<<romanToInt(s);
}
