class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s ;
    
        int start = 0 , maxLen = 1;

        for( int i=0 ; i<s.size() ; i++){
            expand(s, i, i, start, maxLen);

            expand(s, i, i+1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

    void expand(const string &s, int left, int right, int &start, int &maxLen){
        while(left >= 0 && right < s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        int len = right - left - 1;
        if(len > maxLen){
            maxLen = len;
            start = left + 1;
        }
    }
};