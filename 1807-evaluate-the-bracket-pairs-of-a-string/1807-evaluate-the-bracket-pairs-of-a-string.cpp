class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> d;

        for (auto& item : knowledge) {
            d[item[0]] = item[1];
        }

        string ans;
        int start = -1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(') {
                start = i;
            }
            else if (c == ')') {
                string key = s.substr(start + 1, i - start - 1);

                if (d.count(key)) {
                    ans += d[key];
                } else {
                    ans += "?";
                }

                start = -1;
            }
            else if (start < 0) {
                ans += c;
            }
        }

        return ans;
    }
};