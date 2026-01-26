#include <stdio.h>
#include <stdlib.h> // qsort 함수를 사용하기 위해 필요합니다.

// 1. x, y 좌표를 묶을 새로운 구조체 정의
typedef struct {
    int x;
    int y;
} Point;

// 2. qsort를 위한 비교 함수 (Comparator Function)
// 이 함수는 qsort에게 어떤 Point가 더 작은지 알려줍니다.
int compare_points(const void *a, const void *b) {
    // void* 포인터를 Point* 타입으로 캐스팅합니다.
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;

    // 1순위: x 좌표 기준으로 오름차순 정렬
    if (pa->x != pb->x) {
        // pa->x - pb->x 결과가 
        // 음수면 pa가 작다 (순서 유지), 양수면 pb가 작다 (순서 교환)
        return pa->x - pb->x; 
    } 
    // 2순위: x 좌표가 같으면 y 좌표 기준으로 오름차순 정렬
    else {
        return pa->y - pb->y;
    }
}

int main()
{
    int n;
    
    // 입력 크기가 클 경우를 대비하여 배열 크기를 동적으로 설정할 수도 있습니다.
    // 여기서는 최대 크기 100,000을 가정합니다.
    // ⚠️ 만약 N이 1000 이하라면 배열 크기를 1000으로 유지해도 됩니다.
    // 백준 11650번 (좌표 정렬)의 N 최대값은 100,000이므로, 
    // 정적 할당 대신 동적 할당 또는 배열 크기를 늘려야 합니다.
    
    // **N 최대 100,000을 가정하고 정적 배열 크기를 늘린 버전:**
    Point p[100000]; 
    
    // (만약 1000으로 충분하다면 Point p[1000]; 사용)
    
    if (scanf("%d", &n) != 1) return 1;

    for(int i=0;i<n;i++){
        // 3. Point 구조체의 x, y 멤버에 직접 입력받습니다.
        if (scanf("%d %d", &p[i].x, &p[i].y) != 2) return 1;
    }

    // 4. qsort 함수 호출: O(N log N)으로 정렬
    // 인자: (배열 시작 주소, 요소 개수, 요소 하나의 크기, 비교 함수)
    qsort(p, n, sizeof(Point), compare_points);

    // 5. 정렬된 결과 출력
    for(int i=0;i<n;i++){
        printf("%d %d\n", p[i].x, p[i].y);
    }

    return 0;
}

/*
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int n, int *x, int *y)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(x[j]>x[j+1]){
                swap(&x[j], &x[j+1]);
                swap(&y[j], &y[j+1]);
            }
            else if(x[j]==x[j+1] && y[j]>y[j+1]){
                swap(&y[j], &y[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct point
    {
        int x[n];
        int y[n];
    }p;



    for(int i=0;i<n;i++){
        scanf("%d %d", &p.x[i], &p.y[i]);
    }

    sort(n, p.x, p.y);

    for(int i=0;i<n;i++){
        printf("%d %d\n", p.x[i], p.y[i]);
    }
    return 0;
}
*/