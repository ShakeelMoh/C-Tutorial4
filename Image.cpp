//Image.cpp

#include "Image.h"
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//Define image methods

Image::Image(string imageName){
   //Creating image
   cout << "Creating image " << imageName << "\n";
   
}

//Define operational methods

void MHMSHA056::add(Image l1, Image l2){
   cout << "Adding images\n";
   
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