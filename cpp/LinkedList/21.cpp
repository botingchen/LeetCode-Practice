//stupid solution
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        else{
            ListNode* ans;
            ListNode* tmp1;
            ListNode* tmp2;
            if(list1->val >= list2->val){
                ans = list2;
                tmp2 = list2->next;
                tmp1 = list1;
            }
            else{
                ans = list1;
                tmp1 = list1->next;
                tmp2 = list2;
            }
            while(tmp1!= NULL && tmp2!= NULL){
                if(tmp1->val >= tmp2->val){
                    ans->next = tmp2;
                    tmp2 = tmp2->next;
                }
                else{
                    ans->next = tmp1;
                    tmp1 = tmp1->next;
                }
                ans = ans->next;
            }
            if(tmp1 == NULL) ans->next= tmp2;
            else ans->next = tmp1;
        }
        if(list1->val >= list2->val) return list2;
        return list1;
    }
};

//Iterative Solution
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        else{
            if(list1->val >= list2->val){
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
            else{
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
        }
    }
};