class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> nset(nums.begin(), nums.end());
        int l = nums[0];
        int n = nums.size();
        if (n == 1) return l+1;
        for (int i = 1; i<n; i++){
            if (nums[i] != nums[i-1] + 1){
                break;
            } else{
                l += nums[i];
            }
        }
        
        while (true){
            if (nset.find(l)!=nset.end()){
                l++;
                continue;
            } else{
                return l;
            }
        }
        return -1;
    }
};