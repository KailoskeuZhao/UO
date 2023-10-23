#include<bits/stdc++.h>

int main(){
    freopen("paint.in", "r", stdin);
    bool fence[100];
    for(int m = 0; m < 100; m++){
        fence[m] = false;
    }
    
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    for(int m = c; m < d; m++){
        fence[m] = true;
    }
    
    for (int m = a; m < b; m ++){
        fence[m] = true;
    }

    int pt = 0;

    for(int m = 0; m < 100; m++){
        if (fence[m]) pt++;
    }

    freopen("paint.out", "w", stdout);

    std::cout << pt << std::endl;

    
 
}