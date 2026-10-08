class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer = "";
        int level = 0 ;
        for (char ch:s){
            if(ch=='('){
                if(level>0){
                    answer += ch ;
                }
                level++;
            }
            else if (ch==')'){
                level--;
                if(level>0){
                    answer += ch;
                }
            }
        }
        return answer;
    }
};