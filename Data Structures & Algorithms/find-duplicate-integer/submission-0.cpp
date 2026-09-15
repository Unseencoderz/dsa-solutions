class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


 // Method 1: Sort and check
// Time: O(n log n)
// Space: O(1)  (if in-place sorting)

// Method 2: Hash map / set
// Time: O(n)
// Space: O(n)

// Method 3: Floyd's Cycle Detection
// Time: O(n)
// Space: O(1)  <-- optimal
