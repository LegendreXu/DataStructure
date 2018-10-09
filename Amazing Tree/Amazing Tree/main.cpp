//
//  main.cpp
//  Amazing Tree
//
//  Created by 许国嵩 on 17/12/14.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while(cin>>s){
        
        int temp = 1;
        string str;
        int *a = new int[s.size()/2+1];
        for(int i=0;i<s.size()/2+1;i++){
            a[i] = 0;
        }
      
        for(int i=0;i<s.size();i++){
            if(s[i] =='('){
                str += temp;
                temp++;
                for(int j=0;j<str.size();j++){
                    a[str[j]]++;
                }
            }
            
            if(s[i] !='('){
                str = str.substr(0,str.size()-1);
            }
        }
        
        int result = a[1];
        for(int i=2;i<s.size()/2+1;i++){
            result = result ^ a[i];
        }
        cout<<result<<endl;
    }
    return 0;
}
