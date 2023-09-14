class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    Node *head, *tail;
    int cap;
    unordered_map<int,Node*> mp;
    
    void addhead(Node *insnode) {
        insnode->next = head->next;
        head->next->prev = insnode;
        insnode->prev = head;
        head->next = insnode;
    }
    void del(Node *delnode) {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->prev = NULL;
        tail->next = NULL;
        head->key = -1;
        head->val = -1;
        tail->key = -1;
        tail->val = -1;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            // delete node if already present
            Node *tobeadded = mp[key];
            del(mp[key]);
            mp.erase(key);
            // insert at front
            addhead(tobeadded);
            mp[key] = head->next;
            return head->next->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node *temp = mp[key];
            temp->val = value;
            mp.erase(key);
            del(temp);
            addhead(temp);
            mp[key] = head->next;
            return ;
        } else {
            if(mp.size() == cap) {
                mp.erase(tail->prev->key);
                del(tail->prev);
                Node *temp = new Node();
                temp->key = key;
                temp->val = value;
                addhead(temp);
                mp[key] = head->next;
                return ;
            } else {
                Node *temp = new Node();
                temp->key = key;
                temp->val = value;
                addhead(temp);
                mp[key] = head->next;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */