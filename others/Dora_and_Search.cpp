//
// Created by Bobbyshu on 2023/3/6.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }

    int l = 0, r = n - 1;
    int min = 1, max = n;

    while (l <= r) {
        if (v[l] == min) {
            ++l;
            ++min;
        } else if (v[l] == max) {
            ++l;
            --max;
        } else if (v[r] == min) {
            --r;
            ++min;
        } else if (v[r] == max) {
            --r;
            --max;
        } else {
            break;
        }
    }

    if (l <= r) {
        cout << l + 1 << " " << r + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}
/*
int main() {

    int time;
    cin >> time;
    while (time--) {
        solve();
    }
    return 0;
}
 */