#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
//priority need to be considered
int calculate(string s)
{
    int len = s.size();
    int res = 0;
    stack<int> nums;
    stack<int> opers;
    //0 for +, 1 for -, 2 for (, 3 for )
    int tmp_num = 0;
    int operat = 0;
    int first_operand = 0;
    int second_operand = 0;
    int a;
    bool flag = false;
    for (int i = 0; i < len; ){// no i++;
        //cout<<s[i]<<endl;
        tmp_num = 0;
        flag = false;
        while (s[i]==' ')
            i++;
        while (s[i]<='9'&&s[i]>='0'){
            flag = true;
            tmp_num = tmp_num*10+(s[i]-'0');
            i++;
        }
        while (s[i]==' ')
            i++;
        //cout<<s[i]<<" "<<flag<<endl;
        if (!flag){//i.e not number
            switch(s[i]){
                // only push in when the priority of the top is less than current
                //cout<<s[i]<<endl;
                case '+':
                    if (!opers.empty() && opers.top()==1){
                        opers.pop();
                        second_operand = nums.top();
                        nums.pop();
                        first_operand = nums.top();
                        nums.pop();
                        //cout<<operat<<" "<<first_operand<<" "<<second_operand<<endl;
                        nums.push(first_operand-second_operand);
                    }
                    opers.push(0);
                    break;
                case '-':
                    if (!opers.empty() && opers.top()==1){
                        opers.pop();
                        second_operand = nums.top();
                        nums.pop();
                        first_operand = nums.top();
                        nums.pop();
                        //cout<<operat<<" "<<first_operand<<" "<<second_operand<<endl;
                        nums.push(first_operand-second_operand);
                    }
                    opers.push(1);
                    break;
                case '(': opers.push(2); break;
                case ')':
                    while(opers.top()!=2){
                        operat = opers.top();
                        opers.pop();
                        second_operand = nums.top();
                        nums.pop();
                        first_operand = nums.top();
                        nums.pop();
                        //cout<<operat<<" "<<first_operand<<" "<<second_operand<<endl;
                        if (operat==0)
                            nums.push(first_operand+second_operand);
                        else nums.push(first_operand-second_operand);
                    }
                    opers.pop();
                    break;
                default: //cout<<endl<<"invalid operator"<<endl;
                    //cout<<i<<endl;
                    return -1;
            }
            i++;
            while (s[i]==' '){
                i++;
            }
        }
        else {
            nums.push(tmp_num);
            //cout<<tmp_num<<" ";
        }
        //cout<<"hj"<<endl;
    }
    while (!opers.empty()){
        operat = opers.top();
        opers.pop();
        second_operand = nums.top();
        nums.pop();
        first_operand = nums.top();
        nums.pop();
        //cout<<operat<<" "<<first_operand<<" "<<second_operand<<endl;
        if (operat==0)
            nums.push(first_operand+second_operand);
        else nums.push(first_operand-second_operand);
    }
    res = nums.top();
    nums.pop();


    return res;
}
int main()
{
    string s;
    s=" 2-1 + 2-1 ";
    cout<<calculate(s);
}
