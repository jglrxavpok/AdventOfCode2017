#include <stdio.h>
#include "day1/day1.h"

int main() {
    printf("Which day to do want to see ?\n");
    int dayNumber;
    fflush(stdin);
    scanf("%d", &dayNumber);
    getchar(); // removes newline character
    switch(dayNumber) {
        case 1:
            runday1();
            break;
        default:
            printf("Unknown or unavailable day!\n");
            break;
    }
    return 0;
}
