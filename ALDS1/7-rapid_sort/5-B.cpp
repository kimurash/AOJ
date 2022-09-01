/* マージソート(連結リスト) */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef struct node {
    int32_t value;
    struct node *next;
} Node;

// int16_t count = 0;  // 比較回数
// [ERR]: reference to 'count' is ambiguous

void show_all(Node *head) {
    if (head != NULL) {
        cout << head->value;
    } else {
        return;
    }

    head = head->next;
    while (head != NULL) {
        cout << " " << head->value;
        head = head->next;
    }
    cout << endl;

    return;
}

Node *merge_list(Node *a, Node *b, int16_t *cnt) {
    Node head, *p;

    p = &head;
    while (a != NULL && b != NULL) {
        if (a->value <= b->value) {
            p->next = a;
            p = a;
            a = a->next;
        } else {
            p->next = b;
            p = b;
            b = b->next;
        }
        (*cnt)++;
    }

    if (a == NULL) {
        p->next = b;
    } else {
        p->next = a;
    }

    // show_all(head.next);
    return (head.next);
}

Node *sort_list(Node *lst, int16_t *cnt) {
    // 要素が全くない or 1つしかない
    if (lst == NULL || lst->next == NULL) {
        return (lst);
    }

    // 前半と後半に分割
    Node *p = lst;        // 先頭要素
    Node *q = lst->next;  // 2番目の要素
    if (q != NULL) {
        q = q->next;  // 3番目の要素
    }
    /*  ポインタqが末尾に到達したとき
        pはほぼ中央の要素を指している */
    while (q != NULL) {
        p = p->next;
        q = q->next;
        if (q != NULL) {
            q = q->next;
        }
    }
    Node *half = p->next;
    p->next = NULL;

    // (1)前半をマージソート
    // (2)後半をマージソート
    // (3)前半と後半をマージ
    return (merge_list(sort_list(lst, cnt), sort_list(half, cnt), cnt));
}

int main() {
    int n;
    cin >> n;

    int32_t input;
    Node *head = NULL;
    Node **p = &head, *q;
    rep(i, n) {
        cin >> input;
        if ((q = (Node *)malloc(sizeof(Node))) == NULL) {
            cout << "Failled to malloc()" << endl;
            exit(-1);
        }
        q->value = input;
        q->next = NULL;

        *p = q;
        p = &((*p)->next);
    }
    // show_all(head);

    // マージする関数を呼び出す
    int16_t count = 0;
    head = sort_list(head, &count);

    // 全要素と比較回数の表示
    show_all(head);
    cout << count << endl;

    return (0);
}