#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("cowtip.in", "r", stdin);
    int N;
    cin >> N;
    string ined;

    int sto[N][N];

    for(int n = 0; n < N; n++){
        cin >> ined;
        for(int l = 0; l < N; l++){
            sto[n][l] = ined[l]-48;
        }
    }

    bool tipping = true;
    pair<int, int> tp;
    tp.first = -1;
    tp.second = -1;
    bool checked;

    int num = 0;

    while(tipping){

        checked = true;
        for(int l = 0; l < N; l++){
            for(int n = 0; n < N; n++){
                if(sto[l][n]) checked = false;
            }
        }

        if(checked) break;

        num++;

        for(int h = 0; h < N; h++){
            for(int w = 0; w < N; w++){
                if(sto[h][w]){
                    if(w >= tp.first){
                        tp.first = w;
                        if(h >= tp.second){
                            tp.second = h;
                        }
                    }
                }
            }
        }

        for(int l = 0; l <= tp.second; l++){
            for(int t = 0; t <= tp.first; t++){
                if(sto[l][t]) sto[l][t] = 0;
                else sto[l][t] = 1;
            }
        }

        tp.first = -1;
        tp.second = -1;

    }
    
    freopen("cowtip.out", "w", stdout);
    cout << num << endl;

}