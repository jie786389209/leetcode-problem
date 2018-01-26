Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.

//////////////////////////////////////////////////
思路：两个指针，一个count
i遍历指针，newone新的指针（覆盖），count等于1直接添加后置0
count大于1先转化为字符串再添加


#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int count=0,newone=0;
        int m=chars.size();
        for(int i=0;i<chars.size();i++)
        {
            count++;
            if((chars[i]!=chars[i+1]&&i<m-1)||i==m-1)
            {
                chars[newone]=chars[i];
                newone++;
                if(count>1) {
                    string s=to_string(count);
                    for(int j=0;j<s.size();j++, newone++) chars[newone]=s[j];
                    //newone++;
                }
                count=0;
            }
        }
        return newone;
    }
};

int main()
{
    vector<char> chars={'a','b','b','b','b','b','b','b','b','b','b','b','c'};
    Solution x;
    cout<<x.compress(chars)<<endl;
}
