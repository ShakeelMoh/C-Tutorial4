//Image.h
#include <memory>

using namespace std;


class Image {

   private:
      int width;
      int height;
      unsigned char** imagePixels;
      unique_ptr<unsigned char**> data;
      
   public:
      
      Image(string imageName); //takes in image name and sets attributes
      //~Image();   
      
      void getImageDimensions();
      int getHeight();
      int getWidth();
      void printBlock();
      unsigned char** getImagePixels();
      class iterator {
   
         private:
            unsigned char *ptr;
            iterator(unsigned char *p): ptr(p){} //takes pointer and sets iterator pointer
         public:
            
   
      };
      
      
   
   
};

namespace MHMSHA056 {

   unsigned char** add(Image &l1, Image &l2);
   void subtract(Image l1, Image l2);
   void invert(Image l1);
   void mask (Image l1, Image l2);
   void threshold (Image l1, int threshold);
   
   void createImage(string outputImage, unsigned char** finalImageData, int Nrows, int Ncols);

};