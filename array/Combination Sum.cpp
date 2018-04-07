Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]



// ConsoleApplication6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>
//using namespace std;

class Solution {
public:
	std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, 
	                    std::vector<int> &combination, int begin)
        {
		if (!target) {  //符合条件放入res中
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combination, i);
			combination.pop_back();
		}
	}
};

int main()
{
	std::vector<int> ss = { 4,5,6 };
	Solution x;
	std::vector<std::vector<int> > final = x.combinationSum(ss, 10);
	//std::cout << final << endl;
	for (int i = 0; i < final.size(); i++)
	{
  		for(int j=0;j < final[i].size();j++)
			std::cout << final[i][j];
		std::cout << " ";
	}
    return 0;
}

