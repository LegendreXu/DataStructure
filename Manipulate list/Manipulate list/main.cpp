//
//  main.cpp
//  Manipulate list
//
//  Created by 许国嵩 on 17/9/14.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>

using namespace std;

class List{
public:
    void create_List();
    void insert_pos(const int &d, const int &d1);
    void insert_tail(const int &d);
    void erase(const int &d);
    void reverse(const int &d, const int &d1);
    void print(const int&d);
    void print_all();
    
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
            if(p->data == d){
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


void List::print(const int &d){
    Node *p = find_pos(d);
    cout<<p->data<<endl;
}

void List::insert_pos(const int &d, const int &d1){
    Node *p = find_pos(d);
    Node *q = new Node(d1);
    q->next = p->next;
    p->next = q;
}

void List::insert_tail(const int &d){
    Node *currentHead = head;
    Node *temp = new Node(d);
    if(currentHead->next == NULL){
        head->next =temp;
    }else{
        while(currentHead->next){
            currentHead = currentHead->next;
        }
        currentHead->next = temp;
    }
    
}

void List::erase(const int &d){
    Node *p = find_pos(d);
    Node *q = p->next;
    p->next = p->next->next;
    delete q;
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
    
    for (int j = i - 1; j >= 0; j--){
        p->data = arr[j];
        p = p->next;
    }
}
void List::print_all(){
    for(Node * p = head->next;p;p=p->next){
        cout << p->data << endl;
    }
}


int main(){
    List list;
    list.create_List();
    int n,m,q,op;
    cin>>n;
    for(int a = 0; a < n; a++){
        cin>>m;
        list.insert_tail(m);
    }
    cin>>q;
    for(int a = 0; a < q; a++){
        cin>>op;
        if(op == 1){
            int i, val;
            cin>>i>>val;
            list.insert_pos(i, val);
        }else if (op == 2){
            int i;
            cin>>i;
            list.erase(i);
        }else if (op == 3){
            int i, j;
            cin>>i>>j;
            list.reverse(i, j);
        }else if(op == 4){
            int i;
            cin>>i;
            list.print(i);
        }
    }
    
    
    
    
    
    return 0;
}
