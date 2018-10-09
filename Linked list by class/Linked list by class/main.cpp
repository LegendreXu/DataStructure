//
//  main.cpp
//  Linked list by class
//
//  Created by 许国嵩 on 17/9/10.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>

using namespace std;

class List{
public:
    void create_List();
    void insert(const int &d);
    void insert_pos(const int &d, const int &d1);
    void insert_tail(const int &d);
    void erase(const int &d);
    void update(const int &d, const int &d1);
    void reverse(const int &d, const int &d1);
    void print();
    
private:
    struct Node{
        int data;
        Node *next;
        Node(const int& d):data(d),next(NULL){}
    };
    Node *head;
    
    void clear(){
        Node *p = head;
        while(p){
            Node *q = p->next;
            delete p;
            p = q;
        }
    }
    
    Node * find(const int& d){
        Node * p = head;
        for(;p;p = p->next){
            if(p->next->data == d){
                break;
            }
        }
        return p;
    }
    
    Node *find_pos(const int &d){
        Node *p = head;
        for(int i = 0; i < d; i++){
            p = p->next;
        }
        return p;
    }
};

void List::create_List(){
    head = new Node(0);
}

void List::insert(const int& d){
    Node *p = new Node(d);
    p->next = head->next;
    head->next = p;
}

void List::print(){
    for(Node *p = head->next; p; p = p->next ){
        cout<<p<<endl;
    }
}

void List::insert_pos(const int &d, const int &d1){
    Node *p = find(d);
    Node *q = new Node(d1);
    q->next = p->next;
    p->next = q;
}

void List::insert_tail(const int &d){
    Node *currentHead = head;
    Node *temp;
    while(currentHead->next){
        currentHead = currentHead->next;
    }
    temp = new Node(d);
    currentHead->next = temp;
}

void List::erase(const int &d){
    Node *p = find(d);
    Node *q = p->next;
    p->next = p->next->next;
    delete q;
}

void List::update(const int &d, const int &d1){
    Node *p = find(d);
    p->next->data = d1;
}



void List::reverse(const int &d, const int &d1){
    Node *p = find_pos(d);
    const int i = d1 - d + 1;
    int arr[i];
    
    for (int j = 0; j < i; j++){
        arr[j] = p->data;
        p = p->next;
    }
    p = find_pos(d);
    
    for (int j = i; j > 0; j--){
        p->data = arr[j];
        p = p->next;
    }
}

int main(){
    List list;
    int n,m;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>m;
        list.insert_tail(m);
    }
    
    
    return 0;
}




