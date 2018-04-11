//Image.h
#include <memory>

using namespace std;


class Image {

   private:
      int width;
      int height;
      unique_ptr<unsigned char[]> data;
      
   public:
      
      Image(string imageName); //takes in image name and sets attributes
      //~Image();   
      
      void getImageDimensions();
      
      class iterator {
   
         private:
            unsigned char *ptr;
         
   
      };
   
   
};

namespace MHMSHA056 {

   void add(Image l1, Image l2);
   void subtract(Image l1, Image l2);
   void invert(Image l1);
   void mask (Image l1, Image l2);
   void threshold (Image l1, int threshold);

};