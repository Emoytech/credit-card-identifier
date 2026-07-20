#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checksum(long number);
void identifycard(bool num, int fstno, int len);
int firstnos(long num);
int getlen(long num);
void print_border(char character, int length);

int main(void)
{
    char input = 'y';
    while (input == 'y')
    {
        print_border('#', 25);
        printf("Credit card Identifier\n");
        print_border('#', 25);
        long card = 0;
        do
        {
            printf("Enter your card number: ");
            scanf("%ld", &card);
        }
        while (card < 0);

        bool check = checksum(card);
        int first2no = firstnos(card);
        int length = getlen(card);

        if (check == false || length == 0)
        {
            printf("INVALID\n");
        }
        else
        {
            identifycard(check, first2no, length);
        }

        printf("Check another card? (y/n): ");
        scanf(" %c", &input);
    }
    return 0;
}

int getlen(long num)
{
    int len = 0;
    if (num == 0)
        return 1;
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    if (len < 13 || len > 19)
    {
        return 0;
    }
    return len;
}

int firstnos(long num)
{
    while (num >= 100)
    {
        num /= 10;
    }
    return num;
}

bool checksum(long number)
{
    long rest = number / 10;
    int pos = 0;
    int add = (number % 10);
    int lastno = 0;
    while (rest != 0)
    {
        pos += 1;
        lastno = rest % 10;
        rest = rest / 10;
        if (pos % 2 != 0)
        {
            if ((lastno * 2) > 9)
            {
                add += (lastno * 2) % 10;
                add += (lastno * 2) / 10;
            }
            else
            {
                add += (lastno * 2);
            }
        }
        else
        {
            add += lastno;
        }
    }
    if (add % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void identifycard(bool num, int fstno, int len)
{
    if (num == true)
    {
        if ((fstno == 34 || fstno == 37) && len == 15)
        {
            printf("AMEX\n");
        }
        else if (((fstno < 56 && fstno > 50) || fstno == 22) && len == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((fstno > 39 && fstno < 50) && (len == 13 || len == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("Maybe a valid card but not from a known list.\n");
        }
    }
}
void print_border(char character, int length) {
    for (int i = 0; i < length; i++) {
        putchar(character);
    }
    putchar('\n'); // Moves to the next line when done
}