// https://codeforces.com/problemset/problem/20/C
// TO RUN: 
// g++-15 -Wall -Wextra -g ./20C.cpp -o ./output/20C.out && ./output/20C.out
// TAGS: shortest path, graph

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;


int main() {
  // Read Graph
  int amountOfVertices, amountOfEdges;
  cin >> amountOfVertices >> amountOfEdges;

  vector<vector<pair<int, int>>> graph(amountOfVertices + 1);

  for (int i = 0; i < amountOfEdges; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;

    graph[from].push_back({ to, weight });
    graph[to].push_back({ from, weight });
  }


  // Djikstra's Algorithm
  vector<long long> distance(amountOfVertices + 1, INF);
  vector<int> parent(amountOfVertices + 1, -1);
  priority_queue<
    pair<long long, int>, 
    vector<pair<long long, int>>, 
    greater<pair<long long, int>>
  > pq;

  distance[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [current_distance, current_vertex] = pq.top(); 
    pq.pop();

    // Found a better path before we got to process this node
    if (current_distance != distance[current_vertex]) continue;

    for (auto [neighbor, weight] : graph[current_vertex]) {
      if (distance[neighbor] > distance[current_vertex] + weight) {
        distance[neighbor] = distance[current_vertex] + weight;
        parent[neighbor] = current_vertex;

        pq.push({ distance[neighbor], neighbor });
      }
    }
  }

  // Output Result
  if (distance[amountOfVertices] == INF) {
    cout << -1 << '\n';
    return 0;
  }

  // Rebuild path from 1 to N using parent
  vector<int> path;
  for (int cur = amountOfVertices; cur != -1; cur = parent[cur]) path.push_back(cur);
  reverse(path.begin(), path.end());

  // Print path
  for (int i = 0; i < (int)path.size(); i++) {
      if (i) cout << ' ';
      cout << path[i];
  }
  cout << '\n';


  return 0;
}
