#include<iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* swapPairs(ListNode* head)
{
    //introduce a null new head
    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    ListNode *tmp1;
    ListNode *tmp2;
    ListNode *cur = new_head;
    while (cur){
        if (!(cur->next)) break;
        if (!(cur->next->next)) break;
        tmp1 = cur->next;
        cur->next = tmp1->next;
        tmp2 = cur->next->next;
        cur->next->next = tmp1;
        cur->next->next->next = tmp2;
        cur = cur->next->next;
    }
//    ListNode *tmp = new_head;
//    while (tmp){
//        cout<<tmp->val<<" ";
//        tmp = tmp->next;
//    }
    return new_head->next;
}

int main()
{
    int n;
    int tmp;
    cin>>n;
    cin>>tmp;
    ListNode *head = new ListNode(tmp);
    ListNode *tem = head;
    for (int i = 1; i < n; ++i){
        cin>>tmp;
        tem->next = new ListNode(tmp);
        tem = tem->next;
    }
    swapPairs(head);
}
