#include <iostream>
#include <time.h>

using namespace std;

// прототипы функций
void merge_sort(int *a, int *aux, int l, int r);
void sort(int *a, int N);
void merge(int *a, int *aux, int l, int m, int r);

int N;

int main() {
  cin >> N; // количество входных элементов
  // если пригодится для отладки, генератор случайных чисел
  // srand(time(NULL)); // инициализатор генератора
  // rand()%99 + 1: сгенерирует случайное число от 1 до 99.

  int *A = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i]; // заполнение массива
  }
  sort(A, N); // вызов сортировки

  for (int i = 0; i < N; i++) {
    cout << A[i] << " "; // печать
  }
  cout << "\n";
  delete[] A; // освободили память
  return 0;
}

void merge_sort(int *a, int *aux, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(a, aux, l, m);
    merge_sort(a, aux, m + 1, r);
    merge(a, aux, l, m, r);
  }
}

void sort(int *a, int N) {

  int *aux = new int[N];
  for (int k = 0; k < N; ++k) {
    aux[k] = a[k];
  }
  merge_sort(a, aux, 0, N - 1);
  delete[] aux;
}
void merge(int *a, int *aux, int l, int m, int r) {

  int i = l;
  int j = m + 1;
  for (int k = l; k <= r; ++k) {
    aux[k] = a[k];
  }
  for (int k = l; k <= r; ++k) {
    if (i > m) {
      a[k] = aux[j++];
      continue;
    }
    if (j > r) {
      a[k] = aux[i++];
      continue;
    }
    if (aux[j] < aux[i]) {
      a[k] = aux[j++];
    } else {
      a[k] = aux[i++];
    }
  }
}