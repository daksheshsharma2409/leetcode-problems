class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int l = 0;
        int r = nums.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid]>=target){
                r = mid - 1;
                if (nums[mid] == target){
                    res[0] = mid;
                }
            }
            else{
                l = mid + 1;
            }
        }
        l = 0;
        r = nums.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid]<=target){
                l = mid + 1;
                if (nums[mid] == target){
                    res[1] = mid;
                }
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};