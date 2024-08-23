#include <math.h>
#include <stdlib.h>

#include "graph.h"

// STEP 3 VALUE IN POINT

double value_in_point(char *str, double x) {
    char *s = str;
    struct node_double *top = NULL;
    double num = 0;
    int flag = 1, flag_dot = 0, count = 0;
    while (*s != '\0') {
        while ((*s >= '0' && *s <= '9') || (*s == '.')) {
            if (*s == '.') {
                flag_dot = 1;
                s++;
            } else {
                num = num * 10 + (*s - '0');
                s++;
                flag = 0;
            }
            if (flag_dot == 1) count++;
        }
        if (flag == 0) {
            if (flag_dot) num /= pow(10.0, count);
            top = push_double_stack(top, create_number(num));
        } else if (*s == 'x') {
            top = push_double_stack(top, create_number(x));
        } else if (*s != ' ' && *s != '\n') {
            if (check_priority(s) == 5) {
                unarn(s, top);
            } else {
                binarn(top, top->prev, s);
                top = pop_double_stack(top);
            }
        }
        flag = 1;
        flag_dot = 0;
        count = 0;
        num = 0;
        s++;
    }
    double result = *top->item;
    destroy_double_stack(top);
    top->prev = NULL;
    top = NULL;
    return result;
}

double *create_number(double x) {
    double *num = (double *)malloc(sizeof(double));
    *num = x;
    return num;
}

void binarn(struct node_double *top, struct node_double *pre_top, char *s) {
    switch (*s) {
        case '*':
            *(pre_top->item) *= *(top->item);
            break;
        case '/':
            *(pre_top->item) /= *(top->item);
            break;
        case '+':
            *(pre_top->item) += *(top->item);
            break;
        case '-':
            *(pre_top->item) -= *(top->item);
            break;
    }
}

void unarn(char *s, struct node_double *top) {
    switch (*s) {
        case '?':
            *(top->item) *= -1;
            break;
        case 's':
            *(top->item) = sin(*(top->item));
            break;
        case 'c':
            *(top->item) = cos(*(top->item));
            break;
        case 't':
            *(top->item) = tan(*(top->item));
            break;
        case 'g':
            *(top->item) = (double)1 / tan(*(top->item));
            break;
        case 'r':
            *(top->item) = sqrt(*(top->item));
            break;
        case 'l':
            *(top->item) = log(*(top->item));
            break;
        default:
            break;
    }
}

struct node_double *push_double_stack(struct node_double *top, double *item) {
    struct node_double *temp = (struct node_double *)malloc(sizeof(struct node_double));
    temp->item = item;
    temp->prev = top;
    return temp;
}

struct node_double *pop_double_stack(struct node_double *top) {
    struct node_double *temp = top;
    top = top->prev;
    free(temp->item);
    free(temp);
    return top;
}

void destroy_double_stack(struct node_double *top) {
    while (top) {
        top = pop_double_stack(top);
    }
}
