// https://codeforces.com/problemset/problem/416/C
// TO RUN:
// g++-15 -Wall -Wextra -g ./416C.cpp -o ./output/416C.out && ./output/416C.out
// TAGS: greedy

#include <bits/stdc++.h>
using namespace std;

struct Request {
  int id;
  int size;
  int money;
};

struct Table {
  int id;
  int capacity;
  bool isFree = true;
};

bool moreExpensive(const Request& a, const Request& b) {
  return a.money > b.money;
}

bool smaller(const Table& a, const Table& b) { return a.capacity < b.capacity; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  if (!(cin >> n)) return 0;

  vector<Request> requests(n);
  for (int i = 0; i < n; ++i) {
    requests[i].id = i + 1;
    cin >> requests[i].size >> requests[i].money;
  }

  int k;
  cin >> k;
  vector<Table> tables(k);
  for (int i = 0; i < k; ++i) {
    tables[i].id = i + 1;
    cin >> tables[i].capacity;
  }

  // Ordering
  sort(requests.begin(), requests.end(), moreExpensive);
  sort(tables.begin(), tables.end(), smaller);

  vector<pair<int, int>> matches;
  int totalMoney = 0;
  int acceptedRequests = 0;

  // Greedy Matching
  // From the most expensise request to the cheapest
  for (const auto& req : requests) {
    // Find de smallest table that is as big as req.size
    for (auto& table : tables) {
      if (table.isFree && table.capacity >= req.size) {
        table.isFree = false;
        totalMoney += req.money;
        acceptedRequests++;
        matches.push_back({req.id, table.id});
        break;
      }
    }
  }

  cout << acceptedRequests << " " << totalMoney << endl;
  for (const auto& match : matches) {
    cout << match.first << " " << match.second << endl;
  }

  return 0;
}