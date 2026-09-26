// Brute : find all pairs and return max
// Time :O(n^2) space O(1)
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxArea=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                maxArea=max(maxArea , (j-i)*min(height[i],height[j]));
            }
        }
        return maxArea;
    }
};

// Optimal : Time :O(n) space O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxArea=0;
        int i=0 , j=n-1;
        while(i<j){
            int area=min(height[i],height[j])*(j-i);
             maxArea=max(maxArea , area);
            (height[i]>height[j]) ? j-- : i++;
        }
        return maxArea;
    }
};