#include <bits/stdc++.h>

int main(){
    int x, y;

    freopen("lostcow.in", "r", stdin);
    std::cin >> x >> y;

    int req = y - x;
    int mov = 0;
    int at = 1;

    int pres = 0;
    int fin = 0;
    bool fond = false;

    for (int n = 1; !fond; n += 2){
        if (req <= at && req >= 0){
            mov = n;
            fond = true;
        }
        if (!fond) at *= (-2);
        if (req >= at && req <= 0){
            mov = n+1;
            fond = true;
        }
        if (!fond) at *= (-2);

    }

    int nexto = 1;
    int preto = 0;
    for (int n = 1; n < mov; n++){
        pres += preto;
        pres += nexto;
        preto = nexto;
        nexto *= 2;

    }

    at /= (-2);
    if (at < req){
        fin = req - at;
    } else {
        fin = at - req;
    }

    freopen("lostcow.out", "w", stdout);
    std::cout << (pres + fin) << std::endl;

}