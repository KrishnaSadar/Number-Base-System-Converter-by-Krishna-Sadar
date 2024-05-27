#include <stdio.h>
#include <stdlib.h>
#include "NBSC.h"
#include <stdbool.h>

int main() {
    int n1, n2, n3;    // n1 for input option, n2 for output base, n3 for input base
    char num[65];
    char num2[65];
    char fractionalResult[65];
    long long temp;
    header();

    while (1) {
        Menu();
        scanf("%d", &n1);
        printf("|======================================================================|\n\n");

        switch (n1) {
            case 1:
                n3 = 10;
                break;
            case 2:
                n3 = 2;
                break;
            case 3:
                n3 = 8;
                break;
            case 4:
                n3 = 16;
                break;
            case 5:
                printf("Enter the base of the Number: ");
                scanf("%d", &n3);
                if (n3 > 36) {
                    printf("Base greater than 36 is not allowed as there will be no alphabet to represent the higher digits (press enter)\n");
                    printf("======================================================================\n");

                    continue;
                }
                break;
            default:
                printf("Invalid option. Please try again.\n");
                continue;
        }

        printf("Enter the Number: ");
        scanf("%s", num);

        if (!ValidFractional(num, n3)) {
            printf("Invalid Number for the base %d. Please try again. (press enter)\n", n3);
            printf("======================================================================\n");

            continue;
        }

        printf("Enter the base to convert to: ");
        scanf("%d", &n2);
        if (n2 > 36) {
            printf("Base greater than 36 is not allowed as there will be no alphabet to represent the higher digits (press enter)\n");
            printf("======================================================================\n");

            continue;
        }
        if (strchr(num, '.') != NULL){
             convertFractionalPart(num, n3, n2, fractionalResult);
                     temp = cTodF(num, n3);
                     printf("%lld\n",temp);
        cFromd(temp, n2, num2);
                    strcat(num2, ".");
            strcat(num2, fractionalResult);
        }else{
                temp = cTod(num, n3);
                 printf("%lld\n",temp);
        cFromd(temp, n2, num2);
        }

        printResult(n2, num2);

        printf("Do you want to convert another Number? (y/n): ");
        char c;
        scanf(" %c", &c);
        printf("======================================================================\n");
        if (c == 'n' || c == 'N') {
            break;
        }
    }

    return 0;
}
