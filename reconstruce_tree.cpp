#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
  map<int, int> m_index;

 TreeNode *reconstruct_tree(vector<int> &inorder, vector<int> &postorder,
                             int left, int right) {
    if (left > right) {
      return NULL;
    }

    TreeNode *root_local = new TreeNode(postorder[right]);
	cout<<"root: "<<postorder[right]<<endl;
    int inorder_root_index = m_index[postorder[right]];
if(left == right){
return root_local;
}
    int left_tree_left = left;
    int left_tree_right = inorder_root_index - 1;
    root_local->left =
        reconstruct_tree(inorder, postorder, left_tree_left, left_tree_right);

    int right_tree_right = right;
    int right_tree_left = inorder_root_index + 1;
    root_local->right =
        reconstruct_tree(inorder, postorder, right_tree_left, right_tree_right);

    return root_local;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() != postorder.size()) {
      return NULL;
    }

    int left = 0;
    int right = inorder.size() - 1;

    for (int i = 0; i < inorder.size(); i++) {
      m_index[inorder[i]] = i;
    }
    return reconstruct_tree(inorder, postorder, left, right);
  }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> inorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> postorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(inorder, postorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
