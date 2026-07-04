class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++){
            bool fun = true;
            int num = i;
            while(num){
                int digit = num%10;
                if(digit==0 || i%digit!=0){
                    fun = false;
                    break;
                }
                num/=10;
            }
            if(fun==true){
                v.push_back(i);
            }
        }
        return v;
    }
};