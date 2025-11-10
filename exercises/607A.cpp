// https://codeforces.com/problemset/problem/607/A
// TO RUN: 
// g++-15 -Wall -Wextra -g ./607A.cpp -o ./output/607A.out && ./output/607A.out
// TAGS: binary search, dynamic programing

#include <bits/stdc++.h>
using namespace std;

struct Beacon {
  int position;
  int power;

  // To make code cleaner
  bool operator<(const Beacon& other) const {
    return position < other.position;
  }
};

int main() {
  int amountOfBeacons;
  cin >> amountOfBeacons;

  vector<Beacon> beacons(amountOfBeacons);

    for (int i = 0; i < amountOfBeacons; i++) {
      cin >> beacons[i].position >> beacons[i].power;
    }

    sort(beacons.begin(), beacons.end());

    vector<int> dp(amountOfBeacons);

    int maxSurvivors = 0;

    // Bottom up: dp[0], dp[1], dp[2], dp[3]...
    for (int i = 0; i < amountOfBeacons; i++) {
      int destroysUntilPosition = beacons[i].position - beacons[i].power;

      int index = lower_bound(
        beacons.begin(), 
        beacons.end(), 
        Beacon{ destroysUntilPosition, 0 }) - beacons.begin();

      if (index == 0) { 
        // If index is detroyed, only the activated beacon is alive
        dp[i] = 1;
      } else {
        // Else, the activated and the other on the left which are ok are the solutution to subproblem
        dp[i] = 1 + dp[index - 1];
      }
      
      maxSurvivors = max(maxSurvivors, dp[i]);
    }

  cout << amountOfBeacons - maxSurvivors << "\n";

  return 0;
}
