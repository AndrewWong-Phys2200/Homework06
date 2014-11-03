/*
 * Caesar cipher
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 128

int main(int argc, char *argv[])
{
    char buf[N+1], c;
    int key, i;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s key text\n", argv[0]);
        exit(1);
    }

    key = atoi(argv[1]);
    if ((key <= 0) || (key > 26))
    {
        fprintf(stderr, "%s: the key must be an integer, 1 <= key <= 26\n", argv[0]);
        exit(1);
    }

    if (strlen(argv[2]) > N)
    {
        fprintf(stderr, "%s: text is too long, only the first %d bytes will be encrypted\n", argv[0], N);
    }
    strncpy(buf, argv[2], N);

    for (i = 0; i < strlen(buf); i++)
    {
        c = buf[i];
        if (islower(c))
        {
            c = 'a' + (c - 'a' + key)%26;
        }
        else if (isupper(c))
        {
            c = 'A' + (c - 'A' + key)%26;
        }
        printf("%c", c);
    }
    printf("\n");

    return 0;
}
