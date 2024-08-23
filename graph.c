//---------------------------------------------------------//
//           Reverse Polish notation (RPN)                 //
//               Compiller: make all                       //
//                 Run: ./build/graph                     //
//  Make comands: make clean; make format; make cppcheck   //
//---------------------------------------------------------//

#include "graph.h"

#include <stdio.h>

int main() {
    char str[MAX_LEN];
    fgets(str, sizeof(str), stdin);
    replace_math_function(str);

    if (check_valid_str(str)) {
        polka(str);
        outout_graph(str);
    } else
        printf("n/a");

    return 0;
}
