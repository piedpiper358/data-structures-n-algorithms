

#include <iostream>
using namespace std;

int main()
{
    int n, n_st=0; 
    int st[100000][2];
    cin >> n;
    int number;
    cin >> number;
    st[0][0]=st[0][1]=number;
    for (int i = 0; i < n-1; i++)
    {
        cin >> number;
        if(number==st[n_st][0]-1)
        {
            st[n_st][0]=number;
            if(n_st>0 && st[n_st][0]==st[n_st-1][1]+1)
            {
                st[n_st-1][1]=st[n_st][1];
                n_st--;        
            }   
        }
        else
        if(number==st[n_st][1]+1)
            st[n_st][1]=number;
        else
        {
            n_st++;
            st[n_st][0]=st[n_st][1]=number;         
        }   
    }
 
    (n_st==0 && st[0][0]==1 && st[0][1]==n) ? (cout << "Not a proof\n") : ( cout << "Cheater\n");
    return 0;
}