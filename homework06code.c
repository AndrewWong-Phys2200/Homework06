/* 
    Caesar Cipher Decoding
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void caesar (int key, char message[])
{
    char c;
    int i;

    for (i = 0; i < strlen(message); i++)
    {
        c = message[i];
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
}
    
int main(void)
{    
    char message[] = "Libi imycibqwvm ycwbkcvycm ntcmvbma ycivbqbibma"
                     " qvdwtdmvbm, ntcfqwvma qvdmvqzm: mb dqkm dmzai";
    int key;
    
    for(key = 1; key < 26; key++)
    {
        caesar(key, message);
    }                   
    return 0;
}
