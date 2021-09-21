#include <iostream>
using namespace std;

int Combin(int, int);

int main() {
  int N, K;
  cin >> N >> K;
  cout << Combin(N, K);
  return 0;
}

int Combin(int N, int K) {

  // Здесь должна быть реализована рекурсивная процедура
  // вычисления числа сочетаний

  if (N == K || K == 0) {
    return 1;
  }

  return Combin(N - 1, K) + Combin(N - 1, K - 1);
}