#include <bits/stdc++.h>

int main(){
    int c = 321;
    int *p = &c;
    int &r = *p;
    r += 9;

    std::cout << *p << std::endl;
}