#include <bits/stdc++.h>

using namespace std;

struct descript{
    string beborn;
    string fromborn;
    string order;
    string zod;
};

int main(){
    map<string, int> zod;
    zod["Ox"] = 1;
    zod["Tiger"] = 2;
    zod["Rabbit"] = 3;
    zod["Dragon"] = 4;
    zod["Snake"] = 5;
    zod["Horse"] = 6;
    zod["Goat"] = 7;
    zod["Monkey"] = 8;
    zod["Rooster"] = 9;
    zod["Dog"] = 10;
    zod["Pig"] = 11;
    zod["Rat"] = 12;

    int n;
    cin >> n;
    string disca;
    vector<descript> da(n);
    map<string, int> fromBessie;
    map<string, string> eachZod;
    for(int l = 0; l < n; l++){
        cin >> da[l].beborn >> disca >> disca >> da[l].order >> da[l].zod >> disca >> disca >> da[l].fromborn;
    }

    fromBessie["Bessie"] = 0;
    eachZod["Bessie"] = "Ox";

    for(descript &a : da){
        eachZod[a.beborn] = a.zod;
        if(a.order == "previous"){
            if(zod[eachZod[a.fromborn]] == zod[eachZod[a.beborn]]){
                fromBessie[a.beborn] = fromBessie[a.fromborn] - 12;
            } else if(zod[eachZod[a.fromborn]] > zod[eachZod[a.beborn]]){
                fromBessie[a.beborn] = fromBessie[a.fromborn] - (zod[eachZod[a.fromborn]] - zod[eachZod[a.beborn]]);
            } else{
                fromBessie[a.beborn] = fromBessie[a.fromborn]- (12 - (zod[eachZod[a.beborn]] - zod[eachZod[a.fromborn]]));
            }
        } else{
            if(zod[eachZod[a.fromborn]] == zod[eachZod[a.beborn]]){
                fromBessie[a.beborn] = fromBessie[a.fromborn] + 12;
            } else if(zod[eachZod[a.beborn]] >= zod[eachZod[a.fromborn]]){
                fromBessie[a.beborn] = fromBessie[a.fromborn] + (zod[eachZod[a.beborn]] - zod[eachZod[a.fromborn]]);
            } else{
                fromBessie[a.beborn] = fromBessie[a.fromborn] + (12 - (zod[eachZod[a.fromborn]] - zod[eachZod[a.beborn]]));
            }
        }
    }

    cout << std::abs(fromBessie["Elsie"]) << endl;



}