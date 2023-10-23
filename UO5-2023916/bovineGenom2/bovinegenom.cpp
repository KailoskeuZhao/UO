#include <bits/stdc++.h>

using namespace std;

int comp(vector<string> cmspo, vector<string> cmplc, int n){
    int curr = 0;
    bool aha = true;
    for(int l = 0; l < n; l++){
        for(int k = 0; k < n; k++){
            if (cmspo[l] == cmplc[k]) aha = false;
        }
    }

    if (aha) curr = 1;
    return curr;

}

int main(){
    int n, m;

    freopen("cownomics.in", "r", stdin);
    cin >> n >> m;

    string test1;

    vector<string> spo(n), plc(n);
    vector<string> cmspo(n), cmplc(n);
    string tobe = "   ";
    /*
    for (int k = 0; k < n; k++){
        cmspo[k] = "";
        cmplc[k] = "";
    }
    */

    for(int k = 0; k < n; k++){
       cin >> spo[k];
    }

    for(int k = 0; k < n; k++){
        cin >> plc[k];
    }

    int how = 0;

    for(int k = 0; k < m; k++){
        for(int t = k+1; t < m; t++){
            for(int l = t+1; l < m; l++){

                for(int g = 0; g < n; g++){
                    tobe[0] = spo[g][k];
                    tobe[1] = spo[g][t]; 
                    tobe[2] = spo[g][l];
                    cmspo[g] = tobe;
                    tobe[0] = plc[g][k];
                    tobe[1] = plc[g][t];
                    tobe[2] = plc[g][l];
                    cmplc[g] = tobe;
                }
                
                how += comp(cmspo, cmplc, n);
             
            }
        }
    }

    freopen("cownomics.out", "w", stdout);
    cout << how << endl;
}