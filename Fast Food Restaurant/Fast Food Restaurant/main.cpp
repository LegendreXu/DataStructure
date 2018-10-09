//
//  main.cpp
//  Fast Food Restaurant
//
//  Created by 许国嵩 on 17/10/16.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while(cin>>n){
        int time = 0;
        bool b = false;
        int a[n+1], o[n+1], l[n+1];
        for (int j = 0; j < n; j++){
            cin>>a[j]>>o[j]>>l[j];
        }
        int i = 0, k = 0, length = 0;
        queue<int> q = {};
        int tempTime = 0;
        while(k != n){
            if(q.empty()){
                q.push(i);
                tempTime = a[q.front()]+o[q.front()];
                time = a[i];
                length++;
                i++;
            }
            
            else if (a[i] >= tempTime || (i == n && k != n )){
                time = tempTime;
                q.pop();
                k++;
                length--;
                if(q.empty()){
                    tempTime = 0;
                    if(k == n - 1){
                        time = max(time+o[n - 1], a[n-1]+o[n-1]);
                        break;
                    }
                }
                tempTime += (q.empty())?0:o[q.front()];
            }

            else if (length <= l[i]){
                q.push(i);
                time = a[i];
                length++;
                i++;
            }
            
            else{
                time = a[i];
                i++;
                k++;
                b = (i == n);
            }
        }
        
        if(b){
            cout<<-1<<endl;
        }
        else{
            cout<<time - o[n - 1]<<endl;
        }
    }
    return 0;
}
