#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// 어떤 노드를 주든, 그 리스트의 '맨 뒤'를 찾아가서 붙여주는 함수
void addNode(struct Node *head, int newValue) {
    struct Node *curr = head;
    
    // 1. 마지막 노드(next가 NULL인 곳)까지 이동
    while (curr->next != NULL) {
        curr = curr->next;
    }

    // 2. 새 노드 생성
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->next = NULL;

    // 3. 마지막 노드 뒤에 연결
    curr->next = newNode;
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    // 함수를 이용해 계속 추가 가능
    addNode(head, 20);
    addNode(head, 30);
    addNode(head, 40);

    // 출력용 포인터를 따로 써서 head 보존
    struct Node *curr = head;
    while (curr != NULL) {
        printf("데이터: %d\n", curr->data);
        curr = curr->next;
    }

    // 🛡️ 안전한 메모리 해제 (중요!)
    struct Node *temp;
    while (head != NULL) {
        temp = head->next; // 다음 주소를 미리 '백업'
        free(head);        // 현재 노드 해제
        head = temp;       // 백업해둔 주소로 이동
    }

    return 0;
}
