//
//  main.cpp
//  Boring Job
//
//  Created by 许国嵩 on 17/12/14.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

struct Node
{
    int number;
    int index;
};

int main()
{
    int T;
    scanf("%d",&T) ; // the number of test cases
    for(int i=0;i<T;i++) //for each test case
    {
        queue<Node>seq; //sequence
        int N,K; //the length of sequence and magic parameter
        int ptimes=0;
        int num;
        Node aNode;
        int Vmax; // largest in K
        int printNumber; //k中Vmax的Index
        scanf("%d%d",&N,&K);
        Node tmps[K];//temporary sequence
        
        //先输入所有数字
        for(int j=0;j<N;j++)
        {
            scanf("%d",&num);
            aNode.number=num;
            aNode.index = j+1;
            seq.push(aNode);
        }
        
        //开始清理queue
        while(!seq.empty())
        {
            //先拿出前k个
            for(int j=0;j<K;j++)
            {
                tmps[j]=seq.front();
                seq.pop();
                if(seq.empty()) //最后k比n中剩下的还大，每次就拿完
                {
                    K=j+1;//拿到比k还小后重新定义k的大小
                    break;
                }
            }
            
            //假设第一个数最大开始比较
            Vmax = tmps[0].number;
            printNumber =tmps[0].index;
            for(int j=0;j<K;j++) //找到最大的那个数
            {
                if(Vmax<tmps[j].number)
                {
                    printNumber = tmps[j].index;
                    Vmax=tmps[j].number;
                }
                tmps[j].number--; //对每个数大小减一
            }
            ptimes++;
            if(ptimes<N)
                printf("%d ",printNumber);
            else
                printf("%d",printNumber);
            
            
            //将剩下的数重新插入原队中
            for(int j=0;j<K;j++)
            {
                if(tmps[j].index!=printNumber) //print的那个数不插入
                {
                    seq.push(tmps[j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

