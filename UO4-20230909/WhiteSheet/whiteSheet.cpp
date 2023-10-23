#include<bits/stdc++.h>

struct rect{
long x1, y1, x2, y2;

};

bool singFull(rect x, rect y){
    return x.x1 <= y.x1 && x.y1 <= y.y1 && x.x2 >= y.x2 && x.y2 >= y.y2;
}

bool midJie(rect x1, rect x2, rect y){
    return std::min(x1.x1, x2.x1) <= y.x1 && 
    std::max(x1.x2, x2.x2) >= y.x2 &&
    x1.y1 <= y.y1 && x1.y2 >= y.y2 &&
    x2.y1 <= y.y1 && x2.y2 >= y.y2 &&
    std::min(x1.x2, x2.x2) >= std::max(x1.x1, x2.x1);
}

bool halfJie(rect x1, rect x2, rect y){
    return
    std::max(x1.y2, x2.y2) >= y.y2 &&
    std::min(x1.y1, x2.y1) <= y.y1 &&
    x1.x1 <= y.x1 && x1.x2 >= y.x2 &&
    x2.x1 <= y.x1 && x2.x2 >= y.x2 &&
    std::min(x1.y2, x2.y2) >= std::max(x1.y1, x2.y1);

    
}

int main(){

    //freopen("input.txt", "r", stdin);



rect sha1, sha2, whpa;

std::cin >> whpa.x1 >> whpa.y1 >> whpa.x2 >> whpa.y2;
std::cin >> sha1.x1 >> sha1.y1 >> sha1.x2 >> sha1.y2;
std::cin >> sha2.x1 >> sha2.y1 >> sha2.x2 >> sha2.y2;

bool sinFu = false;

sinFu = singFull(sha1, whpa) || singFull(sha2, whpa);

bool midJi = false;

midJi = midJie(sha1, sha2, whpa);

bool halfJi = false;

halfJi = halfJie(sha1, sha2, whpa);

bool yep = false;

yep = sinFu || (midJi||halfJi);



if (yep){
std::printf("NO\n");
} else {
    std::printf("YES\n");
}



}