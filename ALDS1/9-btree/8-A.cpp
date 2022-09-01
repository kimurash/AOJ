/* 二部探索木 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef enum cmd_type { INSERT, PRINT, FIND, DELETE, UNKNOWN } CmdType;

typedef struct node {
    int32_t key;
    // struct node *parent;
    struct node *left, *right;
} Node;

Node *root = NULL;

CmdType discern_cmd(const string &cmd);
Node *insert(int32_t key);
void print_node(Node *p);
void inorder(Node *p);
void preorder(Node *p);
Node *find(int32_t key);
void delete_node(int32_t key);  // deleteは予約語
Node *delete_min(Node **root);

int main() {
    int n;
    cin >> n;

    int32_t key;
    string cmd;
    rep(i, n) {
        cin >> cmd;
        switch (discern_cmd(cmd)) {
            case INSERT:
                cin >> key;
                insert(key);
                break;
            case PRINT:
                print_node(root);
                break;
            case FIND:
                cin >> key;
                find(key);
                break;
            case DELETE:
                cin >> key;
                delete_node(key);
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
    } else if (cmd == "print") {
        return (PRINT);
    } else if (cmd == "find") {
        return (FIND);
    } else if (cmd == "delete") {
        return (DELETE);
    } else {
        return (UNKNOWN);
    }
}

Node *insert(int32_t key) {
    Node **p = &root;
    while (*p != NULL) {
        if (key < (*p)->key) {
            p = &((*p)->left);
        } else if ((*p)->key < key) {
            p = &((*p)->right);
        } else {
            return (*p);
        }
    }

    Node *node_new;
    if ((node_new = (Node *)malloc(sizeof(Node))) == NULL) {
        cout << "Couldn't allocate memory" << endl;
    }
    node_new->key = key;
    node_new->right = node_new->left = NULL;
    *p = node_new;

    return (node_new);
}

void print_node(Node *p) {
    inorder(p);
    cout << endl;
    preorder(p);
    cout << endl;

    return;
}

void inorder(Node *p) {
    if (p->left != NULL) {
        inorder(p->left);
    }
    cout << " " << p->key;
    if (p->right != NULL) {
        inorder(p->right);
    }

    return;
}

void preorder(Node *p) {
    cout << " " << p->key;
    if (p->left != NULL) {
        preorder(p->left);
    }
    if (p->right != NULL) {
        preorder(p->right);
    }

    return;
}

Node *find(int32_t key) {
    Node **p = &root;
    while (*p != NULL) {
        if (key < (*p)->key) {
            p = &((*p)->left);
        } else if ((*p)->key < key) {
            p = &((*p)->right);
        } else {
            cout << "yes" << endl;
            return (*p);
        }
    }

    cout << "no" << endl;
    return (NULL);
}

void delete_node(int32_t key) {
    Node **p = &root;
    while (*p != NULL) {
        if (key < (*p)->key) {
            p = &((*p)->left);
        } else if ((*p)->key < key) {
            p = &((*p)->right);
        } else {
            Node *deleted = *p;
            if ((*p)->right == NULL && (*p)->left == NULL) {  // 葉である
                *p = NULL;
            } else if ((*p)->right == NULL) {  // 左の子を持つ
                *p = deleted->left;
            } else if ((*p)->left == NULL) {  // 右の子を持つ
                *p = deleted->right;
            } else {  // 左右の子を持つ
                *p = delete_min(&(deleted->right));
                (*p)->left = deleted->left;
                (*p)->right = deleted->right;
            }
            free(deleted);
            return;
        }
    }

    cout << "Couldn't find a node of " << key;
    cout << " to be deleted";
    return;
}

// 根をrootとする部分木の最小の節を削除する
Node *delete_min(Node **root) {
    while ((*root)->left != NULL) {
        root = &((*root)->left);
    }
    Node *min = *root;
    *root = (*root)->right;
    return (min);
}