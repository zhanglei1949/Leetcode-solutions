#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //suppose increasing order.
    //merge without using new space
    ListNode *head;
    if (l1==NULL) return l2;
    if (l2==NULL) return l1;

    if (l1->val < l2->val){
        head = l1;
        l1 = l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    ListNode *tmp = head;
    while (l1 && l2){
        if (l1->val < l2->val){
            tmp->next = l1;
            tmp = tmp->next;
            l1 = l1->next;
        }
        else {
            tmp->next = l2;
            tmp = tmp->next;
            l2 = l2->next;
        }
    }
    while (l1){
        tmp->next = l1;
        tmp = tmp->next;
        l1 = l1->next;
    }
    while (l2){
        tmp->next = l2;
        tmp = tmp->next;
        l2 = l2->next;
    }
    return head;
}

int main()
{
    int n;
    int tmp;
    cin>>n;
    cin>>tmp;
    ListNode* l1 = new ListNode(tmp);
    ListNode* tem;
    tem = l1;
    for (int i = 1; i < n; ++i){
        cin>>tmp;
        ListNode* new_ = new ListNode(tmp);
        tem->next = new_;
        tem = tem->next;
    }
    int m;
    cin>>m;
    cin>>tmp;
    ListNode* l2 = new ListNode(tmp);
    tem = l2;
    for (int i = 1; i < m; ++i){
        cin>>tmp;
        ListNode* new_ = new ListNode(tmp);
        tem->next = new_;
        tem = tem->next;
    }
    ListNode *res = mergeTwoLists(l1, l2);
    while (res){
        cout<<res->val<<" ";
        res = res->next;
    }
}
