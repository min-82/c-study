    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct _Node
    {
        char data;
        struct _Node* next;
    } Node;

    void Create_Node(Node **head, Node **tail, char data, int *cursor);
    void Print_Node(Node *head);
    void Delete_Node(Node *head, int position);
    void Insert_Node(Node **head, char data, int position);

    int main()
    {
        Node *head = NULL;
        Node *tail = NULL;
        int n, cursor=0;
        char command, P_command, arr[1001];

        scanf("%s", arr);
        for(int i=0;arr[i]!='\0';i++){
            Create_Node(&head, &tail, arr[i], &cursor);
        }

        scanf("%d", &n);

        for(int i=0;i<n;i++){
            scanf(" %c", &command);

            if(command == 'L'){
                if(cursor != 0)
                    cursor--;
            }

            /*else if(command == 'D'){
                if()
                    cursor++;
            }*/

            else if(command == 'B'){
                Delete_Node(head, cursor);
            }

            else if(command == 'P'){
                scanf(" %c", &P_command);
                Insert_Node(&head, P_command, cursor);
            }
        }

        Print_Node(head);

        return 0;
    }

    void Create_Node(Node **head, Node **tail, char data, int *cursor)
    {
        Node *NewNode = (Node*)malloc(sizeof(Node));
        NewNode->data = data;
        NewNode->next = NULL;

        if(*head == NULL)
        {
            *head = NewNode;
            *tail = NewNode;
        }

        else
        {
            (*tail)->next = NewNode;
            *tail = NewNode;
        }
        (*cursor)++;
    }

    void Print_Node(Node *head)
    {
        Node *cur_Node = head;

        while(cur_Node != NULL)
        {
            printf("%c", cur_Node->data);
            cur_Node = cur_Node->next;
        }
    }

    void Delete_Node(Node *head, int position)
    {
        Node *cur_Node = head;
        
        for(int i=0;i<position-1 && cur_Node != NULL;i++){
            cur_Node = cur_Node->next;
        }

        Node *target_Node = cur_Node->next;
        cur_Node->next = target_Node->next;
        free(target_Node);
    }

    void Insert_Node(Node **head, char data, int position)
    {
        Node *NewNode = (Node*)malloc(sizeof(Node));
        NewNode->data = data;
        NewNode->next = NULL;

        Node *cur_Node = *head;

        if(position == 0)
        {
            NewNode->next = *head;
            *head = NewNode;
            return;
        }

        for(int i=0;i<position-1 && cur_Node != NULL;i++){
            cur_Node = cur_Node->next;
        }

        if(cur_Node ==NULL)
        {
            printf("Out of Bounds\n");
            free(NewNode);
            return;
        }

        NewNode->next = cur_Node->next;
        cur_Node->next = NewNode;
    }