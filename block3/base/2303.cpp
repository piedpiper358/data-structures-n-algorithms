#include <iostream>
#include <string>
#define MAXSTACKSIZE 100

using namespace std;

bool IsStringRight(string&); // прототип функции проверки

struct STACK{ // структура СТЕК
   char A[MAXSTACKSIZE]; // контейнер элементов
   int v; // индекс вершины стека
};

STACK S;

int main(){
   // Наальное состояние = Вершина стека = 0
   S.v = 0;
   
   string str;
   cin >> str; // ввод строки   
   if(IsStringRight(str)){
      cout << "String is right" << "\n";
   }
   else {
      cout << "String is wrong" << "\n";
   }   
   return 0;
}

bool IsStringRight(string& str){
// НАПИШИТЕ ЭТУ ФУНКЦИЮ
// ВОЗВРАЩАЕТ ИСТИНУ В СЛУЧАЕ, ЕСЛИ СТРОКА "ПРАВИЛЬНАЯ"
// ВОЗВРАЩАЕТ ЛОЖЬ, ЕСЛИ СТРОКА "НЕ ПРАВИЛЬНАЯ"
   for(int i=0; i < str.length(); i++)
   {
      if(str[i]=='(' || str[i]=='{' || str[i]=='[')
         S.A[S.v++]=str[i];
      
      if(str[i]==')' || str[i]=='}' || str[i]==']'){
         if(S.v--==0) return false;
         if(str[i]==')' && S.A[S.v]!='(' || str[i]=='}' && S.A[S.v]!='{' || str[i]==']' && S.A[S.v]!='[')
            return false;
      }
   }
   if (S.v!=0)
      return false;
   else
      return true;
} 
