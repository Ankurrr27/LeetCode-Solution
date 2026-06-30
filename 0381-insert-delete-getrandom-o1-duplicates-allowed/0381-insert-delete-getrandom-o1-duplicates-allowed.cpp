class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool first = (mp.find(val) == mp.end() || mp[val].empty());

        nums.push_back(val);
        mp[val].insert(nums.size() - 1);

        return first;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val].empty())
            return false;

        // Get any occurrence of val
        int idx = *mp[val].begin();
        mp[val].erase(idx);

        int last = nums.back();
        int lastIdx = nums.size() - 1;

        if (idx != lastIdx) {
            nums[idx] = last;

            mp[last].erase(lastIdx);
            mp[last].insert(idx);
        }

        nums.pop_back();

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */