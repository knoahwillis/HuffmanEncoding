#include "HuffNode.hpp"

HuffNode::HuffNode(float prob, HuffNode *leftChild, HuffNode *rightChild, char s)
{
  p = prob;
  lChild = leftChild;
  rChild = rightChild;
  symbol = s;
  child_symbols = "";
  child_symbols.push_back(s);
}

float HuffNode::get_probability()
{
  return p;
}

char HuffNode::get_symbol()
{
  return symbol;
}

HuffNode *HuffNode::get_left()
{
  return lChild;
}

HuffNode *HuffNode::get_right()
{
  return rChild;
}

HuffNode *combine_nodes(HuffNode *leftChild, HuffNode *rightChild)
{
  float prob = leftChild->get_probability() + rightChild->get_probability();
  HuffNode *ret = new HuffNode(prob, leftChild, rightChild);
  ret->child_symbols = leftChild->child_symbols + rightChild->child_symbols;
  return ret;
}
