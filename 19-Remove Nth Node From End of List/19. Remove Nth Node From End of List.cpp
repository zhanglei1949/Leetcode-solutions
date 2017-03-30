#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *tem = new ListNode(0);
    tem = head;
    int cnt = 0;
    while (tem){
        cnt++;
        //cout<<tem->val<<" ";
        tem = tem->next;
    }
    tem = head;
    if (cnt==n) return head->next;
    while (tem){
        if (cnt==n+1){
            tem->next = tem->next->next;
            //delete and break;
            break;
        }
        cnt--;
        tem = tem->next;
    }
    return head;
}
int main()
{
    int n;
    int tmp;
    cin>>n;
    cin>>tmp;
    ListNode* head = new ListNode(tmp);
    ListNode* tem = new ListNode(tmp);
    tem = head;
    for (int i = 1; i < n; ++i){
        cin>>tmp;
        ListNode* new_ = new ListNode(tmp);
        tem->next = new_;
        tem = tem->next;
    }
    int nth;
    cin>>nth;
    ListNode *res = removeNthFromEnd(head,nth);
    while (res){
        cout<<res->val<<" ";
        res = res->next;
    }
}
