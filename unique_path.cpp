/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n <= 0)
        {
            return (vector<TreeNode *>());
        }
        return trees(1, n);
    }

  private:
    vector<TreeNode *> trees(int start, int end)
    {
        vector<TreeNode *> vTrees;
        if (start > end)
        {
            vTrees.push_back(NULL);
            return vTrees;
        }
        if (start == end)
        {
            //return this node
            //core, construct this tree
            //leafs are null
            vTrees.push_back(new TreeNode(start));
            return vTrees;
        }
        //wide range
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> ltree = trees(start, i - 1);
            vector<TreeNode *> rtree = trees(i + 1, end);
            for (auto lnode : ltree)
            {
                for (auto rnode : rtree)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    vTrees.push_back(root);
                }
            }
        }
        return vTrees;
    }
};