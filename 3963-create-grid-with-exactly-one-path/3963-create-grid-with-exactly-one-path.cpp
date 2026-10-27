class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m,string(n,'#'));
        int r=0,c=0;
        grid[0][0]='.';
        bool mRight = true;

        while(r!=m-1||c!=n-1){
            if(mRight && c<n-1){
                c++;
            } else if (!mRight&&r<m-1){
                r++;
            } else if (c<n-1){
                c++;
            } else {
                r++;
            }
            grid[r][c]='.';
            mRight=!mRight;
        }
        return grid;

       
    }
};