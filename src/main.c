#include <stdio.h>
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
#include "day6/day6.h"

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
        case 3:
            runday3(part);
            break;
        case 4:
            runday4(part);
            break;
        case 5:
            runday5(part);
            break;
        case 6:
            runday6(part);
            break;
        default:
            printf("Unknown or unavailable day!\n");
            break;
    }
    return 0;
}
