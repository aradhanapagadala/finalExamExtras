#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                              postorder, 0, postorder.size() - 1, inorderMap);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart, int postEnd,
                              unordered_map<int, int>& inorderMap) {
        // Base case: no elements to construct the tree
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        
        // The last element in postorder is the root
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find the index of root in inorder to split left and right subtrees
        int rootIndex = inorderMap[rootVal];
        
        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;
        
        // Recursively build left and right subtrees
        root->left = buildTreeHelper(inorder, inStart, rootIndex - 1,
                                     postorder, postStart, postStart + leftSize - 1,
                                     inorderMap);
        
        root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd,
                                      postorder, postStart + leftSize, postEnd - 1,
                                      inorderMap);
        
        return root;
    }
};