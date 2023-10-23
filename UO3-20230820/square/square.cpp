#include<bits/stdc++.h>

struct Square{
    int x1,y1,x2,y2;
};

int main(){
    freopen("square.in", "r", stdin);
    Square a, b;

    std::cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    std::cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    int widspan = std::max(a.x2, b.x2) - std::min(a.x1, b.x1);
    int hispan = std::max(a.y2, b.y2) - std::min(a.y1, b.y1);

    int fw = std::max(widspan, hispan);
    
    freopen("square.out", "w", stdout);

    std::cout << fw * fw << std::endl;
}