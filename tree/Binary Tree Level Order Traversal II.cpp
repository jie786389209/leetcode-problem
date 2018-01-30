Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

////////////////////

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        vector<int> level;
        int i=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            queue<TreeNode*> q_temp=q;
            level.clear();
            for(int j=0;j<s;j++) ///在队列中每个level的那些值压进res
            {
                TreeNode* aa(q_temp.front());
                level.push_back(aa->val);
                q_temp.pop();
            }
            res.insert(res.begin(),level);
            
            
            for(int j=0;j<s;j++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            
        }
        return res;    
    }
};
