y of integers and an integer k, find out whether there are twGiven an arrao distinct indices i and j in the array such 
that nums[i] = nums[j] and the absolute difference between i and j is at most k.

////////////
思路：用set，先保存前k项，然后窗口滑动，划进来的新值存在就返回真，不存在就添加
set特性不能存在相同项

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};
