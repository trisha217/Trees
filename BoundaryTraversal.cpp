/********************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

********************/
 bool isLeaf(TreeNode<int>* root) {
        return !root->left && !root->right;
    }


void addLeftBoundary(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* cur = root->left;
    while(cur){
        if(!isLeaf(cur)){
            ans.push_back(cur->data);
        }
        if(cur->left){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }        
    }
}

void addRightBoundary(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* cur = root->right;
    vector<int> tmp;
    while(cur){
        if(!isLeaf(cur)){
            tmp.push_back(cur->data);
        }
        if(cur->right){
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }        
    }
    for(int i = tmp.size()-1;i>=0;--i){
        ans.push_back(tmp[i]);
    }
}

void addLeaves(TreeNode<int>* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left){
        addLeaves(root->left, ans);
    }
    if(root->right){
        addLeaves(root->right, ans);
    }
}


vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    if(!isLeaf(root)){
        ans.push_back(root->data);
    }
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}
