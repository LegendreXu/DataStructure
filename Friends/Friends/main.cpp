//
//  main.cpp
//  Friends
//
//  Created by 许国嵩 on 17/12/17.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 30000
struct Node{
    int size;
    int father;
    int rank;
}node[MAX];

int getFather(int x){
    if(node[x].father==x){
        return x;
    }
    return getFather(node[x].father);
}

void toUnion(int a, int b){
    a=getFather(a);
    b=getFather(b);
    if(node[a].rank>node[b].rank)
        node[b].father=a;
    else
    {
        node[a].father=b;
        if(node[a].rank==node[b].rank)
            node[b].rank++;
    }
}

int main() {
    
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N,M;  //N个市民，M对
        cin>>N>>M;
        
        for(int j=0;j<N;j++){
            node[j].father = j;
            node[j].rank = 0;
            node[j].size = 0;
        }
        
        int a,b;
        for(int j=0;j<M;j++){
            cin>>a>>b;
            toUnion(a,b);
        }
        
        int max=1;
        for(int j=0;j<N;j++){
            node[getFather(j)].size++;
            if(max<node[getFather(j)].size)
                max = node[getFather(j)].size;
        }
        
        cout<<max<<endl;
        
    }
    
    return 0;
}
