//
//  main.cpp
//  Tree Reconstruction
//
//  Created by 许国嵩 on 17/11/1.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int search(int arr[], int x, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

void getpost(int in[], int pre[], int n, int fuck){
    int root;
    root = search(in,pre[0],n);
    
    if(root != 0){
        getpost(in, pre+1, root, fuck);
    }
    
    if(root != n-1){
        getpost(in+root+1, pre+root+1, n-root-1, fuck);
    }
    
    cout<<pre[0];
    if(pre[0] != fuck){
        cout<<" ";
    }

}

int main() {
    int t,n;
    cin>>t;
    for(int a = 0; a < t; a++){
        cin>>n;
        int pre[n];
        int in[n];
        for(int b = 0; b < n; b++){
            cin>>pre[b];
        }
        for(int b = 0; b < n; b++){
            cin>>in[b];
        }
        int fuck = pre[0];
        getpost(in, pre, n, fuck);
        cout<<endl;
    }
    return 0;
}
