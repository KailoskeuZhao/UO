#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> st;

ll solve(int at, int n, ll sm1, ll sm2){
    if(at == n){return abs(sm1 - sm2);}

    return min(
        solve(at+1, n, sm1 + st[at], sm2),
        solve(at+1, n, sm1, sm2 + st[at])
    );

}

int main(){
    int n;
    cin >> n;
    ll ans;

    st.resize(n);
    for(int m = 0; m < n; m++){
        cin >> st[m];
    }
    ans = solve(0, n, 0, 0);
    cout << ans << endl;


}