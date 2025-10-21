class LRUCache {
    public:
    class node{
        public:
        int key;
        int value;
        node* next;
        node* prev;
        node(int key, int value){
            this->key = key;
            this->value = value;
            next = prev = nullptr;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    unordered_map<int, node*> mpp;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(node* delnode){
        node* prevnode = delnode->prev;
        node* nextnode = delnode->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    void insertAfterHead(node* newnode){
        node* nextnode = head->next;
        head->next = newnode;
        newnode->prev = head;
        nextnode->prev = newnode;
        newnode->next = nextnode;
    }
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            node* node = mpp[key];
            deleteNode(node);
            insertAfterHead(node);

            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size() == cap){
                node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            node* newnode = new node(key,value);
            mpp[key] = newnode;
            insertAfterHead(newnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */