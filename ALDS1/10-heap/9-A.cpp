/* 完全二分木 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

void print_heap(int32_t *heap, int H) {
    rep2(i, 1, H + 1) {
        printf("node %d: key = %d, ", i, heap[i]);
        if (i / 2 > 0) {
            printf("parent key = %d, ", heap[i / 2]);
        }
        if (2 * i <= H) {
            printf("left key = %d, ", heap[2 * i]);
        }
        if (2 * i + 1 <= H) {
            printf("right key = %d, ", heap[2 * i + 1]);
        }
        putchar('\n');
    }
    return;
}

int main() {
    int H;
    cin >> H;

    int32_t heap[H + 1];
    rep2(i, 1, H + 1) { cin >> heap[i]; }
    print_heap(heap, H);

    return (0);
}