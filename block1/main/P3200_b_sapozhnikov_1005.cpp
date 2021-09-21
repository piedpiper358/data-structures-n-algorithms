
#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

long heaps(vector<long> vec);
bool comp (long i,long j) { return (i>j); }

int main(){
  long N;
  cin >> N;
  long array[N];
  for (long i=0; i<N; i++){
    cin >> array[i];
  }
  std::vector<long> myvector (array, array+N);


  std::sort (myvector.begin(), myvector.end(), comp);


  cout << heaps(myvector);
  cout << "\n";

}


long heaps(vector<long> vec){
  long first_heap = 0;
  long second_heap = 0;

  for (std::vector<long>::iterator it=vec.begin(); it!=vec.end(); ++it){

    if(first_heap > second_heap){
      second_heap+=*it;

    }
    else{
      first_heap+=*it;
    }
  }

  return abs(first_heap - second_heap);
}