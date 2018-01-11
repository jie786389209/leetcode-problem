Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.




#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/////深度优先查找
class Solution
{
public:

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int max_area = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)  ///逐个
				if (grid[i][j] == 1)max_area = max(max_area, AreaOfIsland(grid, i, j));//为1时就进行深度优先查找
		return max_area;
	}


	int AreaOfIsland(vector<vector<int>>& grid, int i, int j) {
		if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {  //边界
			grid[i][j] = 0;
			return 1 + AreaOfIsland(grid, i + 1, j) + AreaOfIsland(grid, i - 1, j) + AreaOfIsland(grid, i, j - 1) + AreaOfIsland(grid, i, j + 1);
		}
		return 0;
	}
};

int main()
{
	vector<vector<int>> grid = { {0,1,0},
						         {1,1,1},
						         {1,0,1} };

	Solution x;
	cout << x.maxAreaOfIsland(grid) << endl;

    return 0;
}
