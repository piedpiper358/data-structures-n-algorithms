
#include <iostream>
using namespace std;

void fools(int N, int array[]);

void find_max(int N, int array[], int *f_max, int *s_max, int *f_max_index);

int main() {
  int N;
  cin >> N;
  int array[N];
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  fools(N, array);
  cout << "\n";
}

void fools(int N, int array[]) {

  int f_max = 0, s_max = 0, f_max_index = -1;

  find_max(N, array, &f_max, &s_max, &f_max_index);
  int raz = f_max - s_max;
  int prev_index = -1;

  for (int i = 0; i < f_max; i++) {
    for (int j = 0; j < N; j++) {

      if (array[j] > 0 && j != f_max_index && prev_index != f_max_index && raz != 0) {
        raz--;
        cout << f_max_index + 1 << " ";
        array[f_max_index]--;
        prev_index = f_max_index;
      }
      if (array[j] > 0) {
        cout << j + 1 << " ";
        array[j]--;
        prev_index = j;
      }
    }
  }
}

void find_max(int N, int array[], int *f_max, int *s_max, int *f_max_index) {

  *f_max = 0;
  *s_max = 0;
  *f_max_index = -1;

  for (int i = 0; i < N; i++) {
    if (array[i] > *f_max) {
      *s_max = *f_max;
      *f_max = array[i];
      *f_max_index = i;
    } else {
      if (array[i] <= *f_max && array[i] > *s_max) {

        *s_max = array[i];
      }
    }
  }
}
