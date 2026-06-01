class Solution {
public:
    bool canEat(vector<int>&piles , int k , int h){
        int hrs=0;
        for(int x:piles){
            hrs+=(x+k-1)/k;
        }
        return h>=hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mx=*max_element(piles.begin(),piles.end());
        int lo=1 , hi = mx ;
        int res=hi;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(canEat(piles , mid , h)){
                res=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }

        return res;

    }
};


//  m largest pile 
// n nums of piles 
// 1 to m check all 