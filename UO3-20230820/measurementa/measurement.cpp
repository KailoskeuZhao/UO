#include <bits/stdc++.h>

main(){
    int n;
    freopen("measurement.in", "r", stdin);
    std::cin >> n;

    struct logr{
        std::string cna;
        int cvol;
        bool marked = false;
    };

    struct co{
        bool iswin;
        int cvol;
    };

    std::vector<logr> sto(1001);
    co j[3];

    for(int m = 0; m < 3; m++){
        j[m].iswin = true;
        j[m].cvol = 7;
    }

    int omax = 7;
    int cmax = 7;

    int chag = 0;

    bool chage = false;

    for(int m = 0; m < n; m++){
        int cnum = 0;
        std::cin >> cnum; 
        std::cin >> sto[cnum].cna >> sto[cnum].cvol;
        sto[cnum].marked = true;
    }

    for(int m = 0; m < 1001; m++){
        if(sto[m].marked){
            if(sto[m].cna == "Bessie"){
                j[0].cvol += sto[m].cvol;
            }
            if(sto[m].cna == "Elsie"){
                j[1].cvol += sto[m].cvol;
            }
            if(sto[m].cna == "Mildred"){
                j[2].cvol += sto[m].cvol;
            }
        
        cmax = j[0].cvol;
        for(int k = 0; k < 3; k++){
            if (j[k].cvol > cmax){
                cmax = j[k].cvol;
            }
        }

        omax = cmax;

        for(int k = 0; k < 3; k++){
            if (j[k].cvol == cmax && !j[k].iswin){
                chage = true;
                j[k].iswin = true;
            }

            if(j[k].cvol < cmax){
                if(j[k].iswin){
                    chage = true;
                }
                j[k].iswin = false;
            }
        }

        if(chage){
            chag ++;
            chage = false;
        }

        }
        
    }

    freopen("measurement.out", "w", stdout);
    std::cout << chag << std::endl;
}