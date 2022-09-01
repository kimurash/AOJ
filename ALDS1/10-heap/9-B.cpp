/* 最大/最小ヒープ */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

void downheap(int32_t *heap, int H, int i) {
    int32_t left = 2 * i;
    int32_t right = 2 * i + 1;

    int largest;
    if (left <= H && heap[i] < heap[left]) {
        largest = left;
    } else {
        largest = i;
    }

    if (right <= H && heap[largest] < heap[right]) {
        largest = right;
    }

    if (largest != i) {
        int32_t temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        downheap(heap, H, largest);
    }
    return;
}

void build_max_heap(int32_t *heap, int H) {
    for (int i = H / 2; i >= 1; i--) {
        downheap(heap, H, i);
    }
}

int main() {
    int H;
    cin >> H;

    int32_t heap[H + 1];
    rep2(i, 1, H + 1) { cin >> heap[i]; }

    build_max_heap(heap, H);
    rep2(i, 1, H + 1) { cout << " " << heap[i]; }
    cout << endl;

    return (0);
}