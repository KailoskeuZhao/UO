#include <bits/stdc++.h>
using namespace std;

void solveTestCase(){
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> da(n);
    for(vector<long long> &a : da) a.resize(m);
    for(int j = 0; j < n; j++){
        for(int l = 0; l < m; l++) cin >> da[j][l];
    }

    long long tt = 0;
    for(int s = 0; s < m; s++){
        vector<long long> da2;
        long long ct = 0;
        for(int k = 0; k < n; k++){
            ct += da[k][s];
            da2.push_back(da[k][s]);
        }

    sort(da2.begin(), da2.end());
    long long dispo = 0;
    for(int j = 0; j < n; j++){
        dispo += da2[j];
        tt += ((ct - dispo) - (n - j - 1) * da2[j]);
    }

    }

    cout << tt << endl;

}

int main(){
    int p;
    cin >> p;
    for(int a = 0; a < p; a++) solveTestCase();
}