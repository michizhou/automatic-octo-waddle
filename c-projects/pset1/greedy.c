#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float d = 0;
    int c_count = 0;
    int w = 0;
    int Quarter = 25;
    int Dime = 10;
    int Nickel = 5;
    int R_count = 0;
    
    do
    {
        printf("Hey there! How much change is owed? ");
        d = GetFloat();
        if (d < 0 || d == 0)
        {
            printf("Amount has to be positive.");
            printf("\n");
        }
    }
    while (d <= 0);
    
    w = (int)round(d * 100);
    
    int Q_count = 0;
    Q_count = w / Quarter;
    R_count = w % Quarter;
    
    int D_count = 0;
    D_count = R_count / Dime;
    R_count = R_count % Dime;
    
    int N_count = 0;
    N_count = R_count / Nickel;
    R_count = R_count % Nickel;
    
    c_count = Q_count + D_count + N_count + R_count;
    
    printf("%d\n", c_count);
    
    return 0;
}
