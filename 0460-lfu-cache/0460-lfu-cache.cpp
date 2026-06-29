class Node {
public:
    int key, value, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
public:
    int capacity, currSize, minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node *node) {

        int freq = node->freq;

        freqList[freq]->remove(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->addFront(node);
    }

    int get(int key) {

        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];

        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {

            Node *node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (currSize == capacity) {

            List *list = freqList[minFreq];

            Node *node = list->tail->prev;

            list->remove(node);

            keyNode.erase(node->key);

            delete node;

            currSize--;
        }

        Node *node = new Node(key, value);

        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->addFront(node);

        keyNode[key] = node;

        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */