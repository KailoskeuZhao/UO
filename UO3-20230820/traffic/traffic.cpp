#include <bits/stdc++.h>

int r0(int a){
    if (a < 0) {
        return 0;
    } else {
        return a;
    }
}

int main(){
    freopen("traffic.in", "r", stdin);
    int n;
    std::cin >> n;

    struct tra{
        std::string type;
        int lb;
        int ub;
    };

    tra sto[n];
    int fnone;
    int lnone;
    bool f1 = false;
    bool f2 = false;

    for (int m = 0; m < n; m++){
        std::cin >> sto[m].type >> sto[m].lb >> sto[m].ub;
        
            if(!f1){
                if(sto[m].type == "none" ){
                    fnone = m;
                    f1 = true;
                }
            }
            if (!f2){
                if(sto[m-1].type == "none" && sto[m].type != "none"){
                    lnone = m-1;
                    f2 = true;
                }
            }
            
        }
    
    if(!f2){
        lnone = n-1;
        f2 = true;
    }

    int op[2][2];
    op[0][0] = sto[fnone].lb;
    op[0][1] = sto[fnone].ub;

    for(int m = fnone; m < lnone; m++){
        if(sto[m+1].lb >= op[0][0]){
            op[0][0] = sto[m+1].lb;
        }
        if(sto[m+1].ub <= op[0][1]){
            op[0][1] = sto[m+1].lb;
        }
    }

    op[1][0] = op[0][0];
    op[1][1] = op[0][1];

    for(int m = fnone-1; m >= 0; m--){
        if(sto[m].type == "on"){
            op[0][0] -= sto[m].ub;
            op[0][0] = r0(op[0][0]);
            op[0][1] -= sto[m].lb;
            op[0][1] = r0(op[0][1]);
            
        }
        if(sto[m].type == "off"){
            op[0][0] += sto[m].lb;
            op[0][1] += sto[m].ub;
        }
    }

    for(int m = lnone + 1; m < n; m++){

        if(sto[m].type == "none"){
            if(sto[m].lb >= op[1][0]){
                op[1][0] = sto[m].lb;
            }
            if(sto[m].ub <= op[1][1]){
                op[1][1] = sto[m].lb;
            }
        }

        if(sto[m].type == "on"){
            op[1][0] += sto[m].lb;
            op[1][1] += sto[m].ub;
        }

        if(sto[m].type == "off"){
            op[1][0] -= sto[m].ub;
            op[1][0] = r0(op[1][0]);
            op[1][1] -= sto[m].lb;
            op[1][1] = r0(op[1][1]);
        }

    }
    
    freopen("traffic.out", "w", stdout);

    for(int m = 0; m < 2; m++){
        std::cout << op[m][0] << " " << op[m][1] << std::endl;
    }
    return 0;
}