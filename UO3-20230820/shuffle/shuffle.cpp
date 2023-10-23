#include <bits/stdc++.h>

int main(){
    int cnum = 0;
    freopen("shuffle.in", "r", stdin);
    std::cin >> cnum;
    int shuf[(2*cnum)];
    int cows[cnum][2];

    for (int n = 0; n < cnum; n++){
        shuf[(2*n)] = (n+1);
        std::cin >> shuf[(2*n)+1];
        
    }

    for (int n = 0; n < cnum; n++){
        cows[n][0] = n+1;
    }

    
    int newcows[cnum][2];

    for (int t = 0; t < 3; t++){
        for(int n = 0; n < 2 * cnum; n += 2){

           newcows[shuf[n+1]-1][0] = cows[shuf[n]-1][0];
           
            
        }
        for(int m = 0; m < cnum; m++){
            cows[m][0] = newcows[m][0];
        }
    }

    for (int n = 0; n < cnum; n++){
        std::cin >> cows[n][1];
    }

    freopen("shuffle.out", "w", stdout);

    for (int n = 0; n < cnum; n++){
        for (int j = 0; j < cnum; j++){
            if ((n+1) == (cows[j][0])){
                std::cout << cows[j][1] << std::endl;
            }
        }
    }

}