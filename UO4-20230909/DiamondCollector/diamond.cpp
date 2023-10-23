#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;

    freopen("diamond.in", "r", stdin);
    cin >> n >> k;


    
    int da[n];
    for(int m = 0; m < n; m++) cin >> da[m];

    int curr = 0, maxx = 0;

    for(int m = 0; m < n; m++){
        curr = 0;
        for(int j = 0; j < n; j++){
            if (da[j] >= da[m] && da[j] <= da[m] + k) curr++;
        }
        if (curr > maxx) maxx = curr;
    }

    freopen("diamond.out", "w", stdout);
    cout << maxx << endl;
}