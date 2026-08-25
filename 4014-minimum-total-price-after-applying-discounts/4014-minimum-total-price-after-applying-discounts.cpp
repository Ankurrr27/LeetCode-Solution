class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        int n = min(prices.size(), discounts.size());

        double ans=0;

        for(int i=0;i<n;i++){
            ans += 1.00*prices[i]*(100-discounts[i])/100;
        }
        for(int i=n;i<prices.size();i++){
            ans += prices[i];
        }

        return ans;
    }
};