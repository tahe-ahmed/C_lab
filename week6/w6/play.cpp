
class Node {
public:
  Node *GetNewNode(int data);

  void insertBST(Node **root, int val);

  bool Search(Node *root, int data);
  void inOrder(Node *root);
  int findHeight(Node *root);

  int data;
  Node *left;
  Node *right;
};

void Node::insertBST(Node **root, int val) {
  if (*root == NULL) { /// EMPYT tree
    std::cout << "creaate a Node" << val << std::endl;
    *root = GetNewNode(val);
    return;
  }

  if (val < (*root)->data) {
    std::cout << " TO THE left" << val << endl;
    insertBST(&(*root)->left, val);
  } else {
    std::cout << " TO THE right" << val << endl;

    insertBST(&(*root)->right, val);
  }

  //   return root;
}

bool Node::Search(Node *root, int data) {
  if (root == NULL)
    return false;
  else if (root->data == data)
    return true;
  else if (data <= root->data)
    return Search(root->left, data);
  else
    return Search(root->right, data);
}

void Node::inOrder(Node *root) {
  if (root == NULL)
    return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

int Node::findHeight(Node *root) {
  if (root == NULL)
    return 0;
  else {
    int leftHeight = findHeight(root->left);

    int rightHeight = findHeight(root->right);

    if (leftHeight > rightHeight) {
      return (leftHeight + 1);
    } else {
      return (rightHeight + 1);
    }
  }
}