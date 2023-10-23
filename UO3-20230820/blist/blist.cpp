#include <bits/stdc++.h>

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    std::cin >> n;

    int sto[n][3];

    for(int m = 0; m < n; m++){
        std::cin >> sto[m][0] >> sto[m][1] >> sto[m][2];
    }

    int t;
    int histB = 0;
    int cB = 0;

    for (int t = 1; t < 1001; t++){
        for(int k = 0; k < n; k++){
            if(sto[k][0] == t){
                cB += sto[k][2];
            }
            if(sto[k][1] == t){
                cB -= sto[k][2];
            }
        }
        if (cB >= histB) histB = cB;
    }

    std::cout << histB;
}