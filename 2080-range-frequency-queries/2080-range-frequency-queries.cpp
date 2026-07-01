class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        if (!mp.count(value))
            return 0;

        vector<int> &v = mp[value];

        auto l = lower_bound(v.begin(), v.end(), left);
        auto r = upper_bound(v.begin(), v.end(), right);

        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */