#include<iostream>
#include<string>
using namespace std;


int myatoi(string str)
{    //1. skip whitespace
    //2. first character must be +/-/number;
    //3. characters followed by numbers will be ignored
    //4. if first sequence is not a valid number or str is empty or full of whitespace, return 0
    //5. if out of range, return INT_MAX or INT_MIN;
    //-------------------------------------------------------------------------------------------
    // first scan
    // then convert to integer
    // judge overflow
    // INT_MAX (2147483647) or INT_MIN (-2147483648)
    int data[10]={0};
    int int_max[10] = {2,1,4,7,4,8,3,6,4,7};
    int int_min[10] = {2,1,4,7,4,8,3,6,4,8};
    int sign = 0;// positive or negative
    int overflow = 0; // 1 implies overflow
    int len = str.size();
    int cur = 0;
    int res = 0;
    if (len==0){
        return 0;
    }
    while (cur < len){
        if (str[cur]==' '|| str[cur]=='\t'){
            cur++;
        }
        else break;
    }
    //
    if (cur==len) return 0;
    else {
        if (str[cur]=='+'){
            sign = 1;// positive
            cur++;
        }
        else if (str[cur]=='-'){
            sign = 0;//negative
            cur++;
        }
        else if (str[cur]<='9'&&str[cur]>='0'){
            sign = 1;
        }
        else return 0;
    }
    int index = 0;
    while (cur < len){
        if (str[cur]>'9' || str[cur] < '0'){
            break;
        }
        data[index++]=str[cur]-'0';
        cur++;
        if (index == 10){
            if (cur < len && (str[cur] <= '9' && str[cur] >= '0'))
                overflow = 1;
            break;
        }
    }
    if (overflow){
        if (sign) return 2147483647;
        else return -2147483648;
    }

    if (sign==1){//positive
        if (index < 9)
            overflow = 0;
        else {
            int i;
            for (i = 0; i < index; ++i){
                if (data[i] < int_max[i]){
                    overflow = 0;
                    break;
                }
                else if (data[i] > int_max[i]){
                    overflow = 1;
                    break;
                }
            }
            if (i==index) overflow = 0;//equal
        }
        if (overflow) return 2147483647;
    }
    else {
        if (index < 9)
            overflow = 0;
        else {
            int i;
            for (i = 0; i < index; ++i){
                if (data[i] < int_min[i]){
                    overflow = 0;
                    break;
                }
                else if (data[i] > int_max[i]){
                    overflow = 1;
                    break;
                }
            }
            if (i==index) overflow = 0;//equal
        }
        if (overflow) return -2147483648;
    }
    for (int i = 0; i < index; ++i){
        res = res*10 + data[i];
    }
    if (sign==0) res = -res;
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<myatoi(s)<<endl;
}
