#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. 처음에 숫자 2개를 담을 공간만 빌립니다.
    int *arr = (int *)malloc(sizeof(int) * 2);
    arr[0] = 10;
    arr[1] = 20;

    printf("--- 확장 전 ---\n");
    for(int i = 0; i < 2; i++) printf("arr[%d] = %d\n", i, arr[i]);
    printf("현재 주소: %p\n", (void*)arr);

    // 2. 공간이 부족해서 5개로 늘리고 싶습니다. (realloc)
    // 원래 주소(arr)와 새로운 총 크기를 알려줍니다.
    int *temp = (int *)realloc(arr, sizeof(int) * 5);

    if (temp == NULL) {
        free(arr);
        return 1;
    }
    arr = temp; // 안전하게 새 주소로 업데이트

    // 3. 늘어난 공간에 데이터 추가
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    printf("\n--- 확장 후 ---\n");
    for(int i = 0; i < 5; i++) printf("arr[%d] = %d\n", i, arr[i]);
    printf("새로운 주소: %p\n", (void*)arr);

    // 4. 정리
    free(arr);
    arr = NULL;

    return 0;
}
