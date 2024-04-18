#include<bits/stdc++.h>
using namespace std;
#define ll  long long
vector<bool>state;
vector<vector<vector<ll>>>dp; // state is ( cur switch , direction of toggle (open > close (or) close > open) , state of right switches)
ll solve(int n,bool close) {
    if (state[n] == close)
        return 0;

    if (n < 1)
        return 0;

    if (n == 1) {
        state[1] = close;
        dp[1][close][1] = 1;
        dp[1][close][0] = 1;
        return 1;
    }

    if (dp[n][close][state[n - 1]]) {
        state[n] = close;
        return dp[n][close][state[n - 1]];
    }

    ll num = 0;

    bool f = close;
    bool s = state[n - 1];

    num += solve(n - 1, false);


    num += solve(n - 2, true);

    state[n] = close;
    num += 1;

    num += solve(n - 1, true);

    dp[n][f][s] = num;

    return num;
}
int main() {
    int n;
    cin >> n;

    state.resize(n + 1);
    dp.resize(n + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    cout << solve(n, true);

}
