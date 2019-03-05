
#include <stdio.h>
#include "MyroC.h"
#include <math.h>

Picture create_black_image (int height, int width);
void create_test_image (Picture * pic);
void pixelStrip (Picture * pic, char color);
void pictureRedder (Picture * pic);
void pictureGreener (Picture * pic);
void pictureBluer (Picture * pic);
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius);
void zebra (Picture * pic);



int main()
{
  Picture pic1 = create_black_image(200,300);
  create_test_image(&pic1);

  //rDisplayPicture (&pic1, 3.0, "Striped Image");


  pictureRedder (&pic1);

  //rDisplayPicture (&pic1, 3.0, "Reddered Image");

  pictureGreener (&pic1);

  //rDisplayPicture (&pic1, 3.0, "Greenered Image");

  //pictureBluer (&pic1);
  
  rDisplayPicture (&pic1, 3.0, "Bluered Image");

  //zebra (&pic1);
  
  //rDisplayPicture (&pic1, 3.0, "Zebra Image");

  int xCenter = pic1.width/2;
  int yCenter = pic1.height/2;

  circleSelect (&pic1, xCenter, yCenter, 25);

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


void pixelStrip(Picture * pic, char color)
{

}

/*Grayscale values for an image are ( (0.3*R) (0.59*G) (0.11*B)*/
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius)
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

void pictureRedder (Picture * pic)
{
  printf("This is the REDDER function\n");
  int row, col;

  for (row = 0; row < (*pic).height; row++)
    {
      for (col = 0; col < (*pic).width; col++)
        {
          if (((((*pic).pix_array[row][col]).R) > 0) && ((((*pic).pix_array[row][col]).R) <= 90))
            {
              Pixel redder = { ((((*pic).pix_array[row][col]).R) += 80), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if (((((*pic).pix_array[row][col]).R) > 90) && ((((*pic).pix_array[row][col]).R) <= 190))
            {
              Pixel redder = { ((((*pic).pix_array[row][col]).R) += 50), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if (((((*pic).pix_array[row][col]).R) > 190) && ((((*pic).pix_array[row][col]).R) < 240))
            {
              Pixel redder = { ((((*pic).pix_array[row][col]).R) += 10), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if (((((*pic).pix_array[row][col]).R) >= 240) && ((((*pic).pix_array[row][col]).R) < 252))
            {
              Pixel redder = { ((((*pic).pix_array[row][col]).R) += 2), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder;
            }
          else if ((((*pic).pix_array[row][col]).R) == 254)
            {
              Pixel redder = { ((((*pic).pix_array[row][col]).R) += 1), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = redder; 
            }
          else if ((((*pic).pix_array[row][col]).R) == 255)
            {
              Pixel noChange = { ((((*pic).pix_array[row][col]).R)), ((*pic).pix_array[row][col]).G, ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = noChange; 
            }

         }
     }
}

void pictureGreener (Picture * pic)
{
  printf("This is the GREENER function\n");
  int row, col;

  for (row = 0; row < (*pic).height; row++)
    {
      for (col = 0; col < (*pic).width; col++)
        {
          if (((((*pic).pix_array[row][col]).G) > 0) && ((((*pic).pix_array[row][col]).G) <= 90))
            {
              Pixel greener = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G += 80), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = greener;
            }
          else if (((((*pic).pix_array[row][col]).G) > 90) && ((((*pic).pix_array[row][col]).G) <= 190))
            {
              Pixel greener = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G += 50), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = greener;
            }
          else if (((((*pic).pix_array[row][col]).G) > 190) && ((((*pic).pix_array[row][col]).G) < 240))
            {
              Pixel greener = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G += 10), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = greener;
            }
          else if (((((*pic).pix_array[row][col]).G) >= 240) && ((((*pic).pix_array[row][col]).G) < 252))
            {
              Pixel greener = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G += 2), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = greener;
            }
          else if ((((*pic).pix_array[row][col]).G) == 254)
            {
              Pixel greener = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G += 1), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = greener;
            }
          else if ((((*pic).pix_array[row][col]).G) == 255)
            {
              Pixel noChange = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G), ((*pic).pix_array[row][col]).B};
              (*pic).pix_array[row][col] = noChange;
            }
         }
     }
}
void pictureBluer (Picture * pic)
{
  printf("This is the BLUER function\n");
  int row, col;

  for (row = 0; row < (*pic).height; row++)
    {
      for (col = 0; col < (*pic).width; col++)
        {
          if (((((*pic).pix_array[row][col]).B) > 0) && ((((*pic).pix_array[row][col]).B) <= 90))
            {
              Pixel bluer = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G), (((*pic).pix_array[row][col]).B += 80)};
              (*pic).pix_array[row][col] = bluer;
            }
          else if (((((*pic).pix_array[row][col]).B) > 90) && ((((*pic).pix_array[row][col]).B) <= 190))
            {
              Pixel bluer = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G), (((*pic).pix_array[row][col]).B += 50)};
              (*pic).pix_array[row][col] = bluer;
            }
          else if (((((*pic).pix_array[row][col]).B) > 190) && ((((*pic).pix_array[row][col]).B) < 240))
            {
              Pixel bluer = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G), (((*pic).pix_array[row][col]).B += 10)};
              (*pic).pix_array[row][col] = bluer;
            }
          else if (((((*pic).pix_array[row][col]).B) >= 240) && ((((*pic).pix_array[row][col]).B) <= 252))
            {
              Pixel bluer = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G), (((*pic).pix_array[row][col]).B += 2)};
              (*pic).pix_array[row][col] = bluer;
            }
          else if ((((*pic).pix_array[row][col]).B) == 254)
            {
              Pixel bluer = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G), (((*pic).pix_array[row][col]).B += 1)};
              (*pic).pix_array[row][col] = bluer;
            }
          else if ((((*pic).pix_array[row][col]).B) == 255)
            {
              Pixel noChange = { (((*pic).pix_array[row][col]).R), (((*pic).pix_array[row][col]).G), (((*pic).pix_array[row][col]).B)};
              (*pic).pix_array[row][col] = noChange;
            }

         }
     }
}

void zebra (Picture * pic){ //Makes a picture of zebra stripes
    printf("This is the Zebra Stripe function\n");
    int row, col;
    
    for (row = 0; row < (*pic).height; row++)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            ((*pic).pix_array[row][col]).R = 255;

            ((*pic).pix_array[row][col]).G = 255;

            ((*pic).pix_array[row][col]).B = 255;
        }
    }
    
    for (row = 0; row < (*pic).height; row += 4)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            ((*pic).pix_array[row][col]).R = 0;

            ((*pic).pix_array[row + 1][col + 1]).R = 0;
            
            ((*pic).pix_array[row][col]).G = 0;

            ((*pic).pix_array[row + 1][col + 1]).G = 0;
            
            ((*pic).pix_array[row][col]).B = 0;

            ((*pic).pix_array[row + 1][col + 1]).B = 0;
        }
    }
}

