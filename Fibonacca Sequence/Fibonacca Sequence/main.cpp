//
//  main.cpp
//  Fibonacca Sequence
//
//  Created by 许国嵩 on 17/12/17.
//  Copyright © 2017年 许国嵩. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int bucket[1024];

int getMaxDig(int a){
    int d = 0;
    while(a){
        a /= 1024;
        d++;
    }
    return d;
}

void sort(int n, int arr[], int md){
    int tmpD = 1;
    int *output = new int[n];
    
    for(int i=0;i<md;i++){
        memset(bucket,0,4096);
        for(int j=0;j<n;j++){
            bucket[(arr[j]/tmpD)%1024]++;
        }
    
        for(int j=1;j<1024;j++){
            bucket[j] = bucket[j]+bucket[j-1];
        }
        
        for(int j=n-1;j>=0;j--){
            int pos =--bucket[(arr[j]/tmpD)%1024];
            output[pos] = arr[j];
        }
        for(int i=0;i<n;i++){
            arr[i] = output[i];
        }
        tmpD *= 1024;
    }
    
    delete []output;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t){
        int n,Q;
        scanf("%d %d",&n,&Q);
        int *arr = new int[n];
        
        arr[0] = 1;
        arr[1] = 1;
        
        for(int j=2;j<n;j++){
            arr[j] = (arr[j-1] + arr[j-2])%Q;
        }
        
        int maxDigit;
        maxDigit = getMaxDig(Q);
        sort(n, arr, maxDigit);
        
        long long int sum = 0;
        for(long long int j=1;j<=n;j++){
            long long int a = j*arr[j-1];
            sum = (sum + a)%Q;
        }
        printf("%lld\n",sum);
        
        delete[]arr;
        t--;
    }
    
    return 0;
}
