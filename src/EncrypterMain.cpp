#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

#include "Encrypter.h"

bool file_exists(char *name) {
  std::ifstream f(name);
  return f.good() and !(f.peek() == std::ifstream::traits_type::eof());
}

bool errorHandler(int argc, char *argv[], std::string &outFile,
                  std::string &treeFile) {
  if (argc > 4) {
    std::cout << "More than 3 files passed" << std::endl;
    return 1;
  }

  if (argc == 1) {
    std::cout << "No file passed!" << std::endl;
    return 1;
  }

  else if (not file_exists(argv[1])) {
    std::cout << "Input file doesn't exists or is empty" << std::endl;
    return 1;
  }

  else {
    std::cout << "Input file: " << argv[1] << std::endl;
  }

  if (argc == 2) {
    std::cout << "Output file not specified" << std::endl;
  }

  else {
    outFile = argv[2];
  }

  std::cout << "Writing output to " << outFile << std::endl;

  if (argc <= 3) {
    std::cout << "Tree file not specified" << std::endl;
  }

  else {
    treeFile = argv[3];
  }

  std::cout << "Writing tree to " << treeFile << std::endl;

  return 0;
}

int main(int argc, char *argv[]) {
  std::string outFile = "output.bin", treeFile = "treeFile.txt";

  if (errorHandler(argc, argv, outFile, treeFile)) {
    return 0;
  }

  Encrypter *enc = new Encrypter(argv[1], treeFile);

  enc->buildFreqSet();
  enc->buildEncryptTree();

  enc->buildMap();

  enc->getEncryption(outFile);

  enc->serializeEncryptTree();

  delete enc;

  return 0;
}