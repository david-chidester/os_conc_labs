#include <stdio.h>
#include "MyroC.h"

Picture create_black_image (int height, int width);
void create_test_image (Picture * pic);
void pixelStrip (Picture * pic, char color);
void pictureRedder (Picture * pic);
void pictureGreener (Picture * pic);
void pictureBluer (Picture * pic);
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius);
void zebra (Picture * pic);
void strip (Picture * pic, char color);



int main()
{
  Picture pic1 = create_black_image(200,300);
  create_test_image(&pic1);

  rDisplayPicture (&pic1, 3.0, "Striped Image");
    
  strip (&pic1, 'B');
    
  rDisplayPicture (&pic1, 3.0, "blue removed from image"); //removes all blue from an image

  pictureRedder (&pic1);

  rDisplayPicture (&pic1, 3.0, "Reddered Image"); //enhances red in image

  pictureGreener (&pic1);

  rDisplayPicture (&pic1, 3.0, "Greenered Image"); //enhances green in image
    
  zebra (&pic1);
  
  rDisplayPicture (&pic1, 3.0, "Zebra image"); //makes all pure black and pure white parts of the image zebra striped
}

Picture create_black_image (int height, int width)
{
  Picture myPic ={height, width};

  Pixel whitePix = {0, 0, 0};
  
  int row, col;

  for (row = 0; row < height; row++)
    {
      for (col = 0; col < width; col++)
        {
          myPic.pix_array [row][col] = whitePix;
        }
    }

  return myPic;
}

void create_test_image(Picture * pic)
{  
  /* Define an array of pixel colors */
  Pixel colorPalette [ 6] = {
                               {100, 0, 0},
                               {0, 0, 100},
                               {0, 100, 0},
                             } ;

  int row, col;

  for (row = 25; row < (*pic).height - 25; row++)
    for (col = 75; col < (*pic).width - 75; col++)
      {
        /* stripes will be 10 pixels wide,
	   and will repeat every 6 colors */
	int colorIndex = ((row + col) / 10) % 6;

	(*pic).pix_array[row][col] = colorPalette [colorIndex];

      }
}

/*Grayscale values for an image are ( (0.3*R) (0.59*G) (0.11*B)*/
void pixelStrip(Picture * pic, char color)
{

}

void pictureRedder (Picture * pic)
{
  printf("This is the REDDER function\n");
  int row, col;

  for (row = 0; row < (*pic).height; row++)
    {
      for (col = 0; col < (*pic).width; col++)
        {
          if (((((*pic).pix_array[row][col]).R) > 0) && ((((*pic).pix_array[row][col]).R) <= 130))
            {
              Pixel redder = { ((((*pic).pix_array[row][col]).R) += 100), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if (((((*pic).pix_array[row][col]).R) >= 130) && ((((*pic).pix_array[row][col]).R) <= 254))
            {
              Pixel redder = { ((((*pic).pix_array[row][col]).R) += 50), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if ((((*pic).pix_array[row][col]).R) >= 255)
            {
              
            }
         }
     }
}

void pictureGreener (Picture * pic)
{
  printf("This is the REDDER function\n");
  int row, col;

  for (row = 0; row < (*pic).height; row++)
    {
      for (col = 0; col < (*pic).width; col++)
        {
          if (((((*pic).pix_array[row][col]).R) > 0) && ((((*pic).pix_array[row][col]).R) <= 130))
            {
              Pixel redder = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G += 100), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if (((((*pic).pix_array[row][col]).R) >= 130) && ((((*pic).pix_array[row][col]).R) <= 254))
            {
              Pixel redder = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G += 50), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if ((((*pic).pix_array[row][col]).R) >= 255)
            {
              
            }
         }
     }
}
void pictureBluer (Picture * pic)
{

}

void zebra (Picture * pic){ //Makes a picture of zebra stripes on black parts of image
    printf("This is the Zebra Stripe function\n");
    int row, col;
    
    for (row = 0; row < (*pic).height; row++)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            if (((*pic).pix_array[row][col]).R == 0 && ((*pic).pix_array[row][col]).G == 0 && ((*pic).pix_array[row][col]).B == 0){
                ((*pic).pix_array[row][col]).R = 255;
                ((*pic).pix_array[row][col]).G = 255;
                ((*pic).pix_array[row][col]).B = 255;
            }
        }
    }
    
    for (row = 0; row < (*pic).height; row += 4)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            if (((*pic).pix_array[row][col]).R == 255 && ((*pic).pix_array[row][col]).G == 255 && ((*pic).pix_array[row][col]).B == 255){
                ((*pic).pix_array[row][col]).R = 0;
                ((*pic).pix_array[row + 1][col + 1]).R = 0;
                
                ((*pic).pix_array[row][col]).G = 0;
                ((*pic).pix_array[row + 1][col + 1]).G = 0;
                
                ((*pic).pix_array[row][col]).B = 0;
                ((*pic).pix_array[row + 1][col + 1]).B = 0;
            }
        }
    }
}

void strip (Picture * pic, char color){
    printf("This function strips an image of the specified color\n");
    int row, col;
    
    for (row = 0; row < (*pic).height; row++)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            if (color == 'R' || color == 'r'){ //Removes all red from the image
                ((*pic).pix_array[row][col]).R = 0;
            }
            
            else if (color == 'G' || color == 'g'){ //Removes all green from the image
                ((*pic).pix_array[row][col]).G = 0;
            }
            
            else if (color == 'B' || color == 'b'){ //Removes all blue from the image
                ((*pic).pix_array[row][col]).B = 0;
            }
            
            else {
                printf("Error: must select red green or blue to strip from image");
            }
        }
    }
}
