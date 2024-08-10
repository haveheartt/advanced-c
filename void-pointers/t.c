#include <stdint.h>
#include <stdio.h>

void *my_memset(void *data, uint8_t c, size_t n) {
    uint8_t *data_as_bytes = (uint8_t*)data;
    for (size_t i = 0; i < n; i++)
        data_as_bytes[i] = c;
    return data;
}

void map(void *xs, size_t n, size_t size, void (*f)(void*)) {
    uint8_t *xs_as_bytes = (uint8_t*)xs;
    for (size_t i = 0; i < n; i++)
        f(&xs_as_bytes[i * size]);
}

void square(void *x) {
    int *p = x;
    *p = *p * *p;
}

int main(void) {
    int xs[5] = {1, 2, 3, 4, 5};  
    for (int i = 0; i < 5; i++)
        printf("%d\n", xs[i]);
    printf("\n");
    map(xs, 5, sizeof(int), square);
    //my_memset(xs, 2, sizeof xs);
    for (int i = 0; i < 5; i++)
        printf("%d\n", xs[i]);
    printf("\n");

    return 0;
}
