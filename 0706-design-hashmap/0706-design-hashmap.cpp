class MyHashMap {
public:
static const int size = 1000;
vector<list<pair<int,int>>> buckets;

int hashFunction(int key){
    return key % size;
}
    MyHashMap() {
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int idx = hashFunction(key);

        for(auto &p : buckets[idx]){
            if(p.first == key){
                p.second = value;
                return;
            }
        }
        buckets[idx].push_back({key,value});
    }
    
    int get(int key) {
        int idx = hashFunction(key);

        for(auto &p : buckets[idx]){
            if(p.first == key){
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hashFunction(key);

        auto &bucket = buckets[idx];
        for(auto it = bucket.begin(); it != bucket.end(); it++){
            if(it->first == key){
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */