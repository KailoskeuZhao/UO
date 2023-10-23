#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("whereami.in", "r", stdin);
    int n;
    cin >> n;
    string da;
    cin >> da;
    unordered_set<string> process1;

    int maxx = 0;

    string curr;
    for(int j = 1; j <= n; j++){
        curr.resize(j);
        for(int k = 0; k <= n-j; k++){
            for(int s = 0; s < j; s++){
                curr[s] = da[k+s];
            }
            if(process1.count(curr) == 1){
                if(curr.size() > maxx) maxx = curr.size();
            }
            process1.insert(curr);
        }
    }

    freopen("whereami.out", "w", stdout);

    cout << (maxx+1) << endl;

}