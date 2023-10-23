#include <iostream>

using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    

    int rd;
    cin >> rd;
    int sco = 0;
    int psco = 0;
    int now = 0;
    int af = 0;
    int a, b, c;

    for(int i = 1; i <= 3; i++){
        now = i;
    for(int n = 0; n < rd; n++){
        cin >> a >> b >> c;
        if (now == a){af = b;}
        else if (now == b){af = a;}
        else {af = now;}

        if (c == af){sco += 1;}
        now = af;
    }
       
       if(sco >= psco){
        psco = sco;
       };
       sco = 0;

    }

    freopen("shell.out", "w", stdout);
    cout << psco << endl;
    return 0;
}