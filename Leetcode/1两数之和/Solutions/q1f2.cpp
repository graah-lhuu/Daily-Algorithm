class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_map;
        for (int i=0;i<nums.size();i++){
        	int complement=target-nums[i];
        	if (num_map.find(complement)!=num_map.end()){
        		return {num_map[complement],i};
			}
			num_map[nums[i]]=i;
		}
		return {};
    }

};

/*
使用hash map,时间复杂度为O(n)
*/
