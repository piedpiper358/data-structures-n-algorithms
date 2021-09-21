
#include <iostream>
using namespace std;

int num_fights(int, int);

int main() {
  int T;
  cin >> T;
  int array[T];
  for (int i = 0; i < T; i++) {
    int n, k;
    cin >> n >> k;
    array[i] = num_fights(k, n);
  }

  for (int i = 0; i < T; i++) {

    cout << array[i];
    cout << "\n";
  }
  return 0;
}

int num_fights(int k, int n) {

  int num_team = k;         // number of teams
  int num_people = n / k;   // number of people in each team
  int extra_people = n % k; // number of extra peoples

  int current_team;  // current team's number
  int num_team_mate; // number of team-mates in the current team
  int sum = 0;       // number of fights

  for (current_team = 1; current_team <= num_team; current_team++) {

    num_team_mate = extra_people == 0 ? num_people : (extra_people--, num_people + 1);

    sum += num_team_mate * (num_people * (num_team - current_team) + extra_people);
  }
  return sum;
}