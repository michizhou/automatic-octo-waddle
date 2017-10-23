#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("One argument only. Try again.\n");
        return 1;
    }
    string k = argv[1];
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Make sure argument is letter only.\n");
            return 1;
        }
    }
    string p = GetString();
    
    int m = strlen(k);
    char newl;
    
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    { 
        if (islower(p[i]))
        {
            if (islower(k[j % m]))
            {    
                newl = p[i] - 97;
                printf("%c", (newl + (k[j++ % m] - 97)) % 26 + 97);
            }
            else 
            {
                newl = p[i] - 97;
                printf("%c", (newl + (k[j++ % m] - 65)) % 26 + 97);
            } 
        }
        else if (isupper(p[i]))
        {
            if (isupper(k[j % m]))
            {
                newl = p[i] - 65;
                printf("%c", (newl + (k[j++ % m] - 65)) % 26 + 65);
            }
            else 
            {
                newl = p[i] - 65;
                printf("%c", (newl + (k[j++ % m] - 97)) % 26 + 65);
            }
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf ("\n");
        
    return 0;
}
