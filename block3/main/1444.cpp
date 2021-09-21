
#include <iostream>
#include <sstream>

using namespace std;

void elephpotamus(int n, int *a);
int delete_pair(stringstream &cout, int *array, int a, int b);
int quarter(dot init, dot i);


struct dot
{
    short int x;
    short int y;
    short int index;
};

int main() {

    int T;
    cin >> T;
    dot array[T];
    for (int i=0; i<T; i++){
        cin >> array[i].x;
        cin >> array[i].y;
        array[i].index=i+1;
    }

    elephpotamus(T, array);


  return 0;
}

void elephpotamus(int n, dot *array) {

    stringstream ss;

    dot init_dot = array[0];

    отсортироватьточки по углу наклона 

    angle = (y2-init_dot.y)/(x2-init_dot.x);


    boolean quart[4]={false, false, false, false};

    for(int i=0; i<n; i++ )
    {
        quart[quarter(init_dot, array[i])]=true;

    }


 
  

  // ss.close(); // закрываем файл
}

int delete_pair(stringstream &out, dot *array, int a, int b) {

  

    return quantity;
}


int quarter(dot init, dot i)
{
    if(i.x-init.x>0)
    {
        if(i.y-init.y>0)
            return 1;
        else
            return 4;
    }
    else
    {
        if(i.y-init.y>0)
            return 2;
        else
            return 3;
    }
}

void sort(int quarter, int n, dot *array)
{
    
     for(int i=0; i<n; i++)
    {
        

    }


}



/*void merge_sort(int * a, int * aux, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(a, aux, l, m);
        merge_sort(a, aux, m + 1, r);
        merge(a, aux, l, m, r);
    }
}

void sort(int * a, int N) {

    int * aux = new int[N];
    for (int k = 0; k < N; ++k) aux[k] = a[k];
    merge_sort(a, aux, 0, N-1);
    delete[] aux;
}
void merge(int * a, int * aux, int l, int m, int r) {

    int i = l;

    int j = m + 1;
    for (int k = l; k <= r; ++k) aux[k] = a[k];
    for (int k = l; k <= r; ++k) {
    if (i > m) { a[k] = aux[j++]; continue; }
    if (j > r) { a[k] = aux[i++]; continue; }
    if (aux[j] < aux[i]) { a[k] = aux[j++]; }
    else
    { a[k] = aux[i++]; }

    }
}*/

