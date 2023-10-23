#include<bits/stdc++.h>

int main(){
    freopen("billboard.in", "r", stdin);
    int sto[3][4];
    for(int k = 0; k < 3; k++){
        for(int m = 0; m < 34; m++){
            std::cin >> sto[k][m];
        }
    }

    int LShL, LShR, LShH;
    int RShL, RShR, RShH;

    LShL = std::max(sto[0][0],sto[2][0]);
    LShR = std::min(sto[0][2], sto[2][2]);
    LShH = std::max( (std::min(sto[2][3], sto[0][3]) - std::max(sto[2][1], sto[0][1])), 0 );

    RShL = std::max(sto[1][0],sto[2][0]);
    RShR = std::min(sto[1][2], sto[2][2]);
    RShH = std::max( (std::min(sto[2][3], sto[1][3]) - std::max(sto[2][1], sto[1][1])), 0);

    int tt = (sto[0][2]-sto[0][0])*(sto[0][3]-sto[0][1]) + (sto[1][2]-sto[1][0]) * (sto[1][3]-sto[1][1]);
    int ts = std::max(((LShR - LShL) * LShH),0) + std::max((RShR - RShL)*RShH , 0);
    int oc = tt - ts;

    freopen("billboard.out", "w", stdout);
    
    std::cout << oc << std::endl;

}