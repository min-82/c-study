    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct StackType
    {
        int arr[10000];
        int top;
    } S_type;

    void init(S_type *s)
    {
        s->top = -1;
    }

    int is_Empty(S_type *s)
    {
        if(s->top == -1)
            return 1;
        return 0;
    }

    int is_Full(S_type *s)
    {
        if(s->top == 10000 - 1)
            return 1;
        return 0;
    }

    void push(S_type *s, int value)
    {
        s->arr[++(s->top)] = value;
    }

    int pop(S_type *s)
    {
        if(is_Empty(s) == 1)
            return -1;
        return s->arr[(s->top)--]; 
    }

    int peek_top(S_type *s)
    {
        if(is_Empty(s) == 1)
            return -1;
        return s->arr[s->top];
    }

    int s_Size(S_type *s)
    {
        return (s->top + 1);
    }

    int main()
    {
        int n, value, *r, count=0;
        char c[100];

        S_type s;
        init(&s);
        
        scanf("%d", &n);

        r = (int*)malloc(sizeof(int)*n);

        for(int i=0;i<n;i++){
            scanf("%s", c);
            if(strcmp(c, "pop") == 0){
                r[count] = pop(&s);
                count++;}
            else if(strcmp(c, "top") == 0){
                r[count] = peek_top(&s);
                count++;}
            else if(strcmp(c, "empty") == 0){
                r[count] = is_Empty(&s);
                count++;}
            else if(strcmp(c, "size") == 0){
                r[count] = s_Size(&s);
                count++;}
            else{
                scanf("%d", &value);
                push(&s, value);
            }
        }

        for(int i=0;i<count;i++){
            printf("%d\n", r[i]);
        }

        free(r);

        return 0;
    }