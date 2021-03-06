/***********************************************************************
 * Name(s)  David Chidester and Christian Sidwell                      *
 * Box(s):           D155                 A211                         *
 * Assignment name  Image Processing                                   *
 * Assignment for 3/5/19                                               *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used: None                                 *
 *                                                                     *
 *   Help obtained                                                     *
 *     Devin Otto                                                      *
 *         Gave advice on writing circle function                      *
 *                                                                     *
 *Signature:                                                           *
 ***********************************************************************/

#include <stdio.h>
#include "MyroC.h"
#include <math.h>

//function prototypes

Picture create_black_image (int height, int width); //creates a black image
void create_test_image (Picture * pic);
void pictureRedder (Picture * pic);
void pictureGreener (Picture * pic);
void pictureBluer (Picture * pic);
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius);
void zebra (Picture * pic);
void strip (Picture * pic, char color);
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius); //creates a grayscale circle



int main()
{
  Picture pic1 = create_black_image(200,300);
  create_test_image(&pic1);

  rDisplayPicture (&pic1, 3.0, "Striped Image"); //creatse RGB striped on a red background
    
  strip (&pic1, 'B');
    
  rDisplayPicture (&pic1, 3.0, "blue removed from image"); //removes all blue from an image

  pictureRedder (&pic1);

  rDisplayPicture (&pic1, 3.0, "Reddered Image"); //enhances red in image

  pictureGreener (&pic1);

  rDisplayPicture (&pic1, 3.0, "Greenered Image"); //enhances green in image
    
  zebra (&pic1);
  
  rDisplayPicture (&pic1, 3.0, "Zebra image"); //makes all pure black and pure white parts of the image zebra striped
    
  int xCenter = pic1.width/2;
  int yCenter = pic1.height/2;
    
  circleSelect (&pic1, xCenter, yCenter, 25); //creatse a greyscaled circle in the center of the image
    
  rDisplayPicture (&pic1, 3.0, "Circle");
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

void pictureRedder (Picture * pic) //increases red value
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

void pictureGreener (Picture * pic) //increases green value
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
void pictureBluer (Picture * pic) //increases blue value
{

}

void zebra (Picture * pic){ //Makes a picture of zebra stripes on black parts of image
    printf("This is the Zebra Stripe function\n");
    int row, col;
    
    for (row = 0; row < (*pic).height; row++) //makes black pixels white
    {
        for (col = 0; col < (*pic).width; col++)
        {
            if (((*pic).pix_array[row][col]).R == 0 && ((*pic).pix_array[row][col]).G == 0 && ((*pic).pix_array[row][col]).B == 0){
                ((*pic).pix_array[row][col]).R = 255; //white pixels are created
                ((*pic).pix_array[row][col]).G = 255;
                ((*pic).pix_array[row][col]).B = 255;
            }
        }
    }
    
    for (row = 0; row < (*pic).height; row += 4) //draws black striped on white pixels
    { //white stripes are two pixels thick as are black
        for (col = 0; col < (*pic).width; col++) //iteration through columns will create horizontal stripes
        {
            if (((*pic).pix_array[row][col]).R == 255 && ((*pic).pix_array[row][col]).G == 255 && ((*pic).pix_array[row][col]).B == 255){
                ((*pic).pix_array[row][col]).R = 0;
                ((*pic).pix_array[row + 1][col + 1]).R = 0; //black pixels are created which are two pixels thick
                
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

/*Grayscale values for an image are ( (0.3*R) (0.59*G) (0.11*B)*/
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius) //Makes a grayscale circle at coordinates with the radius
{
    printf ("This is the circle function\n");
    printf ("This is the height of the pic %d\n", (*pic).height);
    printf ("This is the width of the pic %d\n", (*pic).width);
    int i,j;
    
    for (i = yCenter; i < ((*pic).height); i++)
    {
        for (j = xCenter; j < ((*pic).width); j++)
        {
            if ((pow(j - xCenter, 2)) + (pow(i - yCenter, 2)) <= pow(radius,2))
            {
                (*pic).pix_array[i][j].R = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].G = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].B = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
            }
        }
    }
    for(i = 0; i < yCenter; i++)
    {
        for(j = 0; j < xCenter; j++)
        {
            if((pow((j - xCenter), 2)) + (pow((i - yCenter),2)) <= pow(radius, 2))
            {
                (*pic).pix_array[i][j].R = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].G = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].B = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
            }
        }
    }
    for(i = 0; i < yCenter; i++)
    {
        for (j = xCenter; j < ((*pic).width); j++)
        {
            if ((pow((j - xCenter), 2)) + (pow((i - yCenter),2)) <= pow(radius,2))
            {
                (*pic).pix_array[i][j].R = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].G = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].B = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
            }
        }
    }
    for(i = yCenter; i < ((*pic).height);i++)
    {
        for(j = 0; j < xCenter; j++)
        {
            if ((pow((j - xCenter), 2)) + (pow((i - yCenter), 2)) <=pow(radius, 2))
            {
                (*pic).pix_array[i][j].R = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].G = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
                (*pic).pix_array[i][j].B = ((100 * 0.2126) + (100 * 0.7152) + (100 * 0.0722));
            }
        }
    }
}
