class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Last index of nums1's valid elements
        int j = n - 1; // Last index of nums2
        int k = m + n - 1; // Last index of nums1 (including extra space)
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If any elements are left in nums2, place them in nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
