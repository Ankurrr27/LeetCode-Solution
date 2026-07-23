class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string yc = "", others = "", xc = "";

        bool hasX = false;
        bool hasY = false;

        for(char c : s){
            if(c==x)hasX=true;
            if(c==y)hasY=true;
            
        }

        if(!hasX || !hasY) return s;
        for (char c : s) {
            if (c == y)
                yc += c;
            else if (c == x)
                xc += c;
            else
                others += c;
        }
        return yc + others + xc;
    }
};