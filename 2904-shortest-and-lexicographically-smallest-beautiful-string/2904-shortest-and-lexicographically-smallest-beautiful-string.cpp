class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int start = 0;
        int count = 0;

        string ans = "";

        for (int end = 0; end < n; end++) {

            // Add current character
            if (s[end] == '1') {
                count++;
            }

            while (count == k) {

                // Current window is beautiful
                string current = s.substr(start, end - start + 1);

                // First valid answer
                if (ans == "") {
                    ans = current;
                }

                // Shorter OR same length but lexicographically smaller
                else if (current.length() < ans.length() ||
                        (current.length() == ans.length() && current < ans)) {
                    ans = current;
                }

                // Remove left character
                if (s[start] == '1') {
                    count--;
                }

                start++;
            }
        }

        return ans;
    }
};