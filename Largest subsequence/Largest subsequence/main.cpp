//
//  main.cpp
//  Largest subsequence
//
//  Created by 许国嵩 on 17/9/11.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int n;
    cin>>n;

    for(int i = 0; i <= n; i++){
        bool q = false;
        string str;
        getline(cin,str);
        for(char aim = 'z';aim >= 'a';){
            if(-1 != str.find(aim)){
                unsigned long k = str.find_first_of(aim);
                cout<<str[k];
                str = str.substr(k+1);
                q = true;
            }
            if(-1 == str.find(aim)){
                aim--;
            }
        }
        if(q){
            cout<<endl;
        }
    }
    return 0;
}
