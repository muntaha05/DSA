#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int front = -1, rear = -1;

// Insert a node into the binary tree
void insert(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Tree overflow\n");
        exit(1);
    }
    if (front == -1) front = 0;
    rear++;
    tree[rear] = data;
}

// Print the binary tree
void printTree(int root, int level) {
    if (root >= MAX_SIZE || tree[root] == 0) return;
    printTree(2 * root + 2, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", tree[root]);
    printTree(2 * root + 1, level + 1);
}

// Main function
int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    printf("Binary Tree:\n");
    printTree(0, 0);
    return 0;
}
