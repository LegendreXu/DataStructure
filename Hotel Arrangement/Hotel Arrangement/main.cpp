//
//  main.cpp
//  Hotel Arrangement
//
//  Created by 许国嵩 on 17/12/14.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isOk(int dis, vector<int> place, int N, int C){
    int pres = place[0];
    int num = 1;
    for(int i=1;i<N;i++){
        if(place[i]-pres>=dis){
            num++;
            pres = place[i];
        }
        if(num==C){
            return true;
        }
    }
    return false;
}

int binarySearch(vector<int> place, int N, int C){
    int ans = 1;
    int min = 1;
    int max = (place[N-1]-place[0])/(C-1);
    
    while(min<=max){
        int dis = (min+max)/2;
        if(isOk(dis,place,N,C)){
            min = dis+1;
            ans = dis;
        }
        else{
            max = dis-1;
        }
        
    }
    
    return ans;
    
}

int main() {
    int T;
    cin>>T;
    int temp;
    for(int t=0;t<T;t++){
        int N,C;
        cin>>N>>C;
        vector<int> place(N);
        for(int i=0;i<N;i++){
            cin>>place[i];
        }

        sort(place.begin(),place.end());
        
        
        cout<<binarySearch(place, N, C);
        cout<<endl;
    }
    
    
    return 0;
}
