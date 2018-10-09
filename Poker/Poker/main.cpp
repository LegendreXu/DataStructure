//
//  main.cpp
//  Poker
//
//  Created by 许国嵩 on 17/10/1.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t,n,m;
    cin>>t;
    for(int i = 0;i < t ;i++){
        cin>>n;
        vector<int> a;
        for(int j = 0; j < n; j++){
            int temp;
            cin>>temp;
            a.push_back(temp);
        }
        cin>>m;
        for(int j = 0; j < m; j++){
            char op;
            cin>>op;
            switch (op) {
                case 'm':
                    cout<<*max_element(begin(a), end(a))<<endl;
                    break;
                    
                case 'r':
                    a.pop_back();
                    break;
                    
                case 'a':
                    int temp2;
                    cin>>temp2;
                    a.push_back(temp2);
                    break;
                    
                default:
                    break;
            }
        }
    }
    return 0;
}
