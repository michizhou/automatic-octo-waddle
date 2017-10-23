#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string p;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("One argument only. Try again.\n");
        return 1;
    }
    else 
    {
        p = GetString();
    }
    
    int K = atoi(argv[1]);
    
    char newl;
    for (int i = 0, n = strlen(p); i < n; i++)
        if (islower(p[i]))
        {
            newl = p[i] - 97;
            printf("%c", (newl + K) % 26 + 97);
        }
        else if (isupper(p[i]))
        {
            newl = p[i] - 65;
            printf("%c", (newl + K) % 26 + 65);
        }
        else
        {
            printf("%c", p[i]);
        }
        
        printf ("\n");
        
        return 0;
}
