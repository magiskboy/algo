#include <bits/stdc++.h>

using namespace std;

void sol() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n+1];
        a[n] = 9999999;
        for (int i = 0; i < n; ++i) cin >> a[i];
        int l[n+1];
        int trace[n+1];
        l[n] = 0;
        for (int i = n-1; i >= 0; --i) {
            l[i] = 0;
            int jmax = i;
            for (int j = n; j >= i; --j) {
                if (a[j] > a[i] && l[j] > l[jmax]) {
                    jmax = j;
                }
            }
            if (jmax != i) {
                l[i] = l[jmax] + 1;
                trace[i] = jmax;
            }
            else {
                l[i] = 1;
            }
        }
        cout << l[0] << "\n";
        int i = 0;
        while (i < n) {
            cout << a[i] << " ";
            i = trace[i];
        }
        cout << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(nullptr);
    ifstream in("in.txt");
    ofstream out("out.txt");
    streambuf *cinbuf = cin.rdbuf();
    streambuf *coutbuf = cout.rdbuf();
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    sol();
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
    return 0;
}
