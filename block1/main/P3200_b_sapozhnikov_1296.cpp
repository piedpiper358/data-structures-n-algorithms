#hiper
#include <iostream>
using namespace std;

int hyper(int *array, int num);

int main(){
  int T;
  cin >> T;
  int array[T];
  for (int i=0; i<T; i++){
    cin >> array[i];
  }

  cout << hyper(array, T) << "\n";

  
  return 0;
}


int hyper(int *array, int num){

  int max_sum = 0;
  int sum = 0;

  for (int i=0; i<num; i++){
    if(sum>=0)
    {
      sum+=array[i];
    }
    else
    {

      if(array[i]>0)
      {
        sum=array[i];

      }
    }
    if(sum>max_sum)
    {
      max_sum=sum;
    }
  }



  return max_sum;
}