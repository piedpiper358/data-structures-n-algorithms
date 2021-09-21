#include <iostream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

const int M=8; // длина массива, отводимого под очередь

// прототипы функций
bool PutInQueue(int);
int TakeFromQueue();
void debugging();
void test();
void printqueue();

// Описание структуры очередь
struct QUEUE {
   int Q[M]; // массив, используемый для хранения очереди
   int F; // ИНДЕКС первого элемента очереди
   int L; // ИНДЕКС ПОСЛЕДНЕГО
   bool IsEmpty; // признак пустой очереди
};
QUEUE T;

int main() {
// задание начального состояния очереди
T.F=0;
T.L=-1;
T.IsEmpty=true;
   
// ВНИМАНИЕ!!!
// Для отладки программы используйте процедуру debugging()
// Тестирование происходит с помощью процедуры test()
//debugging(); // При отправке решения на ipc закомментировать
test();      // При отправке решения на ipc раскомментировать 
return 0;
}

bool PutInQueue(int x) {
// НАПИШИТЕ ЭТУ ФУНКЦИЮ
// поместить элемент x в очередь
// возвращает истину в случае успеха
  if (T.L < M-1) {
    T.L++;
    T.Q[T.L] = x;
    T.IsEmpty = false;
    return true;
  } else {
    return false;
  }
}

//----------------------------------------------
int TakeFromQueue() {
// НАПИШИТЕ ЭТУ ФУНКЦИЮ
// Взять элемент из очереди T
// функция возвращает взятый из очереди элемент
// если очередь пуста, то возвращается INT_MAX (defined в limits.h)
  if (!T.IsEmpty) {
    int ret = T.Q[T.F];
    T.F++;
    if (T.L < T.F) {
      T.IsEmpty = true;
    }
    return ret;
  } else {
    return INT_MAX;
  }
}

void debugging(){ // Процедура для отладки
   int k = 0;
   char c;
   do {
      system("cls");
      cout << "1. Добавить элемент в очередь\n";
      cout << "2. Взять элемент из очереди\n";
      cout << "3. Напечатать очередь\n";
      cout << "4. Выход\n\n";
      //cin.get(c);
      cin >> c;
      switch (c) {
      case '1':
         system("cls");
         cout << "Input int element\n";
         int x;
         cin >> x;
         if (!PutInQueue(x)) {
            cout << "Queue is overflow\n\n";
         system("pause");
         }
         break;
      case '2': // Взятие очереди
         system("cls");
         k = TakeFromQueue();
         if (k!=INT_MAX) cout << "Value = " << k << endl;
         else cout << "Queue is empty\n\n";
         system("pause");
         break;
      case '3': // Вывод очереди на экран
         system("cls");
         printqueue();
         system("pause");
         break;
      case '4':
         return;
         break;
      default:
         continue;
      }
   } while (true);
}
void printqueue(){
   if (T.IsEmpty) {
      cout << "Queue is empty\n";
      //system("pause");
      return;
   }
   cout << "Start: ";
   if(T.F<T.L){
      for (int i = T.F; i != T.L+1; i++) {
         cout << T.Q[i] << " < ";
      }
   } else {
      for (int i = T.F; i != T.L; i++) {
         if (i==M) {
            i=0;
         }
         cout << T.Q[i] << " < ";
      }
      cout << T.Q[T.L] << " < ";
   }
   cout << "End\n";
}

void test(){
   int x;
   for(int i = 0; i < M+1; i++){
      cin >> x;
      if(!PutInQueue(x)) cout << "overflow" << endl;
   }
   printqueue();
   
   for(int i = 0; i < M/2; i++){
      cout << TakeFromQueue() << ", ";
   }
   cout << endl;
   for(int i = 0; i < 1+M/2; i++){
      cin >> x;
      if(!PutInQueue(x)) cout << "overflow" << endl;
   }
   printqueue();
   for(int i = 0; i < M+1; i++){
      cout << TakeFromQueue() << ", ";
   }
} 