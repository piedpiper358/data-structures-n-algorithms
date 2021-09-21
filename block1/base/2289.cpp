#include <cmath>
#include <iostream>
using namespace std;

double Power(double, int);

int main() {
  double X;
  int N;
  cin >> X >> N;
  cout << Power(X, N);
  return 0;
}

double Power(double X, int N) {

  // Здесь должна быть реализована рекурсивная процедура
  // вычисления значение выражения X^N

  if (N > 0) {

    if (N % 2 == 0) {
      return Power(X, N / 2) * Power(X, N / 2);
    } else {
      return X * Power(X, N - 1);
    }
  } else {
    if (N < 0) {
      return 1 / Power(X, abs(N));
    } else {
      return 1;
    }
  }
}