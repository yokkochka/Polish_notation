#ifndef GRAPH_H
#define GRAPH_H

#define MAX_LEN 100
#define WIDTH 85
#define HEIGHT 25
#define PI 3.1415926535

// STEP 1 STRING
void replace_math_function(char *str);
void polka(char *str);
int my_strcmp(char *str1, char *str2, int n);
char *my_strcpy(char *str1, char *str2);
int check_valid_str(char *str);

// STEP 2 STACK
int check_priority(const char *symbol);
struct node *push(struct node *top, char *item);
struct node *pop(struct node *top);
void destroy(struct node *top);

// struct
struct node {
    char *item;
    struct node *prev;
};

// STEP 3 VALUE IN POINT
double value_in_point(char *str, double x);
struct node_double *init_double_stack(double *item);
struct node_double *push_double_stack(struct node_double *top, double *item);
struct node_double *pop_double_stack(struct node_double *top);
void destroy_double_stack(struct node_double *top);
void unarn(char *s, struct node_double *top);
void binarn(struct node_double *top, struct node_double *pre_top, char *s);
double *create_number(double x);

// struct
struct node_double {
    double *item;
    struct node_double *prev;
};

// STEP 4 OUTPUT
void outout_graph(char *str);

#endif  // GRAPH_H