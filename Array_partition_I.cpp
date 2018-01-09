/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
*/

/*
思路：排序取奇数位上的数相加
*/


#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int array_sum(vector<int> nums)
    {

        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();sum+=nums[i],i+=2);
        return sum;
    }
};

int main()
{
    vector<int> nums={2,4,1,3};
    Solution x;
    int sum=x.array_sum(nums);
    cout<<sum<<endl;
}
