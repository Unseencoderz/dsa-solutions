// soln-1 Brute force : Create all possible n^2 pairs ; check the sum 
// Time : O(n^2) : try all possible pairs
// Space : O(1) : no extra space used 

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {};
    }
};

// soln 2 : Optimal  ; using hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];
            if (seen.count(need)) return {seen[need], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};


