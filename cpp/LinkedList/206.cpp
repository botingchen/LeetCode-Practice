/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev_node = nullptr;

        while(head){
            ListNode* next_node = head->next;
            head->next = prev_node;
            prev_node = head;
            head = next_node;
        }
        return prev_node;
    }
};

//Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};