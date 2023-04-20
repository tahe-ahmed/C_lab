
#include <iostream>
#include <vector>

class Node {
public:
  int data;
  Node *left;
  Node *right;
};

class BST {
public:
  BST();
  ~BST();
  void insertKey(int newKey);
  bool hasKey(int searchKey);
  std::vector<int> inOrder();
  int getHeight();
  // Node *getNodeRoot() { return this->root; }

private:
  std::vector<int> inOrderVector;
  Node *root;
  void freeMemory(Node *root);
  Node *createNodeRoot(Node *rootPtr, int data);
  Node *createNode(int data);
  int getHeightHelper(Node *root);
  std::vector<int> inOrderHelper(Node *root);
  bool hasKeyHelper(Node *root, int searchKey);
  void insertKeyHelper(Node **root, int newKey);
  Node *constructorHelper();
};

BST::BST() { constructorHelper(); }

Node *BST::constructorHelper() {
  return root;
  // this->root = createNodeRoot(root, val);
}

BST::~BST() { freeMemory(this->root); }

Node *BST::createNodeRoot(Node *rootPtr, int data) {
  rootPtr = new Node();
  rootPtr->data = data;
  rootPtr->left = rootPtr->right = NULL;
  return rootPtr;
}

Node *BST::createNode(int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void BST::freeMemory(Node *root) {

  if (root == nullptr) {
    return;
  } else {
    freeMemory(root->left);
    freeMemory(root->right);
    delete root;
  }
}

void BST::insertKeyHelper(Node **root, int newKey) {
  if (*root == nullptr) { /// EMPYT tree
    *root = createNode(newKey);
    // this->root = createNode(newKey);
    return;
  }

  if (newKey < (*root)->data) {

    insertKeyHelper(&(*root)->left, newKey);

  } else {

    insertKeyHelper(&(*root)->right, newKey);
  }
}
void BST::insertKey(int newKey) { insertKeyHelper(&(this->root), newKey); }

bool BST::hasKeyHelper(Node *root, int searchKey) {
  if (root == nullptr) {
    return false;
  }

  if (root->data == searchKey) {
    return true;
  }

  if (searchKey <= root->data) {
    return hasKeyHelper(root->left, searchKey);
  } else {
    return hasKeyHelper(root->right, searchKey);
  }
}
bool BST::hasKey(int searchKey) { return hasKeyHelper(this->root, searchKey); }

int BST::getHeightHelper(Node *root) {
  if (root == nullptr)
    return 0;
  else {
    int leftHeight = getHeightHelper(root->left);

    int rightHeight = getHeightHelper(root->right);

    leftHeight = leftHeight + 1;
    rightHeight = rightHeight + 1;

    return leftHeight > rightHeight ? leftHeight : rightHeight;
  }
}
int BST::getHeight() { return getHeightHelper(this->root); }

std::vector<int> BST::inOrderHelper(Node *root) {
  if (root == nullptr) {
    return inOrderVector;

  } else {

    // <left><root><right>
    // std::cout << " order : " << root->data << std::endl;
    inOrderHelper(root->left);

    inOrderVector.push_back(root->data);

    inOrderHelper(root->right);

    return inOrderVector;
  }
}
std::vector<int> BST::inOrder() { return inOrderHelper(this->root); }

int main() {

  int inputNum;
  int toSearchNum;

  Node *root;
  root = nullptr;
  BST *bst;

  std::cout << "Enter the numbers to be stored (end with a letter): ";
  std::cin >> inputNum;

  if (std::cin) {

    bst = new BST();

    // root = bst->getNodeRoot();
    bst->insertKey(inputNum);

    std::cin >> inputNum;
    while (std::cin) {
      bst->insertKey(inputNum);
      std::cin >> inputNum;
    }
  } else {
    bst = new BST();
  }

  std::cin.clear();
  std::cin.ignore(10000, '\n');

  std::cout << "Which number do you want to look up? ";
  std::cin >> toSearchNum;

  std::cout << toSearchNum
            << " is in the tree: " << (bst->hasKey(toSearchNum) ? "yes" : "no")
            << std::endl;

  std::cout << "The numbers in sorted order: ";
  std::vector<int> nodeVector = bst->inOrder();
  for (int i = 0; i < nodeVector.size(); ++i) {
    std::cout << nodeVector.at(i) << " ";
  }
  std::cout << std::endl;

  int height = bst->getHeight();
  std::cout << "Height of the tree: " << height << std::endl;

  delete bst;

  return 0;
}