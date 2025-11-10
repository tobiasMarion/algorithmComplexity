// https://codeforces.com/problemset/problem/165/B
// TO RUN: 
// g++-15 -Wall -Wextra -g ./165B.cpp -o ./output/165B.out && ./output/165B.out
// TAGS: binary search

#include <bits/stdc++.h>
using namespace std;


int main() {
  int programSize, productivityDecay;
  cin >> programSize >> productivityDecay;

  int left = 1;
  int right = programSize;
  int answer = programSize;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    long long totalLines = 0;
    long long currentLines = mid;

    while (currentLines > 0) {
      totalLines += currentLines;
      currentLines /= productivityDecay;
    }
    
    if (totalLines >= programSize) {
      answer = mid;
      right = mid - 1;
    } else {
        left = mid + 1;
    }
  }

  cout << answer << endl;

  return 0;
}
