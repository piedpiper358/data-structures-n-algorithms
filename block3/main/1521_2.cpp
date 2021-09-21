
#include <iostream>
using namespace std;



bool* makeRange(int n, int k);
inline int start(bool* arr, int n, int k);
inline int incIndex(int i, int n);


int main(int argc, char *argv[]) {
    int n, k;
    cin >> n;
    cin >> k;

    cout << n << k;


    bool* arr = new bool[n];
    for(int i=0; i<n; i++)
    {
        cout << i;
        arr[i]=true;
    }

    //bool* b = makeRange(n, k);
    //cout << incIndex(n-1, n);
    //cout << "fifnish";
    start(arr, n, k);

    

}

inline int start(bool* arr, int n, int k)
{
    int index = 0;
    index=incIndex(index, n);
    index=incIndex(index, n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            do {
                //index=incIndex(index, n); 
            } while(arr[index]==true);
        }
        cout << index+1 << " ";
        arr[index]=false;
    }
    cout << "\n";
    return 0;
}

inline int incIndex(int i, int n)
{
    //cout << i << " "; 
    if(i >= 0 && i < n-1) return ++i;
    if(i == n-1) return 0;
}