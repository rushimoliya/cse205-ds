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

    ListNode * reverse(ListNode * ptr, int &k, int size)
    {
        if(size < k) return ptr;
        if(ptr == NULL) return ptr;

        ListNode * cur = ptr, *temp = NULL, *pre = NULL;
        int cnt = 0;
        while(cur!=NULL && cnt < k)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            cnt++;
        }

        ptr->next = reverse(temp,k,size-k);
        return pre;
    }

    int len(ListNode * ptr)
    {
        int len = 0;
        while(ptr)
        {
            len++;
            ptr = ptr->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = len(head);
        return reverse(head,k,n);
    }
};