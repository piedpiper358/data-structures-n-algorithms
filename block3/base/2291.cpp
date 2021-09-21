#include <iostream>

using namespace std;

struct NODE { // Описание элемента списка
    int Number;
    NODE *Next;
};

// Прототипы функций
NODE * MakeList();
void DeleteDuplicates(NODE*);

int main(){
   NODE *Head = MakeList();
   DeleteDuplicates(Head);
   cout << "Head";
   for(NODE *p=Head->Next; p!=NULL; p=p->Next){
	cout << " -> " << p->Number;
   }
   return 0;
}

// Эта функция создаёт список для опробования алгоритма
NODE * MakeList(){
int Arr[]={2,3,3,3,5,5,8,9,9,9};
// Создание головы
NODE *Head=new NODE,*x;
Head->Next=NULL; //Явно указываем на NULL
Head->Number=-999; // Условное!! значение головы
// Создание собственно списка
int n=sizeof(Arr)/sizeof(int);
for (int i = 0; i < n; i++) {
	x=new NODE;
	x->Number=Arr[i];
	// вставляем новый узел вслед за головой
	x->Next=Head->Next;
	Head->Next=x;
}
return Head;
}

//===========Не удаляйте и не изменяйте эту строку
// А это функция которую вы должны написать
void DeleteDuplicates(NODE *Head){
  NODE* prev = Head;
  while(Head->Next!=NULL){
    Head=Head->Next;
    if(prev->Number == Head->Number)
      prev->Next=Head->Next; 
    else
      prev = Head;
  }
// Удалить дубликаты
// ............................
}
//===========Не удаляйте и не изменяйте эту строку 