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
