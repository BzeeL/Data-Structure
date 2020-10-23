#pragma
#include <iostream>
using namespace std;

struct List {
  int value;
  List *next;
};

List *initList(int num) {
  List *Node = new List;
  Node->next = nullptr;
  Node->value = num;

  return Node;
}

void printList(const List *tempNode) {
  int index = 1;
  if (tempNode->next != nullptr) {  //если не один узел
    while (tempNode) {
      cout << "#" << index << " " << tempNode->value << endl;
      tempNode = tempNode->next;
      index++;
    }
  } else {  //иначе 1 узел
    cout << "#1"
         << " " << tempNode->value << endl;
  }
  cout << endl;
}

int sizeList(const List *Node) {
  int size = 1;
  if (Node->next != nullptr) {
    while (Node->next != nullptr) {
      Node = Node->next;
      size++;
    }
    return size;
  } else {
    return 1;
  }
}

void push_back(List *Node, int num) {
  while (Node->next != nullptr) {
    Node = Node->next;
  }
  List *NewNode = initList(num);
  Node->next = NewNode;
}

void pop_back(List *Node) {
  int size = sizeList(Node);
  int index = 1;
  List *prev;

  if (!(size < 2)) {
    while (Node->next->next != nullptr) {
      Node = Node->next;
    }
    prev = Node;
    Node = Node->next;
    delete Node;
    prev->next = nullptr;
  } else {
    cout << "You can't delete node, cause Node's size = 1 !" << endl;
  }
}

void addTo(List *Node, int pos, int num) {
  int size = 0;
  List *temp{Node};
  List *posPtr{Node};
  while (temp) {
    size++;
    if (pos == size) {
      posPtr = temp;  // posPtr ссылка на нужную позицию
    }
    temp = temp->next;
  }

  cout << "Size list: " << size << endl;

  if (pos <= size) {
    temp = Node;
    int index{1};
    while (index != pos) {
      temp = temp->next;
      index++;
    }
    List *add = initList(num);
    add->next = temp->next;
    temp->next = add;

  } else {  //если pos>size
    cout << "I can't imput your data, cause pos>max\n";
  }
}

// Not Work!
void reverse(List *Node) {
  int size = sizeList(Node);
  List *temp = new List;
  temp = Node;
  List **pArr = new List *[size];
  for (int index = 0; index < size; index++) {
    pArr[index] = temp;
    if (temp) {
      temp = temp->next;
    }
  }

  cout << "Before reverse\n";
  for (int index = 0; index < size; index++) {  // вывод ревёрса
    cout << "Node " << index + 1 << " value=" << pArr[index]->value << "("
         << pArr[index] << ")"
         << " next: " << pArr[index]->next << "\n";
  }
  cout << "\n";

  // for (int index = size-1; index >0 ; index--) {
  //	pArr[index]->next = pArr[index - 1];
  //}
  // pArr[0]->next = nullptr;
  //

  cout << "After reverse\n";
  int num = 0;
  for (int index{0}; index < size; index++) {  // вывод ревёрса
    cout << "Node " << index + 1 << " value=" << pArr[index]->value
         << " next: " << pArr[index]->next << "\n";
  }

  cout << "DEBUG\n";
  cout << "First el pArr " << pArr[0]->value << "   " << pArr[0]->next << endl;

  // Node->value = pArr[size-1]->value;
  //	Node->next = pArr[size - 1];
  temp = Node;
  int index = 1;
  while (temp->next != nullptr) {
    temp->value = pArr[size - index]->value;
    temp->next = pArr[size - index];
    cout << "Node: " << temp->value << "   " << temp->next << endl;
    index++;
    temp = temp->next;
  }
  temp->value = pArr[0]->value;
  temp->next = nullptr;
  cout << "Node after change " << Node->value << "   " << Node->next << endl;

  // for (int index = size-1; index >0 ; index--) {
  //	temp->value = pArr[index]->value;
  //	temp->next = pArr[index - 1];
  //	cout << temp->value << "   " << temp->next << endl;
  //	temp = temp->next;

  //}

  // for (int index = size - 1; index > 0; index--) {
  //	Node->value = pArr[index]->value;
  //	Node->next	= pArr[index]->next;
  //	cout << temp->value << "   " << temp->next << endl;
  //	temp = temp->next;

  //}
}

List *reverse_List(List *head) {
  List *prev = nullptr;
  List *temp = head;
  while (temp != nullptr) {
    List *nextNode = new List;
    nextNode = temp->next;
    temp->next = prev;
    prev = temp;
    temp = nextNode;
  }
  return prev;
}

//  ревёрс
int main() {
  List *myNumbers = initList(2);
  push_back(myNumbers, 4);
  reverse(myNumbers);
  // printList(myNumbers);

  // for(;;){
  //	cout << "1. Print list \n" << "2. List's size\n" << "3. Push to back\n"
  //		<< "4. Pop back element\n" << "5. Add To\n" << "6. Reverse list"
  //<< endl;
  //
  //	int action;
  //	cin >> action;
  //	switch (action)
  //	{
  //	case 1:
  //		system("cls");
  //		printList(myNumbers);
  //		cout << "\n\n";
  //		break;
  //	case 2:
  //		system("cls");
  //		cout << "List's size is " << sizeList(myNumbers);
  //		cout << "\n\n";
  //		break;
  //	case 3:
  //		system("cls");
  //		cout << "What is number you would like add to back?" << endl;
  //		int numCase_3;
  //		cin >> numCase_3;
  //		push_back(myNumbers, numCase_3);
  //		cout << "Done!\n\n";
  //		break;
  //	case 4:
  //		system("cls");
  //		pop_back(myNumbers);
  //		cout << "Done!\n\n";
  //		break;
  //	case 5:
  //		cout << "What is number?\n";
  //		int numCase_5, posCase_5;
  //		cin >> numCase_5;
  //		cout << "Where number is place?" << endl;
  //		cin >> posCase_5;
  //		addTo(myNumbers, posCase_5, numCase_5);
  //		cout << "Done!\n";
  //		break;
  //	case 6:
  //		break;
  //	default:
  //		system("cls");
  //		break;
  //	}
  //}

  return 0;
}
