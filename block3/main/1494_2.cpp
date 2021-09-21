
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {

  int n, x=0, p=0;
  cin >> n;
  int st[n][2];
  cin >> x;
  st[p][0]=st[p][1]=x;

  for (size_t i = 1 ; i < n; i++) 
  {
    cin >> x;

    if(x == st[p][0]-1){
      st[p][0]=x;
      if(p>0 && st[p-1][1]+1 == st[p][0]){
        st[p-1][1]=st[p][1];
        p--;
      }   
    }
    else
      if(x == st[p][1]+1){
        st[p][1]=x;
      }
      else{
        p++;
        st[p][0]=st[p][1]=x;
      }
  }   
  if(p==0 && st[p][0]==1 && st[p][1]==n)
    cout << "Not a proof";
  else
    cout << "Cheater";
}
  


