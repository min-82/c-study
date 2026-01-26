#include <stdio.h>
#include <stdlib.h>

typedef struct C_Node
{
    int data;
    struct C_Node *next;
}Node;

Node *head = NULL;
Node *tail = NULL;

void CreateNode(int num)
{
    Node *NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = num;
    NewNode->next = NULL;

    if(head == NULL){
        head = NewNode;
        tail = NewNode;
    }

    else{
        tail->next = NewNode;
        tail = NewNode;
    }
}

Node *DeleteNode(int num, Node *curNode, int *arr)
{

    for(int i=0;i<num-1;i++){
        curNode = curNode->next;
    }

    Node *targetNode = curNode->next;
    printf("%d, ", targetNode->data);
    curNode->next = targetNode->next;
    free(targetNode);

    return curNode;
}

int main()
{
    int n, m, count;

    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++){
        CreateNode(i+1);
    }

    int *arr = (int*)malloc(sizeof(int)*n);

    tail->next = head;

    Node *curNode = tail;

    printf("<");
    count=n;
    while(count>1)
    {
        curNode = DeleteNode(m, curNode, arr);
        count--;
    }
    printf("%d>", curNode->data);

    free(curNode);
    free(arr);

    return 0;
}