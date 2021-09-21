
#include <cstdlib>
#include <iostream>
using namespace std;

const char* visits(long long *x, long long n);


int main(int argc, char *argv[]) {

  long long n;
  cin >> n;
  long long x[n];

  for (size_t i = 0; i < n; i++) {
    cin >> x[i];
  }
  cout << visits(x, n) << "\n";
}

const char* visits(long long *x, long long n) {

  long long min = x[0];
  int y[n];
  int isCheater=0;
  std::stack stack = new std::stack;

for (size_t i = 0; i < n; i++) 
  {
    y[i]=0;
  }


  for (size_t i = 0; i < n; i++) 
  {
    if(x[i]>n)
      {
        return "Cheater";
      }

    y[x[i]-1]++;
    if(x[i]<min)
    {
      if(x[i]-min<=-2)
      {
        return "Cheater";
      }
      min=x[i];
    }
  }   
  for (size_t i = 0; i < n; i++) 
  {
    //cout << y[i];
    if(y[i]!=1)
    {

      return "Cheater";
    }

  }


     return "Not a proof";

  };


 



 const char* visits(long long *x, long long n) {

  //long long min = x[0];
  //long long max = x[0];
  long long post = x[0];

  std::stack<long long> stack;
  
  //long long min = x[0];
  int y[n];
  int isCheater=0;
  //std::stack stack = new std::stack;

  for (size_t i = 0; i < n; i++) 
  {
    y[i]=0;
  }

  y[x[0]-1]=1;
  stack.push(x[0])
  if(x[0]>n)
    {
      return "Cheater";
    }



  for (size_t i = 1; i < n; i++) 
  {
    if(x[i]>n)
    {
      return "Cheater";
    }
    y[x[i]-1]++;


   if(x[i]>post && abs(x[i]-post)>1)
    {
      stack.push(post);
     //max=x[i];
    }

    if(x[i]<post)
    {
      if(abs(x[i]-post)>1)
      {
        while(!stack.empty())
        {
          long long var = stack.top();
          stack.pop();
          if(x[i]-var==-1)
          {
            break;
          }
          if(stack.empty())
          {
            return "Cheater";
          }

        }
        
      }
    }



    post=x[i];
  }   
  

  for (size_t i = 0; i < n; i++) 
  {
    //cout << y[i];
    if(y[i]!=1)
    {

      return "Cheater";
    }

  }

     return "Not a proof";

};