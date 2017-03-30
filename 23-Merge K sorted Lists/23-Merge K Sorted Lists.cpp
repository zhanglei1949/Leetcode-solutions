#include<iostream>
#include<vector>
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
ListNode* mergeKLists(vector<ListNode *> &lists){
    //suppose increasing order.
    //merge without using new space
    ListNode *tmp;
    int len = lists.size();
    if (len==0) return NULL;
    tmp = lists[0];
    for (int i = 1; i < lists.size(); ++i){
        tmp = mergeTwoLists(tmp, lists[i]);
    }
    return tmp;
}

int main()
{
    int n;
    int m;
    int tmp;
    cin>>n;
    vector<ListNode *> lists;
    for (int i = 0; i < n; ++i){
        cin>>m;
        cin>>tmp;
        ListNode *head = new ListNode(tmp);
        ListNode *tem = head;
        for (int j = 1; j < m; ++j){
            cin>>tmp;
            tem->next = new ListNode(tmp);
            tem = tem->next;
        }
        lists.push_back(head);
    }
    ListNode *res = mergeKLists(lists);
    while (res){
        cout<<res->val<<" ";
        res = res->next;
    }
}
