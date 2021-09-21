
#include <iostream>
using namespace std;

long long LCD(long long, long long);

int main() {
  long long a, b;
  cin >> a >> b;
  cout << LCD(a, b);
  return 0;
}

long long LCD(long long a, long long b) {

  // Здесь должна быть реализована рекурсивная процедура
  // вычисления НОД по алгоритму Евклида

  if (a == 0 || b == 0) {
    return 1;
  }

  long long rest = a % b;

  if (rest == 0) {
    return b;
  } else {
    return LCD(b, rest);
  }
}
