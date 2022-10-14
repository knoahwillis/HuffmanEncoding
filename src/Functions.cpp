#include "Functions.hpp"

std::vector<HuffNode *> place_sorted(std::vector<HuffNode *> initNodes, HuffNode *newNode)
{
  std::vector<HuffNode *> ret;
  bool added = false;
  if (initNodes.size() == 0)
  {
    ret.push_back(newNode);
  }
  else
  {
    for (auto x : initNodes)
    {
      if (x->get_probability() < newNode->get_probability())
      {
        ret.push_back(x);
      }
      else if (!added)
      {
        ret.push_back(newNode);
        ret.push_back(x);
        added = true;
      }
      else
      {
        ret.push_back(x);
      }
    }
    if (!added)
    {
      ret.push_back(newNode);
      added = true;
    }
  }

  return ret;
}

HuffNode *make_tree(std::vector<HuffNode *> &initNodes)
{
  while (initNodes.size() > 1)
  {
    // create a temp node with the first two nodes in the vector
    HuffNode *temp = combine_nodes(initNodes[0], initNodes[1]);
    // erase the first two nodes in the vector
    initNodes.erase(initNodes.begin());
    initNodes.erase(initNodes.begin());
    // place the temp node back into the vector
    std::vector<HuffNode *> temp_vector = place_sorted(initNodes, temp);
    initNodes = temp_vector;
  }
  return initNodes[0];
}

void create_codes(std::vector<std::pair<char, std::string>> &codes, HuffNode *head, std::string code)
{
  if (head->get_symbol() == '\0')
  {
    if (head->get_right() != nullptr)
    {
      code += "1";
      create_codes(codes, head->get_right(), code);
      code.pop_back();
    }
    if (head->get_left() != nullptr)
    {
      code += "0";
      create_codes(codes, head->get_left(), code);
      code.pop_back();
    }
  }
  else
  {
    codes.push_back(std::make_pair(head->get_symbol(), code));
  }
}