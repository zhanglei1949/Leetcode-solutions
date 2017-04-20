#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s, int e):start(s),end(e){}
};
bool cmp(const Interval i1, const Interval i2)
{
    return i1.start < i2.start;
}
vector<Interval> merge(vector<Interval>& intervals)
{
    vector<Interval> res;
    if (intervals.size()<=1) return intervals;
    sort(intervals.begin(),intervals.end(),cmp);
    int current = 0;
    int expand = 1;
    while (current < intervals.size()){
        //cout<<"current: "<<current<<" expand: "<<expand<<endl;
        while (expand < intervals.size() && intervals[expand].start <= intervals[current].end){
            intervals[current].end = max(intervals[current].end, intervals[expand].end);
            expand++;
        }
        res.push_back(intervals[current]);
        //res.push_back(Interval(intervals[current].start,max(intervals[expand-1].end, intervals[current].end)));
        if (expand==intervals.size()){
            break;
        }
        else {
            current = expand;
        }
    }
    return res;
}
int main()
{
    vector<Interval> intervals;
    Interval i(1,3);
    intervals.push_back(i);
    i.start = 2;
    i.end = 6;
    intervals.push_back(i);
    i.start = 8;
    i.end = 10;
    intervals.push_back(i);
    i.start = 15;
    i.end = 18;
    intervals.push_back(i);
    i.start = 16;
    i.end = 17;
    intervals.push_back(i);
    i.start = 15;
    i.end = 19;
    intervals.push_back(i);
    vector<Interval> res = merge(intervals);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
}
