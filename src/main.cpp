#include "HuffNode.hpp"
#include "Functions.hpp"

int main() {
  std::vector<HuffNode *> vec;
  int total = 0;
  float sum = 0;
  std::unordered_map<char, int> probs = get_probabilities("original.txt", total);
  for(auto i : probs) {
    vec = place_sorted(vec, (new HuffNode((static_cast<float>(i.second) / total), nullptr, nullptr, i.first)));
    sum += (static_cast<float>(i.second) / total);
  }
  HuffNode *tree = make_tree(vec);
  std::unordered_map<char, std::string> codes;
  create_codes(codes, tree);
  std::unordered_map<std::string, char> decode = reverse_map(codes);
  text_to_codes("original.txt", "outputEncoded.txt", codes);
  codes_to_text("outputEncoded.txt", "outputDecoded.txt", decode);
  return 0;
}