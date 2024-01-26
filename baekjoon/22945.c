#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

// two pointer
int two_pointer(int N, short *arr ) {
    int s = 0, e = N - 1;
    int res = 0;
    while (s < e) {
        res = MAX(MIN(arr[s], arr[e]) * (e-s-1), res);
        if (arr[s] < arr[e]) s++;
        else e--;
    }

    return res;
}

int main() {
    int N, i, ans;
    short *arr;

    // Get input
    scanf("%d", &N);

    // Dynamic allocation
    arr = (short *)malloc(N * sizeof(short));
    for(i = 0; i < N; i++) {
        scanf("%hd", arr+i);
    }

    // Run two pointer
    ans = two_pointer(N, arr);

    printf("%d\n", ans);

    // Free resources
    free(arr);
    return 0;
}