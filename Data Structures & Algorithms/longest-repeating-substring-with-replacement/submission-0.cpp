class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);

        int i = 0, j = 0;
        int maxFreq = 0;
        int longest = 0;

        while (j < n) {
            // expand window
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            // shrink window if invalid
           if ((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            // update answer
            longest = max(longest, j - i + 1);

            j++;
        }

        return longest;
    }
};