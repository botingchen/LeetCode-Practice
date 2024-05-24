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
//iterative stack solution, T(n) = O(n), S(n) = O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        else{
            ListNode* tmp = head;
            stack<ListNode*> st;
            while(tmp!= NULL){
                st.push(tmp);
                tmp = tmp->next;
            }
            tmp = head;
            int size = st.size();
            ListNode* tmp2 = tmp->next;
            while(size>0){
                if(tmp == NULL || tmp->next == NULL) break;
                tmp2 = tmp->next;
                tmp->next = st.top();
                tmp->next->next = tmp2;
                st.pop();
                tmp = tmp->next->next;
                size = size - 2;
            }
            tmp->next = NULL;
            return;
        }
    }
};
//recursive solution, time complexity = O(n^2), space complextiy = O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        else{
            ListNode* tmp = head;
            while(tmp->next->next != NULL){
                tmp = tmp->next;
            }
            ListNode* tmp2 = head->next;
            head->next = tmp->next;
            head->next->next = tmp2;
            tmp->next = NULL;
            reorderList(head->next->next);
        }
    }
};