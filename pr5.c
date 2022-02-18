#include <stdio.h>
#include <conio.h>
 
//Suraj Ramrao Diwate

int main()
{
    long decimal_no, remainder, quotient;
    int octalno[100], i = 1, j;
 
    printf("Enter the decimal number: ");
    scanf("%ld", &decimal_no);
    quotient = decimal_no;
    while (quotient != 0)
    {
        octalno[i++] = quotient % 8;
        quotient = quotient / 8;
    }
    printf("Equivalent octal value of decimal no %d: ", decimal_no);
    for (j = i - 1; j > 0; j--)
        printf("%d", octalno[j]);
    return 0;
}
