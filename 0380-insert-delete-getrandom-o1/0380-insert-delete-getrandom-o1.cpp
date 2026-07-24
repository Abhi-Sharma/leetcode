class RandomizedSet {
public:
unordered_map<int,int> mpp;
vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.count(val)) return false;

        arr.push_back(val);
        mpp[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;

        int index = mpp[val];
        int lastElement = arr.back();
        arr[index] = lastElement;
        mpp[lastElement] = index;
        arr.pop_back();
        mpp.erase(val);

        return true;
    }
    
    int getRandom() {
        int index = rand() % arr.size();
        return arr[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */