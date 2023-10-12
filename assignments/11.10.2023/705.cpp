class MyHashSet {
public:
    unordered_set<int> u;
    MyHashSet() {
        u.clear();
    }
    
    void add(int key) {
        u.insert(key);
    }
    
    void remove(int key) {
        u.erase(key);
    }
    
    bool contains(int key) {
        return u.count(key)==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */