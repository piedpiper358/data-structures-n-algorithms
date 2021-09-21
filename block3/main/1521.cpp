
#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

struct soldier {
  int num;
  soldier* next;
};

inline soldier *NewSoldier(int num, soldier* next = NULL);
inline void start(soldier* prev, soldier* first, int n, int k);


int main(int argc, char *argv[]) {

    int n, k;
    //cin >> n >> k;
    scanf("%i %i", &n, &k);
  
    soldier *next, *first, *prev;

    first = prev = NewSoldier(n);

    for (size_t i = 1; i < n; i++) {
    
        next = NewSoldier(i, prev);
        prev->next = next;
        prev = next;

    }
    
    prev->next = first;
    for(int i=0; i<k-1; i++)
    {
        first = first->next;
    }
    
    start(first, first->next, n, k);

}

inline soldier *NewSoldier(int num, soldier* next) {
  soldier *newSoldier = new soldier;
  newSoldier->next = next;
  newSoldier->num = num;
  return newSoldier;
}



inline void start(soldier* prev, soldier* first, int n, int k)
{
    stringstream ss;
    for(int i=0; i<n; i++)
    {
        ss << first->num << " ";
        //printf()
        prev->next = first->next;

        for(int i=0; i<k-1; i++)
        {
            first = first->next;
            prev=first;
        }
        first = first->next;
        
    }
    ss << "\n";
    cout << ss.str();
}