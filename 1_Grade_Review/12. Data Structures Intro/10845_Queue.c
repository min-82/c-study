#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueType
{
    int arr[10000];
    int front;
    int rear;
} Q_type;

void init(Q_type *q)
{
    q->front = -1;
    q->rear = -1;
}

int is_Empty(Q_type *q)
{
    if(q->front == q->rear)
        return 1;
    return 0;
}

void enQueue(Q_type *q, int value)
{
    q->arr[++(q->rear)] = value;
}

int deQueue(Q_type *q)
{
    if(is_Empty(q) == 1)
        return -1;
    return q->arr[++(q->front)];
}

int q_Size(Q_type *q)
{
    return (q->rear - q->front);
}

int front_deQueue(Q_type *q)
{
    if(is_Empty(q) == 1)
        return -1;
    return q->arr[(q->front)+1];
}

int back_deQueue(Q_type *q)
{
    if(is_Empty(q) == 1)
        return -1;
    return q->arr[(q->rear)];
}

int main()
{
    int n, value, *r, count=0;
    char c[100];

    Q_type q;
    init(&q);

    scanf("%d", &n);

    r = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        scanf("%s", c);
            if(strcmp(c, "pop") == 0){
            r[count] = deQueue(&q);
            count++;}
        else if(strcmp(c, "front") == 0){
            r[count] = front_deQueue(&q);
            count++;}
        else if(strcmp(c, "back") == 0){
            r[count] = back_deQueue(&q);
            count++;}
        else if(strcmp(c, "empty") == 0){
            r[count] = is_Empty(&q);
            count++;}
        else if(strcmp(c, "size") == 0){
            r[count] = q_Size(&q);
            count++;}
        else{
            scanf("%d", &value);
            enQueue(&q, value);
        }
    }

    for(int i=0;i<count;i++){
        printf("%d\n", r[i]);
    }

    free(r);

    return 0;
}