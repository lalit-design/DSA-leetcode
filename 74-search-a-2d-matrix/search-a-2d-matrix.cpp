class Solution {
private:
    bool ispresent(int low,int high,int target,vector<int> &matrix){
        while(low<=high){
            int mid =low + (high-low)/2;

            if(matrix[mid]==target){
               return true;
            }
            if(matrix[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i = 0;i<matrix.size();i++){
         
       if(ispresent(0,matrix[i].size()-1,target,matrix[i])){
        return true;
       }
      }
       return false;
    }
};