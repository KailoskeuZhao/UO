#include <bits/stdc++.h>

std::vector<int> exsear(std::string S, std::string T, int fsc, int bsc){
    std::string fp = "", lp =  "", wp = "";
    std::vector<int> ha;
    int nfsc, nbsc;
    bool comple;

    while(!comple){
        comple = true;
        for(int n = 1; n < T.size(); n++){
            
            nfsc = fsc - T.size() + n;
            nbsc = bsc + n;
            if(nbsc >= S.size()){
                break;
            }
            for(int n = nfsc; n < fsc; n++){
                fp = fp + S[n];
            }
            for(int n = bsc + 1; n < (nbsc + 1); n++){
                lp = lp + S[n];
            }
            wp = fp + lp;
            if(wp == T){
                fsc = nfsc;
                bsc = nbsc;
                fp = "", lp =  "", wp = "";
                comple = false;
                break;
            }

        }

        if (comple){
        ha.push_back(fsc);
        ha.push_back(bsc);
        }
    }
    return ha;

}

int main(){
    freopen("censor.in", "r", stdin);
    int stlen, fsc, bsc;
    std::string S, T, temp1;
    std::cin >> S >> T;

    std::vector<int> censp;
    std::vector<int> dudu;

    for(int m = (T.size() - 1); m < S.size(); m++){
        for(int j = 0; j < T.size(); j++){
            temp1 += S[m - T.size() +1 +j];
        }

        if(temp1 == T){
            fsc = (m - T.size() +1);
            bsc = m;
            dudu = exsear(S, T, fsc, bsc);
            for(int n = dudu[0]; n < dudu[1] + 1; n++){
                S[n] = '*';
            }
            
        }

        temp1 = "";

    }

    freopen("censor.out", "w", stdout);
    for(int n = 0; n < S.size(); n++){
        if(S[n] != '*'){
            std::cout << S[n];
        }
    }
    
}

