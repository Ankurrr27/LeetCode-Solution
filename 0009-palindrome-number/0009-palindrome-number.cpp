class Solution {
public:
    bool isPalindrome(int x) {
        long reversed = 0 ;
        int original = x;
        
        if(x<0) return false ;

        while(x!=0){
            int digit = x%10 ;
            reversed = reversed*10 + digit ;
            x = x/10;
        }
        if(reversed==original) return true;
        return false;
    }
};