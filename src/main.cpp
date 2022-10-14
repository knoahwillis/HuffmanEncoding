#include "HuffNode.hpp"
#include "Functions.hpp"
int main()
{
  HuffNode *a = new HuffNode(0.35f, nullptr, nullptr, 'a');
  HuffNode *b = new HuffNode(0.10f, nullptr, nullptr, 'b');
  HuffNode *c = new HuffNode(0.19f, nullptr, nullptr, 'c');
  HuffNode *d = new HuffNode(0.25f, nullptr, nullptr, 'd');
  HuffNode *e = new HuffNode(0.06f, nullptr, nullptr, '1');
  HuffNode *f = new HuffNode(0.05f, nullptr, nullptr, '2');
  std::vector<HuffNode *> vec;

  vec = place_sorted(vec, a);
  vec = place_sorted(vec, b);
  vec = place_sorted(vec, c);
  vec = place_sorted(vec, d);
  vec = place_sorted(vec, e);
  vec = place_sorted(vec, f);
  HuffNode *tree = make_tree(vec);
  std::vector<std::pair<char, std::string>> codes;
  create_codes(codes, tree);
  for (int i = 0; i < codes.size(); i++)
  {
    std::cout << codes[i].first << " " << codes[i].second << "\n";
  }
  return 0;
}