// https://codeforces.com/problemset/problem/600/B
// TO RUN: g++ -Wall -Wextra -g ./600B.cpp -o ./output/600B.out && ./output/600B.out
// TAGS: binary-search

// To achieve the desired time complexity, we use STL upper_bound which 
// implements a binary search under the hood

#include <bits/stdc++.h>
using namespace std;


int main() {
  int sizeA, sizeB;
  cin >> sizeA >> sizeB;

  vector<int> arrayA;

  for (int i = 0; i < sizeA; i++) {
    int a;
    cin >> a;

    arrayA.push_back(a);
  }

  sort(arrayA.begin(), arrayA.end());

  for (int i = 0; i < sizeB; i++) {
    int b;
    cin >> b;

    int count = upper_bound(arrayA.begin(), arrayA.end(), b) - arrayA.begin();

    cout << count << " ";
  }

  return 0;
}