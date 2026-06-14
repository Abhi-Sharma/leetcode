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
ListNode* reverse(ListNode* node){
    ListNode* prev = NULL;
    while(node != NULL){
        ListNode* nextnode = node->next;
        node->next = prev;
        prev = node;
        node = nextnode;
    }
    return prev;
}
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode* tail = head;
        while(tail != NULL){
            tail = tail->next;
            size++;
        }

        int n = size/2 - 1;
        tail = head;
        while(n){
            tail = tail->next;
            n--;
        }
        ListNode* newhead = reverse(tail->next);
        tail->next = NULL;

        int maxi = INT_MIN;
        while(head != NULL && newhead != NULL){
            int sum = head->val + newhead->val;
            maxi = max(maxi,sum);
            head = head->next;
            newhead = newhead->next;
        }
        return maxi;
    }
};