class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        int n=nums.size();

        if (n<4) return false;
        if (nums[0]>=nums[1]) return false;

        while (nums[i]<nums[i+1]){
            i++;
            if (i==n-1) return false;
        }

        while (nums[i]>nums[i+1]){
            i++;
            if (i==n-1) return false;
        }
        while (nums[i]<nums[i+1]){
            i++;
            if (i==n-1) return true;
        }
        return false;

    }
};