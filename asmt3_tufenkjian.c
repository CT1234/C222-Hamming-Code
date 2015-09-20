// ============================================================================
// Name: ASHOD CHRIS TUFENKJIAN
// Project#3: HAMMING CODE CHECKER
// Due: October 23rd, 2014
// COMP 222
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int length;
int even_odd = -1;
char *str;

void max_length()   //SUB OPTION 1
{
    printf("Enter the maximum length:");
    scanf("%d", &length);
    str = (char *)malloc(sizeof(char) * (length+1));
    return;
}

void parity_input() //SUB OPTION 1
{
    while (1)
    {
        printf("Enter the parity (0 = even, 1 = odd) :");
        scanf("%d" , &even_odd);
        printf("\n");
        if (even_odd == 0 || even_odd == 1)
            break;
    }
    return;
}

void option1()      //Enter parameters
{
    max_length();
    parity_input();
    return;
};

void string_array() //SUB OPTION 2
{
    int i;
    for(i = 0; i < length; i++)
        str[i] = -1;

    printf("Enter the hamming code:");
    scanf("%s", str);
    return;
}

int actual_length()
{
    int act_length = 0;
    int i;
    for (i = 0; i < length; i++)
    {
        if ( str[i] == '0' || str[i] == '1' )
        {
            act_length = act_length + 1;
        }
    }
    return act_length;
}

int parity_checker()
{
    int incorrect_bit = 0;
    int act_length;
    act_length = actual_length();
    int parity;
    parity = 0;

    while(1)
    {
        if (parity == 0)
            parity = 1;
        else parity *= 2;

        if (parity > act_length)
            break;
        else
        {
            int k;
            k = act_length-parity;
            int position;
            position = 0;
            int sum;
            sum = 0;
                while (k >= 0)
                {
                    if(position < parity)
                    {
                        int convert_char;
                        convert_char = str[k] - '0';
                        sum = sum + convert_char;
                        position += 1;
                        k--;
                    }
                    else
                    {
                        int l;
                        for(l = 0; l < parity; l++)
                        {
                            position-= 1;
                            k--;
                        }
                    }
                }
            if (sum%2 != even_odd)
            {
                incorrect_bit = incorrect_bit + parity;
            }
            sum = 0;
        }
    }
    return incorrect_bit;
}

void fix_hamming_code(int i)
{
    int corrected_bit;
    corrected_bit = actual_length() - i;

    if (str[corrected_bit] == '0')
        str[corrected_bit] = '1';
    else
        str[corrected_bit] = '0';
    return;
}

void print_corrected_hamming_code()
{
    int i;
    printf("The corrected hamming code is: ");
    for (i=0; i< actual_length(); i++)
        printf("%c",str[i]);
    printf("\n\n");
    return;
};

void option2()      //Check Hamming Code
{
    string_array();
    int error = parity_checker();
    if (error == 0)
        printf("There is no bit error.\n\n");
    else
    {
    printf("There is an error in bit: %d\n", error);
    fix_hamming_code(parity_checker());
    print_corrected_hamming_code();
    }
    return;
}

void option3()   //Quit
{
    free(str);
    exit(0);
    return;
};

void option_menu()
{
    while (1)
    {
    int selection;
        printf("Hamming Code Checker:\n");
        printf("-----------------------\n");
        printf("1) Enter Parameters\n");
        printf("2) Check Hamming Code\n");
        printf("3) Quit\n");
        printf("\nEnter Selection:");
        scanf("%d", &selection);
        printf("\n");

        if (selection == 1)
        {
            option1();
            return;
        }
        else if (selection == 2)
        {
            option2();
            return;
        }
        else if (selection == 3)
        {
            option3();
            return;
        }
    }
}

int main()
{
    while (1)
    option_menu();
    return 0;
}
