class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        int sum = 0;
        for (int i = 0; i < nums.size(); sum += nums[i++])
            if (sum * 2 == total - nums[i])
                return i;
        
        return -1;
    }
};


///////////////

自己写的双指针，太麻烦
先总结规律，别一上来就写，方法很重要
要多方法解题
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int i, j;
		i = 0;
		j = nums.size() - 1;
		int isum = nums[0], jsum = nums[nums.size() - 1];
		while (j - i != 2)
		{
			if (isum<jsum)
			{
				i++;
				isum += nums[i];
			}
			else if (isum>jsum)
			{
				j--;
				jsum += nums[j];
			}
			else
			{
				isum += nums[++i];
				jsum += nums[--j];
			}
		}
		if (isum== jsum)return i+1;
		else 
			return -1;

	}
};

int main()
{
	vector<int> aa = {1,4,3,3,6,5,6,4,3,1};
	Solution x;
	//cout << x.DegreeOfArray(aa) << endl;
	cout << x.pivotIndex(aa) << endl;
}
