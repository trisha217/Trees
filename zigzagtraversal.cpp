class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool flag = true;
        while(!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) 
            {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                
                 // find position to fill node's value
                int index = (flag) ? i : (size - 1 - i);
                row[index] = node->val;
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
          // after this level
            flag = !flag;
            ans.push_back(row);
        }
        return ans;
    }
};