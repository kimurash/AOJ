/* 優先度付きキュー */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define DUMMY -1

using namespace std;

typedef enum cmd_type { INSERT, EXTRACT, END, UNKNOWN } CmdType;

CmdType discern_cmd(const string &cmd);
void insert(int32_t key);
void upheap(int i);
int32_t extract_root();
void downheap(int i);
void print_heap();

vector<int32_t> heap(1, DUMMY);

int main() {
    int32_t key;
    string cmd;

    bool flg = true;
    while (flg) {
        cin >> cmd;
        switch (discern_cmd(cmd)) {
            case INSERT:
                cin >> key;
                insert(key);
                break;
            case EXTRACT:
                cout << extract_root() << endl;
                break;
            case END:
                flg = false;
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

    return (0);
}

CmdType discern_cmd(const string &cmd) {
    if (cmd == "insert") {
        return (INSERT);
    } else if (cmd == "extract") {
        return (EXTRACT);
    } else if (cmd == "end") {
        return (END);
    } else {
        return (UNKNOWN);
    }
}

void insert(int32_t key) {
    // printf("insert(%d)\n", key);

    heap.push_back(key);
    upheap(heap.size() - 1);
}

void upheap(int i) {
    if (i <= 1) {
        return;
    }

    int parent;
    int32_t temp;
    while (i > 1 && heap.at(parent = i / 2) < heap.at(i)) {
        temp = heap.at(i);
        heap.at(i) = heap.at(parent);
        heap.at(parent) = temp;

        i = parent;
    }

    // print_heap();
    return;
}

int32_t extract_root() {
    if (heap.size() <= 1) {
        cout << "heap underflow" << endl;
        return (DUMMY);
    }

    int32_t max = heap.at(1);
    heap.at(1) = heap.at(heap.size() - 1);
    heap.pop_back();
    downheap(1);

    // print_heap();
    return (max);
}

void downheap(int i) {
    int32_t left = 2 * i;
    int32_t right = 2 * i + 1;

    int largest;
    if (left <= heap.size() - 1 && heap.at(i) < heap.at(left)) {
        largest = left;
    } else {
        largest = i;
    }

    if (right <= heap.size() - 1 && heap.at(largest) < heap.at(right)) {
        largest = right;
    }

    if (largest != i) {
        int32_t temp = heap.at(i);
        heap.at(i) = heap.at(largest);
        heap.at(largest) = temp;
        downheap(largest);
    }
    return;
}

void print_heap() {
    rep2(i, 1, heap.size()) { cout << heap.at(i) << " "; }
    cout << endl;
    return;
}