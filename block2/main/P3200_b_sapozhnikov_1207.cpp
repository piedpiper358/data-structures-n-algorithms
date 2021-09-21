#include <cfloat>
#include <climits>
#include <iostream>
using namespace std;

struct dot {
  long x, y;
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
    cin >> p[i].x >> p[i].y;
  }
  median(n);
}

int median(int n) {
  minx = LONG_MAX;
  miny = LONG_MAX;

  for (size_t i = 0; i < n; i++) {
    if (p[i].y < miny || (p[i].y == miny && p[i].x < minx)) {
      minp = i, minx = p[i].x, miny = p[i].y;
    }
  }

  for (size_t i = 0; i < n; i++) {
    if (p[i].x == minx)
      ctg[i] = 0;
    else if (p[i].y == miny)
      ctg[i] = FLT_MAX;
    else
      ctg[i] = (float)(p[i].x - minx) / (p[i].y - miny);

    pos[i] = i;
  }

  flip(minp, n - 1);
  hn = n - 1;
  heapsort();

  cout << minp + 1 << " " << pos[n / 2 - 1] + 1 << "\n";
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