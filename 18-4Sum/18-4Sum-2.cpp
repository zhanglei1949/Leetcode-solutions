#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair <int, int> index;
typedef pair <index, int> item;
//pair<pair<int, int> int>
bool cmp(const pair<pair<int, int>, int> &x, const pair<pair<int, int>, int> &y)
{
    return x.second < y.second;
}
vector<vector<int> > fourSum(vector<int>& nums, int target)
{
    vector<vector<int> > res;
    vector<vector<int> >::iterator int_iter;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if (len < 4) return res;
    for (int i = 0; i < len; ++i){
        //cout<<nums[i]<<" ";
    }
    //cout<<endl;
    //build up map;
    map<pair <int, int>, int> m;
    vector<pair<pair<int, int>, int> > item_vec;
    vector<pair<pair<int, int>, int> >::iterator item_iter;
    for (int i = 0; i < len; ++i){
        for (int j = i+1; j < len; ++j){
            item_vec.push_back(make_pair(make_pair(nums[i],nums[j]), nums[i]+nums[j]));
            //cout<<"push: "<<nums[i]<<" "<<nums[j]<<" "<<nums[i]+nums[j]<<endl;
        }
    }
    //cout<<endl;
    //sort
    sort(item_vec.begin(),item_vec.end(), cmp);

    for (item_iter = item_vec.begin(); item_iter != item_vec.end(); ++item_iter){
        m[item_iter->first] = item_iter->second;
        cout<<item_iter->first.first<<" "<<item_iter->first.second<<" "<<item_iter->second<<endl;
    }
    map<pair <int, int>, int>::iterator head = m.begin();
    map<pair <int, int>, int>::iterator tem = m.begin();
    map<pair <int, int>, int>::iterator rear = m.end();
    rear--;
    while (rear != head){
        cout<<"try: "<<head->second<<" "<<rear->second<<endl;
        tem = head;
        if (--tem == rear) break;
        if (head->second+rear->second == target){
            vector<int> tmp;
            tmp.push_back(head->first.first);
            tmp.push_back(head->first.second);
            tmp.push_back(rear->first.first);
            tmp.push_back(rear->first.second);
            sort(tmp.begin(),tmp.end());
            int i;
            for (i = 0; i < res.size(); ++i){
                if (res[i][0]==tmp[0] && res[i][1]==tmp[1] && res[i][2]==tmp[2] && res[i][3]==tmp[3]){
                    break;
                }
            }
            if (i==res.size())
                res.push_back(tmp);
            else {
                rear--;
                head++;
                continue;
            }
            cout<<"push: "<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<" "<<tmp[3]<<" "<<endl;
        }
        else if (head->second + rear->second > target)
            rear--;
        else head++;
    }
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return res;

}
int main()
{
    int n;
    int target;
    vector<int> nums;
    cin>>n>>target;
    int tmp;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }
    fourSum(nums, target);
//    map<index, int> map1;
//    for (int i = 0; i < 3; ++i){
//        index ind(i,i+1);
//        map1[ind]=10-i;
//    }
//    map<index , int>::iterator iter;
//    for (iter=map1.begin(); iter!=map1.end(); ++iter){
//        cout<<iter->first.first<<" "<<iter->first.second<<" "<<iter->second<<endl;
//    }
//    vector<item> item_vec;
//    for (iter = map1.begin(); iter != map1.end(); ++iter){
//        item_vec.push_back(make_pair(iter->first, iter->second));
//    }
//    sort(item_vec.begin(), item_vec.end(), cmp);
//    for (vector<item>::iterator i = item_vec.begin(); i != item_vec.end(); ++i){
//        cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
//    }
}
