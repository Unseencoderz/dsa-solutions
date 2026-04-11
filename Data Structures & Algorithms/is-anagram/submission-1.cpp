// Time : O(nlogn) space O(1)
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

// soln2 - Most Optimal 
// using frequency count
// Time : O(n) space (1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int c: count) {
            if(c!=0) return false;
        }
        return true;
    }
};
