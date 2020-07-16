
//17.5 Using ftell and rewind functions; p 438

#include <stdlib.h>
#include <stdio.h>

#define BUFLEN 6

char msg[] = "abcdefghijklmnopqrstuvwxyz";

int main(void)
{
    FILE *fp;
    char buf[BUFLEN];

    if((fp = fopen("kamfileposition17_5.txt", "w")) == NULL)
    {
        fprintf(stderr, "Error opening file...");
        exit(1);
    }

    if (fputs(msg,fp) == EOF)
    {
        fprintf(stderr, "Error writing to file...");
        exit(1);
    }

    fclose(fp);

    //now open the file for reading
    if((fp = fopen("kamfileposition17_5.txt", "r")) == NULL)
    {
        fprintf(stderr, "Error opening file...");
        exit(1);
    }
    printf("\nImmediately after opening, position =%ld",ftell(fp));

    //read in 5 characters
    fgets(buf, BUFLEN, fp);
    printf("\nAfter reading in %s, position = %ld",buf,ftell(fp));

    //read in next 5 characters
    fgets(buf, BUFLEN, fp);
    printf("\nThe next 5 characters are %s, and position is now = %ld",buf,ftell(fp));

    //rewind the stream
    rewind(fp);

    printf("\nAfter rewinding, the position is back at %ld",ftell(fp));

    //read in 5 characters
    fgets(buf, BUFLEN, fp);
    printf("\n...and reading starts at the beginning again %s\n\n",buf);

    fclose(fp);
    return 0;

}
