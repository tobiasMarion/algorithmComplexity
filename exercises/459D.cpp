// https://codeforces.com/problemset/problem/459/D
// TO RUN: 
// g++-15 -Wall -Wextra -g ./459D.cpp -o ./output/459D.out && ./output/459D.out
// TAGS: divide and conquer


#include <bits/stdc++.h>
using namespace std;

vector<int> prefix, sufix;

long long countCrossPairings(int l, int mid, int r) {
    vector<int> left_vals;
    vector<int> right_vals;

    left_vals.reserve(mid - l + 1);
    right_vals.reserve(r - mid);

    for (int i = l; i <= mid; ++i) left_vals.push_back(prefix[i]);
    for (int j = mid + 1; j <= r; ++j) right_vals.push_back(sufix[j]);

    sort(left_vals.begin(), left_vals.end());
    sort(right_vals.begin(), right_vals.end());

    long long count = 0;
    int ptr_right = 0;

    for (int val_c : left_vals) {
        while (ptr_right < right_vals.size() && right_vals[ptr_right] < val_c) {
            ptr_right++;
        }
        count += ptr_right;
    }

    return count;
}


long long solveDivideAndConquer(int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    long long total_ans = 0;

    total_ans += solveDivideAndConquer(l, mid);
    total_ans += solveDivideAndConquer(mid + 1, r);

    total_ans += countCrossPairings(l, mid, r);

    return total_ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    prefix.resize(n);
    sufix.resize(n);
    
    map<int, int> freq; 

    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
        prefix[i] = freq[a[i]];
    }

    freq.clear();

    for (int i = n - 1; i >= 0; --i) {
        freq[a[i]]++;
        sufix[i] = freq[a[i]];
    }

    cout << solveDivideAndConquer(0, n - 1) << endl;

    return 0;
}