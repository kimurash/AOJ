/* 2分木の表現 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
// #define all(v) v.begin(), v.end()

#define NIL -1
#define MAX_NODE 25 // 節の数の最大値

using namespace std;

typedef struct node {
    int parent = NIL;
    int left = NIL;
    int right = NIL;
    uint8_t depth = 0;
    uint8_t height = 0;
} Node;

Node btree[MAX_NODE];

// 節番号がidの節から再帰的に深さをセット
void set_depth(int id, uint8_t d) {
    if (id == NIL) {
        return;
    }

    btree[id].depth = d;
    set_depth(btree[id].left, d + 1);
    set_depth(btree[id].right, d + 1);
    return;
}

// 節番号がidの節から再帰的に高さをセット
uint8_t set_height(int id) {
    int hl = 0, hr = 0;

    if (btree[id].left != NIL) {
        hl = set_height(btree[id].left) + 1;
    }

    if (btree[id].right != NIL) {
        hr = set_height(btree[id].right) + 1;
    }

    // 左右の高さの大きい方
    // この高さで+1すると葉の高さが1になる
    btree[id].height = max(hl, hr);
    return (btree[id].height);
}

// 節番号がidの兄弟の節番号を取得
int get_sibling(int id) {
    int parent = btree[id].parent;
    if (parent == NIL) {
        return (NIL);
    }

    if (btree[parent].left != NIL && btree[parent].left != id) {
        return (btree[parent].left);
    } else if (btree[parent].right != NIL && btree[parent].right != id) {
        return (btree[parent].right);
    } else {
        return (NIL);
    }
}

void print_node(int id) {
    cout << "node " << id << ": ";
    cout << "parent = " << btree[id].parent << ", ";
    cout << "sibling = " << get_sibling(id) << ", ";
    int deg = 0;
    if (btree[id].left != NIL) {
        deg++;
    }
    if (btree[id].right != NIL) {
        deg++;
    }
    cout << "degree = " << deg << ", ";
    // cout << "depth = " << btree[id].depth << ", ";
    printf("depth = %u, ", btree[id].depth);
    // cout << "height = " << btree[id].height << ", ";
    printf("height = %u, ", btree[id].height);
    if (btree[id].parent == NIL) {
        cout << "root" << endl;
    } else if (btree[id].left == NIL && btree[id].right == NIL) {
        cout << "leaf" << endl;
    } else {
        cout << "internal node" << endl;
    }
    return;
}

int main() {
    int n;
    cin >> n;

    int id;
    rep(i, n) {
        cin >> id;
        cin >> btree[id].left >> btree[id].right;

        if (btree[id].left != NIL) {
            btree[btree[id].left].parent = id;
        }

        if (btree[id].right != NIL) {
            btree[btree[id].right].parent = id;
        }
    }

    /* 根を特定 */
    int root;
    rep(i, n) {
        if (btree[i].parent == NIL) {
            root = i;
            break;
        }
    }

    set_depth(root, 0);
    set_height(root);
    rep(i, n){ print_node(i); }

    return (0);
}