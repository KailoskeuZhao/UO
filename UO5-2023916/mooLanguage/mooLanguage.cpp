#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, c, p;
    cin >> n >> c >> p;
    vector<string> noun, tran, intran, conj;
    vector<char> output;
    int maxx = 0;
    int curr = 0;

    int currN, currC, currP, currTa, CurrIn, CurrJ;
    int totN{0}, totC{c}, totP{p}, totTa{0}, totIn{0}, totJ{0};

    string typeo, wordo;

    for(int m = 0; m < n; m++){
        cin >> wordo >> typeo;
        if(typeo[0] == 't'){
            tran.push_back(wordo);
            totTa++;
        } else if(typeo[0] == 'i'){
            intran.push_back(wordo);
            totIn++;
        } else if(typeo[0] == 'n'){
            noun.push_back(wordo);
            totN++;
        } else {
            conj.push_back(wordo);
            totJ++;
        }
    }

    int totLb = min(totJ, totP) + totP;
    int totJAv = min(totJ, totP);

    int maxT2 = min((totN/2), totTa);
    int maxFN;
    bool BEx = false;

    int OpN, OpJ, OpIn, OpTa, OpC, OpP;

    int OpBoccu, OpAoccu;

    for(int j = 0; j <= maxT2; j++){

        currN = 2*j;
        currTa = j;

        maxFN = min((totN - currN), totC);
        BEx = j;
        int remA;
        
        int Boccu, Aoccu, OpConj;
        for(int h = 0; h <= maxFN; h++){
            currN = currN + h;
            currC = h;

            remA = min((totN - currN), totTa);

            Boccu = min(totLb, j);
            Aoccu = max(0,  min(remA, (totLb - Boccu)));

            OpConj = min(((Boccu + Aoccu)/2), totJAv);
            
            if(!Boccu) currC = 0;
            curr = Boccu*3 + Aoccu*2 + currC + OpConj;

            if(curr > maxx){
                maxx = curr;
                OpAoccu = Aoccu;
                OpBoccu = Boccu;
                OpP = Boccu + Aoccu - OpConj;
                OpJ = min(totJAv, (totLb - OpP));
                OpN = currN + remA;
                OpC = h;
                OpTa = remA;
                OpIn = j;

            }
            
        }
    }

    cout << maxx << endl;

    int linN = 0, linTA = 0, linIn = 0, linJ = 0;

    bool CanJ = false;

    for(int k = 0; k < OpAoccu; k++){
        if(linJ < OpJ && CanJ){
        cout << " " <<  conj[linJ] + " " << noun[linN] + " " << tran[linTA] << ".";
        linN ++;
        linTA ++;
        linJ ++;
        CanJ = false;
        if(k != OpAoccu - 1 && !OpBoccu) cout << " ";
        } else {
            cout << noun[linN] + " " << tran[linTA];
            CanJ = true;
            linN ++;
            linTA ++;
            if(linJ == OpJ && OpBoccu == 0) cout << ".";
            else if(linJ == OpJ) cout << ". ";
        }
        
    }

    for(int k = 0; k < OpBoccu; k++){
        if(k = OpBoccu -1){
            if(linJ < OpJ && CanJ) cout << " " << conj[linJ];
            else cout << noun[linN] + " " << intran[linIn] + " " << noun[linN];
            
            
            for(int l = 0; l < OpC; l++){
                cout << ", " << noun[linN];
                linN++;
            }

            cout << ".";
        }
        else if(linJ < OpJ && CanJ){
            cout << " " << conj[linJ] + " " << noun[linN] + " " << intran[linIn] + " " << noun[linN] << ". ";
            linJ++;
            linN += 2;
            linIn++;
        } else{
            cout << noun[linN] << " " + intran[linIn] << " " + noun[linN];
            linN += 2;
            linIn ++;
            if(linJ == OpJ) cout << ". ";
        }

    }



}
int main(){
    int T;
    cin >> T;
    for(int ba = 0; ba < T; ba++) solve();

}