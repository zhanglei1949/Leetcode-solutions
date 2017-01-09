#include<iostream>
#include<stack>
using namespace std;

int *selectMaximum(int *arr, int len, int k)
{
    //select top k digits
    stack<int> s;
    int drop = len - k;//have to drop these digits
    for (int i = 0; i < len; ++i){
        while (drop > 0 && !s.empty() && s.top() < arr[i]){// drop 指明是不是有条件pop，
            s.pop();
            --drop;
        }
        s.push(arr[i]);
    }
    int *res = new int [k];
    int i = k-1;
    while (drop>0){
        s.pop();
        drop--;
    }
    while (!s.empty()){
        res[i--] = s.top();
        s.pop();
    }
    return res;
}
int *max_return_pointer(int *arr1, int *arr2,int k)
{
    //length both k;
    if (arr2==NULL) return arr1;
    bool flag = 1;
    for (int i = 0; i < k; ++i){
        if (arr1[i]>arr2[i]){
            return arr1;
        }
        else if (arr1[i] < arr2[i]){
            return arr2;
        }
    }
    return arr2;

}
int *mergeMaximum(int *arr1, int len1, int *arr2, int len2)
{
    int *res = new int [len1+len2];
    int index_1,index_2;
    index_1 = 0;
    index_2 = 0;
    int cur = 0;
    while (index_1 < len1 || index_2 < len2){
        //cout<<index_1<<" "<<index_2<<endl;
        if (index_1 == len1){
            res[cur++] = arr2[index_2++];
            continue;
        }
        else if (index_2 == len2){
            res[cur++] = arr1[index_1++];
            continue;
        }
        else if (arr1[index_1] > arr2[index_2]){
            res[cur++] = arr1[index_1++];
        }
        else if (arr1[index_1] < arr2[index_2]){
            res[cur++] = arr2[index_2++];
        }
        else {
            //数字相同的时候看后面谁大

            int tmp = 1;
            bool flag = 0;
            while (index_1 + tmp < len1 && index_2 + tmp < len2){
                cout<<"loop"<<endl;
                if (arr1[index_1+tmp]==arr2[index_2+tmp]){
                    tmp++;
                    continue;
                }
                else if (arr1[index_1+tmp] > arr2[index_2+tmp]){
                    res[cur++] = arr1[index_1++];
                    flag = 1;
                    break;
                }
                else {
                    res[cur++] = arr2[index_2++];
                    flag = 1;
                    break;
                }
            }
            if (flag==0){
                if (index_1+tmp < len1){
                    res[cur++] = arr1[index_1++];
                }
                else {
                    res[cur++] = arr2[index_2++];
                }
            }

        }
    }
    return res;
}
int *maximumNumber(int *nums1, int *nums2, int m, int n, int k)
{
    //nums1[]->length m
    //nums2[]->length n
    //既然总共k个元素，那么就有k种方案：0+k，1+k-1....
    //分别求出两个数组的最大k个数字，然后merge
    //借助函数select_maximum来挑出k个最大数字，然后merge

    int start_index_nums1 = max(0,k - n);
    int *res;
    res = NULL;
    for (int i = start_index_nums1; i <= min(k,m); ++i){
        res = max_return_pointer(mergeMaximum(selectMaximum(nums1,m,i),i, selectMaximum(nums2,n,k-i), k-i), res, k);
        //merge: select_max(nums1,i), select_max(nums2,k-i);
    }
    return res;
}
int main()
{
    int n,m,k;
    int *nums1,*nums2;
    cout<<"The length of nums1[]: ";
    cin>>m;
    cout<<"The length of nums2[]: ";
    cin>>n;
    nums1 = new int [m];
    nums2 = new int [n];
    cout<<"Enter the elements of nums1[]: "<<endl;
    for (int i = 0; i < m; ++i){
        cin>>nums1[i];
    }
    cout<<"Enter the elements of nums1[]: "<<endl;
    for (int i = 0; i < n; ++i){
        cin>>nums2[i];
    }
    cout<<"Enter k: ";
    cin>>k;
    int *res;
    res = maximumNumber(nums1,nums2,m,n,k);
    for (int i = 0; i < k; ++i){
        cout<<res[i]<<" ";
    }
    //maximumNumber(nums1,nums2,m,n,k);

}
