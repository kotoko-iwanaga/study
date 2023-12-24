#pragma once
#include "../tokenizer/Tokenizer.cpp"
#include "../utils/FileReader.cpp"
#include "ExceptionWrongToken.cpp"

class Parser {
 private:
  Tokenizer tokenizer;
  std::vector<Token> tokens;

 public:
  void parse_string(std::string input) {
    std::vector<ExceptionWrongToken> exceptions = this->parse(input);

    if (exceptions.empty()) {
      std::cout << "parsing: success" << std::endl;
    } else {
      std::cout << "parsing: error" << std::endl;
      for (auto e : exceptions) {
        std::cout << e.what() << std::endl;
      }
    }
  }

  void parse_file(std::string filename) {
    try {
      std::cout << "parsing file: " << filename << std::endl;
      std::string file_content = FileReader::try_read_file(filename);
      this->parse_string(file_content);
    } catch (const std::exception& e) {
      std::cout << "parsing: error" << std::endl;
      std::cout << "File " << filename << " does not exist" << std::endl;
    }
  }

 private:
  std::vector<ExceptionWrongToken> parse(std::string input) {
    this->tokens = tokenizer.get_tokens_from_string(input);
    std::vector<ExceptionWrongToken> exceptions;

    while (!this->eof()) {
      try {
        switch (this->tok().type) {
          case TokenType::classt:
          case TokenType::structt:
          case TokenType::uniont:
            this->parse_class();
            break;
          case TokenType::voidt:
          case TokenType::intt:
          case TokenType::chart:
          case TokenType::floatt:
          case TokenType::doublet:
          case TokenType::boolt:
            this->parse_outer_method();
            break;
          case TokenType::semicolon:
            this->require(TokenType::semicolon);
            break;
          default:
            throw ExceptionWrongToken(this->eat(), "Wrong construction");
        }
      } catch (const ExceptionWrongToken e) {
        exceptions.push_back(e);
      }
    }
    return exceptions;
  }

  Token tok() { return this->tokens[0]; }
  Token eat() {
      Token tok = this->tok();
      if (!this->eof())
          this->tokens.erase(this->tokens.begin());
      return tok;
  }
  bool eof() { return this->tok().type == TokenType::eof; }

  Token require(TokenType type) {
    if (this->tok().type != type) {
      std::string message = "Expected: " + Token::print_type(type);
      throw ExceptionWrongToken(this->tok(), message);
    }
    return this->eat();
  }

  Token require_any(TokenType type1, TokenType type2) {
    if (this->tok().type != type1 && this->tok().type != type2) {
      std::string message = "Expected: " + Token::print_type(type1) + " or " +
                            Token::print_type(type2);
      throw ExceptionWrongToken(this->tok(), message);
    }
    return this->eat();
  }

  Token require_any(TokenType type1, TokenType type2, TokenType type3) {
    if (this->tok().type != type1 && this->tok().type != type2 &&
        this->tok().type != type3) {
      std::string message = "Expected: " + Token::print_type(type1) + " or " +
                            Token::print_type(type2) + " or " +
                            Token::print_type(type3);
      throw ExceptionWrongToken(this->tok(), message);
    }
    return this->eat();
  }

  void parse_class() {
    this->require_any(TokenType::classt, TokenType::structt,
                      TokenType::uniont);                      // class
    Token ident_token = this->require(TokenType::identifier);  // Classname
    this->require(TokenType::lsquirly);                        // {

    while (this->tok().type != TokenType::rsquirly) {  // }

      switch (this->tok().type) {
        case TokenType::classt:
        case TokenType::structt:
        case TokenType::uniont:
          this->parse_class();
          break;
        case TokenType::semicolon:
          this->require(TokenType::semicolon);
          break;
        default:
          this->parse_method();
          break;
      }

      if (this->eof())
        this->require(TokenType::rsquirly);  // throw error
    }
    this->require(TokenType::rsquirly);   // }
    this->require(TokenType::semicolon);  // ;
  }

  void parse_return_type() {
    switch (this->tok().type) {
      case TokenType::voidt:
      case TokenType::intt:
      case TokenType::chart:
      case TokenType::floatt:
      case TokenType::doublet:
      case TokenType::boolt: {
        this->eat();
        break;
      }
      default:
        Token tok = this->eat();
        throw ExceptionWrongToken(tok, "Expected: return type");
    }
  }

  void parse_var_type() {
    switch (this->tok().type) {
      case TokenType::intt:
      case TokenType::chart:
      case TokenType::floatt:
      case TokenType::doublet:
      case TokenType::boolt: {
        this->eat();
        break;
      }
      default:
        Token tok = this->eat();
        throw ExceptionWrongToken(tok, "Expected: variable type");
    }
  }

  void parse_method() {
    this->parse_return_type();                // void/int/char/float/double/bool
    this->require(TokenType::identifier);     // variable
    this->parser_method_arguments_and_body(); /* (int x, bool is, char ch) {
                                                  Dima will handle this}

                                                  or

                                                  (int x, bool is, char ch);
                                              */
  }

  void parser_method_arguments_and_body() {
    this->require(TokenType::lparen);  // (
    this->parse_method_arguments();    // int x, bool is, char ch
    this->require(TokenType::rparen);  // )

    if (this->tok().type == TokenType::semicolon) {
      this->require(TokenType::semicolon);  // ;
      return;
    }

    this->require(TokenType::lsquirly);  // {
    this->parse_method_body();           // Dima will handle this
    this->require(TokenType::rsquirly);  // }
  }

  void parse_method_arguments() {
    if (this->tok().type != TokenType::rparen) {  // )
      this->parse_var_type();                     // int/char/float/double/bool
      this->require(TokenType::identifier);       // variable

      while (this->tok().type == TokenType::comma) {  // ,
        this->require(TokenType::comma);              // ,
        this->parse_var_type();                // int/char/float/double/bool
        this->require(TokenType::identifier);  // variable
      }

      if (this->tok().type != TokenType::rparen) {  // )
        this->require(TokenType::rparen);           // throw error
      }
    }
  }

  void parse_method_body() {
    while (this->tok().type != TokenType::rsquirly) {  // }
      this->eat();                                     // Dima will handle this
      if (this->eof())
        this->require(TokenType::rsquirly);  // throw error
    }
  }

  void parse_outer_method() {
    this->parse_return_type();              // void/int/char/float/double/bool
    this->require(TokenType::identifier);   // Classname
    this->require(TokenType::doublecolon);  // ::
    this->require(TokenType::identifier);   // variable
    this->parser_method_arguments_and_body();
  }
};
