class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int max_len = 0;

        for (int num : s) {
            // check if it's the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int current = num;
                int length = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                max_len = max(max_len, length);
            }
        }

        return max_len;
    }
};