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
         inFile.read((char*) &imageData[i][j], 8);
         //Values are not visible on console
      }
   }
   
   //Assign char array to image unique pointer
   //unique_ptr<unsigned char*> data = imageData[0][0];
   inFile.close();
   cout << "\n\n";
   
   
}

void Image::getImageDimensions(){
   cout << "Height: " << height << "\n";
   cout << "Width: " << width << "\n";
}

//Define operational methods

void MHMSHA056::add(Image l1, Image l2){
   cout << "Adding images method\n";
   
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