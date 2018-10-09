//
//  main.cpp
//  Syntax Checker
//
//  Created by 许国嵩 on 17/9/27.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int position(string str1){
    int max = 0;
    stack<char> s;
    bool b = true;
    bool isfirst  = true;
    int i = 0;
    for(i = 0; i < str1.length(); i++){
        if(str1[i] == '(' || str1[i] == '['||str1[i] == '{'){
            s.push(str1[i]);
            if(isfirst){
                max = i;
                isfirst = false;
            }
        }
        
        else if (str1[i] == ')'){
            if(i == 0){
                b = false;
                return 1;
            }
            else if(s.empty()){
                b = false;
                return i+1;
            }
            else if(s.top() == '('){
                s.pop();
                if(s.empty()){
                     isfirst = true;
                }
               
            }
            else{
                b = false;
                return i+1;
            }
        }
        else if (str1[i] == ']'){
            if(i == 0){
                b = false;
                return 1;
            }
            else if(s.empty()){
                b = false;
                return i+1;
            }
            else if(s.top() == '['){
                s.pop();
                if(s.empty()){
                    isfirst = true;
                }
            }
            else{
                b = false;
                return i+1;
            }

        }
        else if (str1[i] == '}'){
            
            if(i == 0){
                b = false;
                return 1;
            }
            else if(s.empty()){
                b = false;
                return i+1;
            }
            else if(s.top() == '{'){
                s.pop();
                if(s.empty()){
                    isfirst = true;
                }
            }
            else{
                b = false;
                return i+1;
            }
        }
        
    }
    if(s.empty()){
        return 0;
    }
    
    if((s.top() == '(' || s.top() == '['||s.top() == '{')&& b){
        return max + 1;
    }
    
    return 0;
}



int main() {
    stack<char> s;
    string str1;
    while(getline(cin,str1)){
        int a = position(str1);
        if(a == 0){
            cout<<"Success"<<endl;
        }else{
            cout<<a<<endl;
        }
    }
    return 0;
}



