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

    ListNode* findm(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* merge2sorted(ListNode* head1,ListNode* head2){
        ListNode* sorted = new ListNode(-1);
        ListNode* curr = sorted;

        ListNode* t1 = head1;
        ListNode* t2 = head2;

        while(t1 != NULL && t2 != NULL){
            if(t1->val <= t2->val){
                curr->next = t1;
                t1 = t1->next;
            }
            else{
                curr->next = t2;
                t2 = t2->next;
            }
            curr = curr->next;
        }

        if(t1) curr->next = t1;
        if(t2) curr->next =t2;

        return sorted->next;
    }
    ListNode* mgs(ListNode* head){
        if(head==NULL || head->next == NULL) return head;

        ListNode* mid = findm(head);
        ListNode* lh = head;
        ListNode* rh = mid->next;

        mid->next = NULL;
        lh = mgs(lh);
        rh = mgs(rh);
        return merge2sorted(lh,rh);
    }
    ListNode* sortList(ListNode* head) {
        return mgs(head);
    }
};