
#include <iostream>
#include <sstream>

using namespace std;

void duons(int *a);
int delete_pair(stringstream &cout, int *array, int a, int b);
int func(stringstream &cout, int *array);
int array_sum(int *array);

string names_of_peaks = "ABCDEFGH";

int main() {

  int array[8];
  for (int i = 0; i < 8; i++) {
    cin >> array[i];
  }

  duons(array);

  // 0 0 0 1 1 0 1 2

  // 1 0 1 0 3 1 0 0
  // 0 1  0 1 0 0 0
  // A B C D E F G H

  // A - B, D, E
  // B - A, C, F
  // C - B, D, G
  // D - A, C, H
  // E - A, F, H
  // F - B, E, G
  // G - C, F, H
  // H - D, E, G

  //	   H__________G 		   7__________6
  //	  /|	     /|			  /|	     /|
  //	 / | 	    / |			 / | 	    / |
  //	E__________F  |			4__________5  |
  //	|  | 	   |  |			|  | 	   |  |
  //	|  D_______|__C			|  3_______|__2
  //	| /        | /			| /        | /
  //	|/	 	   |/			|/	 	   |/
  //	A__________B			0__________1

  return 0;
}

void duons(int *array) {

  stringstream ss;
  int num_of_act = 0;

  if (array_sum(array) % 2 != 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  num_of_act += delete_pair(ss, array, 0, 1);
  num_of_act += delete_pair(ss, array, 1, 2);
  num_of_act += delete_pair(ss, array, 2, 3);
  num_of_act += delete_pair(ss, array, 3, 0);

  num_of_act += delete_pair(ss, array, 4, 5);
  num_of_act += delete_pair(ss, array, 5, 6);
  num_of_act += delete_pair(ss, array, 6, 7);
  num_of_act += delete_pair(ss, array, 7, 4);

  num_of_act += delete_pair(ss, array, 0, 4);
  num_of_act += delete_pair(ss, array, 1, 5);
  num_of_act += delete_pair(ss, array, 2, 6);
  num_of_act += delete_pair(ss, array, 3, 7);

  num_of_act += func(ss, array);

  if (array_sum(array) != 0 || num_of_act > 1000) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << ss.str();
  }

  // ss.close(); // закрываем файл
}

int delete_pair(stringstream &out, int *array, int a, int b) {

  int quantity = min(array[a], array[b]);

  array[a] -= quantity;
  array[b] -= quantity;

  for (int i = 0; i < quantity; i++) {
    out << names_of_peaks[a] << names_of_peaks[b] << "-\n";
  }

  return quantity;
}

int func(stringstream &out, int *array) {

  int quantity = 0;

  if (array[0] != 0 && array[6] != 0) {

    quantity = min(array[0], array[6]);
    array[0] -= quantity;
    array[6] -= quantity;

    for (int i = 0; i < quantity; i++) {
      out << names_of_peaks[1] << names_of_peaks[5] << "+\n";
      out << names_of_peaks[0] << names_of_peaks[1] << "-\n";
      out << names_of_peaks[5] << names_of_peaks[6] << "-\n";
    }
  }

  if (array[1] != 0 && array[7] != 0) {

    quantity = min(array[1], array[7]);
    array[1] -= quantity;
    array[7] -= quantity;

    for (int i = 0; i < quantity; i++) {
      out << names_of_peaks[2] << names_of_peaks[6] << "+\n";
      out << names_of_peaks[1] << names_of_peaks[2] << "-\n";
      out << names_of_peaks[7] << names_of_peaks[6] << "-\n";
    }
  }
  if (array[2] != 0 && array[4] != 0) {

    quantity = min(array[2], array[4]);
    array[2] -= quantity;
    array[4] -= quantity;

    for (int i = 0; i < quantity; i++) {
      out << names_of_peaks[3] << names_of_peaks[7] << "+\n";
      out << names_of_peaks[2] << names_of_peaks[3] << "-\n";
      out << names_of_peaks[4] << names_of_peaks[7] << "-\n";
    }
  }

  if (array[3] != 0 && array[5] != 0) {

    quantity = min(array[3], array[5]);
    array[3] -= quantity;
    array[5] -= quantity;

    for (int i = 0; i < quantity; i++) {
      out << names_of_peaks[0] << names_of_peaks[4] << "+\n";
      out << names_of_peaks[0] << names_of_peaks[3] << "-\n";
      out << names_of_peaks[4] << names_of_peaks[5] << "-\n";
    }
  }

  return quantity;
}

int find_max(int *array) {

  int max_value = -1;
  int max_index = -1;

  for (int i = 0; i < 8; i++) {
    if (array[i] > max_value) {
      max_value = array[i];
      max_index = i;
    }
  }

  return max_index;
}

int array_sum(int *array) {

  int array_sum = 0;
  for (int i = 0; i < 8; i++) {
    array_sum += array[i];
  }

  return array_sum;
}