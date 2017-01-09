#include<iostream>
#include<iomanip>
using namespace std;

int a[100] = {0};
int b[100] = {0};
int median = 0;
double find_median(int left_a, int right_a, int left_b, int right_b, int k);
int main()
{
    double res = 0;
    int len_a,len_b;
    cin>>len_a;
    for (int i = 0; i < len_a; ++i){
        cin>>a[i];
    }
    cin>>len_b;
    for (int i = 0; i < len_b; ++i){
        cin>>b[i];
    }
    if (len_a!=0 && len_b!=0){
        median = (len_a + len_b)/2;
        if ((len_a+len_b)%2==0){
            res = double(find_median(0,len_a-1,0, len_b-1, median)+
                        find_median(0,len_a-1,0, len_b-1, median+1))/2;
        }
        else {
            res = find_median(0,len_a-1,0, len_b-1, median+1);
        }
    }
    else if (len_a==0 && len_b==0){
        cerr<<"invalid input"<<endl;
        return 0;
    }
    else if (len_a==0){
        if (len_b%2==0){
            res = double(b[len_b/2] + b[len_b/2-1])/2;
        }
        else res = b[len_b/2];
    }
    else {
        if (len_a%2==0){
            res = double(a[len_a/2] + a[len_a/2-1])/2;
        }
        else res = a[len_a/2];
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<res<<endl;
    return 1;
}
double find_median(int left_a, int right_a, int left_b, int right_b, int k)
{
    //cout<<left_a<<" "<<right_a<<" "<<left_b<<" "<<right_b<<" "<<k<<endl;
    if (left_a > right_a){
        return b[left_b+k-1];
    }
    if (left_b > right_b){
        return a[left_a+k-1];
    }
    double res = 0;

    int mid_a = (left_a + right_a)/2;
    int mid_b = (left_b + right_b)/2;
    int tmp = mid_a - left_a +mid_b - left_b +1 ;
    //int mid_ab = (len_a+len_b)/2;
    if (a[mid_a] <= b[mid_b]){
        //mid_ab <= mid_a+mid_b+1)
        if (k <= tmp){
            return find_median(left_a, right_a, left_b, mid_b-1,k);
        }
        else {
            return find_median(mid_a+1, right_a, left_b, right_b, k-(mid_a - left_a + 1));
        }
    }
    else {
        if (k <= tmp){
            return find_median(left_a, mid_a - 1, left_b, right_b,k);
        }
        else {
            return find_median(left_a, right_a, mid_b+1, right_b, k-(mid_b - left_b + 1));
        }
    }
}
