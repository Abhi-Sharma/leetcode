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
    ListNode* reverseLL(ListNode* temp)
{
    ListNode* prev = NULL;

    while(temp != NULL){
        ListNode* nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}

ListNode* findKthNode(ListNode* temp, int k){
    int cnt = 1;

    while(temp != NULL && cnt < k){
        temp = temp->next;
        cnt++;
    }
    return temp;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* kthnode = findKthNode(temp,k);
            if(kthnode == NULL){
                if(prev) prev->next = temp;
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;
            reverseLL(temp);
            if(temp == head) head = kthnode;
            else prev->next = kthnode;
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};