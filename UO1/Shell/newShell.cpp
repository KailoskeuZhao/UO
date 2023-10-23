#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>


int main(){
    freopen("shell.in", "r", stdin);
    int it1;
    std::cin >> it1;
    std::array<int, 3> showler;
    std::array<int, 3> points;



    for(int i = 1; i <= 3; i++){
        showler[i-1] = i;
        points[i-1] = 0;
    }

    int a, b, c;

    for(int m = 0; m < it1; m++){
        std::cin >> a >> b >> c;
        std::swap(showler[a-1], showler[b-1]);
        points[showler[c-1]] +=1;
   }

   int fina = std::max({points[0], points[1], points[2]});

   freopen("shell.out", "w", stdout);
   std::cout << fina << "\n";
   return 0;

}