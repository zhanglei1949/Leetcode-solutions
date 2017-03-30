#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseKGroup(ListNode* head, int k)
{
    if (k < 2) return head;
    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    ListNode *cur = new_head;
    ListNode *tmp = cur;
    ListNode *tmp2 = cur;
    while (cur){
        int t = k;
        tmp = cur;
        while (t > 0){
            t--;
            tmp = tmp->next;
            if (!tmp) return new_head->next;
        }
        for (int i = 0; i < k-1; ++i){
            //move cur->next to the end
            tmp = cur->next;
            cur->next = cur->next->next;
            tmp2 = cur;
            int cnt = k-1-i;
            while (cnt > 0){
                tmp2 = tmp2->next;
                cnt--;
            }
            tmp->next = tmp2->next;
            tmp2->next = tmp;
        }
        t = k;
        while (t > 0){
            t--;
            cur = cur->next;
        }
    }
    return new_head->next;//actually never invoked.
}
int main()
{
    int n;
    int tmp;
    int k;
    cin>>n;
    cin>>k;
    cin>>tmp;
    ListNode *head = new ListNode(tmp);
    ListNode *tem = head;
    for (int i = 1; i < n; ++i){
        cin>>tmp;
        tem->next = new ListNode(tmp);
        tem = tem->next;
    }
    ListNode *temp = reverseKGroup(head,k);
    while (temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
