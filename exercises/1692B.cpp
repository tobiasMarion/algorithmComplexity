// https://codeforces.com/problemset/problem/1692/B
// TO RUN: 
// g++-15 -Wall -Wextra -g ./1692B.cpp -o ./output/1692B.out && ./output/1692B.out
// TAGS: set

#include <bits/stdc++.h>
using namespace std;


int main() {
  int amountOfTests;
  cin >> amountOfTests;

  for (int i = 0; i < amountOfTests; i++) {
    int arraySize;
    cin >> arraySize;

    set<int> uniques;

    for (int j = 0; j < arraySize; j++) {
      int newInt;
      cin >> newInt;

      uniques.insert(newInt);
    }

    int setSize = uniques.size();
    int amountOfDuplicates = arraySize - setSize;

    cout << (setSize - (amountOfDuplicates % 2)) << endl;
  }

  return 0;
}
