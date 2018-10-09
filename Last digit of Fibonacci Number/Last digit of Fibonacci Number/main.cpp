//
//  main.cpp
//  Last digit of Fibonacci Number
//
//  Created by 许国嵩 on 17/9/7.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int n;
    int m [60]={0,1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8,1,9,0,9,9,8,7,5,2,7,9,6,5,1,6,7,3,0,3,3,6,9,5,4,9,3,2,5,7,2,9,1};
    
    for(int i = 0;i < 60;i++){
        if(i == 0){
            m[0] = 0;
        }
        else if(i == 1){
            m[1] = 1;
        }
        else{
            m[i] = (m[i - 1]+m[i - 2]) % 10;
        }
    }
    
    

    while(cin>>n){
        n %= 60;
        cout<<m[n]<<endl;
    }
    
   
    
    return 0;
}
