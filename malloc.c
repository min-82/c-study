#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	int *ptr;

	printf("메모리를 몇 칸(int 기준) 빌릴까요? : ");
    scanf("%d", &size);

	// 1. 메모리 빌리기 (malloc: memory allocation)
    // int 크기 * 개수 만큼 메모리를 '힙(Heap)' 영역에서 빌려옵니다.
    ptr = (int *)malloc(sizeof(int) * size);

    if (ptr == NULL) {
        printf("메모리 빌리기에 실패했습니다.\n");
        return 1;
    }

    // 2. 빌린 메모리 사용하기
    for (int i = 0; i < size; i++) {
        ptr[i] = (i + 1) * 10;
        printf("ptr[%d]의 값: %d (주소: %p)\n", i, ptr[i], (void*)&ptr[i]);
    }

    // 3. 다 썼으면 반드시 반납하기 (free)
    // 이걸 안 하면 '메모리 누수(Memory Leak)'가 발생합니다.
    free(ptr);
    printf("메모리를 반납했습니다.\n");

    return 0;
}
