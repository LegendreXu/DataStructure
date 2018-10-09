//
//  main.cpp
//  Stack shuffling
//
//  Created by 许国嵩 on 17/9/30.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;
bool checker(int n, int *p){
    stack<int> a,s;
    int arr[n];
    for(int i = 0; i < n; i++){
        a.push(p[i]);
    }
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int c = 0;
    while(c != n){
    
        
        if(!s.empty()&&(s.top()==arr[c])){
            c++;
            s.pop();
        }
        else if(!a.empty()&&(a.top()==arr[c])){
            c++;
            a.pop();
        }
        else if(!a.empty()&&(a.top()!=arr[c])){
            s.push(a.top());
            a.pop();
        }
        else if(a.empty()&&(s.top()!=arr[c])){
            return false;
        }
    }
    return true;
}


int main() {
    int n,m,t;
    cin>>t;
    while(t--){
        cin>>n;
        int aByArr[n];
        for(int i = 0; i < n; i++){
            cin>>aByArr[i];
            
        }
        cin>>m;
        
        while(m--){
            if(checker(n, aByArr)){
                cout<<"Aye"<<endl;
            }
            else{
                cout<<"Impossible"<<endl;
            }
            
        }
    }
    return 0;
}








