
#include <vector>
#include "Token.cpp"

class Tokenizer {
 private:
  std::string input;
  size_t pos = 0;

 public:
  std::vector<Token> get_tokens_from_string(std::string input) {
    this->input = input;
    this->pos = 0;

    std::vector<Token> tokens;
    Token token = this->next_token();
    tokens.push_back(token);

    while (token.type != TokenType::eof) {
      token = this->next_token();
      tokens.push_back(token);
    }
    return this->get_tokens_without_comments(tokens);
  };

 private:
  std::vector<Token> get_tokens_without_comments(std::vector<Token> tokens) {
    std::vector<Token> tokens_without_comments;
    for (Token tok : tokens) {
      if (tok.type != TokenType::linecomment &&
          tok.type != TokenType::longcomment)
        tokens_without_comments.push_back(tok);
    }
    return tokens_without_comments;
  }

  bool eof() { return this->pos >= this->input.length(); }
  char ch() { return this->input[this->pos]; }

  char look_ahead() {
    if (!this->eof())
      return this->input[this->pos + 1];
    else
      return '\0';
  }

  void skip_space() {
    while (isspace(this->ch())) {
      this->eat();
    }
  }

  char eat() {
    if (!this->eof()) {
      char ch = this->ch();
      this->pos++;
      return ch;
    } else
      return '\0';
  }

  Token make_token(TokenType type) {
    TokenPosition pos(this->pos, this->pos + 1);
    char ch = this->eat();
    return Token(type, ch, pos);
  }

  Token next_token() {
    this->skip_space();

    char ch = this->ch();
    switch (ch) {
      case '(': {
        return this->make_token(TokenType::lparen);
      }
      case ')': {
        return this->make_token(TokenType::rparen);
      }
      case '{': {
        return this->make_token(TokenType::lsquirly);
      }
      case '}': {
        return this->make_token(TokenType::rsquirly);
      }
      case ',': {
      return this->make_token(TokenType::comma);
      }
      case ';': {
        return this->make_token(TokenType::semicolon);
      }
      case ':': {
        if (this->look_ahead() == ':') {
          size_t start = this->pos;
          this->eat();
          this->eat();
          size_t end = this->pos;
          return Token(TokenType::doublecolon, "::", TokenPosition(start, end));
        }
      }
      case '/': {
        if (this->look_ahead() == '/') {
          this->eat();
          this->eat();
          size_t start = this->pos;
          std::string comment = "";

          while (!(this->ch() == '\n' || this->ch() == '\0')) {
            comment += this->eat();
          }
          size_t end = this->pos;
          this->eat();
          TokenPosition pos(start, end);
          return Token(TokenType::linecomment, comment, pos);
        } else if (this->look_ahead() == '*') {
          this->eat();
          this->eat();
          size_t start = this->pos;
          std::string comment = "";
          while (!(this->ch() == '*' && this->look_ahead() == '/')) {
            comment += this->eat();
            if (this->eof())
              return Token(TokenType::illegal, "/*",
                           TokenPosition(start, start + 2));
          }
          size_t end = this->pos;
          TokenPosition pos(start, end);
          this->eat();
          this->eat();
          return Token(TokenType::longcomment, comment, pos);
        }
      }
      case '\0': {
        TokenPosition pos(this->pos, this->pos + 1);
        this->eat();
        return Token(TokenType::eof, "<eof>", pos);
      }
      default:
        break;
    }

    if (this->is_letter_or_number_or_lodash(ch) && !isdigit(ch)) {
      size_t start = this->pos;
      std::string identifier = get_identifier();
      size_t end = this->pos;
      TokenPosition pos(start, end);

      if (identifier == "class")
        return Token(TokenType::classt, identifier, pos);
      else if (identifier == "struct")
        return Token(TokenType::structt, identifier, pos);
      else if (identifier == "union")
        return Token(TokenType::uniont, identifier, pos);
      else if (identifier == "void")
        return Token(TokenType::voidt, identifier, pos);
      else if (identifier == "int")
        return Token(TokenType::intt, identifier, pos);
      else if (identifier == "char")
        return Token(TokenType::chart, identifier, pos);
      else if (identifier == "float")
        return Token(TokenType::floatt, identifier, pos);
      else if (identifier == "double")
        return Token(TokenType::doublet, identifier, pos);
      else if (identifier == "bool")
        return Token(TokenType::boolt, identifier, pos);

      return Token(TokenType::identifier, identifier, pos);
    }

    size_t start = this->pos;
    this->eat();
    return Token(TokenType::illegal, ch, TokenPosition(start, this->pos));
  }

  std::string get_identifier() {
    std::string identifier = "";
    while (this->is_letter_or_number_or_lodash(this->ch())) {
      identifier += this->eat();
    }
    return identifier;
  }

  bool is_letter_or_number_or_lodash(char ch) {
    return isalpha(ch) || isdigit(ch) || ch == '_';
  }
};
