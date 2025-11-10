// https://codeforces.com/problemset/problem/2562/C2
// TO RUN: 
// g++-15 -Wall -Wextra -g ./1562C2.cpp -o ./output/1562C2.out && ./output/1562C2.out
// TAGS: binary search

#include <bits/stdc++.h>
using namespace std;


int main() {
  int amountOfPotions;
  cin >> amountOfPotions;

  long long currentHealth = 0;
  int potionsDrunk = 0;  

  priority_queue<long long, vector<long long>, greater<long long>> badPotions;

  for (int i = 0; i < amountOfPotions; i++) {
    long long currentPotion;
    cin >> currentPotion;

    currentHealth += currentPotion;
    potionsDrunk++;


    if (currentPotion < 0) {
      badPotions.push(currentPotion);
    }

    if (currentHealth < 0) {
      long long worstPotion = badPotions.top();
      badPotions.pop();

      currentHealth -= worstPotion;

      potionsDrunk--;
    }
  }

  cout << potionsDrunk << endl;

  return 0;
}
