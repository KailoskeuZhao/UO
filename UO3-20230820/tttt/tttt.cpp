#include <bits/stdc++.h>

int tvco(int dis){
    if (dis > 0 && dis < 3) {return 1;}
    else return 0;

}

int ivco(int dis){
    if (dis == 3) {return 1;}
    else return 0;
}

int csm(int a, int b, int c){
    int t = 0;
    if (a == b) t++;
    if (b == c) t++;
    if (c == a) t++;
    return t;
}

int main(){
    int bd[3][3];
    int iv = 0, tv = 0;

    freopen("tttt.in", "r", stdin);
    std::string curl;

    for (int m = 0; m < 3; m++){
        std::cin >> curl;
        for(int j = 0; j < 3; j++){
            bd[m][j] = curl[j];
        }
    }

    int ver;

    for (int n = 0; n < 3; n++){
    ver = csm(bd[n][0], bd[n][1], bd[n][2]);
    iv += ivco(ver); 
    tv += tvco(ver);
    ver = csm(bd[0][n], bd[1][n], bd[2][n]);
    iv += ivco(ver); 
    tv += tvco(ver);
    }

    ver = csm(bd[0][0], bd[1][1], bd[2][2]);
    iv += ivco(ver); 
    tv += tvco(ver);
    ver = csm(bd[0][2], bd[1][1], bd[2][0]);
    iv += ivco(ver); 
    tv += tvco(ver);
    
    freopen("tttt.out", "w", stdout);
    std::cout << iv << std::endl << tv << std::endl;
}

