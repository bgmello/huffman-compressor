#include <fstream>
#include <iostream>
#include <vector>

#include "EncrypterNode.h"

class Decrypter {
  // File where the huffman tree is stored
  // Binary file compressed by the encrypter
  std::ifstream *inputFile;

  // Root of the huffman tree
  EncrypterNode *root;

 public:
  Decrypter(std::string fileName);

  ~Decrypter();

  void deserializeEncryptTree();

  void deserializeEncryptTree(EncrypterNode *&);

  void decode(std::ofstream &);
};
