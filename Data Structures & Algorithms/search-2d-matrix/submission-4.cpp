//  here only the catch is that you need to know how matrix stores in memory 

// row=flatidx/cols;
// col=flatidx%cols;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size(); // cols
        int n=matrix.size();    //rows

        int lo=0 , hi = m*n-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]>target) hi=mid-1;
            else if(matrix[row][col]<target) lo=mid+1;
            else return true;
        }

        return false;
    }
};
