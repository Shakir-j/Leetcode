/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*

// Recursive Approach
class Solution {
public:

    void inorder(TreeNode* node, vector<int> &ans) {
        if(node == NULL) {
            return;
        }

        inorder(node->left, ans);
        
        ans.push_back(node->val);

        inorder(node->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root,ans);

        return ans;
    }
};

*/

// Iterative Approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;

        vector<int> inorder;
        while(true) {
            if(node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }

        return inorder;
    }
};
