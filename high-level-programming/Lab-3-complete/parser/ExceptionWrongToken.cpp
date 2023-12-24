#pragma once
#include <exception>
#include "../tokenizer/Token.cpp"

class ExceptionWrongToken : public std::exception {
 private:
  Token wrong_token;
  std::string error_message;

 public:
  ExceptionWrongToken(Token wrong_token, std::string message)
      : wrong_token(wrong_token) {
    this->error_message =
        message + "; Got: " + "`" + this->wrong_token.literal +
        "`"
        " at start positon: " +
        std::to_string(this->wrong_token.pos.start) +
        ", end position: " + std::to_string(this->wrong_token.pos.end);
  }

 public:
  const char* what() const throw() {
    const char* message = this->error_message.c_str();
    return message;
  }
};
