//
//  main.cpp
//  Quadtree
//
//  Created by 许国嵩 on 17/9/22.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void print(bool **m, int k){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cout<<m[i][j];
        }
        cout<<endl;
    }
}



int quad(bool **m, int a, int b, int c, int d){
    if(c-a == 1){
        return 1;
    }
    
    bool q = true;
    for(int i = a; i < c; i++){
        for(int j = b; j < d; j++){
            if(m[i][j] != m[a][b]){
                q = false;
            }
        }
    }
    if(q){
        return 1;
    }
    if (c - a == 2){
        return 5;
    }
    return 1 + quad(m, a, b, (c+a)/2, (d+b)/2) + quad(m, a, (d+b)/2, (c+a)/2, d) + quad(m, (c+a)/2, b, c, (b+d)/2) + quad(m, (a+c)/2, (b+d)/2, c, d);
}

int main() {
    int k;
    while(cin>>k){
        k = pow(2,k);
     
        bool **map;
        map = new bool *[k];
        for(int i = 0; i < k; i++){
            map[i] = new bool [k];
        }
        
        string str1;
        getline(cin,str1);
        
        for(int i = 0; i < k; i++){
            
            getline(cin,str1);
            for(int j = 0; j < k; j++){
                if(str1[j] == '0'){
                    map[i][j] = 0;
                }else{
                    map[i][j] = 1;
                }
            }
        }
        cout<<quad(map,0,0,k,k)<<endl;
    }
    return 0;
}
