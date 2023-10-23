#include <bits/stdc++.h>

int main(){
    freopen("blocks.in", "r", stdin);    
   
    int ct[26];
    int sc1[26];
    int sc2[26];
    
    


    int n;
    std::cin >> n;
   
    for(int m = 0; m < 26; m++){
            ct[m] = 0;
        }

   
   
    for (int m = 0; m < n; m++){
        std::string a;
        std::string b;
        std::cin >> a >> b;

        for(int m = 0; m < 26; m++){
            sc1[m] = 0;
            sc2[m] = 0;
        }

        for(int t = 0; t < a.size(); t++){
            sc1[a[t]-'a'] += 1;
        }

        for(int t = 0; t < b.size(); t++){
            sc2[b[t]-'a'] += 1;
        }

        for(int t = 0; t < 26; t++){
            if(sc1[t] > sc2[t]){
                ct[t] += sc1[t];
            } else {
                ct[t] += sc2[t];
            }
        }

    }

    freopen("blocks.out", "w", stdout);

    for(int m = 0; m < 26; m++){
    std::cout << ct[m] << std::endl;
    }

}