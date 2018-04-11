//Image.cpp

#include "Image.h"
#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

//Define image methods

Image::Image(string imageName){
   //Creating image
   cout << "Creating image " << imageName << "\n";
   int Nrows;
   int Ncols;
   
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
         //cout << "Image Dimensions " << Nrows << "x" << Ncols << "\n";
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
   
   //cout << "hello";
   //Array of pixels
   unsigned char pixel;
   
   unsigned char** imageData = new unsigned char*[Nrows];
   for (int i = 0; i < Nrows; i++){
      imageData[i] = new unsigned char[Ncols];
   }
   
   //Fill unsigned char array 
   
   for (int i = 0; i < Nrows; i++){
      for (int j = 0; j < Ncols; j++){
         //ss >> imageData[i][j];
         inFile.read((char*) &imageData[i][j], 1);
         //Values are not visible on console
      }
   }
   
   //Print out
   /*
   for (int i = 0; i < Nrows; i++){
      for (int j = 0; j < Ncols; j++){
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

unsigned char** MHMSHA056::add(Image &l1, Image &l2){
   cout << "Adding images method\n";
   
   unsigned char** sumPixels = new unsigned char*[l1.getHeight()];
   for (int i = 0; i < l1.getHeight(); i++){
      sumPixels[i] = new unsigned char[l1.getWidth()];
   }
   
   for (int i = 0; i < l1.getHeight(); i++){
      for (int j = 0; j < l1.getWidth(); j++){
         sumPixels[i][j] = l1.getImagePixels()[i][j] + l2.getImagePixels()[i][j];
         if (sumPixels[i][j] > 255){
            sumPixels[i][j] = 255;
         }
      }
   }
   
   
   return sumPixels;
   
   
}

void MHMSHA056::subtract(Image l1, Image l2){
   cout << "Subtracting images\n";
}

void MHMSHA056::invert(Image l1){
   cout << "Inverting image\n";
}

void MHMSHA056::mask (Image l1, Image l2){
   cout << "Masking image\n";
}

void MHMSHA056::threshold (Image l1, int threshold){
   cout << "Thresholding image\n";
}

void MHMSHA056::createImage(string outputImage, unsigned char** finalImageData, int Nrows, int Ncols){
   cout << "Creating image method\n";
   
   ofstream outFile(outputImage);
   outFile.close();
        
   //write header information first
   
   ofstream pFile (outputImage, ios::binary);
   for (int i = 0; i < Nrows; i++){
      for (int j = 0; j < Ncols; j++){
         pFile.write((char*)& finalImageData[i][j], 1);
      }
   }
   
   
}