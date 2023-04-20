#include <iomanip>
#include <limits>

#include "Node.h"

#define COUNT 10

class BST {
public:
  BST();
  ~BST();
  void insertKey(int newKey);
  bool hasKey(int searchKey);
  std::vector<int> inOrder();
  int getHeight();
  void prettyPrint();
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
  void prettyPrintHelper(Node *root, int h, int w, int countSpaceLeft,
                         int countSpaceRight);
  std::vector<std::vector<int>> twoD;
  void prettyPrintLeft(Node *root, int h, int w, int countSpaceLeft);
  void prettyPrintRight(Node *root, int h, int w, int countSpaceLeft,
                        int countSpaceRight);
  void print2D(int row, int col);
  std::vector<int> widthVector;
  int count = 0;
  int findIndex(int key);
  void levelOrderTrans(Node *root, int level, int depth);
  void fill2DVector(int row, int col);
  int getWidth(Node *root, int level);
};

void BST::fill2DVector(int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      std::vector<int> vec(col, std::numeric_limits<int>::max());
      twoD.push_back(vec);
    }
  }
}
void BST::print2D(int row, int col) {
  //   for (int j = 0; j < col; ++j) {
  std::cout << std::setfill('-') << std::setw((5 * col) + 1) << "" << std::endl;
  //   }
  std::cout << std::setfill(' ');

  //   std::cout << std::endl;
  for (int i = 0; i < row; ++i) {

    for (int j = 0; j < col; ++j) {
      //   std::string content;
      if (twoD.at(i).at(j) == std::numeric_limits<int>::max()) {
        // content = "|    |";
        std::cout << "|" << std::setw(5);

      } else {
        // content = ;
        std::cout << "|" << std::setw(4) << twoD.at(i).at(j);
      }
      //   std::cout << twoD.at(i).at(j) << " ";
    }
    std::cout << "|";
    std::cout << std::endl;

    std::cout << std::setfill('-') << std::setw((5 * col) + 1) << ""
              << std::endl;
    //   }
    std::cout << std::setfill(' ');
  }
}

void BST::prettyPrintLeft(Node *root, int h, int w, int countSpaceLeft) {
  if (root == NULL)
    return;
  //   int h = getHeightHelper(root);
  int row = getHeight() - h;
  std::cout << "H : " << row << std::endl;

  int col = 4 - w;

  prettyPrintLeft(root->left, --h, --w, --countSpaceLeft);
  twoD.at(row).at(countSpaceLeft) = root->data;
}

// void BST::prettyPrintRight(Node *root, int h, int w, int countSpaceLeft,
//                            int countSpaceRight) {

//   if (root == NULL)
//     return;

//   //   int h = getHeightHelper(root);
//   //   std::cout << "H : " << h << std::endl;
//   int row = getHeight() - h;

//   int col = 4 - w;

//   twoD.at(row + 1).at(countSpaceLeft + countSpaceRight) = root->data;
//   prettyPrintRight(root->right, --h, --w, countSpaceLeft, ++countSpaceRight);
// }

int BST::findIndex(int key) {
  for (int i = 0; i < widthVector.size(); ++i) {
    if (widthVector.at(i) == key) {
      return i + 1;
    }
  }
  return 0;
}
void BST::levelOrderTrans(Node *root, int level, int depth) {

  if (root == nullptr) {
    return;

  } else if (level == 1) {
    // std::cout << "level : " << depth << " data : " << root->data <<
    // std::endl;

    /// find the index of root>dataa
    int index = findIndex(root->data);
    // std::cout << "DAta : " << root->data << "  col: " << index
    //           << "row : " << depth << std::endl;
    twoD.at(depth - 1).at(index - 1) = root->data;

  } else {

    // <left><root><right>
    // std::cout << " order : " << root->data << std::endl;
    levelOrderTrans(root->left, level - 1, depth);
    levelOrderTrans(root->right, level - 1, depth);

    // return;
  }
}

void BST::prettyPrintHelper(Node *root, int h, int w, int countSpaceLeft,
                            int countSpaceRight) {
  //
  //
  //

  inOrder();

  for (int i = 0; i < widthVector.size(); ++i) {

    // std::cout << widthVector.at(i) << " ";
  }
  //   std::cout << std::endl;

  int treeHeight = getHeightHelper(root);

  for (int i = 1; i <= treeHeight; i++) {
    // std::cout << " Level : " << i;
    int depth = i;
    levelOrderTrans(root, i, depth);
  }

  //   std::cout << std::endl;

  //   prettyPrintLeft(root, h, w, countSpaceLeft);
  //   prettyPrintRight(root->right, h, w, countSpaceLeft, countSpaceRight);

  //   if (root == NULL)
  //     return;
  //   //   int h = getHeightHelper(root);
  //   //   std::cout << "H : " << h << std::endl;
  //   int row = getHeight() - h;

  //   int col = 4 - w;

  //   //   prettyPrintHelper(root->left, --h, --w, --countSpace);
  //   //   twoD.at(row).at(countSpaceLeft) = root->data;

  //   twoD.at(row).at(countSpaceRight) = root->data;
  //   prettyPrintHelper(root->right, --h, --w, countSpaceLeft,
  //   ++countSpaceRight);

  //   std::cout << " Data : " << root->data << " space " << countSpace <<
  //   std::endl;

  //   std::cout << "Row : " << row << std::endl;

  //   std::cout << "Col: " << col << std::endl;
}

void BST::prettyPrint() {

  int maxWidth = getWidth(root, 1);
  //   for (int i = 1; i <= getHeight(); i++) {
  // std::cout << " Level : " << i;
  //     int countNodes = 0;
  //     int width = getWidth(root, i);
  //     if (width > maxWidth)
  //       maxWidth = width;
  //   }
  //   std::cout << " width : " << maxWidth << std::endl;
  fill2DVector(getHeight(), maxWidth);
  prettyPrintHelper(root, getHeight(), 4, 3, 0);
  print2D(getHeight(), maxWidth);
}

int BST::getWidth(Node *root, int maxWidth) {
  if (root == nullptr) {
    return --maxWidth;

  } else {
    // std::cout << " inside : " << maxWidth << std::endl;
    return getWidth(root->left, ++maxWidth) + getWidth(root->right, 1);

    // int width =
    //     getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
    // return width;
    // return;
  }
}

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
    widthVector.push_back(root->data);

    inOrderHelper(root->right);

    return inOrderVector;
  }
}

std::vector<int> BST::inOrder() { return inOrderHelper(this->root); }