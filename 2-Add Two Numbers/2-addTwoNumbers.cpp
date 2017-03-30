#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *res, *p1, *p2, *tmp;
    p1 = l1; p2 = l2;
    res = NULL;
    tmp = NULL;
    int tmpnum;
    int carry = 0;
    while (p1!=NULL && p2!=NULL){
        tmpnum = p1->val + p2->val + carry;
        if (tmpnum>=10){
            carry = 1;
            tmpnum = tmpnum - 10;
        }
        else carry = 0;
        //tmpnum = tmpnum - carry;
        //cout<<tmpnum<<" "<<carry<<endl;
        if (tmp == NULL){
            tmp = new ListNode(tmpnum);
            res = tmp;
        }
        else {
            tmp -> next = new ListNode(tmpnum);
            tmp = tmp->next;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1!=NULL){
        tmp->next = new ListNode((p1->val+carry)%10);
        carry = (p1->val+carry)/10;
        tmp = tmp->next;
        p1 = p1->next;

    }
    while (p2!=NULL){
        tmp->next = new ListNode((p2->val+carry)%10);
        carry = (p2->val+carry)/10;
        tmp = tmp->next;
        p2 = p2->next;
    }
    if (carry!=0){
        tmp -> next = new ListNode(carry);
    }
    tmp = res;
    while (tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    return res;
}
int main()
{
    ListNode *head1 = new ListNode(1);
    ListNode *head2 = new ListNode(9);
    ListNode *tmp;
    tmp = new ListNode(9);
    head2->next = tmp;



//    tmp = new ListNode(6);
//    head2->next = tmp;
//    tmp = new ListNode(4);
//    head2->next->next = tmp;
//    tmp = new ListNode(4);
//    head2->next->next->next = tmp;
    addTwoNumbers(head1, head2);

}

