#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    int i, flag = 0;

    printf("Enter an identifier: ");
    scanf("%s", str);

    if (!isalpha(str[0]) && str[0] != '_')
    {
        flag = 1;
        printf("Invalid identifier. The first character must be a letter or an underscore.\n");
    }

    for (i = 1; i < strlen(str); i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            flag = 1;
            printf("Invalid identifier. The remaining characters must be letters, digits, or underscores.\n");
            break;
        }
    }

    if (!flag)
    {
        printf("Valid identifier.\n");
    }

    return 0;
}