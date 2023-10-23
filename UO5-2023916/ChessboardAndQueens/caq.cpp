#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>> reserva;
    vector<string> board(8);
    vector<int> queens(8);
    
    for(int m = 0; m < 8; m++) queens[m] = m;

    for(int m = 0; m < 8; m++){
        cin >> board[m];
    }          

    for(int m = 0; m < 8; m++){
        for(int c = 0; c < 8; c++){
            if(board[m][c] == '*'){
                reserva.push_back(make_pair(c, m));
            }
        }
    }

    bool yes = true;
    int curr = 0;

    do{
        yes = true;
        for(int m = 0; m < 8; m++){
            for(int k = 0; k < reserva.size(); k++){
                if( queens[m] == reserva[k].first && m == reserva[k].second) {
                    yes = false;
                    break;
                }
            }
        }
        for(int m = 0; m < 7; m++){
            for(int a = (m+1); a < 8; a++){
                if (abs(a-m) == abs(queens[a] - queens[m])) yes = false;
            }
        }

        if(yes) curr++;


    } while(next_permutation(queens.begin(), queens.end()));

    cout << curr << endl;

    }