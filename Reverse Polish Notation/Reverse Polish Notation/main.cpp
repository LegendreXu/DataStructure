//
//  main.cpp
//  Reverse Polish Notation
//
//  Created by 许国嵩 on 17/11/28.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
unsigned long int l;
stack<int> s;
int temp;

int main() {
    while(getline(cin,str)){
        l = str.size();
        for(int i = 0; i < l; i++){
            if(str[i] <= '9' && str[i] >= '0'){
                temp = str[i] - 48;
                s.push(temp);
            }
            else if(str[i] == '+' || str[i] == '*' || str[i] == '-'){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if (str[i] == '+')
                    s.push(a+b);
                else if (str[i] == '-')
                    s.push(b-a);
                else if (str[i] == '*')
                    s.push(a*b);
            }
        }
        cout<<s.top()<<endl;
        s.pop();
        
    }
    return 0;
}
