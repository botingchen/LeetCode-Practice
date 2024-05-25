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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next==NULL) return NULL;
        ListNode* result = new ListNode(0, head);
        ListNode* ptr2 = result;
        for(int i = 0;i < n; i++){
            head = head->next;
        }
        while(head!= NULL){
            ptr2 = ptr2->next;
            head = head->next;
        }
        // cout << head->val;
        ptr2->next = ptr2->next->next;
        return result->next;
    }
};