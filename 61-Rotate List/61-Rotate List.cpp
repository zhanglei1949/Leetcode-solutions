#include<iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k)
{
    if (!head) return head;
    //1->2->3->4->5->NULL
    //4->5->1->2->3->NULL
    ListNode* fast;
    ListNode* slow;
    slow = head;
    fast = head;
    int length = 0;
    // first get the length
    ListNode * tmp = head;
    while (tmp){
        tmp = tmp->next;
        length++;
    }
    k = k%length;
    for (int i = 0; i < k; ++i){
        fast = fast->next;
    }
    while (fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    //cout<<fast->val<<" "<<slow->val<<endl;

    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}

int main()
{
    ListNode * head = new ListNode(1);
    ListNode *tmp = head;
    for (int i = 2; i < 6; ++i){
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    ListNode *res = rotateRight(head, 4);
    while (res){
        cout<<res->val<<" ";
        res = res->next;
    }
}
