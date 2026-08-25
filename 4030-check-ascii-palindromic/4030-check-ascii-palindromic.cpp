class Solution {
public:
    bool isPalindromic(string s) {
        string s2 = "";

        for (char c : s) {
            int x = (int)c;
            for (int i = 7; i >= 0; i--) {
                s2 += ((x >> i) & 1) + '0';
            }
        }

        int l = 0, r = s2.size()-1;
        while(l<r){
            if(s2[l]!=s2[r]) return false;
            l++;r--;
        }

        return true;
    }
};