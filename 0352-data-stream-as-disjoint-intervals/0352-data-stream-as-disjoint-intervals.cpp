class SummaryRanges {
public:
    map<int, int> intervals;

    SummaryRanges() {}

    void addNum(int value) {
        auto right = intervals.lower_bound(value);
        auto left = right;

        if (left != intervals.begin())
            --left;
        else
            left = intervals.end();

        // Already covered by the right interval (same start)
        if (right != intervals.end() &&
            right->first <= value &&
            value <= right->second)
            return;

        // Already covered by the left interval
        if (left != intervals.end() &&
            left->first <= value &&
            value <= left->second)
            return;

        bool mergeLeft =
            (left != intervals.end() && left->second + 1 == value);

        bool mergeRight =
            (right != intervals.end() && right->first == value + 1);

        if (mergeLeft && mergeRight) {
            // Merge left and right intervals
            left->second = right->second;
            intervals.erase(right);
        }
        else if (mergeLeft) {
            // Extend left interval
            left->second = value;
        }
        else if (mergeRight) {
            // Extend right interval to the left
            int end = right->second;
            intervals.erase(right);
            intervals[value] = end;
        }
        else {
            // Create a new interval
            intervals[value] = value;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (auto &p : intervals)
            ans.push_back({p.first, p.second});

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */