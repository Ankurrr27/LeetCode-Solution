class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        vector<int> positionS;
        for(int i=0;i<n;i++){
            if(s[i]=='1')positionS.push_back(i);
        }

        int onesS = positionS.size();
        vector<bool> ans;

        for(string t:strs){
            int fixedOnes = 0, ques = 0;

            for(char c:t){
                if(c=='1')fixedOnes++;
                else if(c=='?')ques++;
            }
            int ne = onesS-fixedOnes;

            if(ne<0||ne>ques){
                ans.push_back(false);
                continue;
            }

            string cur = t;
            for(int i=n-1;i>=0;i--){
                if(cur[i]=='?'){
                    if(ne>0){
                        cur[i]='1';
                        ne--;
                    } else {
                        cur[i]='0';
                    }
                }
            }

            vector<int> positionT;
            for(int i=0;i<n;i++){
                if(cur[i]=='1')positionT.push_back(i);
            }

            bool ok = true;
            for(int i=0;i<onesS;i++){
                if(positionT[i]<positionS[i]){
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);
        }
        return ans;
    }
};