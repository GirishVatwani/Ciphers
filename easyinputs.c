#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *get_string(const char *prompt)
{
    // Display the prompt to the user
    if (prompt != NULL)
    {
        printf("%s", prompt);
    }

    // Allocate an initial buffer
    size_t size = 64;
    char *buffer = malloc(size);
    if (buffer == NULL)
    {
        return NULL; // Memory allocation failed
    }

    // Read input from the user
    size_t length = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Resize buffer if needed
        if (length + 1 >= size)
        {
            size *= 2;
            char *temp = realloc(buffer, size);
            if (temp == NULL)
            {
                free(buffer);
                return NULL; // Memory reallocation failed
            }
            buffer = temp;
        }

        // Append character to buffer
        buffer[length++] = c;
    }

    // Null-terminate the string
    buffer[length] = '\0';

    // Return the dynamically allocated string
    return buffer;
}
    

int get_int(const char *prompt)
{
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}


int main(){
    // char *input = get_string("Enter some text: ");
    // printf("You entered: %s\n", input);
    // free(input); // Free the allocated memory
    int input = get_int("Enter an integer: ");
    printf("You entered: %d\n", input);

    return 0;
    // printf("Hello, world!\n");
    // return 0;
}


