#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int flag = 1;
    int swap = 0;
    char *temp;

    while(flag) {
        flag = 0;
        for (int i = 0; i < size - 1; i++) {
            if (mx_strcmp(arr[i], arr[i + 1]) > 0) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
                swap++;
            }
        }
    }
    return swap;
}
