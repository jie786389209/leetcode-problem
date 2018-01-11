
/////思路：i和j指针，i遍历当前，j遇到零就停等待赋值前移
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
