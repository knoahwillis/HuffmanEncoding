#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "HuffNode.hpp"

// FUNCTION TO PLACE A NODE SORTED INTO THE VECTOR
std::vector<HuffNode *> place_sorted(std::vector<HuffNode *> initNodes, HuffNode *newNode);

// FUCNTION TO TAKE A VECTOR OF NODES AND CONVERT IT INTO A TREE
HuffNode *make_tree(std::vector<HuffNode *> &initNodes);

// FUNCTION TO TAKE A TREE AND CONVERT ALL LEAFS INTO <SYMBOL, CODE> PAIRS
void create_codes(std::vector<std::pair<char, std::string>> &codes, HuffNode *head, std::string code = "");

