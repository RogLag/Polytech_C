# include <stdio.h>

# include "list-test.h"

int main() {
    test_create();
    test_insert();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_erase();
    test_splice();
    test_sort();
    return 0;
}