#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[20];
	int age;
	int isAdmin; // 1 is admin, 0 is user
}User;

int main()
{
	User *user1 = (User*)malloc(sizeof(User));

	strcpy(user1->name, "Gemini");
	user1->age = 20;
	user1->isAdmin = 0;

	printf("--- 사용자 정보 ---\n");
    printf("이름: %s\n", user1->name);
    printf("나이: %d\n", user1->age);
    printf("관리자 여부: %s\n", user1->isAdmin ? "YES" : "NO");

    // 4. 메모리 반납 및 보안 조치
    free(user1);
    user1 = NULL;

    printf("\n안전하게 메모리를 반납했습니다.\n");

    return 0;
}
