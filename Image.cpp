//Image.cpp

#include "Image.h"
#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

//Define image methods

Image::Image(string imageName){
   //Creating image
   cout << "Creating image " << imageName << "\n";
   int Nrows;
   int Ncols;
   
   //Read in image
   ifstream inFile(imageName, ios::binary);
   
   inFile.seekg(0, inFile.end);
   int length = inFile.tellg();
   inFile.seekg(0, ios::beg);
   cout << "Lenght of file: " << length << "\n\n";
   stringstream ss;
   string line = "";
   
   //First line is PX
   getline(inFile, line);
   cout << "Version: " << line << "\n";
   //Second line(s) are comments
   bool flag = false;
   while (!flag){
      getline(inFile, line);
      if (line.at(0) != '#'){
         flag = true;
         //3rd line is image dimensions
         istringstream is(line);
         is >> Nrows >> Ncols;
         height = Nrows;
         width = Ncols;
         Image::getImageDimensions();
         break;
      }
      cout << "Comment: " << line << "\n";
   }
   
   //4th line is 255
   getline(inFile, line);
   //line >> Nrows >> Ncols;
   cout << "Max intensity value: " << line << "\n";
   
   //5th line onwards is the block of data
   //ss << inFile.rdbuf(); //need to restore something here...
   
   //Array of pixels
   unsigned char pixel;
   
   unsigned char** imageData = new unsigned char*[Nrows];
   for (int i = 0; i < Nrows; i++){
      imageData[i] = new unsigned char[Ncols];
   }
   
   //Fill unsigned char array 
   
   for (int i = 0; i < Nrows; i++){
      for (int j = 0; j < Ncols; j++){
         inFile.read((char*) &imageData[i][j], 1);
      }
   }
   
   //Print out
   /*
   for (int i = 0; i < 500; i++){
      for (int j = 0; j < 220; j++){
         if (imageData[i][j] == 255){
            cout << "1"; //white
         } else if (imageData[i][j] == 0){
            cout << "0"; //black
         }
      }
      cout << "\n";
   }
   */
   //Assign char array to image unique pointer
   imagePixels = imageData;
   
   //unique_ptr<unsigned char**> ptr(&imageData);
   data = make_unique<unsigned char**>(imageData);
   inFile.close();
   cout << "\n\n";
   
   
}

//Get image dimensions
void Image::getImageDimensions(){
   cout << "Height: " << height << "\n";
   cout << "Width: " << width << "\n";
}
int Image::getHeight(){
   return height;
}
int Image::getWidth(){
   return width;
}

//Print a given image block
void Image::printBlock(){
   
   for (int i = 0; i < 200; i++){
      for (int j = 0; j < 300; j++){
         if (imagePixels[i][j] == 255){
            cout << "1"; //white
         } else if (imagePixels[i][j] == 0){
            cout << "0"; //black
         } else {
            cout << "X";
         }
      }
      cout << "\n";
   }
   
   
}

unsigned char** Image::getImagePixels(){
   return imagePixels;
}

//Define operational methods

//operational add overload
/*
unsigned char** MHMSHA056::operator+(Image &l1, Image &l2){
   unsigned char** sum = MHMSHA056::add(l1, l2);
   return sum;
   //return MHMSHA056::add(l1, l2);
}
*/

int** MHMSHA056::add(Image &l1, Image &l2){
   cout << "Adding images method\n";
   /*
   for (int i = 0; i < 200; i++){
      for (int j = 0; j < 220; j++){
         cout << (int) l2.getImagePixels()[i][j];
         
         if (l2.getImagePixels()[i][j] == 255){
            cout << "1"; //white
         } else if (l2.getImagePixels()[i][j] == 0){
            cout << "0"; //black
         } else if (l2.getImagePixels()[i][j] < 255 && l2.getImagePixels()[i][j] > 0){
            cout << "G";
         }
         
      }
      cout << "\n";
   }
   */
   
   int** sumPixels = new int*[l1.getHeight()];
   for (int i = 0; i < l1.getHeight(); i++){
      sumPixels[i] = new int[l1.getWidth()];
   }
   for (int i = 0; i < l1.getHeight(); ++i){
      for (int j = 0; j < l1.getWidth(); ++j){
         sumPixels[i][j] = (int)l1.getImagePixels()[i][j] + (int)l2.getImagePixels()[i][j];//think error here
         //cout << (unsigned char)sumPixels[i][j];
         
         if (sumPixels[i][j] > 255){
            sumPixels[i][j] = 255;
         }
         if (sumPixels[i][j] < 0){
            sumPixels[i][j] = 0;
         }
      }
   }
   
   return sumPixels;
   
}

int** MHMSHA056::subtract(Image &l1, Image &l2){
   cout << "Subtracting images method\n";
   
   int** subPixels = new int*[l1.getHeight()];
   for (int i = 0; i < l1.getHeight(); i++){
      subPixels[i] = new int[l1.getWidth()];
   }
   for (int i = 0; i < l1.getHeight(); ++i){
      for (int j = 0; j < l1.getWidth(); ++j){
         subPixels[i][j] = (int)l1.getImagePixels()[i][j] - (int)l2.getImagePixels()[i][j];
         
         if (subPixels[i][j] > 255){
            subPixels[i][j] = 255;
         }
         if (subPixels[i][j] < 0){
            subPixels[i][j] = 0;
         }
      }
   }
   
   return subPixels;
   
}

int** MHMSHA056::invert(Image &l1){
   cout << "Inverting image method\n";
   
   int** invPixels = new int*[l1.getHeight()];
   for (int i = 0; i < l1.getHeight(); i++){
      invPixels[i] = new int[l1.getWidth()];
   }
   for (int i = 0; i < l1.getHeight(); ++i){
      for (int j = 0; j < l1.getWidth(); ++j){
         invPixels[i][j] = 255 - (int)l1.getImagePixels()[i][j];
         
         if (invPixels[i][j] > 255){
            invPixels[i][j] = 255;
         }
         if (invPixels[i][j] < 0){
            invPixels[i][j] = 0;
         }
      }
   }
   
   return invPixels;
   
}

void MHMSHA056::mask (Image l1, Image l2){
   cout << "Masking image\n";
}

void MHMSHA056::threshold (Image l1, int threshold){
   cout << "Thresholding image\n";
}

void MHMSHA056::createImage(string outputImage, int** finalImageData, int Nrows, int Ncols){
   cout << "Creating image method\n";
   
   /*
   for (int i = 200; i < 400; i++){
      for (int j = 0; j < 220; j++){
         if (finalImageData[i][j] == 255){
            cout << "1"; //white
         } else if (finalImageData[i][j] == 0){
            cout << "0"; //black
         } else {
            cout << "X";
         }
      }
      cout << "\n";
   }
   */
   //ofstream outFile(outputImage);
   //outFile.close();
        
   //write header information first
   
   ofstream pFile (outputImage, ios::binary);
   
   pFile << "P5\n";
   pFile << "#This is a result image\n";
   pFile << Nrows << " " << Ncols << "\n";
   pFile << "255\n";
   for (int i = 0; i < Nrows; i++){
      for (int j = 0; j < Ncols; j++){
         pFile.write((char*)& finalImageData[i][j], 1);
      }
   }
   pFile.close();
   
}