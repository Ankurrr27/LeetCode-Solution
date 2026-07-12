class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxSize = 0;
        int left = 0;
        int right = 0;
        vector<int> hash(256, -1);

        for (right = 0; right < n; right++) {

            if (hash[s[right]] != -1) {
                if (hash[s[right]] >= left) {
                    left = hash[s[right]] + 1;
                }
            }
            hash[s[right]]= right;

            int curr_length = right-left+1;
            maxSize = max(maxSize, curr_length);
        }
        return maxSize;
    }
};