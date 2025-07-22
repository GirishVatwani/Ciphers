#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.c>

// Make sure program was run with just one command-line argument
// Make sure every character in argv[1] is a digit
// Convert argv[1] from a `string` to an `int`
// Prompt user for plaintext
// For each character in the plaintext:
// Rotate the character if it's a letter

bool only_digit(string arr[]);
void encipher(string text, int k);
int main(int argc, string argv[])
{
    int key;
    string plaintext;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // when input is not valid
        if (only_digit(argv) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            key = atoi(argv[1]);
            plaintext = get_string("plaintext: ");
            encipher(plaintext, key);
        }
    }
}

bool only_digit(string arr[])
{
    int len = strlen(arr[1]);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(arr[1][i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void encipher(string text, int k)
{
    int margin;
    printf("ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if isalpha (text[i])
        {
            if isupper (text[i])
            {
                margin = (text[i] - 65 + k) % 26;
                printf("%c", margin + 65);
            }
            else
            {
                margin = (text[i] - 97 + k) % 26;
                printf("%c", margin + 97);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
