/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    FILE* cd = fopen("card.raw", "r");
    
    if (cd == NULL)
    {
        fclose(cd);
        fprintf(stderr, "Can't open the cardfile.\n");
        return 1;
    }
    
    int jpcount = 0;
    int op = 0;
    FILE* output;
    
    uint8_t buffer[512];
    uint8_t check[4];
    fread(buffer, 512, 1, cd);
    
    while (fread(buffer, 512, 1, cd) > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            check[i] = buffer[i];
        }
        if (((check[3] == 0xe1) || (check[3] == 0xe0)) && (check[0] == 0xff) && (check[1] == 0xd8) && (check[2] == 0xff))
        {
            char jpg[3]; 
            sprintf(jpg, "%03d.jpg", jpcount); 
            
            if (op == 0)
            {
                output = fopen(jpg, "w");
                fwrite(buffer, sizeof(buffer), 1, output);
                op = 1;
            }          
            if (op == 1)
            {
                fclose(output);
                output = fopen(jpg, "w");
                fwrite(buffer, sizeof(buffer), 1, output);
                jpcount++;
            }
        }   
        else
        {
            if (op == 1)
            {
                fwrite(buffer, sizeof(buffer), 1, output);
            }
        } 
    }
    

    fclose(output);
    fclose(cd);
    return 0; 
}
