#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("lineup.in", "r", stdin);
    string dispo, name1, name2;
    int n;
    cin >> n;

    set<string> cows;
    cows.insert({"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"});
    map<string, vector<string>> graphlist;
    for(const string &a : cows){
        graphlist[a] = {};
    }
   

    for(int l = 0; l < n; l++){
        cin >> name1;
        for(int t = 0; t < 4; t++){
            cin >> dispo;
        }
        cin >> name2;
        
        graphlist[name1].push_back(name2);
        graphlist[name2].push_back(name1);
    }

    set<string> d1_nodes;

    for(const pair<string, vector<string>> &a : graphlist){
        if(a.second.size() <= 1) d1_nodes.insert(a.first);
    }

    string last_node;
    string this_node;
    string end_node = "";
    int printed = 0;
    
    freopen("lineup.out", "w", stdout);
    map<string, bool> endnoded;
    for(const string &a : cows){
        endnoded[a] = false;
    }
    
    for(const string &a: d1_nodes){
        if(printed == 8) break;
        if(graphlist[a].size() == 0) {cout << a << endl;
        printed++;}
        else{
            bool iterating = true;
            if(!endnoded[a]){
                cout << a << endl;
                cout << graphlist[a][0] << endl;
                printed+=2;
                last_node = a;
                this_node = graphlist[a][0];
                while(iterating){
                    for(string &b : graphlist[this_node]){
                        if(b != last_node) {
                            cout << b;
                            last_node = this_node;
                            this_node = b;
                            printed++;
                            break;
                        }
            
                    }
                    if(graphlist[this_node].size() <= 1){
                        end_node = this_node;
                        endnoded[end_node] = true;
                        break;
                    }
                    
                }
            }
        }
    }
}