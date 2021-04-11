#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#define ull unsigned long long

using namespace std;

void sol() {
    int t;
    cin >> t;
    vector<ull>  out;
    while (t--) {
        ull n, m, x;
        cin >> n >> m >> x;
        ull col = ((x - 1) / n) + 1;
        ull row = ((x - 1) % n) + 1;
        out.push_back((row-1) * m + col);
    }
    for (auto x : out) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
    return 0;
}
