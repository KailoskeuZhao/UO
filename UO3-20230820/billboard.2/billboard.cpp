#include <bits/stdc++.h>

struct bbo{
    int x1, y1, x2, y2;
};

int main(){
    bbo shade;
    bbo board;

    freopen("billboard.in", "r", stdin);

    std::cin >> board.x1 >> board.y1 >> board.x2 >> board.y2;
    std::cin >> shade.x1 >> shade.y1 >> shade.x2 >> shade.y2;

    int w, h;

    if(shade.y1 <= board.y1 && shade.y2 >= board.y2){
        if(shade.x2 >= board.x1 && shade.x1 <= board.x1){
            w = board.x2 - board.x1 - (std::min(shade.x2, board.x2) - std::max(board.x1, shade.x1));
        }
        else if (shade.x2 >= board.x2 && shade.x1 >= board.x1 ){
            w = board.x2 - board.x1 - (std::min(shade.x2, board.x2) - std::max(board.x1, shade.x1));
        }
        else{ w = board.x2 - board.x1; }
    } else {
        w = board.x2 - board.x1;
    }

    if(shade.x2 >= board.x2 && shade.x1 <= board.x1){
        if(shade.y1 >= board.y1 && shade.y2 >= board.y2){
            h = board.y2- board.y1 - (std::min(board.y2, shade.y2) - std::max(board.y1, shade.y1));
        } else if (shade.y2 >= board.y1 && shade.y1 <= board.y1){
            h = board.y2 - board.y1 - (std::min(board.y2, shade.y2) - std::max(board.y1, shade.y1));
        } 
        else{ h = board.y2 - board.y1; }
    } else {
        h = board.y2 - board.y1;
    }

    freopen("billboard.out", "w", stdout);
    
    std::cout << w*h << std::endl;
    
}