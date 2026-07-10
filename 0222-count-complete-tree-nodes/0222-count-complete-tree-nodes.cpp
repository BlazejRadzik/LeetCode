
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int left_depth = 0;
        int right_depth = 0;
        
        TreeNode* l = root;
        TreeNode* r = root;
        
        while (l != nullptr) {
            left_depth++;
            l = l->left;
        }
        
        while (r != nullptr) {
            right_depth++;
            r = r->right;
        }
        
        if (left_depth == right_depth) {
            return (1 << left_depth) - 1; 
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};