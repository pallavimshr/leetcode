class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Node ko list se remove karna
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Node ko tail ke paas insert karna
    void insertAtEnd(Node* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
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
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        int value = node->value;

        removeNode(node);
        insertAtEnd(node);

        return value;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            insertAtEnd(node);

            return;
        }

        // Cache full hai
        if (mp.size() == capacity) {
            Node* lru = head->next;

            mp.erase(lru->key);
            removeNode(lru);

            delete lru;
        }

        // Naya node banao
        Node* newNode = new Node(key, value);

        insertAtEnd(newNode);

        mp[key] = newNode;
    }
};