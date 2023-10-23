#include <bits/stdc++.h>

std::vector<int> cal(std::vector<int> s, char t){   
    if(t == 'E'){
        s[0] += 1;
    }
    if(t == 'W'){
        s[0] -= 1;
    }
    if(t == 'N'){
        s[1] += 1;
    }
    if(t == 'S'){
        s[1] -= 1;
    }

    return s;
}

int main(){
    std::vector<int> gd(2, 0); 
    int n;
    freopen("mowing.in", "r", stdin);

    std::cin >> n;

    char direc;
    int steps;
    std::vector<std::vector<int>> d;
    d.push_back({0, 0});
    std::vector<int> cur(2);
    int x;

    for(int m = 0; m < n; m++){
        std::cin >> direc >> steps;
        for(int j = 0; j < steps; j++){
            gd = cal(gd, direc);
            cur[0] = gd[0];
            cur[1] = gd[1];
            d.push_back(cur);
        }

    }

    int t = INFINITY;
    int a = t;

    for(int m = 0; m < d.size(); m++){
        for(int j = m+1; j < d.size(); j++){
            if(d[m][0] == d[j][0] && d[m][1] == d[j][1]){
                if ((j - m ) < t ){
                    t = (j-m);
                }
                break;
            }
        }
    }

    if(t == a) t = -1;
    
    freopen("mowing.out", "w", stdout);
    std::cout << t << std::endl;


}