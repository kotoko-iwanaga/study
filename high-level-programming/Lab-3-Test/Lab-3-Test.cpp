#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
    illegal,
    eof,

    identifier,
    semicolon,
    lparen,
    rparen,
    lsquirly,
    rsquirly,
    doublecolon,  // ::
    classt,
    structt,
    uniont,
    voidt,
    intt,
    chart,
    floatt,
    doublet,
    linecomment,
    longcomment,
};

struct Position {
    size_t start = 0;
    size_t end = 0;
    Position() {}
    Position(size_t start, size_t end) {
        this->start = start;
        this->end = end;
    }
};

struct Token {
    TokenType type;
    std::string literal;
    Position pos;
    Token(TokenType type, std::string literal, Position pos) {
        this->type = type;
        this->literal = literal;
        this->pos = pos;
    }
    Token(TokenType type, char literal, Position pos) {
        this->type = type;
        this->literal = literal;
        this->pos = pos;
    }

    void print() {
        std::cout << "start: " << this->pos.start << " end: " << this->pos.end
            << " literal: " << this->literal << std::endl;
    }
};

class Lexer {
private:
    std::string input;
    size_t pos = 0;

public:
    std::vector<Token> get_tokens_from_string(std::string input) {
        this->input = input;
        this->pos = 0;

        std::vector<Token> tokens;

        while (!this->eof()) {
            Token token = this->next_token();
            token.print();
            tokens.push_back(token);
        }
        return tokens;
    };

private:
    bool eof() { return this->pos >= this->input.length(); }
    char ch() {
        if (!this->eof())
            return this->input[this->pos];
        else
            return '\0';
    }

    char ch_after() {
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
        }
        else
            return '\0';
    }

    Token next_token() {
        this->skip_space();

        char ch = this->ch();
        switch (ch) {
        case ';': {
            Position pos(this->pos, this->pos + 1);
            this->eat();
            return Token(TokenType::semicolon, ch, pos);
        }
        case '(': {
            Position pos(this->pos, this->pos + 1);
            this->eat();
            return Token(TokenType::lparen, ch, pos);
        }
        case ')': {
            Position pos(this->pos, this->pos + 1);
            this->eat();
            return Token(TokenType::rparen, ch, pos);
        }
        case '{': {
            Position pos(this->pos, this->pos + 1);
            this->eat();
            return Token(TokenType::lsquirly, ch, pos);
        }
        case '}': {
            Position pos(this->pos, this->pos + 1);
            this->eat();
            return Token(TokenType::rsquirly, ch, pos);
        }
        case '/': {
            if (this->ch_after() == '/') {
                this->eat();
                this->eat();
                size_t start = this->pos;
                std::string comment = "";

                while (!(this->ch() == '\n' || this->ch() == '\0')) {
                    comment += this->eat();
                }
                size_t end = this->pos;
                this->eat();
                Position pos(start, end);
                return Token(TokenType::linecomment, comment, pos);
            }
            else if (this->ch_after() == '*') {
                this->eat();
                this->eat();
                size_t start = this->pos;
                std::string comment = "";
                while (!(this->ch() == '*' && this->ch_after() == '/')) {
                    comment += this->eat();
                    if (this->eof())
                        return Token(TokenType::illegal, "/*",
                            Position(start, start + 2));
                }
                size_t end = this->pos;
                Position pos(start, end);
                this->eat();
                this->eat();
                return Token(TokenType::linecomment, comment, pos);
            }
        }
        case '\0': {
            Position pos(this->pos, this->pos);
            this->eat();
            return Token(TokenType::eof, ch, pos);
        }
        default:
            break;
        }

        if (this->is_letter_or_lodash(ch)) {
            size_t start = this->pos;
            std::string identifier = get_identifier();
            size_t end = this->pos;
            Position pos(start, end);

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
            else if (identifier == "float")
                return Token(TokenType::floatt, identifier, pos);
            else if (identifier == "double")
                return Token(TokenType::doublet, identifier, pos);

            return Token(TokenType::identifier, identifier, pos);
        }

        size_t start = this->pos;
        this->eat();
        return Token(TokenType::illegal, ch, Position(start, this->pos));
    }

    std::string get_identifier() {
        std::string identifier = "";
        while (this->is_letter_or_lodash(this->ch())) {
            identifier += this->eat();
        }
        return identifier;
    }

    bool is_letter_or_lodash(char ch) { return isalpha(ch) || ch == '_'; }
};

int main() {
    Lexer lexer;

    std::string a = "{"
        "// comment \n"
        "/* long \n"
        "comment */ \n"
        "class Program "
        "{"
        "int Test() {"
        "int a = 0;"
        "return a;"
        "}"
        "void VoidTest() {"
        ""
        "}"
        "};";
    std::string b =
        "class Artemiy"
        "{"
        "}"
        ;
    auto tokens = lexer.get_tokens_from_string(a);

    
    bool find = false;
    /*for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::classt) {
            i++;
            if (tokens[i].type == TokenType::identifier) {
                i++;
                if (tokens[i].type == TokenType::lsquirly) {
                    if (tokens[i].type == TokenType::rsquirly) {
                        std::cout << "You win " << std::endl;
                    }
                    else {
                        std::cout << "Bad luck with }" << std::endl;
                    }
                }
                else {
                    std::cout << "Bad luck with {" << std::endl;
                }
            }
            else {
                std::cout << "Bad luck with name" << std::endl;
            }
        }
    }*/

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::classt) {
            i++;
            for (int j = i; j < tokens.size(); j++) {
                if (tokens[j].type == TokenType::identifier) {
                    j++;
                    for (int k = j; k < tokens.size(); k++) {
                        if (tokens[k].type == TokenType::lsquirly) {
                            k++;
                            for (int m = k; m < tokens.size(); m++) {
                                if (tokens[m].type == TokenType::rsquirly) {
                                    std::cout << "You win" << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}