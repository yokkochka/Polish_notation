#include <stdlib.h>

#include "graph.h"

// STEP 2 STACK
struct node *push(struct node *top, char *item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->item = item;
    temp->prev = top;
    return temp;
}

struct node *pop(struct node *top) {
    struct node *temp = top;
    top = top->prev;
    free(temp);
    return top;
}

void destroy(struct node *top) {
    while (top) {
        top = pop(top);
    }
}

void polka(char *str) {
    char temp[MAX_LEN];
    char *s = str;
    int j = 0, flag = 1;
    struct node *top = NULL;
    while (*s != '\0') {
        if (*s == ' ' || *s == '\n') {
            s++;
            flag = 0;
        }
        if (check_priority(s) == 5 || *s == '(') {
            top = push(top, s);
        } else if (*s == ')') {
            while (top && *(top->item) != '(') {
                temp[j++] = *(top->item);
                top = pop(top);
            }
            if (top && *(top->item) == '(') top = pop(top);
        } else if (check_priority(s) == 3 || check_priority(s) == 4) {
            while (top && check_priority(s) <= check_priority(top->item)) {
                temp[j++] = *(top->item);
                top = pop(top);
            }
            top = push(top, s);
        } else {
            int is_number = 0;
            while ((*s >= '0' && *s <= '9') || *s == 'x' || *s == '.') {
                temp[j++] = *s++;
                is_number = 1;
            }
            if (is_number) temp[j++] = ' ';
            flag = 0;
        }
        if (flag != 0) s++;
        flag = 1;
    }
    while (top) {
        temp[j++] = *(top->item);
        top = pop(top);
    }
    temp[j] = '\0';
    my_strcpy(str, temp);
    destroy(top);
}

int check_priority(const char *symbol) {
    int res = 0;
    if (*symbol == '?' || *symbol == 's' || *symbol == 'c' || *symbol == 'r' || *symbol == 'l' ||
        *symbol == 't' || *symbol == 'g') {
        res = 5;
    } else if (*symbol == '*' || *symbol == '/') {
        res = 4;
    } else if (*symbol == '+' || *symbol == '-') {
        res = 3;
    } else if (*symbol == '(') {
        res = 2;
    } else if (*symbol == ')') {
        res = 1;
    }

    return res;
}
