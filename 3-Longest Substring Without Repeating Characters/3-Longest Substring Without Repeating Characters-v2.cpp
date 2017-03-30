#include<iostream>

using namespace std;


int lengthOfLongestSubstring(string s)
{
    int charac[26] = {-1};
    for (int i = 0; i< 26; ++i){
        charac[i] = -1;
    }
    int len = s.length()-2;
    int head = 1;
    int rear = 1;
    charac[s[1]-'a'] = 0;
    int maximum = 1;
    while (rear < len){
        //move rear
        //cout<<"head "<<head<<" rear "<<rear<<endl;
        int tmp = charac[s[rear+1]-'a'];
        if (rear+1 < len && tmp == -1){
            //cout<<s[rear+1]<<" "<<s[rear+1]-'a'<<" "<<tmp<<endl;
            rear = rear+1;
            charac[s[rear] - 'a'] = rear;

            maximum = max(maximum, rear-head+1);
        }
        else if (rear+1 < len){
            //cout<<s[rear+1]<<" "<<s[rear+1]-'a'<<" "<<tmp<<endl;
            for (int i = head; i <= tmp; ++i){
                charac[s[i] -'a'] = -1;
            }
            head = tmp+1;
            rear = rear+1;
            charac[s[rear]-'a'] = rear;
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
