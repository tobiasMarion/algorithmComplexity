// https://codeforces.com/problemset/gymProblem/104821/G
// TO RUN:
// g++-15 -Wall -Wextra -g ./104821G.cpp -o ./output/104821G.out
// ./output/104821G.out
//  TAGS: dynamic-programming knapsack-problem

#include <bits/stdc++.h>
using namespace std;

struct Gem {
  int price;
  long long beauty;
};

bool moreBeautifull(const Gem& a, const Gem& b) { return a.beauty > b.beauty; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int amountOfGems, availableMoney, cupons;
  if (!(cin >> amountOfGems >> availableMoney >> cupons)) return 0;

  vector<Gem> gems(amountOfGems);
  for (int i = 0; i < amountOfGems; i++) {
    cin >> gems[i].price >> gems[i].beauty;
  }

  sort(gems.begin(), gems.end(), moreBeautifull);

  vector<long long> prefixCost(amountOfGems + 1, 0);
  vector<long long> prefixBeauty(amountOfGems + 1, 0);

  priority_queue<int, vector<int>, greater<int>> freeItems;

  long long bruteValue = 0;
  long long amountOfDiscounts = 0;

  for (int i = 0; i < amountOfGems; i++) {
    prefixBeauty[i + 1] = prefixBeauty[i] + gems[i].beauty;
    bruteValue += gems[i].price;

    // Try get it for free
    freeItems.push(gems[i].price);
    amountOfDiscounts += gems[i].price;

    // If we have more free itens than cupons, we have to pay for the cheapest
    if (freeItems.size() > cupons) {
      int priceToPay = freeItems.top();
      freeItems.pop();
      amountOfDiscounts -= priceToPay;
    }

    prefixCost[i + 1] = bruteValue - amountOfDiscounts;
  }

  // dp[w] = Greatest beauty with w money
  vector<long long> dp(availableMoney + 1, 0);
  long long ans = 0;

  // DP loop
  for (int i = amountOfGems; i >= 0; i--) {
    long long cost = prefixCost[i];

    if (cost <= availableMoney) {
      long long money_left = availableMoney - cost;
      long long total_beauty = prefixBeauty[i] + dp[money_left];
      ans = max(ans, total_beauty);
    }

    if (i > 0) {
      Gem current = gems[i - 1];
      for (int w = availableMoney; w >= current.price; w--) {
        dp[w] = max(dp[w], dp[w - current.price] + current.beauty);
      }
    }
  }

  cout << ans << endl;

  return 0;
}