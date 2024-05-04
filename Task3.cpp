#include<bits/stdc++.h>
using namespace std;
#define ll  long long
vector<bool>state;
vector<vector<vector<ll>>>dp;
// state is (cur switch , direction of toggle (open > close (or) close > open) , state of right switches)
// false >> turn on
// true >> turn off
void to_print(int idx,bool state_to_toggle,ll num) {
    static ll i = 1;
    if (!num) {
        cout << i;
        cout << "-turn switch " << idx << " ";
        if (state_to_toggle)
            cout << "off.\n";
        else
            cout << "on.\n";

        i++;
    } else {
        cout << "repeat " << num << " steps we did before to toggle switch " << idx << ".\n";
        i += num;
    }
}
ll solve(int idx,bool state_to_toggle) {
    if (state[idx] == state_to_toggle)
        return 0;

    if (idx < 1)
        return 0;

    if (idx == 1) {
        state[1] = state_to_toggle;
        dp[1][state_to_toggle][1] = 1;
        dp[1][state_to_toggle][0] = 1;
        to_print(1, state_to_toggle, 0);
        return 1;
    }

    if (dp[idx][state_to_toggle][state[idx - 1]]) {
        state[idx] = state_to_toggle;
        to_print(idx, state_to_toggle, dp[idx][state_to_toggle][state[idx - 1]]);
        return dp[idx][state_to_toggle][state[idx - 1]];
    }

    ll num = 0;

    bool f = state_to_toggle;
    bool s = state[idx - 1];

    num += solve(idx - 1, false);


    num += solve(idx - 2, true);


    state[idx] = state_to_toggle;
    to_print(idx, state_to_toggle, 0);
    num += 1;

    num += solve(idx - 1, true);
    dp[idx][f][s] = num;


    return num;
}
int main() {
    int n;
    cin >> n;

    state.resize(n + 1);
    dp.resize(n + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    ll minimum_number_of_moves = solve(n, true);
    cout << "\nAll switches are currently off.\n";
    cout << "Minimum number of moves : " << minimum_number_of_moves << ".";
}
