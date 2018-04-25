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
      ~Image();   
      
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
      /*
       friend iterator begin(void){
         return data.get();
       }
            /*
            iterator end(){
               return data[height*width+1];
            } 
            */
       
      
      friend int** operator+(Image &l1, Image &l2);//add
      friend int** operator-(Image &l1, Image &l2);//sub
      friend int** operator!(Image &l1);//invert
      friend int** operator/(Image &l1, Image &l2);//mask
      friend int** operator*(Image &l1, int threshold);//thresh
   
};

namespace MHMSHA056 {

   
   int** add(Image &l1, Image &l2);
   int** subtract(Image &l1, Image &l2);
   int** invert(Image &l1);
   int** mask (Image &l1, Image &l2);
   int** threshold (Image &l1, int threshold);
   
   void createImage(string outputImage, int** finalImageData, int Nrows, int Ncols);

};