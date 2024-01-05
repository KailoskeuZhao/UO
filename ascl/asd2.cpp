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
    bool used = false;
    bool doul = false;
    int num1;
    int num2;
};

int findHandSum(int originalRows, string handTiles, string drawPile) {
    int end_nums[4]{0, 0, 0, 0};
    string ths = to_string(originalRows);
    for (int l = 0; l < ths.length(); l++){
        end_nums[l] = (int)ths[l] - 48;
    }
    
    vector<tile> sto;
    vector<tile> sto2;

    
    for(int l = 0; l < handTiles.length(); l ++){
        if((int)handTiles[l] >= 48 && (int)handTiles[l+1] >= 48){
            tile thi;
            thi.num1 = (int)handTiles[l] - 48;
            thi.num2 = (int)handTiles[l+1] - 48;
            if(thi.num1 == thi.num2) thi.doul = true;
            sto.push_back(thi);
            l = l+2;
        }
        else if((int)handTiles[l] >= 48 && (int)handTiles[l+1] == ' '){
            tile thi;
            thi.num1 = (int)handTiles[l] - 48;
            thi.num2 = 0;
            sto.push_back(thi);
            l = l+1;
        }
        else if((int)handTiles[l] >= 48 && l == (handTiles.length()-1)){
            tile thi;
            thi.num1 = (int)handTiles[l] - 48;
            thi.num2 = 0;
            sto.push_back(thi);
            l = l+1;
        }
    }
    
    for(int l = 0; l < drawPile.length(); l ++){
        if((int)drawPile[l] >= 48 && (int)drawPile[l+1] >= 48){
            tile thi;
            thi.num1 = (int)drawPile[l] - 48;
            thi.num2 = (int)drawPile[l+1] - 48;
            if(thi.num1 == thi.num2) thi.doul = true;
            sto2.push_back(thi);
            l = l+2;
        }
        else if((int)drawPile[l] >= 48 && (int)drawPile[l+1] == ' '){
            tile thi;
            thi.num1 = (int)drawPile[l] - 48;
            thi.num2 = 0;
            sto2.push_back(thi);
            l = l+1;
        } 
        else if(((int)drawPile[l] >= 48 && l == (drawPile.length()-1))){
            tile thi;
            thi.num1 = (int)drawPile[l] - 48;
            thi.num2 = 0;
            sto2.push_back(thi);
            l = l+1;
        }
    }
 
    
    int non_found_count = 0;
    bool searching = true;

    int cur_row = 0;
    bool noncanbe = false;
    int doulnum = -1;
    

    while(searching){

        noncanbe = true;
        for(int l = 0; l < sto.size(); l++){
            
             if(!sto[l].used){
                non_found_count = 0;
               for(cur_row; non_found_count < 4; cur_row = cur_row % 4){

                if((doulnum+1)){cur_row = doulnum;}

                    if(sto[l].num1 == end_nums[cur_row]){
                        if((doulnum+1)){doulnum = -1;}
                        noncanbe = false;
                        end_nums[cur_row] = sto[l].num2;
                        cur_row++;
                        sto[l].used = true;
                        if(sto[l].doul)
                        {doulnum = (cur_row-1);}
                        l = 0;
                        break;
                    } else if (sto[l].num2 == end_nums[cur_row]){
                        if((doulnum+1)){doulnum = -1;}
                        noncanbe = false;
                        end_nums[cur_row] = sto[l].num1;
                        cur_row++;
                        sto[l].used = true;
                        if(sto[l].doul)
                        {doulnum = (cur_row-1);}
                        l = 0;
                        break;
                    } 
                    non_found_count++;
                    cur_row++;

                if((doulnum+1)){break;}

                }
            }
            
        } 

        bool passed = true;
        for(tile &a :sto){
            if (!a.used) passed = false;
        }

        if(passed) break;

        if(sto2.size()){
            if(noncanbe){
                sto.push_back(sto2[0]);
                sto2.erase(sto2.begin(), sto2.begin() + 1);
                noncanbe = false;
            }
        }

        if(noncanbe && (sto2.size() == 0)){
            break;
        }
    
    }


    int op = 0;
 
    string das = "";
    
    for(tile &a : sto){
        if(!a.used){
        das = das + to_string(a.num1) + to_string(a.num2);
        }
    }

    for(int l = 0; l < das.length(); l++){
        op += das[l] - 48;
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