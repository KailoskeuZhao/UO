#include<bits/stdc++.h>

using namespace std;

main(){

    freopen("gymnastics.in", "r", stdin);

    int k, n;
    cin >> k >> n;
    int da[n][k][1];

    int who, how;
    for(int l = 0; l < k; l++){
        for(int m = 0; m < n; m++){
        cin >> who;
        who--;
        da[who][l][0] = m;
        }
    }

    int pairs = 0;
   

    for(int m = 0; m < n; m++){

        

        for(int j = 1 + m; j < n; j++){
            int win = 0;
            int lose = 0;
            for(int l = 0; l < k; l++){
                if(da[m][l][0] > da[j][l][0]) win++;
                if(da[m][l][0] < da[j][l][0]) lose++;
            }

            if(win*lose == 0 ) pairs ++;

        }
    }

    freopen("gymnastics.out", "w", stdout);
    cout << pairs << endl;
    
}