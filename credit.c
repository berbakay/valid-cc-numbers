#include <stdio.h>
#include <cs50.h>

int main() 
{
    long ccNumber = get_long("Number:");
    int count  = 0;
    long numberLength = ccNumber;
    long first2Numbers = ccNumber;
        while(first2Numbers > 100) {
            first2Numbers /= 10;
        }

    do {
        count++;
        numberLength /= 10;
    } while(numberLength != 0);

    int checkSum = 0;
    int numberCount = 0;

    do {
        if(numberCount % 2 == 0) {
            numberCount++;
            checkSum += ccNumber % 10;
            ccNumber /= 10;
        } else {
            numberCount++;
            int numberToCheck = (ccNumber % 10)* 2;
            if(numberToCheck < 10) {
                checkSum += numberToCheck;
            } else {
                while(numberToCheck >= 1) {
                    checkSum += numberToCheck % 10;
                    numberToCheck /= 10;
                }
            }
            ccNumber /= 10;
        }
    } while (ccNumber > 0);

    
    if(checkSum % 10 == 0) {
    if(count == 15) {
        if(first2Numbers == 34 || first2Numbers == 37) {
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    } else if (count == 16) {
        if(first2Numbers == 51 ||first2Numbers == 52 || first2Numbers == 53 || first2Numbers == 54 || first2Numbers == 55) {
            printf("MASTERCARD\n");
        } else {
            first2Numbers /= 10;
            if(first2Numbers == 4) {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        }
    } else if (count == 13) {
        first2Numbers /= 10;
        if(first2Numbers == 4) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }} else {
        printf("INVALID\n");
    }
}