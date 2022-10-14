#include "HuffNode.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <string>

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
    std::cout << temp->get_probability() << " ";
    initNodes.erase(initNodes.begin());
    initNodes.erase(initNodes.begin());
    std::cout << temp->get_probability() << "\n";
    // place the temp node back into the vector
    std::vector<HuffNode *> temp_vector = place_sorted(initNodes, temp);
    initNodes = temp_vector;
    for (int i = 0; i < initNodes.size(); i++)
    {
      std::cout << initNodes[i]->get_probability() << " ";
    }
    std::cout << "\n";
  }
  return combine_nodes(initNodes[0], initNodes[1]);
}

void encode(std::vector<std::pair<char, std::string>> &codes, HuffNode *head, std::string code = "")
{
  if (head->get_symbol() == '\0')
  {
    if (head->get_right() != nullptr)
    {
      code += "1";
      encode(codes, head->get_right(), code);
    }
    if (head->get_left() != nullptr)
    {
      code += "0";
      encode(codes, head->get_left(), code);
    }
    if (head->get_right() == nullptr && head->get_left() == nullptr)
    {
      return;
    }
  }
  else
  {
    codes.push_back(std::make_pair(head->get_symbol(), code));
  }
}

void print2DUtil(HuffNode *root, int space)
{
  // Base case
  if (root == NULL)
    return;

  // Increase distance between levels
  space += 10;

  // Process right child first
  print2DUtil(root->get_right(), space);

  // Print current node after space
  // count
  std::cout << std::endl;
  for (int i = 10; i < space; i++)
    std::cout << " ";
  char c;
  if (root->get_symbol() == '\0')
  {
    c = '0';
  }
  else
  {
    c = root->get_symbol();
  }
  std::cout << c << "\n";

  // Process left child
  print2DUtil(root->get_left(), space);
}

// Wrapper over print2DUtil()
void print2D(HuffNode *root)
{
  // Pass initial space count as 0
  print2DUtil(root, 0);
}

int main()
{
  HuffNode *a = new HuffNode(0.35f, nullptr, nullptr, 'a');
  HuffNode *b = new HuffNode(0.10f, nullptr, nullptr, 'b');
  HuffNode *c = new HuffNode(0.19f, nullptr, nullptr, 'c');
  HuffNode *d = new HuffNode(0.25f, nullptr, nullptr, 'd');
  HuffNode *e = new HuffNode(0.06f, nullptr, nullptr, 'e');
  HuffNode *f = new HuffNode(0.05f, nullptr, nullptr, 'f');
  std::vector<HuffNode *> vec;

  vec = place_sorted(vec, a);
  vec = place_sorted(vec, b);
  vec = place_sorted(vec, c);
  vec = place_sorted(vec, d);
  vec = place_sorted(vec, e);
  vec = place_sorted(vec, f);
  HuffNode *tree = make_tree(vec);
  print2D(tree);
  std::vector<std::pair<char, std::string>> codes;
  encode(codes, tree);
  for (int i = 0; i < codes.size(); i++)
  {
    std::cout << codes[i].first << " " << codes[i].second << "\n";
  }
  return 0;
}