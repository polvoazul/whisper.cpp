#include <string>
#include <vector>
#include "./json.hpp"



struct Token {
  std::string token;
  float prob;
};

void to_json(nlohmann::json& j, const Token& p) {
    j = nlohmann::json{{"p", (int) (p.prob * 100)}, {"t", p.token}};
}

struct TextAndTokens {
  std::string _text;
  std::vector<Token> _tokens;
  void add(const char * token, float prob) {_text += token; _tokens.push_back({token, prob});}
  void clear() {_text.clear(); _tokens.clear();}
  bool empty() {return _text.empty();}
  const char* c_str() {return _text.c_str();}
};

void print_tokens_as_json(const TextAndTokens& text, const std::string_view start, const std::string_view end) {
    nlohmann::json j {
      {"full_text", text._text},
      {"start", start },
      {"end", end },
      {"tokens", text._tokens}
    };
    printf("%s\n", j.dump().c_str());
}
