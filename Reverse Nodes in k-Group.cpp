/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p=head;
        ListNode* next=nullptr;
        ListNode* prev=nullptr;
        int count=0;
        while(p&&count<k)
        {
            next=p->next;
            p->next=prev;
            prev=p;
            p=next;
            count++;
        }
        ListNode* check=next;
        int cnt=0;
        while(check)
        {
            check=check->next;
            cnt++;
        }
        if(next!=nullptr&&cnt-k>=0)
            head->next=reverseKGroup(next,k);
        else
        {
            head->next=next;
        }
        return prev;
    }

};
