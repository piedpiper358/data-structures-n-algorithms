
#include <cstdlib>
#include <iostream>
using namespace std;

long long visits(long long *x, long long *y, long long n);

int cmp(const void *a, const void *b) {
  long long f = *((long long *)a);
  long long s = *((long long *)b);

  if (f > s)
    return 1;
  if (f < s)
    return -1;

  return 0;
}

int main(int argc, char *argv[]) {

  long long n;
  cin >> n;
  long long x[n], y[n];

  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout << visits(x, y, n) << "\n";
}

long long visits(long long *x, long long *y, long long n) {

  long long l = 0;

  qsort(x, n, sizeof(long long), cmp);
  qsort(y, n, sizeof(long long), cmp);

  for (size_t i = 0; i < n - 1; i++) {
    l += (x[i + 1] - x[i] + y[i + 1] - y[i]) * (i + 1) * (n - i - 1);
  }

  return l * 2 / (n * (n - 1));
}