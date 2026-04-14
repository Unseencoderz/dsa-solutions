//  SOLN 1 : USING DIVISION 

// Intution : 
// we need product of all elements except itself 
// so total product / current element 

// edge case : zeros 
// if no zero → normal division works 
// if one zero → only that index has product of remaining elements 
// if more than one zero → all answers = 0 

// Approach : 
// count number of zeros 
// compute product of non-zero elements 
// then build answer based on zero count 

// TC : O(n)
// SC : O(1) (excluding output)


//  SOLN 1 : USING DIVISION (CORRECTED) 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1;
        int zeroCount = 0;
        
        // calculate product of non-zero elements
        for (int x : nums) {
            if (x == 0) {
                zeroCount++;
            } else {
                prod *= x;
            }
        }
        
        vector<int> res;
        
        for (int x : nums) {
            
            // case 1 : more than 1 zero
            if (zeroCount > 1) {
                res.push_back(0);
            }
            
            // case 2 : exactly 1 zero
            else if (zeroCount == 1) {
                if (x == 0) res.push_back(prod);
                else res.push_back(0);
            }
            
            // case 3 : no zero
            else {
                res.push_back(prod / x);
            }
        }
        
        return res;
    }
};