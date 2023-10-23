#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll arr_a[n], arr_b[n];
    for(ll l = 0; l < n; l++){
        cin >> arr_a[l];
        arr_a[l] *= (l+1)*(n-l);
    }
    for(ll l = 0; l < n; l++){
        cin >> arr_b[l];
    }

    sort(arr_a, arr_a + n);
    sort(arr_b, arr_b + n);

    ll sum = 0;
    for(ll i = 0; i < n; i++){
        sum += ((arr_a[i])*(arr_b[n-i-1]));
    }

    cout << sum << "\n";
    

}