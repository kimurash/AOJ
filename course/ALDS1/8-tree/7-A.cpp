/* 根付き木の表現 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_NODE 100000  // 節の数の最大値
#define NIL -1

using namespace std;

typedef struct node {
    uint32_t depth;     // 深さ
    int parent = -1;    // 親
    int child = NIL;    // 子
    int sibling = NIL;  // 兄弟
} Node;

Node tree[MAX_NODE];

// 節番号がidの節の深さをdにセットする
void set_depth(int id, uint32_t d) {
    tree[id].depth = d;
    if (tree[id].sibling != NIL) {
        set_depth(tree[id].sibling, d);
    }
    if (tree[id].child != NIL) {
        set_depth(tree[id].child, d + 1);
    }
    return;
}

// 各節の情報を出力
void print_node(int id) {
    cout << "node " << id << ": ";    // 節番号
    cout << "parent = " << tree[id].parent << ", ";   // 親
    cout << "depth = " << tree[id].depth << ", ";     // 深さ
    
    // 節の種類
    if (tree[id].parent == NIL) {
        cout << "root, ";
    } else if (tree[id].child == NIL) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }

    // 子のリスト
    cout << "[";
    int child = tree[id].child;
    while (child != NIL) {
        cout << child;
        child = tree[child].sibling;
        if (child != NIL) {
            cout << ", ";
        } else{
            break;
        }
    }
    cout << "]" << endl;

    // if (tree[id].sibling != NIL) {
    //     print_tree(tree[id].sibling);
    // }

    // if(tree[id].child != NIL){
    //     print_tree(tree[id].child);
    // }

    return;
}

int main() {
    int n;  // 節の数
    cin >> n;

    // tree[0].depth = 0;
    // tree[0].parent = tree[0].child = tree[0].sibling = NIL;

    int parent, child1, child2, n_child;
    rep(i, n) {
        cin >> parent >> n_child;
        if (n_child == 0) {
            continue;
        }

        cin >> child1;
        tree[parent].child = child1;
        tree[child1].parent = parent;

        rep(j, n_child - 1) {
            cin >> child2;
            tree[child1].sibling = child2;
            tree[child2].parent = parent;

            child1 = child2;
        }
    }

    // 根を特定する
    int root;
    rep(i, n){
        if(tree[i].parent == NIL){
            root = i;
            break;
        }
    }

    set_depth(root, 0);
    rep(i, n){ print_node(i); } // 節番号の昇順に出力

    return (0);
}