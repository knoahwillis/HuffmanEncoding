#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
#include <fstream>
#include "HuffNode.hpp"

// FUNCTION TO PLACE A NODE SORTED INTO THE VECTOR
std::vector<HuffNode *> place_sorted(std::vector<HuffNode *> initNodes, HuffNode *newNode);

// FUCNTION TO TAKE A VECTOR OF NODES AND CONVERT IT INTO A TREE
HuffNode *make_tree(std::vector<HuffNode *> &initNodes);

// FUNCTION TO TAKE A TREE AND CONVERT ALL LEAFS INTO AN UNORDERED MAP CONTAINING <SYMBOL, CODE> PAIRS
void create_codes(std::unordered_map<char, std::string> &codes, HuffNode *head, std::string code = "");

// FUNCTION WHICH, WHEN GIVEN AN INPUT TEXT, GIVES AN UNORDERED MAP OF <CHAR, PROBABILITY> PAIRS
std::unordered_map<char, int> get_probabilities(std::string filename, int &total);

// FUNCTION WHICH, WHEN GIVEN AN INPUT AND OUTPUT FILE AND A MAP OF <CHAR, CODE> PAIRS, ENCODES THE
// INPUT FILE AND WRITES IT TO THE OUTPUT FILE
void text_to_codes(std::string ifile, std::string ofile, std::unordered_map<char, std::string> codes);

// REVERSE OF THE PREVIOUS FUNCTION
void codes_to_text(std::string ifile, std::string ofile, std::unordered_map<std::string, char> codes);

// FUNCTION WHICH TAKES AN UNORDERED MAP OF <SYMBOL, CODE> PAIRS, AND RETURNS A NEW UNORDERED MAP
// OF <CODE, SYMBOL> PAIRS
std::unordered_map<std::string, char> reverse_map(std::unordered_map<char, std::string> map);
