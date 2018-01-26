方法一：使用KMP

First, we build the KMP table.

Roughly speaking, dp[i+1] stores the maximum number of characters that the string is repeating itself up to position i.
Therefore, if a string repeats a length 5 substring 4 times, then the last entry would be of value 15.
To check if the string is repeating itself, we just need the last entry to be non-zero and str.size() to divide (str.size()-last entry).
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n+1,0);
        while( i < str.size() ){
            if( str[i] == str[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
    
//////////////////////////////

方法二：使用左移，前后比较

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string nextStr = str;
        int len = str.length();
        if(len < 1) return false;
        for(int i = 1; i <= len / 2; i++){
            if(len % i == 0){
                nextStr = leftShift(str, i);
                if(nextStr == str) return true;
            }
        }
        return false;
    }
    
    string leftShift(string &str, int l){
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }
};


bool repeatedSubstringPattern(string str) {
    int n = str.length();
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0 && str.substr(i) == str.substr(0, n - i))
            return true;
    return false;
}

////////////////////////////
方法三：先找出substring，然后倍乘再与原string比较
public boolean repeatedSubstringPattern(String str) {
	int l = str.length();
	for(int i=l/2;i>=1;i--) {
		if(l%i==0) {
			int m = l/i;
			String subS = str.substring(0,i);
			StringBuilder sb = new StringBuilder();
			for(int j=0;j<m;j++) {
				sb.append(subS);
			}
			if(sb.toString().equals(str)) return true;
		}
	}
	return false;
}
