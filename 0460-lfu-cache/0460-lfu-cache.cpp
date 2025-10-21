#include <bits/stdc++.h>
using namespace std;

struct node {
    int key, value, cnt;
    node *next;
    node *prev;
    node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = prev = nullptr;
    }
};

struct List {
    int size;
    node *head;
    node *tail;
    
    List() {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(node *newNode) {
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
    
    void removeNode(node *delNode) {
        node* prevNode = delNode->prev;
        node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
    map<int, node*> keyNode;
    map<int, List*> freqList;
    int maxSize;
    int currSize;
    int minFreq;

public:
    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreqList(node *currNode) {
        int freq = currNode->cnt;
        freqList[freq]->removeNode(currNode);

        if (freq == minFreq && freqList[freq]->size == 0) {
            minFreq++;
        }

        currNode->cnt++;
        List *higherList;
        if (freqList.find(currNode->cnt) != freqList.end()) {
            higherList = freqList[currNode->cnt];
        } else {
            higherList = new List();
            freqList[currNode->cnt] = higherList;
        }

        higherList->addFront(currNode);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        node *currNode = keyNode[key];
        int val = currNode->value;
        updateFreqList(currNode);
        return val;
    }

    void put(int key, int value) {
        if (maxSize == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            node *existingNode = keyNode[key];
            existingNode->value = value;
            updateFreqList(existingNode);
        } else {
            if (currSize == maxSize) {
                List *list = freqList[minFreq];
                node *delNode = list->tail->prev;
                keyNode.erase(delNode->key);
                list->removeNode(delNode);
                currSize--;
            }

            currSize++;
            minFreq = 1;
            List *listFreq;
            if (freqList.find(minFreq) != freqList.end()) {
                listFreq = freqList[minFreq];
            } else {
                listFreq = new List();
                freqList[minFreq] = listFreq;
            }

            node *newNode = new node(key, value);
            listFreq->addFront(newNode);
            keyNode[key] = newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
