class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_map;
        for (int i=0;i<nums.size();i++){
        	int complement=target-nums[i];
        	if (num_map.find(complement)!=num_map.end()){// 检查互补数是否已经在哈希表中
        		return {num_map[complement],i};
			}
			num_map[nums[i]]=i;//// 如果不在，就把当前数和它的索引加入哈希表
		}
		return {};
    }

};

/*
使用hash map,时间复杂度为O(n)
*/


