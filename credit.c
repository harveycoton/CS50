#include <cs50.h>
#include <stdio.h>
#include <string.h>

struct card_type
{
    const char *prefix;
    const char *type;
};

const struct card_type lookup[] =
{
    {"34", "AMEX"},
    {"37", "AMEX"},
    {"51", "MASTERCARD"},
    {"52", "MASTERCARD"},
    {"53", "MASTERCARD"},
    {"54", "MASTERCARD"},
    {"55", "MASTERCARD"},
    {"4", "VISA"}
};

int main(void)
{
    //long n = get_long("4003600000000014");
    long n = get_long("ENTER CARD NUMBER: ");
    char str[15]; //Creates an array of chars 16 digits (0-15) long
    int sum = 0;
    bool alt = false;
    sprintf(str, "%ld", n);
    if (strlen(str) > 16 || strlen(str) < 13)
    {
        printf ("INVALID\n");
    }
    else
    {
        for (int i = strlen(str) - 1; i >= 0; i -= 1) //Initialise variable with --2 to give us second to last digit (16-2=14)
        {
            int digit = str[i] - '0';
            if (alt == false)
            {
                sum += digit;
                alt = true;
            }
            else
            {
                sum += digit * 2 / 10 + digit * 2 % 10;
                alt = false;
            }
        }
        if (sum % 10 == 0)
        {
            int j = sizeof(lookup) / sizeof(lookup[0]);
            bool found = false;
            for (int i = 0; i < j; i++)
            {
                if (strncmp(str, lookup[i].prefix, strlen(lookup[i].prefix)) == 0)
                {
                    printf("%s\n",lookup[i].type);
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
