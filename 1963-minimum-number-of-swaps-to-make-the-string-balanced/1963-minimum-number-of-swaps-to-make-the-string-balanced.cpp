class Solution {
public:
    int minSwaps(string s) {
        stack<int> open;
        stack<int> close;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                open.push(i);
            } else {
                if (!open.empty()) {
                    open.pop();
                } else {
                    close.push(i);
                }
            }
        }

        int count = (close.size() + 1) / 2;

        return count;
    }
};