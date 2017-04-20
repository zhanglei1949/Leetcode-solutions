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
int search_interval(vector<Interval>& intervals, Interval newInterval)
{
    //return the index of the first interval that has larger end than the start of newInterval
    int target = newInterval.start;
    int current_ind = 0;
    if (newInterval.start < intervals[0].start) return -2;
    while (current_ind < intervals.size() && target > intervals[current_ind].end){
        //cout<<current_ind<<" "<<target<<" "<<intervals[current_ind].end<<endl;
        current_ind++;
    }
    if (current_ind == intervals.size()) return -1;
    return current_ind;

}
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    //binary search
    vector<Interval> res;
    if (intervals.size()==0){
        res.push_back(newInterval);
        return res;
    }
    int index = search_interval(intervals, newInterval);
    //cout<<"index: "<<index<<endl;
    if (index == -1){
        for (int i = 0; i < intervals.size(); ++i){
            res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        return res;
    }
    if (index == -2){
        int index2 = 0;
        Interval current(newInterval.start,newInterval.end);
        while (index2 <intervals.size() && intervals[index2].start <= current.end){
                current.end = intervals[index2].end;
                index2++;
        }
        if (index2==intervals.size()) res.push_back(current);
        else {
            res.push_back(current);
            for (int i = index2; i < intervals.size(); ++i){
                if (intervals[i].end <= newInterval.end) continue;
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
    for (int i = 0; i < index; ++i){
        res.push_back(intervals[i]);
    }
    Interval tmp(intervals[index].start,intervals[index].end);
    while (index < intervals.size() && intervals[index].end <= newInterval.end){
        index++;
    }
    //cout<<"index: "<<index<<endl;
    //now index.end > newInterval.end
    if (index==intervals.size()){
        tmp.end = newInterval.end;
        res.push_back(tmp);
    }
    else {
        tmp.end = intervals[index].end;
        res.push_back(tmp);
        for (int i = index; i < intervals.size(); ++i){
            res.push_back(intervals[i]);
        }
    }
    return res;
}
int main()
{
    vector<Interval> intervals;
    Interval i(1,5);
    intervals.push_back(i);
    Interval j(9,10);
    intervals.push_back(j);
    Interval newInterval(0,3);
    vector<Interval> res = insert(intervals, newInterval);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
}
