#include<iostream>

using namespace std;


int lengthOfLongestSubstring(string s)
{
    int charac[127] = {-1};
    for (int i = 0; i< 127; ++i){
        charac[i] = -1;
    }
    int len = s.length();
    if (len == 0)
        return 0;
    int head = 0;
    int rear = 0;
    charac[s[0]-' '] = 0;
    int maximum = 1;
    int tmp = 0;
    while (rear < len){
        //move rear
        //cout<<"head "<<head<<" rear "<<rear<<endl;

        if (rear+1 < len)
            tmp = charac[s[rear+1]-' '];
        if (rear+1 < len && tmp == -1){
            //cout<<s[rear+1]<<" "<<s[rear+1]-'a'<<" "<<tmp<<endl;
            rear = rear+1;
            charac[s[rear] - ' '] = rear;

            maximum = max(maximum, rear-head+1);
        }
        else if (rear+1 < len){
            //cout<<s[rear+1]<<" "<<s[rear+1]-'a'<<" "<<tmp<<endl;
            for (int i = head; i <= tmp; ++i){
                charac[s[i] -' '] = -1;
            }
            head = tmp+1;
            rear = rear+1;
            charac[s[rear]-' '] = rear;
        }
        else break;
    }
    return maximum;
}

int main()
{
    string s = "abcabcbb";
    //cout<<'"'-'a'<<endl;
    cout<<lengthOfLongestSubstring(s);
}
