#include <math.h>
#include <stdio.h>

#include "graph.h"

void outout_graph(char *str) {
    double step_x = (4 * PI) / 84.0;
    double step_y = 2.0 / 24.0;

    double func_value;

    for (double y_value_level = -1; y_value_level <= 1.02; y_value_level += step_y) {
        for (double x = 0; x <= 4 * PI; x += step_x) {
            func_value = value_in_point(str, x);
            if (fabs(func_value - y_value_level) < step_y / 2.0) {
                printf("*");
            } else
                printf(".");
        }
        printf("\n");
    }
}
