#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define NIL -1
#define MAX_NODE 25

using namespace std;

typedef struct node {
    int parent = NIL;
    int left = NIL;
    int right = NIL;
} Node;

Node btree[MAX_NODE];

// 節番号がidの節から行きがけ順で走査
void preorder(int id) {
    cout << " " << id;

    if (btree[id].left != NIL) {
        preorder(btree[id].left);
    }

    if (btree[id].right != NIL) {
        preorder(btree[id].right);
    }
    return;
}

// 節番号がidの節から通りがけ順で走査
void inorder(int id) {
    if (btree[id].left != NIL) {
        inorder(btree[id].left);
    }

    cout << " " << id;

    if (btree[id].right != NIL) {
        inorder(btree[id].right);
    }
    return;
}

// 節番号がidの節から帰りがけ順で走査
void postorder(int id) {
    if (btree[id].left != NIL) {
        postorder(btree[id].left);
    }

    if (btree[id].right != NIL) {
        postorder(btree[id].right);
    }

    cout << " " << id;
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

    cout << "Preorder" << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;

    return (0);
}