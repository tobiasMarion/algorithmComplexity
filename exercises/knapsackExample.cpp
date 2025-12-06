// TO RUN:
// g++-15 -Wall -Wextra -g ./knapSackExample.cpp -o ./output/knapSackExample.out
// && ./output/knapSackExample.out TAGS: dp, knapsack

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight;
  int value;
};

int main() {
  int knapsackCapacity, amountOfItens;
  cin >> knapsackCapacity >> amountOfItens;

  vector<Item> items(amountOfItens);

  for (int i = 0; i < amountOfItens; i++) {
    int weight, value;
    cin >> weight >> value;
    items[i] = {weight, value};
  }

  vector<vector<int>> dp(amountOfItens + 1, vector<int>(knapsackCapacity + 1));

  for (int i = 1; i <= amountOfItens; i++) {
    for (int w = 0; w <= knapsackCapacity; w++) {
      auto item = items[i - 1];

      if (item.weight > w) {
        dp[i][w] = dp[i - 1][w];
      } else {
        dp[i][w] = max(dp[i - 1][w], item.value + dp[i - 1][w - item.weight]);
      }
    }
  }

  cout << dp[amountOfItens][knapsackCapacity] << endl;

  return 0;
}
