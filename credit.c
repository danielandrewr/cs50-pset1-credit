#include <cs50.h>
#include <math.h>
#include <stdio.h>

/**
 *
 * Author: Daniel Andrew
 *
 * CS50 Problem Set 1: Credit
 *
 */

int countDigit(long long n);

int main(void) {

    int digitCount = 0;
    long long card = 0;
    printf("Credit Validity Checker\n");

    int i = 0;
    while (i > -1) {
        card = get_long_long("Insert your card number: ");
        int card_length = countDigit(card);
        if ((card_length != 13) && (card_length != 15) && (card_length != 16)) {
            printf("Invalid card number!\n");
            i++;
        }
        i = -1;
    }

    long long digit = card;
    //Counts the digits of the card number
    while (digit > 0) {
        digit = digit / 10;
        digitCount++;
    }

    int number[digitCount];

    for (i = 0; i < digitCount; i++) {
        number[i] = card % 10;
        card = card / 10;
    }

    //Gets the initial
    int initialNumber[digitCount];
    for (int j = 1; j < digitCount; j++) {
        initialNumber[j] = number[j];
    }

    //Multiplies selected digit by 2
    for (int k = 1; k < digitCount; k+=2) {
        number[k] = number[k] * 2;
    }

    int sum = 0;
    int value = 0;

    if (digitCount == 13) {
        for (i = 0; i < digitCount; i++) {
            sum = (number[i] % 10) + (number[i]/10 % 10);
            value = value + sum;
        }

        if ((initialNumber[12] == 4) && (value % 10 == 0)) {
            printf("VALID AS VISA CARD\n");
        } else {
            printf("THIS CARD NUMBER IS INVALID!\n");
        }
    }

    if (digitCount == 15) {
        for (i = 0; i < digitCount; i++) {
            sum = (number[i] % 10) + (number[i]/10 % 10);
            value = value + sum;
        }

        if ((initialNumber[14] == 4) && (value % 10 == 0)) {
            printf("VALID AS AMEX\n");
        } else {
            printf("THIS CARD NUMBER IS INVALID!\n");
        }
    }

    if (digitCount == 16) {
        for (i = 0; i < digitCount; i++) {
            sum = (number[i] % 10) + (number[i]/10 % 10);
            value = value + sum;
        }

        if ((initialNumber[15] == 4) && (value % 10 == 0)) {
            printf("VALID AS VISA\n");
        } else if ((initialNumber[15] == 5) && (value % 10 == 0)) {
            printf("VALID AS MASTERCARD\n");
        } else {
            printf("THIS CARD NUMBER IS INVALID!\n");
        }
    }

    return 0;
}

int countDigit(long long n) {
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}