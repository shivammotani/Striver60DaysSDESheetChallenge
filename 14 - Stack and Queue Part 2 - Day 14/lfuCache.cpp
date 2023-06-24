#include <bits/stdc++.h> 

class Node{
    public:
        int key;
        int val;
        int cnt;
        Node* next;
        Node* prev;

        Node(int keys, int vals){
            key = keys;
            val = vals;
            cnt = 1;
        }

    };

class List{
    public:
        int size;
        Node* head;
        Node* tail;
        List(){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addNode(Node* nd){
            nd->next = head->next;
            nd->prev = head;
            head->next->prev = nd;
            head->next = nd;
            size++;
        }
        void deleteNode(Node* nd){
            Node *delnext = nd->next;
            Node *delprev = nd->prev;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
};

class LFUCache
{
public:
    int cap;
    int freq;
    int cur_size;
    unordered_map<int, Node*> keyNode_mp;
    unordered_map<int, List*> freq_mp;

    LFUCache(int capacity)
    {
        // Write your code here.
        cap = capacity;
        freq = 0;
        cur_size = 0;
    }

    void updateFreqMap(Node* node){
        keyNode_mp.erase(node->key);
        freq_mp[node->cnt]->deleteNode(node);
        if(node->cnt == freq && freq_mp[node->cnt]->size == 0) {
            freq++; 
        }
        List* newHigherFreqList = new List();
        if(freq_mp.find(node->cnt+1) != freq_mp.end()){
            newHigherFreqList = freq_mp[node->cnt+1];
        }
        node->cnt += 1; 
        newHigherFreqList->addNode(node); 
        freq_mp[node->cnt] = newHigherFreqList; 
        keyNode_mp[node->key] = node;

    }
    
    int get(int key)
    {
        // Write your code here.
            if(keyNode_mp.find(key) != keyNode_mp.end()){
            Node *res = keyNode_mp[key];
            int ans = res->val;
            updateFreqMap(res);
            return ans;
        }
        return -1;
    }

    void put(int key, int val)
    {
        // Write your code here.
        if(cap == 0) return;

        if(keyNode_mp.find(key) != keyNode_mp.end()){
            Node *res = keyNode_mp[key];
            res->val = val;
            updateFreqMap(res);
        }
        else{
            if(cur_size == cap){
                List* List = freq_mp[freq]; 
                keyNode_mp.erase(List->tail->prev->key); 
                freq_mp[freq]->deleteNode(List->tail->prev);
                cur_size--; 
            }
            cur_size++;
            freq = 1; 
            List* ListFreq = new List(); 
            if(freq_mp.find(freq) != freq_mp.end()) {
                ListFreq = freq_mp[freq]; 
            }
            Node* node = new Node(key, val); 
            ListFreq->addNode(node);
            keyNode_mp[key] = node; 
            freq_mp[freq] = ListFreq; 

        }
    }
};
