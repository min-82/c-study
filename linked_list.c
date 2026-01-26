#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// 1. 특정 위치(index) 뒤에 삽입 (0부터 시작)
void insertNode(struct Node *head, int index, int newValue) {
    struct Node *curr = head;
    for (int i = 0; i < index && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) return; // 범위를 벗어난 경우

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newValue;

    // 핵심: 새 노드가 기존 다음 노드를 가리키게 하고, 
    // 기존 노드는 새 노드를 가리키게 함
    newNode->next = curr->next; 
    curr->next = newNode;
}

// 2. 특정 데이터값을 가진 노드 삭제
void deleteNode(struct Node **headAddr, int targetValue) {
    struct Node *curr = *headAddr;
    struct Node *prev = NULL;

    // 삭제할 노드 찾기
    while (curr != NULL && curr->data != targetValue) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return; // 찾는 값이 없음

    // 머리 노드를 삭제하는 경우
    if (prev == NULL) {
        *headAddr = curr->next;
    } else {
        // 이전 노드가 내 다음 노드를 가리키게 함 (나를 건너뜀)
        prev->next = curr->next;
    }

    free(curr); // 실제 메모리 해제
}

// 리스트 출력 함수
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    // 기본 추가
    insertNode(head, 0, 20); // 10 뒤에 20 삽입 (10 -> 20)
    insertNode(head, 1, 30); // 20 뒤에 30 삽입 (10 -> 20 -> 30)
    
    printf("초기 리스트: ");
    printList(head);

    // 특정 위치 삽입 테스트
    printf("인덱스 1 위치에 99 삽입: ");
    insertNode(head, 1, 99); // (10 -> 20 -> 99 -> 30)
    printList(head);

    // 삭제 테스트
    printf("데이터 20 삭제: ");
    deleteNode(&head, 20);
    printList(head);

    // 메모리 해제 루틴
    struct Node *temp;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }

    return 0;
}
