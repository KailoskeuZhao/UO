#include <bits/stdc++.h>

using namespace std;

int main(){
    string in, des;
    bool flipped = false;
    int strlen;

    freopen("breedflip.in", "r", stdin);
    cin >> strlen >> in >> des;

    int f_need = 0;

    for(int l = 0; l < strlen; l++){
        if(in[l] != des[l]){
            if(!flipped){
                f_need++;
            }
            flipped = true;
        } else flipped = false;
    }

    freopen("breedflip.out", "w", stdout);

    cout << f_need << endl;
}