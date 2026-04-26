class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,0);
        int max_len=0;
        int n=s.length();
        int i=0 , j=0;
        while(j<n){
            if(freq[s[j]]==0) {
                freq[s[j]]++;
                 j++;
            }
            else{
                freq[s[i]]--;
                i++;
            }
            max_len=max(max_len,j-i);
            
        }
        return max_len;
    }
};
