Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
/////////////////////////////////////////////
方法一：
//Using two hash map.
//One records the starting index for the character.
//The other records the frequency of the character.

//Once a certain character’s frequency is bigger than others. we update the variable len. When more than two character have the same frequency, just compare their length, choose the shorter one.

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int res = nums.size();
        unordered_map<int, int> startIndex, count;
        int len = nums.size(), fre = 0;
        for (int i = 0; i < nums.size() ;i++) {
            if (startIndex.count(nums[i]) == 0) startIndex[nums[i]] = i;
            count[nums[i]]++;
            if (count[nums[i]] == fre){  //一样多则返回长度小的
                len = min(i - startIndex[nums[i]] + 1, len);
            }
            if (count[nums[i]] > fre){ 
                len = i - startIndex[nums[i]] + 1;
                fre = count[nums[i]];
            }
        }
        return len;
    }
};
