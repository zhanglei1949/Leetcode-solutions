#include<iostream>

using namespace std;

string intToRoman(int num)
{
    string res;
    string r[4][10]=
            {
                 {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                 {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                 {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                 {"", "M", "MM", "MMM", "",   "",  "",    "",    "",     ""}
            };
    int cnt = 0;
    while (num > 0){
        res = r[cnt++][num%10] + res;
        num = num / 10;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<intToRoman(n);
}
