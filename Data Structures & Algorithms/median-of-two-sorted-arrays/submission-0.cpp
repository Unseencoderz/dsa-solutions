class Solution {
   public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        vector<int> res;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n1) {
            res.push_back(nums1[i]);
            i++;
        }
        while (j < n2) {
            res.push_back(nums2[j]);
            j++;
        }
        return res;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res = merge(nums1, nums2);
        int n = res.size();
     

        if (n & 1) return (double)res[n / 2];

        return (res[n / 2 - 1] + res[n / 2]) / 2.0;
    }
};
