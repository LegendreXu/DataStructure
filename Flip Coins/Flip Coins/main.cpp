//
//  main.cpp
//  Flip Coins
//
//  Created by 许国嵩 on 17/9/19.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <bitset>

using namespace std;

class coinsMatrix{
public:
    
    void swapColumns(int c){
        for(int i = 0; i < n ;i++){
            matrix[i][c] = !matrix[i][c];
        }
    }
    
    void alphaToOmega(){
        bitset<10> v;
        v = pow(2, m) - 1;
        while(v != 0){
            if (answer == n*m){
                break;
            }
            for(int i = 0; i < m ; i++){
                if(v[i] == 0){
                    swapColumns(i);
                }
            }
            countByRows();
            for(int i = 0; i < m ; i++){
                if(v[i] == 0){
                    swapColumns(i);
                }
            }
            v = v.to_ulong() - 1;
        }
    }
    
    void countByRows(){
        int c = 0;
        for(int i = 0; i < n; i++){
            int temp = 0;
            for(int j = 0; j < m; j++){
                if(matrix[i][j]){
                    temp++;
                }
            }
            c += ((temp > m - temp)?(temp):(m-temp));
        }
        if(c > answer){
            answer = c;
        }
    }
    
    void define(int n1, int m1){
        n = n1;
        m = m1;
        matrix = new bool*[n1];
        for (int i=0; i<n1; i++ ){
            matrix[i] = new bool[m1];
        }
        
        for (int j=0; j<n1; j++){
            string str1;
            cin>>str1;
            for (int k=0; k<m1; k++){
                if(str1[k] == '0'){
                    matrix[j][k] = 0;
                }
                else{
                    matrix[j][k] = 1;
                }
            }
        }
    }
    
    void bingo(){
        int hiahiahia = answer;
        cout<<hiahiahia<<endl;
    }
    
private:
    int n, m;
    bool **matrix;
    int answer = 0;
};

int main() {
    int n, m;
    while(cin>>n>>m){
        coinsMatrix q;
        q.define(n, m);
        q.alphaToOmega();
        q.bingo();
    }
    return 0;
}





