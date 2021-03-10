/*
暴力解法，不讲道理，注意条件i != j
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
				//这里注意条件 i!=j
                if(nums[i] + nums[j] == target && i != j){
                    return {i,j};
                }
            }
        }
        return {};
    }
};


/*
一遍哈希表
nums = [2, 8, 5, 11, 7]
target = 9

建立键值对
k    v
2    0
8    1
5    3
11    4
找到

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		//建立无序哈希表，键位nums[i], 值位i
        unordered_map<int, int> hashtable;
		//遍历数组
        for(int i = 0; i<nums.size(); i++){
			//找键有没有target-nums[i],如果有，就会把值赋值给it, 在本例中，it指的是2和0这一个键值对
            auto it = hashtable.find(target - nums[i]);
			//如果找到了，返回找到的那个数的索引，以及现在的索引
            if(it != hashtable.end()){
                return {it->second, i};
            }
			//找不到，将nums[i],i这一个键值对存下来
            hashtable[nums[i]] = i;
        }
        return {};
    }
};