#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fptr;
    char fileName[25];
    int number = 1000, i;
    for(;number<=10000;){
        sprintf(fileName, "%d_random_numbers.txt", number);
        fptr = fopen(fileName, "w");

        if (fptr == NULL)
        {
            printf("ERROR");
            exit(1);
        }

        for(i=0; i<number; i++)
        {
            int val = rand() % number;
            fprintf(fptr, "%d ", val);
        }
        printf("File with %d numbers generated successfully\n", number);
        number+=1000;
    }
    fclose(fptr);
    return 0;
}
