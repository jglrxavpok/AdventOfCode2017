#include <stdio.h>
#include "day1/day1.h"
#include "day2/day2.h"

int main() {
    printf("Which day to do want to see ?\n");
    int dayNumber;
    scanf("%d", &dayNumber);
    getchar(); // removes newline character

    printf("Which part ?\n");
    int part;
    scanf("%d", &part);
    getchar();
    switch(dayNumber) {
        case 1:
            runday1(part);
            break;
        case 2:
            runday2(part);
            break;
        default:
            printf("Unknown or unavailable day!\n");
            break;
    }
    return 0;
}
