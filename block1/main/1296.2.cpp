
#include <iostream>
using namespace std;

int hypertransition();

int main() {

  cout << hypertransition() << "\n";

  return 0;
}

int hypertransition() {

  int max_sum = 0;
  int sum = 0;
  int element = 0;
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> element;
    if (sum >= 0) {
      sum += element;
    } else {

      if (element > 0) {
        sum = element;
      }
    }
    if (sum > max_sum) {
      max_sum = sum;
    }
  }

  return max_sum;
}