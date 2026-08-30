class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;

        vector<string> res(n);

        for (int x : nums) {
            res[idx++] = fn(x);
        }

        return res;
    }

private:
    string fn(int n) {
        int freq[26] = {};
        int i = 'a';

        for (i = 'a'; i < 'z' && n >= 2; i++, n /= 2) {
            if (n % 2 == 1) {
                freq[i - 'a']++;
            }
        }

        freq[i - 'a'] = n;

        string res;

        for (i = 25; i >= 0; i--) {
            while (freq[i]-- != 0) {
                res.append(1, (char)(i + 'a'));
            }
        }

        return res;
    }
};