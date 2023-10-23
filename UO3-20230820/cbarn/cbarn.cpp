#include <bits/stdc++.h>

int main(){
    freopen("cbarn.in", "r", stdin);

    int n;
    std::cin >> n;
    int steps = 0;
    int osteps = INFINITY;

    int band[n];
    int barn[n];
    for(int m = 0; m < n; m++){
        std::cin >> barn[m];
        band[m] = m;
    }
    int newf;

    for(int m = 0; m < n; m++){
        newf = band[n-1];

        for(int k = 0; k < n; k++){
        steps += band[k]*barn[k];
        }

        for (int j = n-1; j > 0; j--){
            band[j] = band[j-1];
        }

        band[0] = newf;

        if(steps < osteps){
            osteps = steps;
        }

        steps = 0;
    }

    freopen("cbarn.out", "w", stdout);
    std::cout << osteps;

}

