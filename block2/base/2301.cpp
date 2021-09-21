#include <iostream>
#include <limits.h>

using namespace std;

struct Node {
  int Number;
  Node *Next;
};

Node *MakeList(int *, int);
Node *JoinTwoList(Node *, Node *);
Node *NewNode(int num = INT_MAX, Node *next = NULL);

int main() {
  int Arr1[] = {2, 3, 5, 9};
  int Arr2[] = {4, 6, 7, 11, 16};
  Node *Head1, *Head2;
  Head1 = MakeList(Arr1, sizeof(Arr1) / sizeof(int));
  Head2 = MakeList(Arr2, sizeof(Arr2) / sizeof(int));
  Node *Head = JoinTwoList(Head1, Head2);
  cout << "Head";
  for (Node *p1 = Head->Next; p1 != NULL; p1 = p1->Next) {
    cout << " -> " << p1->Number;
  }
  cout << "\n";
  return 0;
}

Node *JoinTwoList(Node *Head1, Node *Head2) {
  // Выполнить слияние списков с головами Head1 и Head2
  // Функция возвращает указатель на голову списка,
  // являющегося результатом слияния
  // ............................
  Head1 = Head1->Next, Head2 = Head2->Next;
  Node *Head = NewNode();
  Node *x = Head;

  while (Head1 != NULL && Head2 != NULL) {

    if (Head1->Number < Head2->Number) {
      x->Next = NewNode(Head1->Number, Head1->Next);
      Head1 = Head1->Next;
    } else {
      x->Next = NewNode(Head2->Number, Head2->Next);
      Head2 = Head2->Next;
    }
    x = x->Next;
  }
  if (Head1 == NULL) {
    while (Head2 != NULL) {
      x->Next = NewNode(Head2->Number, Head2->Next);
      Head2 = Head2->Next;
      x = x->Next;
    }
  } else {
    while (Head1 != NULL) {
      x->Next = NewNode(Head1->Number, Head1->Next);
      Head1 = Head1->Next;
      x = x->Next;
    }
  }

  return Head;
}

Node *NewNode(int num, Node *next) {
  Node *NewNode = new Node;
  NewNode->Next = next;
  NewNode->Number = num;
  return NewNode;
}

Node *MakeList(int Arr[], int n) {
  // Эта функция создаёт один список
  // Arr - массив чисел, которые должны быть помещены в список
  // n - их количество
  Node *Head = NewNode();
  Node *x = Head;
  // Создание собственно списка
  for (int i = 0; i < n; i++) {
    x->Next = NewNode(Arr[i], NULL);
    x = x->Next;
  }
  return Head;
}