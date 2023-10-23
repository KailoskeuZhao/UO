#include <iostream>
#include <bits/stdc++.h>
#include <array>

std::array<int, 2> pour(std::array<int, 3> show, std::array<int, 3> capa, int p, int pd){
    std::array<int, 2> ret;
    int poFr = (capa[pd]-show[pd]);
    if(poFr < show[p]){
        show[p] -= poFr;
        show [pd] = capa[pd];
    } else {
        show[pd] += show[p];
        show[p] = 0;
        
    }

    ret[0] = show[p];
    ret[1] = show[pd];

    return ret;


}

int main(){
    freopen("mixmilk.in","r", stdin);

    std::array<int, 3> show;
    std::array<int, 3> capa;
    std::array<int, 2> tempo;

    for(int i = 0; i < 3; i++){

        std::cin >> capa[i];
        std::cin >> show[i];
        
    }

    for(int m = 0; m < 33; m++){

        tempo = pour(show, capa, 0, 1);
        show[0] = tempo[0];
        show[1] = tempo[1];
        tempo = pour(show, capa, 1, 2);
        show[1] = tempo[0];
        show[2] = tempo[1];
        tempo = pour(show, capa, 2, 0);
        show[2] = tempo[0];
        show[0] = tempo[1];
    }
    
    tempo = pour(show, capa, 0, 1);
        show[0] = tempo[0];
        show[1] = tempo[1];

    freopen("mixmilk.out", "w", stdout);

    for (int j = 0; j < 3; j++){
        std::cout << show[j] << "\n";
    }

}


