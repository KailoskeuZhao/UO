#include <bits/stdc++.h>

using namespace std;


int main(){

    int n, k, h;
    string dis1, ba;

    freopen("guess.in", "r", stdin);

    cin >> n;

    vector<pair<int ,vector<string>>> da(n);
    

    for(int m = 0; m < n; m++){
       
        cin >> dis1 >> k;
        da[m].first = k;
        for(int t = 0; t < k; t++){
            cin >> ba;
            da[m].second.push_back(ba);
        }
    }

    int maxx = 0;
    int curr = 0;

    
    for(int m = 0; m < n-1; m++){
        for(int k = (m+1); k < n; k++){
            for(int t = 0; t < da[m].first; t++){
                for(int j = 0; j < da[k].first; j++){
                    
                    if(da[m].second[t] == da[k].second[j]) curr++;
                }
                
            }

            if(curr > maxx) maxx = curr;
            curr = 0;
        }
    }

    freopen("guess.out", "w", stdout);
    cout << maxx+1 << endl;

}