#pragma once
#include <iostream>
#include <string>
#include "TokenPosition.cpp"
#include "TokenType.cpp"

struct Token {
  TokenType type;
  std::string literal;
  TokenPosition pos;

  Token(TokenType type, std::string literal, TokenPosition pos) {
    this->type = type;
    this->literal = literal;
    this->pos = pos;
  }
  Token(TokenType type, char literal, TokenPosition pos) {
    this->type = type;
    this->literal = literal;
    this->pos = pos;
  }

  void print() {
    std::cout << "start: " << this->pos.start << " end: " << this->pos.end
              << " literal: " << this->literal << std::endl;
  }

  std::string print_type() { return Token::print_type(this->type); }

  static std::string print_type(TokenType type) {
    std::string type_message;

    switch (type) {
      case TokenType::illegal:
        type_message = "illegal";
        break;
      case TokenType::eof:
        type_message = "eof";
        break;
      case TokenType::identifier:
        type_message = "identifier";
        break;
      case TokenType::lparen:
        type_message = "(";
        break;
      case TokenType::rparen:
        type_message = ")";
        break;
      case TokenType::lsquirly:
        type_message = "{";
        break;
      case TokenType::rsquirly:
        type_message = "}";
        break;
      case TokenType::comma:
        type_message = ",";
        break;
      case TokenType::semicolon:
        type_message = ";";
        break;
      case TokenType::doublecolon:
        type_message = "::";
        break;
      case TokenType::classt:
        type_message = "class";
        break;
      case TokenType::structt:
        type_message = "struct";
        break;
      case TokenType::uniont:
        type_message = "union";
        break;
      case TokenType::voidt:
        type_message = "void";
        break;
      case TokenType::intt:
        type_message = "int";
      case TokenType::chart:
        type_message = "char";
        break;
      case TokenType::floatt:
        type_message = "float";
        break;
      case TokenType::doublet:
        type_message = "double";
        break;
      case TokenType::boolt:
        type_message = "bool";
        break;
      case TokenType::linecomment:
        type_message = "line comment";
        break;
      case TokenType::longcomment:
        type_message = "long comment";
        break;
      default:
        throw std::runtime_error("TokenType::? does not exist");
    }

    return type_message;
  }
};