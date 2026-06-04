class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0 , hi = n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(target == nums[mid]) return mid;

            if(nums[lo] <= nums[mid]){ // we are in left sorted part of array 
               if(target >= nums[lo] && target <nums[mid]){
                hi=mid-1;
               }
               else{
                lo=mid+1;
               }
            }
            else{
                if(target > nums[mid] && target <=nums[hi]){
                lo=mid+1;
               }
               else{
                hi=mid-1;
               }
            }
        }
        return -1;
    }
};


// check in which part of array are we in 
// if left sorted -> check if target is in range if yes then search left else search right
// if right sorted -> check if target target > nums[mid]> search right else search left