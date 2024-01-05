#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'findHandSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER originalRows
 *  2. STRING handTiles
 *  3. STRING drawPile
 */
 
struct tile{
    bool doul = false;
    int num1;
    int num2;
};

int findHandSum(int originalRows, string handTiles, string drawPile) {
    int end_nums[4];
    string ths = to_string(originalRows);
    for (int l = 0; l < 4; l++){
        end_nums[l] = (int)ths[l] - 48;
    }
    
    vector<tile> sto;
    vector<tile> sto2;

    cout << handTiles << endl << drawPile;
    
    for(int l = 0; l < handTiles.length(); l += 3){
        tile thi;
        thi.num1 = (int)handTiles[l] - 48;
        thi.num2 = (int)handTiles[l+1] - 48;
        if(thi.num1 == thi.num2) thi.doul = true;
        sto.push_back(thi);
    }
    
    for(int l = 0; l < drawPile.length(); l += 3){
        tile thi;
        thi.num1 = (int)drawPile[l] - 48;
        thi.num2 = (int)drawPile[l+1] - 48;
        if(thi.num1 == thi.num2) thi.doul = true;
        sto2.push_back(thi);
    }
    
  
    bool searching = true;
    bool draw_need = false;
    bool doulmode = false;
    int doulplace = 0;
    int doulnum = 0;
    
    while(searching){
        
        if(sto2.size() == 0 && sto.size() == 0){
            break;
        }
        
        if(draw_need){
            if(!sto2.size()){
                break;
            }
        }
    
        
        if(draw_need){
            sto.push_back(sto2[0]);
            sto2.erase(sto2.begin(), sto2.begin() + 1);
            draw_need = false;
        }
        
        int l = 0;

        if(doulmode){
            for(int k = 0; k < sto.size(); k++){
                 if(sto[k].num1 == doulnum){
                        end_nums[doulplace] = sto[k].num2;
                        sto.erase(sto.begin() + k, sto.begin() + (k+1));
                        doulmode = false;
                        break;
                    } else if (sto[k].num2 == end_nums[doulplace]){
                        end_nums[doulplace] = sto[k].num1;
                        sto.erase(sto.begin() + k, sto.begin() + (k+1));
                        doulmode = false;
                        break;
                    }
                if (k == sto.size() - 1) {
                    draw_need = true;
                    break;
                }
            }
        }
        
        while(!doulmode){
            
            if(l == sto.size()){
                draw_need = true;
                break;
            }
            
            
                
                for(int a = 0; a < 4; a++){
                    l = 0;
                    while(true){
                        if(l == sto.size()){
                            break;
                        }

                        if(sto[l].num1 == end_nums[a]){
                            end_nums[a] = sto[l].num2;
                            if(sto[l].doul) {
                                doulmode = true;
                                doulnum = sto[l].num1;
                                doulplace = a;
                            }
                            sto.erase(sto.begin() + l, sto.begin() + (l+1));
                                l = 0;
                            break;
                        } else if (sto[l].num2 == end_nums[a]){
                            end_nums[a] = sto[l].num1;
                                if(sto[l].doul) {
                                doulmode = true;
                                doulnum = sto[l].num1;
                                doulplace = a;
                            }
                            sto.erase(sto.begin() + l, sto.begin() + (l+1));
                            l = 0;
                            break;
                        } 
                    
                        l++;
                      
                    }

                    if(doulmode) break;
                }
                
            
            
           
            
            
        }
        
    }
    
    int op = 0;
    for(int &a : end_nums){
        op += a;
    }
    
    return op;
    
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string originalRows_temp;
    getline(cin, originalRows_temp);

    int originalRows = stoi(ltrim(rtrim(originalRows_temp)));

    string handTiles;
    getline(cin, handTiles);

    string drawPile;
    getline(cin, drawPile);

    int result = findHandSum(originalRows, handTiles, drawPile);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
