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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* dnode = new ListNode(-1);
        ListNode* small = dummyNode;
        ListNode* large = dnode;
        ListNode* curr = head;
        
        while(curr != NULL){
            ListNode* next = curr->next;
            if(curr->val < x){
                small->next = curr;
                small = curr;
            }
            else{
                large->next = curr;
                large = curr;
            }
            curr->next = NULL;
            curr = next;
        }
        large->next = NULL;
        small->next = dnode->next;
        return dummyNode->next;
    }
};