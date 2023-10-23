#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<vector<int>> da(26);

    freopen("circlecross.in", "r", stdin);

    string ined;
    cin >> ined;

    for(int n = 0; n < 52; n++){
        da[ined[n]-'A'].push_back(n);
    }

    int inn = 0, noin = 0, pairs = 0;

    for(int n = 0; n < 26; n++){
        for(int k = 0; k < 26; k++){
            if(da[k][0] < da[n][1] && da[k][0] > da[n][0]){
                inn++;
            } else {noin ++;}
            if(da[k][1] < da[n][1] && da[k][1] > da[n][0]){
                inn++;
            } else {noin ++;}
            
            if(noin == 1 && inn ==1){
                pairs ++;
            }

            inn = 0;
            noin = 0;
        }
    }
    
    freopen("circlecross.out", "w", stdout);
    cout << pairs/2 << endl;

}