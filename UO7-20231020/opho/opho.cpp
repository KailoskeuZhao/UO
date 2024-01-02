#include <bits/stdc++.h>

int main(){
    int evNum = 0, odNum = 0;
    int N;

    std::cin >> N;

    int ined;

    for(int n = 0; n < N; n++){
        std::cin >> ined;
        if(ined%2) odNum++;
        else evNum++;
    }

    int op;

    int ex;

    if(evNum >= odNum){
        op = 2 * odNum;
        if(evNum >= odNum +1) op++;
        std::cout << op << std::endl;
    } else {
        int add;
        ex = odNum - evNum;
        if(ex%3 == 1){
            add = (ex/3 + (ex/3 -1));
        }else if(ex %3 == 2){
            add = 2*(ex/3) + 1;
        }else{
            add = 2*(ex/3);
        }
        std::cout << (2* evNum + add) << std::endl;
    }

}