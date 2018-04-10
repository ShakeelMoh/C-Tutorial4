//Image Driver Class

#include "Image.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;



int main (int argc, char *argv[]) {
   string programName = "";
   string option = "";
   string image1 = "";
   string image2 = "";
   int thresholdVal = 0;
   string outputFile = "";
   
   programName = argv[0];
   option = argv[1];
   image1 = argv[2];
   
   if (argc == 4){//-i invert option
      outputFile = argv[3];
   }
   if (argc == 5 && option !="-t"){ //-a/s/l
      image2 = argv[3];
      outputFile = argv[4];
      
   }
   if (option == "-t"){ //-t
      cout << "-t option";
      stringstream str(argv[3]); //convert to int
      str >> thresholdVal;
      outputFile = argv[4];
   }
   
   //Determine function given option
   
   if (option == "-a"){
      cout << "\nAdding images\n";
      //Create 2 image instances
      Image a1(image1);
      Image a2(image2);
      
      
   } else if (option == "-s") {
      cout << "\nSubtracting images\n";
   } else if (option == "-i") {
      cout << "\nInverting image\n";
   } else if (option == "-l") {
      cout << "\nMasking image\n";
   } else if (option == "-t") {
      cout << "\nThresholding image\n";
   } else {
      cout << "\nInvalid option selected\n";
   }
   
   
   //cout << "Program name: " << programName << "\n";
   //cout << "Option: " << option << "\n";
   //cout << "Images: " << image1 << image2 << "\n";
   //cout << "Threshold: " << thresholdVal << "\n";
   //cout << "Output file: " << outputFile << "\n";
   

   return 0;
   
}