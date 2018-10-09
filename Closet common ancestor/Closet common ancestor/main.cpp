//
//  main.cpp
//  Closet common ancestor
//
//  Created by 许国嵩 on 17/11/1.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>

using namespace std;


int main() {
    
    int t,n,root, f, s , k1, k2, temp;
    cin>>t;
    for(int a = 0; a<t; a++){
        bool finish = false;
        int tree[100];
        cin>>root>>n;
        tree[root] = -1;
        for(int b = 0; b < n - 1; b++){
            cin>>s>>f;
            tree[s] = f;
        }
        cin>>k1>>k2;
        while(k1 != -1 ||finish){
            temp = k2;
            while(temp != -1){
                if(temp == k1){
                    cout<<temp<<endl;
                    finish = true;
                    break;
                }
                temp = tree [temp];
            }
            if(finish){
                break;
            }
            k1 = tree[k1];
        }
    }
    return 0;
}
