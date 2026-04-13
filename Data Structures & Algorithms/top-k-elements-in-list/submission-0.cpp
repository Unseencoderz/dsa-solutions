// Time: O(n log n)  |  Space: O(n)
// Approach: Hashing + Sorting
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int , int>> freq;
        for(auto &it : mp)
        {
            freq.push_back({it.second , it.first});
        }
        sort(freq.rbegin(),freq.rend());
        vector<int> res;
        for(int i=0;i<k;i++){
               res.push_back(freq[i].second);
        }
        return res;
    }
};

// Time:O(n+mlogm+klogm)  ~ O(n log n) 
//   Space: O(n)
// Approach: Hashing + Max Heap

class Solution2{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
       priority_queue<pair<int,int>> pq;
        for(auto &it : mp)
        {
            pq.push({it.second , it.first});
        }
        vector<int> res;
        for(int i=0;i<k;i++){
               res.push_back(pq.top().second);
               pq.pop();
        }
        return res;
    }
};

// Time: O(n log k)  |  Space: O(n)
// Approach: Hashing + Min Heap

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;

        // min heap: {frequency, number}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto &it : mp) {
            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop(); // remove smallest frequency
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};


