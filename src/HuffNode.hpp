#pragma once
#include <string>
 
class HuffNode {
protected:
  float p;
  HuffNode* lChild;
  HuffNode* rChild;
  char symbol;
  
public:
  std::string child_symbols;
  HuffNode(float prob, HuffNode* leftChild, HuffNode* rightChild, char s = '\0');

public:
  float get_probability();
  char get_symbol();
  HuffNode* get_right();
  HuffNode* get_left();
};

HuffNode* combine_nodes(HuffNode* leftChild, HuffNode* rightChild);