class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int key) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == key)
                return mid;
            else if (nums[mid] < key)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n - 1; i++) {
            int complement = target - numbers[i];
            int idx = binarySearch(numbers, i + 1, n - 1, complement);

            if (idx != -1)
                return {i + 1, idx + 1};
        }
        return {};
    }
};