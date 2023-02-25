#include "../inc/header.h"

void int_to_char_array(int num, char char_array[]) {
    int i = 0, j = 0;
    char tmp;
    if (num < 0) {
        char_array[j++] = '-';
        num = -num;
    }
    do {
        char_array[i++] = num % 10 + '0';
        num /= 10;
    } while (num != 0);
    char_array[i] = '\0';
    if (char_array[0] == '-') {
        ++j;
        --i;
    }
    while (j < i) {
        tmp = char_array[j];
        char_array[j++] = char_array[i];
        char_array[i--] = tmp;
    }
}
