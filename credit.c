#include <stdio.h>
#include <cs50.h>

int main() 
{
    long ccNumber = get_long("Number:"); //get cc number from user;
    int count  = 0; //count for number of digits recieved
    long numberLength = ccNumber; //copy of ccNumber to find number of digits without change ccNumber
    long first2Numbers = ccNumber; //get first two numbers of ccNumber using while loop below
        while(first2Numbers > 100) {
            first2Numbers /= 10;
        }

    do {
        count++;
        numberLength /= 10;
    } while(numberLength != 0); //get number of digits

    int checkSum = 0; //check sum of digits comes to correct amount for valid card
    int numberCount = 0; //need to check where digit is on card

    do {
        if(numberCount % 2 == 0) { //if number count is an even position on card 
            numberCount++; //add 1 to number count
            checkSum += ccNumber % 10; //checkSum plus equals the final digitin ccNumber;
            ccNumber /= 10; //take last number off ccNumber and move onto the next one
        } else { //if number is not even position on card
            numberCount++; //add 1 to number count
            int numberToCheck = (ccNumber % 10)* 2; //multiply final number by 2
            if(numberToCheck < 10) {
                checkSum += numberToCheck; //if numberToCheck is less than 10 then add number to check to checkSum
            } else { //if number to check is greater than 9 then add each digit individually to checkSum
                while(numberToCheck >= 1) {
                    checkSum += numberToCheck % 10;
                    numberToCheck /= 10;
                }
            }
            ccNumber /= 10; //remove last number off ccNumber and move to next one
        }
    } while (ccNumber > 0); //stop when ccNumber == 0

    
    if(checkSum % 10 == 0) { //if checkSum ends in 0 then it may be a valid number
        if(count == 15) { //could be amex if length is 15
            if(first2Numbers == 34 || first2Numbers == 37) { //amex must start with 34 or 37
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
            }
        } else if (count == 16) { //can be mastercard or visa if length is 16
            if(first2Numbers == 51 ||first2Numbers == 52 || first2Numbers == 53 || first2Numbers == 54 || first2Numbers == 55) { //mastercards must start with these numbers
                printf("MASTERCARD\n");
            } else {
                first2Numbers /= 10;
                if(first2Numbers == 4) { //visa must start with 4
                    printf("VISA\n");
                } else {
                    printf("INVALID\n");
                }
            }
        } else if (count == 13) { //could be visa if 13 digits
            first2Numbers /= 10;
            if(first2Numbers == 4) {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else {
            printf("INVALID\n");
    }
}