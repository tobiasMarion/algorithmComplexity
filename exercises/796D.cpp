// https://codeforces.com/problemset/problem/796/D
// TO RUN: 
// g++-15 -Wall -Wextra -g ./796D.cpp -o ./output/796D.out && ./output/796D.out
// TAGS: bfs, shortest path, graph

#include <bits/stdc++.h>
using namespace std;



int main() {
  // Read Graph
  int amountOfCities, amountOfPoliceStations, maxDistance;
  cin >> amountOfCities >> amountOfPoliceStations >> maxDistance;
  
  queue<int> q;
  vector<int> distances(amountOfCities + 1, -1);
  vector<int> owner(amountOfCities + 1);
  vector<pair<int, int>> edges;

  for (int i = 0; i < amountOfPoliceStations; i++) {
    int policeStation;
    cin >> policeStation;
    q.push(policeStation);

    distances[policeStation] = 0;
    owner[policeStation] = policeStation;
  }

  vector<vector<int>> graph(amountOfCities + 1);

  for (int i = 0; i < amountOfCities - 1; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);

    edges.push_back({from, to});
  }



  // BFS
  while (!q.empty()) {
    int currentNode = q.front(); q.pop();

    for (int neighbor : graph[currentNode]) {
      if (distances[neighbor] != -1) continue;

      distances[neighbor] = distances[currentNode] + 1;
      owner[neighbor] = owner[currentNode];

      q.push(neighbor);
    }
  }
  


  // Check roads that can be removed
  vector<int> roadsToShutdown;  
  for (size_t i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    if (owner[u] != owner[v]) {
      roadsToShutdown.push_back(i + 1);
    }
  }

  // Print result
  cout << roadsToShutdown.size() << endl;
  for (size_t i = 0; i < roadsToShutdown.size(); i++) {
    cout << roadsToShutdown[i] << (i == roadsToShutdown.size() - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
} 
