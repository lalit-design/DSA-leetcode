class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

      vector<int>nums3;

   //merging both the arrays
      for(int i = 0;i<nums1.size();i++){
        nums3.push_back(nums1[i]);
      }
    
    for(int i = 0;i<nums2.size();i++){
        nums3.push_back(nums2[i]);
    }

  //sorting the nums3 array
    sort(nums3.begin(),nums3.end());

  
     int median = nums3.size()/2;

    if(nums3.size()%2 != 0){
        return nums3[median];
    }else{
        float sum = (nums3[median]+nums3[median - 1])/2.0;
         return sum;
    }

    }
};