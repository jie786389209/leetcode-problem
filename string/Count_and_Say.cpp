 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.   13211311123113112211
 
 /////////////////////
 思路：迭代，
 #include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s,result;;
        int count=1;
        
        if(n==1) return s="1";
        s=countAndSay(n-1); //注意这里当前result返回赋值给上一个s进行操作
        for(int i=0;i<s.size();i++)
        {
            if((s[i]!=s[i+1]&&i<s.size()-1)||i==s.size()-1)//注意这里的技巧，到达尾端前和到达尾端
            {
                result.append(to_string(count));
                result.append(s,i,1);
                count=1;
            }
            else 
                count++;    
        }
        return result;
    }
};



int main() 
{
    Solution x;
    cout<<x.countAndSay(10)<<endl;
}
