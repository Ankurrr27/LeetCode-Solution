class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        // Count frequency of all characters
        for (char c : s) {
            freq[c - 'a']++;
        }

        string half = "";
        char mid = 0;

        // Build half + middle (if odd count)
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                mid = 'a' + i;
            }
            half += string(freq[i] / 2, 'a' + i);
        }

        string rev = half;
        reverse(rev.begin(), rev.end());

        return half + (mid ? string(1, mid) : "") + rev;
    }
};