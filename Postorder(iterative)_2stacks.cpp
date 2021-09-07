vector<int> PostOrder(TreeNode * node)
{
    vector<int> ans;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    st1.push(root);
    TreeNode * node = root;
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL)
        {
            st1.push(root->left);
        }
        if(root->right!=NULL)
        {
            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}