#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

/**
 * Inverse une image "en place"
 */
void invert (IplImage* img)
{
  int x,y;
  uchar *p;
  assert (img->depth == IPL_DEPTH_8U && img->nChannels == 1);

  for (y = 0; y < img->height; ++y)
  {
    for (x = 0; x < img->width; ++x)
    {
      // récupération d'un pointeur sur le pixel de coordonnées (x,y)
      p = cvPtr2D (img, y, x, NULL);
      *p = 255 - *p;
    }
  }
}

/**
 * Ce programme prend deux arguments dont un optionnel:
 * IMAGE:     l'image à inverser
 * SAVE_PATH: (optionnel) l'image dans laquelle sauvegarder le résultat
 */
int main (int argc, char* argv[])
{
  IplImage* img = NULL;
  const char* src_path = NULL;
  const char* dst_path = NULL;
  const char* window_title = "Inverse";

  if (argc < 2)
  {
    fprintf (stderr, "usage: %s IMAGE [SAVE_PATH]\n", argv[0]);
    return EXIT_FAILURE;
  }

  src_path = argv[1];

   // optionnel: sauvegarde du résultat
   // si un second chemin est passé au programme
  if (argc > 2)
    dst_path = argv[2];

  if (!(img = cvLoadImage (src_path, CV_LOAD_IMAGE_GRAYSCALE)))
  {
    fprintf (stderr, "couldn't open image file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  invert (img);

  cvNamedWindow (window_title, CV_WINDOW_AUTOSIZE);
  cvShowImage   (window_title, img);
  cvWaitKey (0);
  cvDestroyAllWindows ();

  if (dst_path && !cvSaveImage (dst_path, img, NULL))
  {
    fprintf (stderr, "couldn't write image to file: %s\n", dst_path);
  }

  cvReleaseImage(&img);
  return EXIT_SUCCESS;
}
