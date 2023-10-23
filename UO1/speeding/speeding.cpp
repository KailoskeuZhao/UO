#include <bits/stdc++.h>
#include <vector>

int dl(int a, std::vector<int> b){
    int suf = 0;
    for(int n = 0; n <= b.size(); n += 2){
        suf += b[n];

        if (a <= suf ){
            return b[n+1];
        }
    }

}

int main(){
    int n, m;

    int a;

    std::vector<int> speedLimits;
    std::vector<int> speeds;

    freopen("speeding.in", "r", stdin);

    std::cin >> n >> m;
    
    
    for(int j = 0; j < (2*n); j++){
        std::cin >> a;
        speedLimits.push_back(a); 
    }

    for(int n = 0; n < (2*m); n++){
        std::cin >> a;
        speeds.push_back(a);
    }

    int co = 0;

    for (int n = 0; n <= 100; n++){
        if ((dl(n, speeds) - dl(n, speedLimits)) >= co){
            co = (dl(n, speeds) - dl(n, speedLimits));

        }
        

    }

    freopen("speeding.out", "w", stdout);

    std::cout << co;

   

}

