#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::queue;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

struct strTreeNode {
  string val;
  strTreeNode* left;
  strTreeNode* right;
  strTreeNode() : val(""), left(nullptr), right(nullptr) {}
  strTreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
  strTreeNode(string x, strTreeNode* left, strTreeNode* right)
      : val(x), left(left), right(right) {}
};

class graduate {
 public:
  /* Convert a binary tree to an InOrder string representation with brackets
  that represent calculation priority */
  string expressionTree(strTreeNode* root) {
    string str = expressionTreeHelper(root);
    // remove the first and last bracket
    // first parameter: index, second parameter: length
    str = str.substr(1, str.size() - 2);
    return str;
  }

  string expressionTreeHelper(strTreeNode* root) {
    string res{};
    if (!root) return res;

    if (!root->left && !root->right) {
      return root->val;
    }
    // ! key point: how to handle the brackets!
    res += "(";
    res += expressionTreeHelper(root->left);
    res += root->val;
    res += expressionTreeHelper(root->right);

    res += ")";
    return res;
  }

 public:
  int wpl = 0;
  int calWPL(TreeNode* root) {
    preorder(root, -1);
    return wpl;
  }

  void preorder(TreeNode* root, int depth) {
    if (root == nullptr) return;
    depth++;
    if (root->left == nullptr && root->right == nullptr) {
      wpl += depth * root->val;
    }
    preorder(root->left, depth);
    preorder(root->right, depth);
    depth--;
  }
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string str;
    serialize(root, str);
    return str;
  }

  void serialize(TreeNode* root, string& str) {
    if (root == nullptr) {
      str += "null,";
      return;
    }
    str += std::to_string(root->val) + ",";

    serialize(root->left, str);
    serialize(root->right, str);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);  // string to stream
    return deserialize(ss);
  }

  TreeNode* deserialize(stringstream& data) {
    string str;
    if (getline(data, str, ',')) {
      if (str == "null") {
        return nullptr;
      }
      TreeNode* root = new TreeNode(stoi(str));
      root->left = deserialize(data);
      root->right = deserialize(data);
      return root;
    }
    return nullptr;
  }
};

class Solution {
 public:
  int maxDiameter = 0;
  /* 每一条二叉树的「直径」长度，就是一个节点的左右子树的最大深度之和。*/
  int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);
    return maxDiameter;
  }

  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    // 后序
    maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

    return 1 + std::max(leftDepth, rightDepth);
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<TreeNode*> q;  // q contains pointer which points to TreeNode
    q.push(root);

    /* from top to down */
    while (!q.empty()) {
      int sz = q.size();
      vector<int> levelRes;  // initialize levelRes for each level
      /* from left to right */
      for (int i = 0; i < sz; i++) {
        /* switch and pop */
        TreeNode* cur = q.front();
        levelRes.push_back(cur->val);
        q.pop();
        if (cur->left != nullptr) q.push(cur->left);
        if (cur->right != nullptr) q.push(cur->right);
      }
      res.push_back(levelRes);
    }
    return res;
  }

  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;

    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
  }

  void flatten(TreeNode* root) {
    if (root == nullptr) return;

    flatten(root->left);
    flatten(root->right);

    /* record left tree and right tree */
    TreeNode* left = root->left;
    TreeNode* right = root->right;

    /* make left tree as right tree */
    root->left = nullptr;
    root->right = left;

    /* find the last right node*/
    TreeNode* p = root;
    while (!p->right) {
      p = p->right;
    }
    /* insert right to last */
    p->right = right;
  }

  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size() - 1);
  }

  TreeNode* construct(vector<int>& nums, int lo, int hi) {
    // base case
    if (lo > hi) return nullptr;

    /* max_element: [first, last) */
    auto max_iterator =
        std::max_element(nums.begin() + lo, nums.begin() + hi + 1);
    int max_index = std::distance(nums.begin(), max_iterator);

    TreeNode* root = new TreeNode(*max_iterator);
    root->left = construct(nums, lo, max_index - 1);
    root->right = construct(nums, max_index + 1, hi);
    return root;
  }

  /* 105. Construct Binary Tree from Preorder and Inorder Traversal */
  unordered_map<int, int> hashmap;

  TreeNode* buildTreePI(vector<int>& preorder, vector<int>& inorder) {
    int preLen = preorder.size();
    int inLen = inorder.size();

    // build hashmap
    for (int i = 0; i < inLen; i++) {
      hashmap[inorder[i]] = i;
    }

    return buildPI(preorder, 0, preLen - 1, inorder, 0, inLen - 1);
  }

  /* 106. Construct Binary Tree from Inorder and Postorder Traversal */
  TreeNode* buildTreeIP(vector<int>& inorder, vector<int>& postorder) {
    int inLen = inorder.size();
    int postLen = postorder.size();

    // build hashmap
    for (int i = 0; i < inLen; i++) {
      hashmap[inorder[i]] = i;
    }

    return buildIP(inorder, 0, inLen - 1, postorder, 0, postLen - 1);
  }

  /* 889. Construct Binary Tree from Preorder and Postorder Traversal */
  TreeNode* buildTreePP(vector<int>& pre, vector<int>& post) {
    int preLen = pre.size();
    int postLen = post.size();

    for (int i = 0; i < preLen; i++) {
      hashmap[pre[i]] = i;
    }
    return buildPP(pre, 0, preLen - 1, post, 0, postLen - 1);
  }

  TreeNode* buildPP(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& postOrder, int postStart, int postEnd) {
    if (preStart > preEnd) return nullptr;
    int rootVal = preorder[preStart];
    int index = hashmap[rootVal + 1];

    TreeNode* root = new TreeNode(rootVal);

    return root;
  }

  TreeNode* buildIP(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postOrder, int postStart, int postEnd) {
    if (inStart > inEnd) return nullptr;

    int rootVal = postOrder[postEnd];
    int index = hashmap[rootVal];

    TreeNode* root = new TreeNode(rootVal);
    // https://labuladong.github.io/algo/images/二叉树系列2/5.jpeg
    root->left = buildIP(inorder, inStart, index - 1, postOrder, postStart,
                         postStart + index - inStart - 1);
    root->right = buildIP(inorder, index + 1, inEnd, postOrder,
                          postStart + index - inStart, postEnd - 1);
    return root;
  }

  TreeNode* buildPI(vector<int>& preOrder, int preStart, int preEnd,
                    vector<int>& inOrder, int inStart, int inEnd) {
    if (preStart > preEnd) return nullptr;

    int rootVal = preOrder[preStart];  // root value
    int index = hashmap[rootVal];

    TreeNode* root = new TreeNode(rootVal);
    // https://labuladong.github.io/algo/images/二叉树系列2/4.jpeg
    root->left = buildPI(preOrder, preStart + 1, preStart + index - inStart,
                         inOrder, inStart, index - 1);
    root->right = buildPI(preOrder, preStart + index - inStart + 1, preEnd,
                          inOrder, index + 1, inEnd);
    return root;
  }
};

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}

  Node* connect(Node* root) {
    if (root == nullptr) return root;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();

      for (int i = 0; i < sz; i++) {
        Node* cur = q.front();
        q.pop();

        // check if nullptr(can't check if queue is empty)
        if (i < sz - 1) {
          cur->next = q.front();
        } else {
          cur->next = nullptr;
        }

        if (cur->left != nullptr) q.push(cur->left);
        if (cur->right != nullptr) q.push(cur->right);
      }
    }
    return root;
  }
};

/* Hard to control Time Complexity */
vector<char> preOrderTraverse(TreeNode* root) {
  vector<char> res;
  if (root == nullptr) return res;

  res.push_back(root->val);
  vector<char> leftRes = preOrderTraverse(root->left);
  res.insert(res.end(), leftRes.begin(), leftRes.end());
  vector<char> rightRes = preOrderTraverse(root->right);
  res.insert(res.end(), rightRes.begin(), rightRes.end());
  return res;
}

vector<char> inOrderTraverse(TreeNode* root) {
  vector<char> res;
  if (root == nullptr) return res;

  vector<char> leftRes = inOrderTraverse(root->left);
  res.insert(res.end(), leftRes.begin(), leftRes.end());
  res.push_back(root->val);
  vector<char> rightRes = inOrderTraverse(root->right);
  res.insert(res.end(), rightRes.begin(), rightRes.end());
  return res;
}

vector<char> postOrderTraverse(TreeNode* root) {
  vector<char> res;
  if (root == nullptr) return res;

  vector<char> leftRes = postOrderTraverse(root->left);
  res.insert(res.end(), leftRes.begin(), leftRes.end());
  vector<char> rightRes = postOrderTraverse(root->right);
  res.insert(res.end(), rightRes.begin(), rightRes.end());
  res.push_back(root->val);
  return res;
}

/* create a binary tree by NLR: -+a*b-cd/ef */
void createBiTree(TreeNode*& T) {
  char ch;
  std::cin >> ch;
  if (ch == '#') {
    T = nullptr;
  } else {
    T = new TreeNode(ch);
    createBiTree(T->left);
    createBiTree(T->right);
  }
}

void createBiTree(Node*& T) {
  char ch;
  std::cin >> ch;
  if (ch == '#') {
    T = nullptr;
  } else {
    T = new Node(ch);
    createBiTree(T->left);
    createBiTree(T->right);
  }
}

int main() {
  graduate g = graduate();

  strTreeNode* root;
  // [*, +, /, -, *, 40, 17, null, 92, 81, 57, null, null, null, null, null,
  // null, null, null, null, null]
  root = new strTreeNode("*");
  root->left = new strTreeNode("+");
  root->left->left = new strTreeNode("/");
  root->left->left->left = new strTreeNode("-");
  root->left->left->left->left = new strTreeNode("*");
  root->left->left->left->left->left = new strTreeNode("40");
  root->left->left->left->left->right = new strTreeNode("17");
  root->left->left->left->right = new strTreeNode("92");
  root->left->left->right = new strTreeNode("81");
  root->left->right = new strTreeNode("57");
  root->right = nullptr;

  std::cout << g.expressionTree(root) << std::endl;
  // TreeNode* root;
  // // [8, 12, 2, null, null, 6, 4, null, null, null, null]
  // root = new TreeNode(8);
  // root->left = new TreeNode(12);
  // root->left->left = nullptr;
  // root->left->right = nullptr;
  // root->right = new TreeNode(2);
  // root->right->left = new TreeNode(6);
  // root->right->left->left = nullptr;
  // root->right->left->right = nullptr;
  // root->right->right = new TreeNode(4);
  // root->right->right->left = nullptr;
  // root->right->right->right = nullptr;

  // std::cout << g.calWPL(root) << std::endl;

  return 0;
}