/*
Problem: 2. Add Two Numbers
Difficulty: Medium
Topic: Linked List

Approach:
- Traverse both linked lists simultaneously.
- Add corresponding digits along with the carry.
- Create a new node containing (sum % 10).
- Update carry as (sum / 10).
- Continue until both lists and carry are exhausted.
- Use a dummy node to simplify result list construction.

Time Complexity: O(max(n, m))
Auxiliary Space: O(1)
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};
