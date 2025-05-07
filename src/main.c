#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DEFAULT_VALUE 100
#define DEFAULT_FILENAME "file"
#define OUTPUT_DIR "output/"

int main(int argc, char *argv[])
{
    clock_t startTime = clock();
    int number = DEFAULT_VALUE;
    const char *filename = DEFAULT_FILENAME;
    char fullPath[256];

    if(argc > 1)
    {
        number = atoi(argv[1]);
    }
    if(argc > 2)
    {
        filename = argv[2];
    }

    snprintf(fullPath, sizeof(fullPath), "%s%s", OUTPUT_DIR, filename);

    if(number <= 0)
    {
        fprintf(stderr, "Invalid number: %d\n", number);
        return 1;
    }

    FILE *file = fopen(fullPath, "w");
    if(file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }
    for(int i = 0; i < number; i++)
    {
        fprintf(file, "memmove(&buffer->text[(int)buffer->cursorPos.x - 1], &buffer->text[(int)buffer->cursorPos.x], buffer->length - buffer->cursorPos.x + 1);\n");
    }

    clock_t endTime = clock();
    double executionTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Execution time: %f\n", executionTime);

    fclose(file);
    return 0;
}