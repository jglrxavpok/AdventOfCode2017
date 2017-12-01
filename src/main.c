#include <stdio.h>
#include "day1/day1.h"
#include "ioutils.h"

int main() {
    printf("Which day to do want to see ?\n");
    int dayNumber;
    fflush(stdin);
    scanf("%d", &dayNumber);
    getchar(); // removes newline character
    char *input = NULL;
    switch(dayNumber) {
        case 1:
            printf("Your input?\n");
            size_t inputSize;
            getline(&input, &inputSize, stdin);
            int result = solveday1(input);
            printf("The answer is %d\n", result);
            break;
        default:
            printf("Unknown or unavailable day!\n");
            break;
    }
    return 0;
}
