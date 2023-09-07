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
    bool isPalindrome(ListNode* head) {
        ListNode * tempf = head;
        ListNode * mid = head;
        while(tempf !=NULL && tempf->next!= NULL){
            mid = mid->next;
            tempf = tempf->next->next;
        }
        ListNode * prev = NULL;
        ListNode * curr = mid;
        ListNode * next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        mid = prev;
        while(mid != NULL){
            if(head->val != mid->val){
                
                return false;
            }
            mid = mid->next;
            head = head->next;
        }
        return true;

    }
};