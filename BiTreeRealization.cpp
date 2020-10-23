#include <iostream>
using namespace std;

int size = 0;
struct BinaryTree {
  int data;
  BinaryTree* leftPtr;
  BinaryTree* rightPtr;
};

BinaryTree* create(int data_tree) {
  BinaryTree* Node = new BinaryTree;
  ::size++;
  Node->data = data_tree;
  Node->leftPtr = nullptr;
  Node->rightPtr = nullptr;
  return Node;
}

void addElement(BinaryTree* tree, int element) {
  BinaryTree* temp = tree;
  BinaryTree* newNode = new BinaryTree;
  newNode->data = element;
  newNode->leftPtr = nullptr;
  newNode->rightPtr = nullptr;

  while ((element < temp->data && temp->leftPtr != nullptr) ||
         (element >= temp->data) && temp->rightPtr != nullptr) {
    if (element < (temp->data)) {
      temp = temp->leftPtr;
    } else if (element >= (temp->data)) {
      temp = temp->rightPtr;
    }
  }
  if (element < (temp->data))
    temp->leftPtr = newNode;
  else if (element >= (temp->data))
    temp->rightPtr = newNode;
}

void out(const BinaryTree* tree) {
  cout << tree->data << " ";
  while (tree->leftPtr != nullptr) {
    out(tree->leftPtr);
    break;
  }

  while (tree->rightPtr != nullptr) {
    out(tree->rightPtr);
    break;
  }
}

// void deleteElement(BinaryTree* tree, int element) {
//    bool founded = false;
//    bool notfounded = true;
//    BinaryTree* temp = tree;
//    while (element != temp->data) {
//
//        if (element < temp->data){
//            if (temp->leftPtr != nullptr)
//                temp = temp->leftPtr;
//            else
//                cout << "element isn't founded!\n";
//                break;
//        }
//
//        else if (element >= temp->data){
//                if (temp->rightPtr != nullptr)
//                    temp = temp->rightPtr;
//                else
//                    cout << "element isn't founded!\n";
//                    break;
//        }
//    }
//    if(element==temp->data)
//    delete temp;
//}

int main() {
  BinaryTree* tree = create(10);
  cout << "Root data: " << tree->data << endl;
  addElement(tree, 0);
  addElement(tree, 20);
  addElement(tree, -10);
  addElement(tree, -5);
  addElement(tree, 15);
  addElement(tree, 30);
  addElement(tree, -20);
  addElement(tree, -15);
  out(tree);

  return 0;
}
