class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> nums2 = nums1;

        int minOdd = INT_MAX;
        bool hasOdd = false;

        for (int x : nums1) {
            if (x % 2) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }

       
        if (!hasOdd) return true;

        
        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd) {
                return false;
            }
        }

        return true;
    }
};