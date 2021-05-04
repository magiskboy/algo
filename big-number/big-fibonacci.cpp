#include<iostream>
#include<cstdlib>

using namespace std;

string add(string a, string b) {
    size_t la = a.size(), lb = b.size();
    if (la > lb) {
        b.insert(0, la-lb, '0');
    }
    else if (lb > la) {
        a.insert(0, lb-la, '0');
    }

    string c;
    uint8_t m = 0, r = 0, k = 0;
    for (int32_t i = a.size()-1; i >= 0; --i) {
        k = a[i] + b[i] - 96 + m;
        r = k % 10; m = k / 10;
        c.insert(0, 1, (char)(r+48));
    }
    if (m == 1)
        c.insert(0, 1, '1');
    return c;
}

void solve(uint32_t n, int32_t show) {
    string a = "0", b = "1", c;
    while (n--) {
        c = add(a, b);
        b = a;
        a = c;
        if (show) 
            cout << c << "\n";
    }
}

int main(int argc, char* argv[]) {
    uint32_t n = atoi(argv[1]);
    int show = atoi(argv[2]);
    solve(n, show);
    return 0;
}