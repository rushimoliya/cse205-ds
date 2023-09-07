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
    int len(ListNode* head){
        int cnt=- 0;
        while(head !=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = len(head);
        int i = l-n+1;
        if(l == 1){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;

        if (i == 1){
            head = curr ->next;
            curr ->next = prev;
            delete curr;
            return head;
        }

        int cnt = 1;
        while(cnt < i){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // cout<< prev->val;
        // cout << curr ->val;

        
        prev -> next = curr ->next;
        curr->next = NULL;
        delete curr; 

        return head;
    }
};