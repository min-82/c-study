#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 연락처 구조체
typedef struct {
    char name[30];
    char phone[20];
} Contact;

int main() {
    int capacity = 2;   // 현재 수첩의 최대 칸 수 (처음엔 2칸)
    int count = 0;      // 현재 저장된 연락처 개수
    
    // 1. 구조체 포인터 배열 (포인터들의 주소를 담을 공간 할당)
    Contact **contacts = (Contact **)malloc(sizeof(Contact *) * capacity);

    printf("--- 연락처 관리 프로그램 시작 (초기 용량: %d) ---\n", capacity);

    while (1) {
        if (count == capacity) {
            printf("\n[시스템] 공간이 부족하여 확장합니다! (%d -> %d)\n", capacity, capacity * 2);
            
            // 2. realloc을 이용한 용량 확장 (보험용 temp 사용!)
            capacity *= 2;
            Contact **temp = (Contact **)realloc(contacts, sizeof(Contact *) * capacity);
            
            if (temp == NULL) {
                printf("메모리 확장 실패!\n");
                break;
            }
            contacts = temp;
        }

        // 3. 새 연락처 입력 받기
        contacts[count] = (Contact *)malloc(sizeof(Contact));
        
        printf("\n[%d번째 연락처 입력]\n", count + 1);
        printf("이름 (종료하려면 'exit' 입력): ");
        scanf("%s", contacts[count]->name);

        if (strcmp(contacts[count]->name, "exit") == 0) {
            free(contacts[count]); // 입력취소한 메모리 해제
            break;
        }

        printf("전화번호: ");
        scanf("%s", contacts[count]->phone);

        count++;
    }
	// 목록 출력 직전에 이 코드를 추가해 보세요.
	printf("\n[시스템] 이름순으로 정렬을 시작합니다...\n");

	for (int i = 0; i < count - 1; i++) {
	    for (int j = i + 1; j < count; j++) {
	        // strcmp로 이름을 비교해서 순서가 잘못됐다면
        	if (strcmp(contacts[i]->name, contacts[j]->name) > 0) {
            	// 핵심: '주소값(열쇠)'만 서로 맞바꿉니다!
            	Contact *tempPtr = contacts[i];
            	contacts[i] = contacts[j];
            	contacts[j] = tempPtr;
        	}
    	}
	}

    // 4. 전체 목록 출력
    printf("\n--- 저장된 연락처 목록 ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s : %s\n", i + 1, contacts[i]->name, contacts[i]->phone);
    }

    // 5. 메모리 해제 (중요!)
    for (int i = 0; i < count; i++) {
        free(contacts[i]); // 각 연락처 알맹이 해제
    }
    free(contacts); // 포인터 배열(기판) 해제

    printf("\n프로그램을 종료합니다. 메모리가 깨끗하게 정리되었습니다.\n");
    return 0;
}
