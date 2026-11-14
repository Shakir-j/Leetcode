#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {

    int capacity;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        auto it = mpp.find(key);

        if (it == mpp.end()) return -1;

        Node* node = it->second;

        removeNode(node);
        insertAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {

        auto it = mpp.find(key);

        // Key already exists
        if (it != mpp.end()) {

            Node* node = it->second;
            node->val = value;

            removeNode(node);
            insertAfterHead(node);

            return;
        }

        // Cache is full
        if (mpp.size() == capacity) {

            Node* node = tail->prev;

            mpp.erase(node->key);
            removeNode(node);

            delete node;
        }

        // Insert new node
        Node* node = new Node(key, value);

        mpp[key] = node;
        insertAfterHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */