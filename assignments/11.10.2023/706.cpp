class MyHashMap {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    vector<Node*> buckets;
    static const int numBuckets = 1000; 

public:
    MyHashMap() {
        buckets = vector<Node*>(numBuckets, nullptr);
    }

    void put(int key, int value) {
        int index = key % numBuckets;

        if (buckets[index] == nullptr) {
            buckets[index] = new Node(key, value);
        } else {
            
            Node* curr = buckets[index];
            while (curr) {
                if (curr->key == key) {
                    curr->value = value; 
                    return;
                }
                if (curr->next == nullptr) {
                    break;
                }
                curr = curr->next;
            }
            curr->next = new Node(key, value);
        }
    }

    int get(int key) {
        int index = key % numBuckets;
        Node* curr = buckets[index];

        while (curr) {
            if (curr->key == key) {
                return curr->value; 
            }
            curr = curr->next;
        }
        return -1; 
    }

    void remove(int key) {
        int index = key % numBuckets;
        Node* curr = buckets[index];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev) {
                    prev->next = curr->next; 
                } else {
                    buckets[index] = curr->next; 
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};