//
//  main.cpp
//  Task Manager
//
//  Created by 许国嵩 on 17/12/14.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct task
{
    int R;
    int W;
    int P;
    int taskNumber;
    int leaveTime;
};

int main()
{
    
    int n;
    while(cin>>n)
    {
        task t[100];
        for(int i=0;i<n;i++)
        {
            cin>>t[i].R>>t[i].W>>t[i].P;
            t[i].taskNumber=i;
            
        }
        
        queue<task>high;
        queue<task>low;
        int clock;
        int runtime=0;
        int tmp=0;
        
        
        for(clock=0;clock<10000;clock++)
        {
            for(int i=tmp;i<n;i++)
            {
                if(t[i].R==clock)
                {
                    tmp=i;
                    if(t[i].P==0)
                        high.push(t[i]);
                    else
                        low.push(t[i]);
                }
            }
            
            if(runtime==0)
            {
                if(!high.empty())
                {
                    runtime=high.front().W;
                    t[high.front().taskNumber].leaveTime=runtime+clock;
                    high.pop();
                    runtime--;
                }
                else if(!low.empty())
                {
                    runtime=low.front().W;
                    t[low.front().taskNumber].leaveTime=runtime+clock;
                    low.pop();
                    runtime--;
                }
            }
            else
                runtime--;
            
            if(tmp==n-1&&high.empty()&&low.empty()&&runtime==0)
                break;
            
        }
        
        for(int i=0;i<n;i++ )
        {
            if(i==n-1)
                cout<<t[i].leaveTime;
            else
                cout<<t[i].leaveTime<<" ";
        }
        
        cout<<endl;
        
    }
    return 0;
}
