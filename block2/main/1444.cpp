
/*#include <iostream>
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

float ctg(dot init, dot i){
    float ctg;
    if (p.x == minx)
      ctg = 0;
    else if (p.y == miny)
      ctg = FLT_MAX;
    else
      ctg = (float)(p.x - minx) / (p.y - miny);

  return ctg;
}

float tg(dot init, dot i){
    float tg;
    if (p.x == minx)
      tg = FLT_MAX;
    else if (p.y == miny)
      tg = 0;
    else
      tg = (float)(p.y - miny)/(p.x - minx);

  return ctg;
}



void sort(int quarter, int n, dot *array)
{
    
     for(int i=0; i<n; i++)
    {
        

    }


}*/






#include <cfloat>
#include <climits>
#include <iostream>
using namespace std;

struct dot {
  long x, y;
  float ctg;
  //int index;
};

int hn, n, minp, hx, hy;
long minx, miny;

int *pos;
dot *p;
float *ctg;

int median(int n);
void heapsort();
void sift(int pos);
void flip(int i, int j);

int main(int argc, char *argv[]) {
  cin >> n;
  pos = new int[n];
  p = new dot[n];
  ctg = new float[n];

  for (size_t i = 0; i < n; i++) {
    //cin >> p[i].x >> p[i].y;
  }
  median(n);
}

int median(int n) {

    stringstream ss;
    dot init_dot = array[0];
    ss << "1\n";


    dot* fir = new dot[][4];
    //dot* sec = new dot[];
   //dot* ther = new dot[];
    //dot* four = new dot[];
    int* num = new int[4]{0,0,0,0};

    for (size_t i = 1; i < n; i++) {
        dot Dot;
        cin >> Dot.x >> Dot.y;
        arr[quarter(init_dot, Dot)][num[quarter(init_dot, Dot)]++]=Dot;
    }

  for (size_t i = 1; i < n; i++) {
    if (p[i].x == init_dot.x)
      ctg[i] = 0;
    else if (p[i].y == init_dot.y)
      ctg[i] = FLT_MAX;
    else
      ctg[i] = (float)(p[i].x - init_dot.x) / (p[i].y - init_dot.y);

    pos[i] = i;
  }

  flip(minp, n - 1);
  hn = n - 1;
  heapsort();
  for (int i=0; i<T; i++){
        cout << array[i].index << "\n";
    }
  //cout << minp + 1 << " " << pos[n / 2 - 1] + 1 << "\n";
  return 0;
}

void heapsort() {
  int i;

  for (i = hn / 2; i >= 0; sift(i--))
    ;
  while (hn) {
    flip(0, hn-- - 1);
    sift(0);
  }
}

void flip(int i, int j) {
  long aux;
  float pp;

  aux = p[i].x; p[i].x = p[j].x; p[j].x = aux;
  aux = p[i].y; p[i].y = p[j].y; p[j].y = aux;
  aux = pos[i]; pos[i] = pos[j]; pos[j] = aux;
  pp = ctg[i]; ctg[i] = ctg[j]; ctg[j] = pp;
}

void sift(int pos) {
  int minpos = pos, son;

  do {
    son = 2 * pos + 1;
    if (son < hn && ctg[son] < ctg[minpos])
      minpos = son;

    son = 2 * pos + 2;
    if (son < hn && ctg[son] < ctg[minpos])
      minpos = son;

    if (pos == minpos)
      break;

    flip(pos, minpos);
    pos = minpos;
  } while (1);
}



int quarter(dot init, dot i)
{
    if(i.x-init.x>0)
    {
        if(i.y-init.y>0)
            return 0;
        else
            return 3;
    }
    else
    {
        if(i.y-init.y>0)
            return 1;
        else
            return 2;
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