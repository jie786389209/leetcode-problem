First one: check from strs[0][0] to strs[i][0]. If matches, check strs[0][1] to strs[i][1].
思路：纵向比较
Code:

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        string ans="";
        int max=INT_MAX;
        for(auto& s:strs)
        {
            max=(max>s.length())?s.length():max;
        }
        for(int i=0;i<max;i++)
        {
            bool flag=true;
            char x=strs[0][i];
            for(auto& s:strs)
            {
                if(s[i]!=x)
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false)
            return ans;
            ans+=x;
        }
        return ans;
    }
};

//////////////////////////////////////////////////

Second one: assume the prefix is strs[0]. Compair with strs[i], and cut the letters which don’t match.
横向比较
Code:

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        string ans=strs[0];
        int max=INT_MAX;
        for(auto& s:strs)
        {
            if(s.length()==0)
            return "";
            int i=0;
            for(i=0;i<ans.length()&&i<s.length();i++)
            {
                if(s[i]!=ans[i])
                break;  //跳出整个循环
            }
            ans=ans.substr(0,i);
        }

        return ans;
    }
};

////////////////////////////////////

Third one: use a Trie data structure to save the strs. Search the trie, and stops when a TrieNode has more than one son.
数据结构trie
Code:

class TrieNode{
public:
	bool val;
	TrieNode* next[52];
	int sons;
	TrieNode() :val(false), sons(0)
	{
		for (int i = 0; i < 52; i++)
			next[i] = nullptr;
	}
};


class Trie{
private:
	TrieNode* putst(string& s, TrieNode * node, int loc, TrieNode *father)
	{
		if (s.length() == 0)
		{
			node->val = true;
			node->sons++;
			return node;
		}
		if (node == nullptr)
		{
			node = new TrieNode();
			if (father != nullptr)
				father->sons++;
		}
		if (loc == s.length())
		{
			node->val = true;
			return node;
		}
		if (s[loc] >= 'a')
			node->next[s[loc] - 'a'] = putst(s, node->next[s[loc] - 'a'], loc + 1, node);
		else
			node->next[s[loc] - 'A' + 26] = putst(s, node->next[s[loc] - 'A' + 26], loc + 1, node);
		return node;
	}
  
public:
	TrieNode *root;
	void insert(string & str){ putst(str, root, 0, nullptr); }
	Trie(){ root = new TrieNode(); }
};


class Solution {
private:
	string findPre(TrieNode * node)
	{
		if (node == nullptr || (node != nullptr&&node->sons > 1))
			return string("");
		int i = 0;
		for (i = 0; i < 52; i++)
		{
			if (node->next[i] != nullptr)
				break;
		}
		if (i == 52)
			return string("");
		char temp1 = ((i>25) ? ('A' + i) : ('a' + i));
		string temp;
		temp.insert(temp.begin(), temp1);
		if (node->val)
		{
			return string("");
		}
		else
		{
			return temp + findPre(node->next[i]);
		}
	}
  
public:
	string longestCommonPrefix(vector<string>& strs) {
		Trie a;
		for (auto& str : strs)
			a.insert(str);
		return findPre(a.root);
	}
};
