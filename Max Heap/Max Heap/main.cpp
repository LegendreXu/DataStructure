//
//  main.cpp
//  Max Heap
//
//  Created by 许国嵩 on 17/12/17.
//  Copyright © 2017年 许国嵩. All rights reserved.
//

#include <iostream>

using namespace std;

void insert(int value,int index,int* heap) {
    int temp;
    heap[index] = value;
    while (value > heap[index / 2]) {
        temp = heap[index / 2];
        heap[index / 2] = value;
        heap[index] = temp;
        index = index / 2;
    }
}

void pop(int size, int *heap) {
    int temp;
    
    heap[1] = heap[size+1];
    int value = heap[1];
    int position = 1;
    if (size % 2 == 0) {
        while (position * 2 <= size) {
            if (position * 2 == size) {
                if (value < heap[position * 2]) {
                    temp = value;
                    heap[position] = heap[position * 2];
                    heap[position * 2] = temp;
                    break;
                }
                else
                    break;
            }
            else if (value < heap[position * 2] || value < heap[position * 2 + 1]) {
                temp = value;
                if (heap[position * 2] >= heap[position * 2 + 1]) {
                    heap[position] = heap[position * 2];
                    heap[position * 2] = temp;
                    position = position * 2;
                }
                else if (heap[position * 2] < heap[position * 2 + 1]) {
                    heap[position] = heap[position * 2 + 1];
                    heap[position * 2 + 1] = temp;
                    position = position * 2 + 1;
                }
            }
            else
                break;
        }
    }
    if (size % 2 == 1) {
        while (position*2+1 <= size) {
            if (value < heap[position * 2] || value < heap[position * 2 + 1]) {
                temp = value;
                if (heap[position * 2] >= heap[position * 2 + 1]) {
                    heap[position] = heap[position * 2];
                    heap[position * 2] = temp;
                    position = position * 2;
                }
                else if (heap[position * 2] < heap[position * 2 + 1]) {
                    heap[position] = heap[position * 2 + 1];
                    heap[position * 2 + 1] = temp;
                    position = position * 2 + 1;
                }
            }
            else
                break;
        }
    }
    
}

int main() {
    int numOfOperations;
    while (cin >> numOfOperations) {
        int value,index=0;
        char operation;
        int heap[100002];
        heap[0] = { 1001 };
        for (int j = 0; j < numOfOperations;j++) {
            cin >> operation;
            if (operation == 'a') {
                index++;
                cin >> value;
                insert(value,index,heap);
            }
            else if (operation == 'p') {
                index--;
                pop(index,heap);
            }
            else if (operation == 'r') {
                int sum = 0;
                for (int x = 1; x <= index; x++) {
                    sum = sum + heap[x];
                }
                cout << sum << endl;
            }
        }
    }
    return 0;
}
