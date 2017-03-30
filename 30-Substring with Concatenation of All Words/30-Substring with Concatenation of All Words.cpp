#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> res;
    vector<string>::iterator iter;
    int len_s = s.size();
    int words_size = words.size();
    if (words_size == 0) return res;
    int word_len = words[0].size();
    if (word_len*words_size > len_s) return res;
    //cout<<len_s<<" "<<words_size<<" "<<word_len<<endl;
    vector<string> sub;
    for (int i = 0; i < len_s ; i = i+word_len){
        string tmp = s.substr(i,word_len);
        sub.push_back(tmp);
    }
//    for (int i = 0; i < sub.size(); ++i){
//        cout<<sub[i]<<" ";
//    }
//    cout<<endl;
    for (int i = 0; i <= sub.size()-words_size; i = i+1){
        vector<string> searc = words;
        int j;
        for (j = 0; j < words.size(); ++j){
            iter = find(searc.begin(), searc.end(), sub[i+j]);

            if (iter==searc.end())
                break;
            //cout<<sub[i+j]<<" "<<iter-searc.begin()<<endl;
            searc.erase(iter);

        }
        if (searc.empty() && j == words.size()) res.push_back(i*word_len);
        //cout<<endl;
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
    s="wordgoodgoodgoodbestword";
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");//same length;
    words.push_back("good");//same length;
    findSubstring(s, words);
}

//vector<string> tmp_words = words;
//        int j;
//        for (j = 0; j < words_size; ++j){
//            string tmp_str = s.substr(i+3*j,3);
//            iter = find(words.begin(), words.end(), tmp_str);
//            if (iter==words.end())
//                break;
//            //cout<<tmp_str<<" "<<iter-words.begin()<<endl;
//            if (flag[iter-words.begin()]==1)
//                break;
//            flag[iter-words.begin()] = 1;
//
//        }
//        if (j==words_size) res.push_back(i);
