#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>> sto(3);
    vector<bool> rever{false, false, false, true, true, true};
    vector<pair<int, int>> amsto(3);
    vector<int> namea{'A', 'B', 'C'};

    vector<string> op;

    

    for(int m = 0; m < 3; m++){
        cin >> sto[m].first >> sto[m].second;
    }

    bool done = false;
    int sl = 0;

    do{
        do{
            next_permutation(namea.begin(), namea.end());

            amsto = sto;
            for(int k = 0; k < 3; k++){
                if(rever[k]){
                    swap(amsto[k].first, amsto[k].second);
                }
            }
            
            if(amsto[0].second == amsto[1].second){
                if((amsto[2].second + amsto[1].second) == amsto[2].first == (amsto[0].first + amsto[1].first)){
                    sl = amsto[0].first + amsto[1].first;
                    op.resize(sl);

                    for(string &e : op){
                        for(int m = 0; m < sl; m++)
                        e.push_back('n');
                    }

                    for(int m = 0; m < amsto[0].second; m++){
                        for(int j = 0; j < amsto[0].first; j++) op[m][j] = (char)(namea[0]);
                    }

                    for(int m = 0; m < amsto[0].second; m++){
                        for(int j = amsto[0].first; j < sl; j++) op[m][j] = (char)(namea[1]);
                    }

                    for(int m = amsto[0].second; m < sl; m++){
                        for(int j = 0; j < sl; j++) op[m][j] = (char)(namea[2]);
                    }

                    done = true;
                    break;
                }

                
            }

            if(amsto[0].first == amsto[1].first){
                if(amsto[0].first == (amsto[0].second + amsto[1].second + amsto[2].second) == amsto[2].first){
                    sl = amsto[0].first;
                    op.resize(sl);

                    for(string &e : op){
                        for(int m = 0; m < sl; m++)
                        e.push_back('n');
                    }

                    for(int m = 0; m < amsto[0].second; m++){
                        for(int j = 0; j < sl; j++) op[m][j] = (char)(namea[0]);
                    }

                    for(int m = amsto[0].second; m < (amsto[0].second + amsto[1].second); m++){
                        for(int j = 0; j < sl; j++) op[m][j] = (char)(namea[1]);
                    }

                    for(int m = (amsto[0].second + amsto[1].second); m < sl; m++){
                        for(int j = 0; j < sl; j++) op[m][j] = (char)(namea[2]);
                    }
                    
                    done = true;
                    break;

                }
            }



            

            if((amsto[0].first + amsto[1].first) == (amsto[0].first + amsto[2].first) ==
            amsto[0].second == (amsto[1].second + amsto[2].second)){
                sl = amsto[0].first + amsto[1].first;
                op.resize(sl);

                for(string &e : op){
                    for(int m = 0; m < sl; m++)
                    e.push_back('n');
                }

                for(string &t : op){
                    for(int j = 0; j < amsto[0].first; j++) t[j] = (char)(namea[0]);
                }
                for(int m = 0; m < amsto[1].second; m++) {
                    for(int j = amsto[0].first; j < (amsto[0].first + amsto[1].first); j++) op[m][j] = (char)(namea[1]);
                }
                for(int m = amsto[1].second; m < amsto[0].second; m++){
                    for(int j = amsto[0].first; j < (amsto[0].first + amsto[1].first); j++) op[m][j] = (char)(namea[2]);
                }
                done = true;
               
                break;
            }

            if((amsto[0].second + amsto[1].second) == (amsto[1].first) == (amsto[0].first + amsto[2].first) == (amsto[1].second + amsto[2].second)){
                for(int m = 0; m < amsto[0].second; m++){
                sl = amsto[1].first;
                op.resize(sl);
                    for(int j = 0; j < amsto[0].first; j++) op[m][j] = (char)(namea[0]);
                }
                for(int m = 0; m < amsto[2].second; m++){
                    for(int j = amsto[0].first; j < (amsto[0].first + amsto[2].first); j++) op[m][j] = (char)(namea[1]);
                }
                for(int m = amsto[0].second; m < (amsto[0].second + amsto[1].second); m++){
                    for(int j = 0; j < amsto[1].first; j++) op[m][j] = (char)(namea[2]);
                }
                done = true;

                 for(string &e : op){
                    for(int m = 0; m < sl; m++)
                    e.push_back('n');
                }
       
                break;
            }

            

        }
        while(next_permutation(sto.begin(), sto.end()));
    } while(next_permutation(rever.begin(), rever.end()) && !done);

    if(done){
    cout << sl << endl;
    for(string &a : op) cout << a << endl;
    } else{
        cout << -1 << endl;
    }

}