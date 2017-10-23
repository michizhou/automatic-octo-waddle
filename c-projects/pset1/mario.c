#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    
    do
    {
        printf("Enter a height: ");    
        n = GetInt();
        if ((n < 0) || (n > 23))
        {
            printf("Try again! Number has to be from 1 to 23.");
            printf("\n");
        }  
        else if (n == 0)
        {   
            return 0;
        } 
    }
    while ((n < 1) || (n > 23));

        for(int r = 0; r <= n - 1; r++)
        {
            for(int s = n - r - 1;s > 0 ;s--) 
            {
                printf(" ");
            }
            for(int h = 0;h <= r + 1;h++)  
            {   
                printf("#"); 
            } 
            printf("\n");
        }  

        return 0;
}
