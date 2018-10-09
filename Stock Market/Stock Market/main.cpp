//
//  main.cpp
//  Stock Market
//
//  Created by 许国嵩 on 17/12/14.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    for(int j = 0; j<t ;j++){
        long long int n, area = 0;
        scanf("%lld",&n);
        stack<long long int>data;
        long long int  price;
 
        for(int i = 0; i < n; i++){
            scanf("%lld",&price);
 
            if(data.empty()||price>=data.top()){
                data.push(price);
            }
            else{
                int count=0;
                while(!data.empty()&&price<data.top()){
                    long long int h = data.top();
                    data.pop();
                    count++;
                    if(area < h * count){
                        area = h * count;
                    }
                }
                for(int k=0; k< count + 1; k++){
                    data.push(price);
                }
            }
        }
        int count = 0;
        while(!data.empty()){
            long long int h = data.top();
            data.pop();
            count++;
            if(area < h * count){
                area = h * count;
            }
        }
        printf("%lld\n",area);
    }
    return 0;
}
