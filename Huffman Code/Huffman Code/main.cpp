//
//  main.cpp
//  Huffman Code
//
//  Created by 许国嵩 on 17/12/17.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator ()(int &a,int &b){
        return a>b;
    }
};

int main() {
    int n;
    while(cin>>n){
        int wl=0;
        priority_queue<int,vector<int>,cmp> num;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            num.push(a);
        }
        if(n==0){
            wl = 0;
        }
        else if(n==1){
            wl = wl+num.top();
        }
        while(num.size()>1){
            int zuixiao = num.top();
            num.pop();
            int dierxiao = num.top();
            num.pop();
            num.push(zuixiao+dierxiao);
            wl = wl+zuixiao+dierxiao;
        }
        
        cout<<wl<<endl;
    }
    return 0;
}
