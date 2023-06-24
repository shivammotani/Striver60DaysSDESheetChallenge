 #include <bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
        int key;
        int val;
        Node* nxt;
        Node* prv;
        Node(int k, int v){
            key = k;
            val = v;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> mp;
    int cap;

    void deleteNode(Node* delNode){
        Node* p = delNode->prv;
        Node* n = delNode->nxt;
        p->nxt = n;
        n->prv = p;
    }

    void addNode(Node* newNode){
        Node* temp = head->nxt;
        head->nxt = newNode;
        newNode->nxt = temp;
        newNode->prv = head;
        temp->prv = newNode;
    }



    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->nxt = tail;
        tail->prv = head;
    }

    int get(int key)
    {
        // Write your code here
        auto it = mp.find(key);
        if(it != mp.end()){
            Node* resNode = it->second;
            int ans = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->nxt;
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        auto it = mp.find(key);
        if(it != mp.end()){
            Node* resNode = it->second;
            mp.erase(key);
            deleteNode(resNode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prv->key);
            deleteNode(tail->prv);
        }
        addNode(new Node(key,value));
        mp[key] = head->nxt;
    }
};
