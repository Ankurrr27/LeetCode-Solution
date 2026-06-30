class Node {
public:
    int cnt;
    unordered_set<string> keys;
    Node *prev, *next;

    Node(int c) {
        cnt = c;
        prev = next = nullptr;
    }
};

class AllOne {
private:
    Node *head, *tail;
    unordered_map<string, Node*> mp;

    void insertAfter(Node* prevNode, Node* newNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {

        // New key
        if (!mp.count(key)) {

            if (head->next != tail && head->next->cnt == 1) {
                head->next->keys.insert(key);
                mp[key] = head->next;
            } else {
                Node* node = new Node(1);
                node->keys.insert(key);

                insertAfter(head, node);
                mp[key] = node;
            }

            return;
        }

        Node* cur = mp[key];
        Node* nxt = cur->next;

        int newCnt = cur->cnt + 1;

        if (nxt != tail && nxt->cnt == newCnt) {
            nxt->keys.insert(key);
            mp[key] = nxt;
        } else {
            Node* node = new Node(newCnt);
            node->keys.insert(key);

            insertAfter(cur, node);
            mp[key] = node;
        }

        cur->keys.erase(key);

        if (cur->keys.empty())
            removeNode(cur);
    }

    void dec(string key) {

        Node* cur = mp[key];

        if (cur->cnt == 1) {

            cur->keys.erase(key);
            mp.erase(key);

            if (cur->keys.empty())
                removeNode(cur);

            return;
        }

        Node* prv = cur->prev;
        int newCnt = cur->cnt - 1;

        if (prv != head && prv->cnt == newCnt) {

            prv->keys.insert(key);
            mp[key] = prv;

        } else {

            Node* node = new Node(newCnt);
            node->keys.insert(key);

            insertAfter(prv, node);
            mp[key] = node;
        }

        cur->keys.erase(key);

        if (cur->keys.empty())
            removeNode(cur);
    }

    string getMaxKey() {

        if (tail->prev == head)
            return "";

        return *(tail->prev->keys.begin());
    }

    string getMinKey() {

        if (head->next == tail)
            return "";

        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */