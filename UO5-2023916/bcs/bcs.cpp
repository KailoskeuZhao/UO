#include <bits/stdc++.h>

using namespace std;

vector<int> Turan(vector<pair<int, int>> da, vector<vector<pair<int, int>>> scrap, int k){
    bool assumeFit = false;
    vector<int> dis = {0};

    vector<tuple<int, int, bool>> thisDa, anotherDa;

    for(int j = 0; j < da.size(); j++){
        thisDa.push_back(make_tuple(da[j].first, da[j].second, false));
    }

    for(int h = 0; h < k; h++){
        int outp1, outp2;
        bool assumeFit = true;
        vector<tuple<int, int, bool>> thisScrap;

        for(int j = 0; j < scrap[h].size(); j++){
            thisScrap.push_back(make_tuple(scrap[h][j].first, scrap[h][j].second, false));
        }

        for(tuple<int, int, bool> &d : thisDa){


            for(tuple<int, int, bool> &s : thisScrap){
                get<0>(s) += get<0>(d);
                get<1>(s) += get<1>(d);
            }
        

            for(tuple<int, int, bool> &s: thisScrap){
                for(tuple<int, int, bool> &d : thisDa){
                    if(get<0>(s) == get<0>(d) && get<1>(s) == get<1>(d)) 
                    {
                        get<2>(s) = true;
                        get<2>(d) = true;
                    }
                }
            }

            for(tuple<int, int, bool> &s: thisScrap){
                if(!get<2>(s)) assumeFit = false;
            }

            if(assumeFit){
                
                outp1 = h;
                for(tuple<int, int, bool> &d : thisDa){
                    if (!get<2>(d)) anotherDa.push_back(make_tuple(get<0>(d), get<1>(d), false)); 
                }

                

                for(int jj = 0; jj < k; jj++){
                    assumeFit = true;
                    vector<tuple<int, int, bool>> anotherScrap;
                    if(jj != outp1){
                        
                        
                        for(int hh = 0; hh < scrap[jj].size(); hh++)
                        {
                            anotherScrap.push_back(make_tuple(scrap[jj][hh].first, scrap[jj][hh].second, false));
                        }

                        for(tuple<int, int, bool> &s : anotherScrap){
                            get<0>(s) += get<0>(d);
                            get<1>(s) += get<1>(d);
                        }
        

                        for(tuple<int, int, bool> &s: anotherScrap){
                            for(tuple<int, int, bool> &d : anotherDa){
                                if(get<0>(s) == get<0>(d) && get<1>(s) == get<1>(d)) 
                                {
                                    get<2>(s) = true;
                                    get<2>(d) = true;
                                }
                            }
                        }

                        for(tuple<int, int, bool> &s: anotherDa){
                            if(!get<2>(s)) assumeFit = false; 
                        }

                        if(assumeFit) {outp2 = jj;
                        vector<int> ans(2);
                        ans.push_back(outp1);
                        ans.push_back(outp2);
                        sort(ans.begin(), ans.end());
                        return ans;
                        }

                    }
                }
               
            }



        }

        
    }

    return dis;
}

int main(){

    freopen("bcs.in", "r", stdin);
    int n, k;
    cin >> n >> k;

    string inSto[n];
    vector<pair<int, int>> da;
    vector<vector<pair<int, int>>> scrap(k);

    

    vector<int> ans(2, 0);
    int sX = 0, sY = 0;
    int rX = 0, rY = 0;
    bool fxF;
    bool filled;
    string filla = "";

    fxF = false;
    for(int m = 0; m < n; m++){
        cin >> filla;
        inSto[m] = filla;
        for(int l = 0; l < n; l++){
            for(int g = 0; g < n; g++){
                if(!fxF && inSto[l][g] == '#'){
                    sX = g;
                    sY = l;
                    fxF = true;
                }

                if(inSto[l][g] == '#'){
                    rX = g - sX;
                    rY = l - sY;
                    da.push_back(make_pair(rX, rY)); 
                }

            }
        }
    }

    for(int h = 0; h < k; h++){
        fxF = false;
        for(int m = 0; m < n; m++){
            cin >> filla;
            inSto[m] = filla;
            for(int l = 0; l < n; l++){
                for(int g = 0; g < n; g++){
                    if(!fxF && inSto[l][g] == '#'){
                        sX = g;
                        sY = l;
                        fxF = true;
                    }

                    if(inSto[l][g] == '#'){
                        rX = g - sX;
                        rY = l - sY;
                        scrap[h].push_back(make_pair(rX, rY)); 
                    }

                }
            }
        }
    }

    freopen("bsc.out", "w", stdout);
    ans = Turan(da, scrap, k);

    for(int bos = 0; bos < 2; bos++){
        cout << ans[bos] << "";
    }
    
    cout << endl;
        
}

    
