#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Dean Gibson"
#define YEAR 2022

char * Dec2RadixI(decInt, Radix)
{
    if (decInt==0)
    {
      printf("0\n");
    }

    int n;

    n = (log(decInt)/log(Radix))+1;               //find how large the array must be to store the radix-i number

    int revArray[n];                              //creating array of size n to store the remainder in 'reverse order'

    for(int k = 0 ; k < n ; k++)                  //loop through number using modulo to find the remainder which equals the radix input
        {

        int remainder = decInt%Radix;             //initializing remainder varibale which is equal to the modulus of x and y (decimal number and radix)

        if (remainder >= 10)
        {

            remainder = remainder - 10;

            if (remainder == 0)
                remainder = 'A';

            else if (remainder == 1)
                remainder = 'B';

            else if (remainder == 2)
                remainder = 'C';

            else if (remainder == 3)
                remainder = 'D';

            else if (remainder == 4)
                remainder= 'E';

            else if (remainder== 5)
                remainder= 'F';
        }

        else
        {
           remainder= remainder + '0';
        }

        revArray[k] = remainder;                            // storing the remainder in array

        decInt = decInt/Radix;

        }

        for (int i = n-1 ; i>=0 ; i--)                      // reversing the array to put the sequemce in the right order
        {
            printf("%c",revArray[i]);                       // printing array
        }
        printf("\n");

}


int main()
{
    printf("****************************\n");                                                //Printing the title, author and year created, using defined variables
    printf("%s\nWritten by: %s\nDate: %d\n",TITLE,AUTHOR,YEAR);
    printf("****************************\n");

    int decInt = 0;

    while (decInt >= 0)                                                                      //while loop to repeatedly ask for user input

    {
        printf("Enter a decimal number: ");
        scanf("%d",&decInt);
        printf("The number you have entered is %d\n",decInt);

        if (decInt<0)                                                                       // if statement to break the while loop if a negative number is input
        {
            printf("EXIT");
            break ;
        }

        int Radix;
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d",&Radix);
        printf("The radix you have entered is %d\n",Radix);

        if (Radix<0)                                                                       // if statement to break the while loop if a negative number is input
        {
            printf("EXIT");
            break ;
        }

        float logofbase;

        logofbase = log2(decInt);
        printf("The log2 of the number is %.2f\n",logofbase);                              // finding the log of base 2 of the decimal number

        int result;

        result = (decInt/Radix);
        printf("The integer result of the number divided by %d is %d\n",Radix,result);

        int remainder;

        remainder = decInt%Radix;
        printf("The remainder is %d\n", remainder);                                       // printing the remainder of the decimal and radix input


        printf("The radix-%d value is ", Radix);
        Dec2RadixI(decInt, Radix);                                                        // calling the Dec2RadixI function to print the radix i sequence

    }


}

