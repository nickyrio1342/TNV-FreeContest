#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 500100
#define pp pair<int, int>
#define IO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

int a, b, n;
long long w[N], c[N];

bool ok(long long m) {
    long long need = 0;
    REP(i, n) {
        c[i] = w[i] - m * b;
    }
    if (a == b) {
        REP(i, n) if (c[i] > 0) return false;
        return true;
    }
    if (a > b) {
        FORD(i, n - 1, 0) {
            if (c[i] <= 0) break;
            need += (c[i] - 1) / (a - b) + 1;
        }
        return need <= m;
    }
    else {
        if (c[n - 1] > 0) return false;
        REP(i, n) {
            if (c[i] >= 0) break;
            need += c[i] / (a - b);
        }
        return need >= m;
    }
}

void solve() {
    freopen("HUNTER.inp","r",stdin);
    freopen("HUNTER.out","w",stdout);
    cin>>n>>a>>b;
    REP(i, n) cin>>w[i];
    sort(w, w + n);
    long long l = 0;
    long long r = 5e14;
    long long ans = -1;
    while (l <= r) {
        long long m = (l + r) >> 1;
        if (ok(m)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout<<ans;
}
int main() {
    IO;
    solve();

}

