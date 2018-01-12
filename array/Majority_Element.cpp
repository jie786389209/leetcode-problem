///方法一：map(自己写)
// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
	bool containsKey(map<int,int> set,int key) //存在键值
	{
		map<int, int>::iterator it = set.find(key);
		if (it != set.end())
			return true;
		else
			return false;
	}



	map<int, int> countNums(vector<int> nums) 
		{
		map<int, int> counts;
		for (int num : nums) 
		{
			if (!containsKey(counts,num)) 
			{
				counts.insert(pair<int,int>(num, 1));
			}
			else
			{
				//counts.insert(num, counts.at(num) + 1);//插入相同键值insert会不起作用
				counts.at(num) +=1;
			}
		}
		return counts;
	}

	//map<int, int>::key_type 
	int
		val_getkey(map<int, int> set,int val)
	{
		//std::string s = "c";
		auto find_item = find_if(set.begin(), set.end(),
			[val](map<int,int>::value_type item) //不能省略value_type，因为item是iterator指针
			                                     //去掉后单纯声明一个map
		{
			return item.second == val;
		});

		//int n = 0;
		if (find_item != set.end())
		{
			return (*find_item).first;
		}
	}
	

public:
	void majorityElement(vector<int> nums)
	{
		map<int, int> counts = countNums(nums);

		//Map.Entry<Integer, Integer> majorityEntry = null;
		int major = 0;
		for (auto entry : counts) {

			major = max(major, entry.second);

		}
		cout << val_getkey(counts, major) << endl;
	}
	
	
};


////同方法一：对比简略版
/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};*/

int main()
{
	vector<int> aa = {1,2,3,2,5,2,1,2,2,2};
	                      
	Solution x;
		x.majorityElement(aa);

    return 0;
}

///方法二:排序
///java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
	  int len = nums.length; //一般来说是直接排序然后取中间值返回
                           // 下面用nth_element只排序一个，可能是时间使用更少
                           //另外，c++的sort(a,a+10);
	  return nums[len/2];
    }
}

////c++
///nth_element(start, start+n, end) 只排序第n大的数在n位置，保证n前小，n后大，不保证有序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    } 
};



///方法三:分而治之
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm; //左边和右边的major一样则直接返回
        //否则哪边的major更多就选哪个
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
}; 

///方法四：Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};

///方法五Randomization
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }
};

///方法六：Bit Manipulation
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
    } 
};
