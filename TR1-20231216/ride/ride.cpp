/*
ID: a9816581
PROG: ride
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string a, b;
    cin >> a >> b;

    int c = 1, d = 1;

    for(int l = 0; l < a.length(); l++){
        c *= (a[l]- 'A' + 1);
    }

    for(int l = 0; l < b.length(); l++){
        d *= (b[l] - 'A' + 1);
    }

    bool op = false;

    if(
        (c % 47 == 
        d % 47)
    ){
        op = true;
    }

    if(op) cout << "GO" << endl;
    else cout << "STAY" << endl;
}