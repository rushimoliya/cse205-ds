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

    ListNode* mid(ListNode* head) {
        //if(head == NULL || head->next == NULL) return head;
        ListNode* f = head->next;
        ListNode* s = head;

        while(f != NULL && f->next != NULL){
            f=f->next->next;
            s=s->next;
        }
        return s;
    }

    ListNode* mergeSortLL(ListNode* head){

        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* m = mid(head);

        ListNode* left = head;
        ListNode* right = m->next;
        m->next = NULL;

        // ListNode* l = mergeSortLL(left);        
        // ListNode* r = mergeSortLL(right);  
        
        left = mergeSortLL(left);        
        right = mergeSortLL(right);    

        ListNode* ans = mergeLinkList(left,right);
        return ans;

    }

    ListNode* mergeLinkList(ListNode* left,ListNode* right){

        if(left==NULL) return right;
        if(right==NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(left !=NULL && right!=NULL){
            if(left -> val <= right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while(left != NULL){
           temp->next = left;
            temp = left;
            left = left->next; 
        }
        while(right != NULL){
           temp->next = right;
            temp = right;
            right = right->next; 
        }

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {      
        return mergeSortLL(head); 
    }
};