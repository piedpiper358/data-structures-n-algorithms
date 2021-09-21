
#include <iostream>
using namespace std;

inline int incIndex(int i, int n);


int main(int argc, char *argv[]) {
    int n, k;
    cin >> n;
    cin >> k;

  
    bool arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=true;
    }
  
   


    int index = k-1;
    
    for(int i=0; i<n; i++)
    {
       
        cout << index+1 << " ";
        arr[index]=false;
        if(i==n-1) break;
        for(int j=0; j<k; j++)
        {
            do {
                index=incIndex(index, n); 
            } while(arr[index]!=true);
        }
    }
    cout << "\n";
}


inline int incIndex(int i, int n)
{
    if(i >= 0 && i < n-1) return ++i;
    if(i == n-1) return 0;
}