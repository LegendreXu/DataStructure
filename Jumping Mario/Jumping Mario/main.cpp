//
//  main.cpp
//  Jumping Mario
//
//  Created by 许国嵩 on 17/12/14.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <stdio.h>

int main() {
    int t, n, low = 0, high = 0, temp = 0 ,temp2 = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d",&n);
        while(n){
            scanf("%d",&temp);
            low += (temp<temp2);
            high += (temp>temp2);
            n--;
            temp2  = temp;
        }
        printf("Case %d: %d %d\n", i+1, high-1, low);
        low  = 0;
        high = 0;
        temp = 0;
        temp2 = 0;
    }
    return 0;
}
