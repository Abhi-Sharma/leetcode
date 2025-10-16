/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        temp = head;
        while(temp != NULL){
            Node* copyNode = temp->next;
            if(temp->random) copyNode->random = temp->random->next;
            else copyNode->random = temp->random;

            temp = temp->next->next;
        }
        temp = head;
        Node* dnode = new Node(-1);
        Node* res = dnode;
        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res= res->next;
            temp = temp->next;
        }
        return dnode->next;
    }
};