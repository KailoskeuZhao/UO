#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("tttt.in", "r", stdin);
    string da[3];
    for(int n = 0; n < 3; n++){
       cin >> da[n];
    }

    unordered_set<char> checker;
    unordered_set<char> ivwins;
    set<char> pushas;
    unordered_set<string> twins;
    string puchasa;
    

    for(int l = 0; l < 3; l++){
        checker.clear();
        for(int p = 0; p < 3; p++){
            checker.insert(da[l][p]);
        }
        if(checker.size() == 1){

            for(const char &a : checker){
                ivwins.insert(a);
            }
        }
        if(checker.size() == 2){
            puchasa = "";
            for(const char &a : checker){
                pushas.insert(a);
            }
            for(const char &a : pushas){
                puchasa = puchasa + a;
            }
            twins.insert(puchasa);
            checker.clear();
            pushas.clear();
            
        }
    }

    checker.clear();

    for(int l = 0; l < 3; l++){
        checker.clear();
        for(int p = 0; p < 3; p++){
            checker.insert(da[p][l]);
        }
        if(checker.size() == 1){
            for(const char &a : checker){
                ivwins.insert(a);
            }
        }
        if(checker.size() == 2){
             puchasa = "";
            for(const char &a : checker){
                pushas.insert(a);
            }
            for(const char &a : pushas){
                puchasa = puchasa + a;
            }
            twins.insert(puchasa);
            checker.clear();
            pushas.clear();
            
        }
    }

    checker.clear();

    for(int l = 0; l < 3; l++){
        checker.insert(da[l][l]);
    }

    if(checker.size() == 1){
        for(const char &a : checker){
                ivwins.insert(a);
            }
    }
    if(checker.size() == 2){
        puchasa = "";
            for(const char &a : checker){
                pushas.insert(a);
            }
            for(const char &a : pushas){
                puchasa = puchasa + a;
            }
            twins.insert(puchasa);
            checker.clear();
            pushas.clear();
    }

    checker.clear();

    for(int l = 0; l < 3; l++){
        checker.insert(da[l][2-l]);
    }

    
    if(checker.size() == 1){
          for(const char &a : checker){
                ivwins.insert(a);
            }
    }
    if(checker.size() == 2){
        puchasa = "";
            for(const char &a : checker){
                pushas.insert(a);
            }
            for(const char &a : pushas){
                puchasa = puchasa + a;
            }
            twins.insert(puchasa);
            checker.clear();
            pushas.clear();
    }

    freopen("tttt.out", "w", stdout);

    cout << ivwins.size() << endl << twins.size() << endl;

}