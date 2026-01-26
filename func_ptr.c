#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[20];
    int isAdmin;
};

// 사용자를 관리자로 승격시키는 함수
// 포인터를 매개변수로 받아서 원본을 직접 건드립니다.
void promoteToAdmin(struct User *u) {
    if (u != NULL) {
        u->isAdmin = 1;
		strcpy(u->name, "SuperUser");
        printf("[시스템] %s님의 권한이 관리자로 승격되었습니다.\n", u->name);

    }
}

int main() {
    // 1. 동적 할당
    struct User *myUser = (struct User *)malloc(sizeof(struct User));
    
    strcpy(myUser->name, "Guest");
    myUser->isAdmin = 0;

    printf("현재 상태: %s (Admin: %d)\n", myUser->name, myUser->isAdmin);

    // 2. 함수에 '주소값'을 넘깁니다.
    promoteToAdmin(myUser);

    // 3. 함수 밖에서도 값이 바뀌었는지 확인
    printf("변경 후 상태: %s (Admin: %d)\n", myUser->name, myUser->isAdmin);

    // 4. 정리
    free(myUser);
    myUser = NULL;

    return 0;
}
