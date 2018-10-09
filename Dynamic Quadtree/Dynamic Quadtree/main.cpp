//
//  main.cpp
//  Dynamic Quadtree
//
//  Created by 许国嵩 on 17/10/21.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

void increase(int * qt, int temp){
    while(temp > 0){
        if(qt[(temp-1)/4] == 0){
            qt[(temp-1)/4] = 1;
            increase(qt, (temp-1)/4);
        }
        qt[(temp-1)/4]++;
        temp = (temp-1)/4;
    }
    
}
void decrease(int *qt, int temp){
    while(1){
        qt[temp]--;
        if(temp == 0){
            break;
        }
        temp = (temp-1)/4;
    }
}

bool checker(bool **m, int a, int b, int c, int d){
    int i = 0;
    int j = 0;
    bool w;
    for(i = a; i < b; i++){
        for(j = c; j < d; j++){
            w = (m[i][j] != m[a][c]);
            if(w){
                return false;
            }
        }
    }
    return true;
}

int deletenode(bool **m, int *qt, int a, int b, int c, int d, int k){
    if(k == 0){
        return 0;
    }
    int con = k - ((k-1)/4)*4;
    int temp = (k-1)/4;
    if(con == 1){
        b += b-a;
        d += d-c;
    }
    if(con == 2){
        a -= b-a;
        d += d-c;
    }
    if(con == 3){
        a -= b-a;
        c -= d-c;
    }
    if(con == 4){
        b += b-a;
        c -= d-c;
    }
    
    if(checker(m, a, b, c, d)) {
        decrease(qt, 4*temp+1);
        decrease(qt, 4*temp+2);
        decrease(qt, 4*temp+3);
        decrease(qt, 4*temp+4);
        deletenode(m, qt, a, b, c, d, temp);
    }
    return 0;
}

int ininode(bool **m, int *qt, int a, int b, int c, int d, int k){
    // k is the place in the tree
    int temp = k;
    if(b-a == 1){
        qt[k] = 1;
        temp = k;
        increase(qt, temp);
        return 0;
    }
    
   
    if(checker(m, a, b ,c, d)){
        qt[k] = 1;
        temp = k;
        increase(qt, temp);
        return 0;
    }
    
    
    ininode(m, qt, a, (a+b)/2, c, (c+d)/2, 4*k+1);
    ininode(m, qt, a, (a+b)/2, (c+d)/2, d, 4*k+4);
    ininode(m, qt, (a+b)/2, b, (c+d)/2, d, 4*k+3);
    ininode(m, qt, (a+b)/2, b, c,(c+d)/2, 4*k+2);
    
    return 0;
}

int checknode(bool **m, int *qt, int a, int b, int c, int d, int r1, int c1){
    //
  
    int cond = 0;
    int k = 0;
    while(qt[k] != 1){
        cond = ((r1)>(a+b)/2)*2+((c1)>(c+d)/2);
        switch (cond) {
            case 0:
                b = (a+b)/2;
                d = (c+d)/2;
                k = 4*k+1;
                break;
                
            case 1:
                b = (a+b)/2;
                c = (c+d)/2;
                k = 4*k+4;
                break;
                
            case 2:
                a = (a+b)/2;
                d = (c+d)/2;
                k = 4*k+2;
                break;
                
            case 3:
                a = (a+b)/2;
                c = (c+d)/2;
                k = 4*k+3;
                break;
                
            default:
                break;
        }
    }
    if(b - a == 1){
        deletenode(m, qt, a, b, c, d, k);
        //cout<<"qvq"<<endl;
    }
    else{
        ininode(m, qt, a, b, c, d, k);
    }
    return k;
}


int q[2 * 1024 * 1024 + 1]; //the tree

int main() {
    int k,t;
    cin>>t;
    
    for(int x = 0; x < t ; x++){ //work for t times
        cin>>k;   //the map size
        k = pow(2,k);
        int m,r,c;
        memset(q, 0, 2*1024*1024);
        q[0] = 1;
        bool **map;
        map = new bool *[k];
        for(int i = 0; i < k; i++){
            map[i] = new bool [k];
        }
        
        string str1;
        //getline(cin,str1);
        
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
        
        ininode(map, q, 0, k, 0, k, 0);
        cin>>m;
        for(int b = 0; b < m; b++){
            cin>>r>>c;
            map[r-1][c-1] = !map[r-1][c-1];
            checknode(map, q, 0, k, 0, k, r, c);
            cout<<q[0]<<endl;
        }
    }
    return 0;
}
