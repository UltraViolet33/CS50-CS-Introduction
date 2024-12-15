#include "helpers.h"
#include <stdio.h>
#include <math.h>

#define RED 0
#define GREEN 1
#define BLUE 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i;
    int j;

    double average = 0;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int i;
    int j;

    double newRed;
    double newGreen;
    double newBlue;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            newRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            newGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            newBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = newRed;

            if (newRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }

            image[i][j].rgbtGreen = newGreen;

            if (newGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }

            image[i][j].rgbtBlue = newBlue;

            if (newBlue > 255)
            {
                image[i][j].rgbtBlue = newBlue;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i;

    double limit = round(width / 2);

    for (i = 0; i < height; i++)
    {
        int j;
        for (j = 0; j < limit; j++)
        {
            RGBTRIPLE swap = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = swap;
        }
    }

    return;
}

int getBlurValue(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float count = 0;
    int sum = 0;

    for (int row = i - 1; row <= (i + 1); row++)
    {
        for (int column = j - 1; column <= (j + 1); column++)
        {
            if (row < 0 || row >= height || column < 0 || column >= width)
            {
                continue;
            }

            if (color_position == RED)
            {
                sum += image[row][column].rgbtRed;
            }
            else if (color_position == GREEN)
            {
                sum += image[row][column].rgbtGreen;
            }
            else
            {
                sum += image[row][column].rgbtBlue;
            }

            count++;
        }
    }

    return round(sum / count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlurValue(i, j, height, width, copy, RED);
            image[i][j].rgbtGreen = getBlurValue(i, j, height, width, copy, GREEN);
            image[i][j].rgbtBlue = getBlurValue(i, j, height, width, copy, BLUE);
        }
    }

    return;
}