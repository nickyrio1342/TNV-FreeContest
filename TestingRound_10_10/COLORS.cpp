#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

const long long MOD = 1e9 + 7;

long long POW(long long a, long long k) {
    if (k == 1) return a;
    long long tmp = POW(a, k >> 1);
    tmp = tmp * tmp % MOD;
    if (k % 2) tmp = tmp * a % MOD;
    return tmp;
}

long long f[N];
int n, k;
long long cal(int n, int k) {
    f[0] = 1;
    FOR(i, 1, n) f[i] = f[i - 1] * k % MOD;
    long long ans = 0;
    FOR(i, 1, n) {
        if (n % i == 0) {
            ans = (ans + f[i] * POW(i, MOD - 2) % MOD) % MOD;
        }
        for (int j = i + i; j <= n; j += i) {
            f[j] -= f[i];
            if (f[j] < 0) f[j] += MOD;
        }
    }
    return ans;
}
int main() {
   // freopen("NECKLACE.inp","r",stdin);
   // freopen("NECKLACE.out","w",stdout);
    IO;
    int test;
    cin>>test;
    while (test--) {
        cin>>n>>k;
        cout<<cal(n, k)<<endl;
    }
}
