// https://codeforces.com/problemset/problem/277/A
// TO RUN: 
// g++-15 -Wall -Wextra -g ./277A.cpp -o ./output/277A.out && ./output/277A.out
// TAGS: DFS

#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}


int main() {
    int employees, languages;
    cin >> employees >> languages;

    vector<vector<int>> graph(employees + languages); // Grafo bipartido
    bool any = false;

    for (int i = 0; i < employees; ++i) {
        int languagesSpoken; 
        cin >> languagesSpoken;

        if (languagesSpoken > 0) any = true;
        for (int j = 0; j < languagesSpoken; j++) {
            int language;
            cin >> language;
            int langNode = employees + language - 1; // offset para os nós das linguas

            graph[i].push_back(langNode);
            graph[langNode].push_back(i);
        }
    }


    vector<int> isVisited(employees + languages, false);
    int components = 0;

    for (int i = 0; i < employees; ++i) {
        if (!isVisited[i]) {
            dfs(i, graph, isVisited);
            components++;
        }
    }

    if (any) cout << components - 1 << "\n";
    else cout << employees << "\n"; 

    return 0;
}
