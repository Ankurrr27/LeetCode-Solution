class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3, -1);
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;

            int minindex = min({last[0], last[1], last[2]});
            if (minindex != -1) {
                ans += minindex + 1;
            }
        }
        return ans;
    }
};