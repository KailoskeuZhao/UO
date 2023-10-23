#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<long long> p(n);
    
    for(int j = 0; j < n; j++){
        cin >> p[j];
    }

    sort(p.begin(), p.end());

    long long jib = p[0];

    int op = 0;

    for(int k = 1; k < p.size(); k++){
        if (p[k-1] != p[k]) op++;
    }

    cout << op+1 << endl;
    
}