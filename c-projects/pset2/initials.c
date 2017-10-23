#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string p = GetString();
    printf("%c", toupper(p[0]));
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (p[i] == ' ')
        {
            i++;
            printf("%c", toupper(p[i]));
        }
    }
    printf("\n");
}
