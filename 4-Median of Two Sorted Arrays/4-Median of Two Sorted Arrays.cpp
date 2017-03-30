#include<iostream>
#include<vector>
using namespace std;

double findKthElementSortedArray(vector<int>& nums1, int s1, int e1, int m,
                                 vector<int>& nums2, int s2, int e2, int n, int k)
{
    //cout<<"s1: "<<s1<<" e1: "<<e1<<" m: "<<m<<" s2: "<<s2<<" e2: "<<e2<<" n: "<<n<<" k: "<<k<<endl;
    if (m > n)
        return findKthElementSortedArray(nums2, s2, e2, n, nums1, s1, e1, m, k);
    if (m == 0)
        return nums2[s2 + k - 1];
    if (k==1)
        return min(nums1[s1], nums2[s2]);

    int pa = min(k/2, m);
    int pb = k - pa;

    if (nums1[s1+pa-1] < nums2[s2+pb-1]){
        return findKthElementSortedArray(nums1, s1+pa, e1, m - pa,
                                         nums2, s2, e2, n, k-pa);
    }
    else if (nums1[s1+pa-1] > nums2[s2+pb-1]){
        return findKthElementSortedArray(nums1, s1, e1, m,
                                         nums2, s2+pb, e2, n - pb, k - pb);
    }
    else return nums1[s1+pa-1];
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    if ((len1+len2) % 2 ==1)
        return findKthElementSortedArray(nums1, 0, len1-1, len1,
                                         nums2, 0, len2 - 1, len2,
                                          (len1+len2+1)/2);
    else{
        cout<<findKthElementSortedArray(nums1, 0, len1-1, len1,
                                         nums2, 0, len2 - 1, len2,
                                         (len1+len2)/2)
                 <<" "<<findKthElementSortedArray(nums1, 0, len1-1, len1,
                                             nums2, 0, len2 - 1, len2,
                                             (len1+len2)/2+1)<<endl;
        return (
                 findKthElementSortedArray(nums1, 0, len1-1, len1,
                                         nums2, 0, len2 - 1, len2,
                                         (len1+len2)/2)
                 + findKthElementSortedArray(nums1, 0, len1-1, len1,
                                             nums2, 0, len2 - 1, len2,
                                             (len1+len2)/2+1)
                 ) / 2;
    }
}
int main()
{
    vector<int> nums1, nums2;
    int len1;
    cin>>len1;
    int len2;
    cin>>len2;
    int tmp;
    for (int i = 0; i < len1; ++i){
        cin>>tmp;
        nums1.push_back(tmp);
    }
    for (int i = 0; i < len2; ++i){
        cin>>tmp;
        nums2.push_back(tmp);
    }
    cout<<findMedianSortedArrays(nums1, nums2);
    cout<<endl;
    for (int i = 1; i <= nums1.size()+nums2.size(); ++i){
        cout<<findKthElementSortedArray(nums1,0,len1-1, len1, nums2, 0, len2-1, len2, i)<<endl;
    }

}
