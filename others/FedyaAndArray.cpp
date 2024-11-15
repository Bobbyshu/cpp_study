//
// Created by Bobbyshu on 2023/3/6.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll mx, mn;
    cin >> mx >> mn;
    ll gap = 2 * (mx - mn);
    cout << gap << '\n';
    vector<ll> v(gap);
    int idx = 0;
    for (ll c = mx; c >= mn; --c) {
        v[idx++] = c;
    }
    for (ll c = mn + 1; c < mx; ++c) {
        v[idx++] = c;
    }

    for (int i = 0; i < gap; ++i) {
        cout << v[i] << " \n"[i == gap - 1];

        /*
        cout << v[i] << " ";
        if (i == gap - 1) {
            cout << "\n";
        }
         */
    }
}

int main() {

    int time;
    cin >> time;
    while (time--) {
        solve();
    }
    return 0;
}