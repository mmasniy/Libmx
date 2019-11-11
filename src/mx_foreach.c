#include "libmx.h"

void mx_foreach(const int *arr, int size, void (*f)(int)) {
    if (f && arr && size > 0)
        for (int i = 0; i < size; i++)
            f(arr[i]);
}
