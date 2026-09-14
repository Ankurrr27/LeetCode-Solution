class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        vector<int> answer(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            // Current person can see all shorter people
            while (!st.empty() && heights[i] > st.top()) {
                answer[i]++;
                st.pop();
            }

            // Current person can also see the first taller person
            if (!st.empty()) {
                answer[i]++;
            }

            // Add current person to the stack
            st.push(heights[i]);
        }

        return answer;
    }
};