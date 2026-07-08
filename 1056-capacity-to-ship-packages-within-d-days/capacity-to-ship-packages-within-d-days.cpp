class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int capacity=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0;
            int ans=1;
            
            for(int w : weights){
                count +=w;
            
            if(count>mid){
                ans++;
                count=w;
            }
            }
            if(ans<=days){
                capacity=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return capacity;
    }
};