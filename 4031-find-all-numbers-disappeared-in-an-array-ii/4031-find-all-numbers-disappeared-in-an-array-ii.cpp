class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        vector<bool> present(1000001, false);

        for (int x : nums) {
            present[x] = true;
        }

        vector<vector<int>> ans;

        int i = lower;

        while (i <= upper) {
            if (present[i]) {
                i++;
                continue;
            }

            int start = i;

            while (i <= upper && !present[i]) {
                i++;
            }
            ans.push_back({start, i - 1});
        }
        return ans;
    }
};