#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)     // Convert all pixels to grayscale.
    {
        for (int j = 0; j < width; j++)
        {   // Grayscale: New values of RGB for each pixel should be same + brightness should be same as orignal pixel's
            int new_image= round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtGreen = image[i][j].rgbtRed = image[i][j].rgbtBlue = new_image; //Assigning value of new_image to all
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int new_image_red=0;
    int new_image_green=0;
    int new_image_blue=0;
    for (int i = 0; i < height; i++)     // Convert all pixels to sepia/redish-brown.
    {
        for (int j = 0; j < width; j++)
        {   // Sepia: New values of RGB for each pixel should be calculated by the algorithem + cap down these values between integer values of 0-255
            new_image_red = round(((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue)));
            new_image_green = round(((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue)));
            new_image_blue = round(((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue)));

// Note: All if-else staements can be replaced with this format:
    //image[i][j].rgbtBlue = (new_image_blue > 255) ? 255 : new_image_blue;
         //image[i][j].rgbtGreen = (new_image_green > 255) ? 255 : new_image_green;
             // image[i][j].rgbtRed = (new_image_red > 255) ? 255 : new_image_red;
// For Red

        if (new_image_red>255)
        {
            image[i][j].rgbtRed=255;
        }
        else
        {
            image[i][j].rgbtRed= new_image_red; //without else's brackets, the code wasn't running that well.
        }
// For Green
        if (new_image_green>255)
        {
            image[i][j].rgbtGreen=255;
        }
        else
        {
            image[i][j].rgbtGreen= new_image_green;
        }
// For Blue
        if (new_image_blue>255)
        {
            image[i][j].rgbtBlue=255;
        }
        else
        {
        image[i][j].rgbtBlue= new_image_blue;
        }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)     // Convert all pixels to grayscale.
    {
// For even number of pixels
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {   // Reflect: Swap RGB values of left side to right and right side to left
                RGBTRIPLE swap_var[height][width];
                swap_var[i][j]= image[i][j];        //assign values of original pixels up till j
                image[i][j] = image[i][width - (j + 1)]; //reflect left side
                image[i][width - (j + 1)] = swap_var[i][j]; //reflect right side
            }
        }
 else
// For odd number of pixel
        if (width % 2 != 0) // see if you need it
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                RGBTRIPLE swap_var[height][width];
                swap_var[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = swap_var[i][j];
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blured_temp;
    for (int i = 0; i < height; i++)     // Convert all pixels to grayscale.
    {
        for (int j = 0; j < width; j++)
        {   // Blur: Average RGB values of 8 pixels surrounding concerned pixel + itlsef:
                 //except for pixels lying on boundaries of image (3 + 1)
            for (int row = -1; row < 2; row++) // for row = -1, 0, +1
            {
                for (int column = -1; column < 2)
                {
                    if (i + row < 0 || i + row > height - 1)

                    j < column || j < column + 1; // WHATS WRONG

                    {
                          int blur_red = round(image[i][j].rgbtRed)
                          int blur_green = round(image[i][j].rgbtGreen)
                          int blur_blue = round(image[i][j].rgbtBlue)

                    }
                }
            }



        }
    }
    return;
}
