#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int is_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char filename[8];
    FILE *image;
    int counter = 0;

    BYTE buffer[BLOCK_SIZE];

    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        if (is_jpeg(buffer) == 1)
        {
            if (counter != 0)
            {
                fclose(image);
            }

            sprintf(filename, "%03i.jpg", counter++);
            image = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
        else if (counter > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
    }

    fclose(raw_file);
    fclose(image);
}

int is_jpeg(BYTE buffer[])
{

    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }

    return 0;
}