#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> res;
    int words_size = words.size();
    if (words_size < 1) return res;
    int word_len = words[0].size();
    int str_len = s.size();
    if (str_len < word_len * words_size) return res;
    map<string, int> dic;
    map<string, int> cnt;
    string tmp;
    map<string, int>::iterator iter;
    for (int i = 0; i < words_size; ++i){
        ++dic[words[i]];
    }
//    for (iter = dic.begin(); iter!=dic.end(); ++iter){
//        cout<<iter->first<<" "<<iter->second<<endl;
//    }
//    cout<<endl;
    for (int i = 0; i <= s.size() - words_size*word_len; ++i){
        cnt.clear();
        //cout<<i<<" "<<i+words_size*word_len-1<<endl;
        int j;
        for (j = i; j < i+words_size*word_len; j+=word_len){
            tmp = s.substr(j, word_len);
            if (dic[tmp]==0){
                break;
            }
            else {
                cnt[tmp]++;
                if (cnt[tmp] > dic[tmp]){
                    break;
                }
            }
        }
//        for (iter = cnt.begin(); iter!=cnt.end(); ++iter){
//            cout<<iter->first<<" "<<iter->second<<endl;
//        }
//        cout<<endl;
        if (j==i+word_len*words_size) res.push_back(i);
    }
//    for (int i = 0; i < res.size(); ++i){
//        cout<<res[i]<<" ";
//    }
    return res;
}



int main()
{
    string s;
    vector<string> words;
    //s="wordgoodgoodgoodbestword";
    cin>>s;
    words.push_back("bar");
    words.push_back("foo");
    //words.push_back("best");//same length;
    //words.push_back("good");//same length;
    findSubstring(s, words);
}
