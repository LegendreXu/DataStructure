//
//  main.cpp
//  Word Count
//
//  Created by 许国嵩 on 17/9/5.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;


int main() {
    
    map<string, int> wordCount;
    
    for(int i = 0; i < 100; i++){
        string word;
        getline(cin,word);
        
        istringstream iss(word), end;
        string n;
        
        while(iss >> n){
            if(wordCount.find(n) == wordCount.end()){
                wordCount[n] = 1;
            }
            else{
                wordCount[n]++;
            }
        }
    }
    
    map<string,int>::iterator m;
    for(m = wordCount.begin();m!=wordCount.end();++m){
        cout<<m->first<<" "<<m->second<<endl;
    }
    return 0;
}

