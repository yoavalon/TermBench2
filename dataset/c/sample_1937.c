#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

typedef struct {
    char key[100];
    union {
        double f;
        struct {
            int size;
            void** elements;
        } list;
        struct {
            int size;
            struct {
                char key[100];
                void* value;
            }* items;
        } dict;
    } value;
    char type; // 'f' for float, 'l' for list, 'd' for dict
} Node;

bool check_precision(Node* node) {
    if (node->type == 'f') {
        double rounded = round(node->value.f * 10000000000) / 10000000000;
        return fabs(node->value.f - rounded) < 1e-10;
    } else if (node->type == 'd') {
        for (int i = 0; i < node->value.dict.size; i++) {
            if (!check_precision((Node*)node->value.dict.items[i].value)) {
                return false;
            }
        }
        return true;
    } else if (node->type == 'l') {
        for (int i = 0; i < node->value.list.size; i++) {
            if (!check_precision((Node*)node->value.list.elements[i])) {
                return false;
            }
        }
        return true;
    }
    return true;
}

bool analyze_tree(Node* tree) {
    return check_precision(tree);
}

void main() {
    Node data;
    data.type = 'd';
    data.value.dict.size = 4;
    data.value.dict.items = (struct {
        char key[100];
        void* value;
    }*)malloc(data.value.dict.size * sizeof(struct {
        char key[100];
        void* value;
    }));

    Node* a = (Node*)malloc(sizeof(Node));
    a->type = 'f';
    a->value.f = 1.123456789012345;
    strcpy(data.value.dict.items[0].key, "a");
    data.value.dict.items[0].value = a;

    Node* b = (Node*)malloc(sizeof(Node));
    b->type = 'l';
    b->value.list.size = 2;
    b->value.list.elements = (void**)malloc(b->value.list.size * sizeof(void*));

    Node* b1 = (Node*)malloc(sizeof(Node));
    b1->type = 'f';
    b1->value.f = 2.123456789012345;
    b->value.list.elements[0] = b1;

    Node* b2 = (Node*)malloc(sizeof(Node));
    b2->type = 'd';
    b2->value.dict.size = 1;
    b2->value.dict.items = (struct {
        char key[100];
        void* value;
    }*)malloc(b2->value.dict.size * sizeof(struct {
        char key[100];
        void* value;
    }));

    Node* c = (Node*)malloc(sizeof(Node));
    c->type = 'f';
    c->value.f = 3.123456789012345;
    strcpy(b2->value.dict.items[0].key, "c");
    b2->value.dict.items[0].value = c;
    b->value.list.elements[1] = b2;

    strcpy(data.value.dict.items[1].key, "b");
    data.value.dict.items[1].value = b;

    Node* d = (Node*)malloc(sizeof(Node));
    d->type = 'f';
    d->value.f = 4.123456789;
    strcpy(data.value.dict.items[2].key, "d");
    data.value.dict.items[2].value = d;

    Node* e = (Node*)malloc(sizeof(Node));
    e->type = 'f';
    e->value.f = 0.0;
    strcpy(data.value.dict.items[3].key, "e");
    data.value.dict.items[3].value = e;

    bool result = analyze_tree(&data);
    printf("Precision check: %d\n", result);
}