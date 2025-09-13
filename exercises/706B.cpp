// https://codeforces.com/problemset/problem/706/B
// TO RUN: g++ -Wall -Wextra -g ./706B.cpp -o ./output/706B.out && ./output/706B.out
// TAGS: binary-search

// To achieve the desired time complexity, we use STL upper_bound which 
// implements a binary search under the hood

#include <bits/stdc++.h>
using namespace std;


int main() {
  int amountOfStores;
  vector<int> prices;
  int priceOnStore;

  int amountOfDays;
  int coinsOnDay;

  cin >> amountOfStores;
  for (int i = 0; i < amountOfStores; i++) {
    cin >> priceOnStore;

    prices.push_back(priceOnStore);
  }

  sort(prices.begin(), prices.end());

  cin >> amountOfDays;
  for (int i = 0; i < amountOfDays; i++) {
    cin >> coinsOnDay;

    int max = upper_bound(prices.begin(), prices.end(), coinsOnDay) - prices.begin();

    cout << max << "\n";
  }

  return 0;
}