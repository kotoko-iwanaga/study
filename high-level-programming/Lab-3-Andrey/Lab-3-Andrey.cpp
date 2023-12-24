#include <iostream>
using namespace std;

int a() {
    return 0;
}
enum TokenType {
    NAME,
    ZERO,
    EQUAL,
    NOT_EQUAL,
    MORE,
    LESS,
    MORE_OR_EQUAL,
    LESS_OR_EQUAL,
    COLON,
    OPEN_PARENTHESES,
    CLOSE_PARENTHESES,
    COMMA,
    SEMICOLON,
    SPACE,
    QUESTION,
    ASSIGNMENT,
    PLUS,
    MINUS,
    MULT,
    DIV,
    PERCENT,
    AND,
    XOR,
    OR,
    B_OR,
    B_AND,
    NOT,
    INC,
    DEC,
    INT,
    UNDEFINED
};

struct Token {
    TokenType type;
    int beginIndex;
    int line;
    char token[100];
    int ordinal;

    Token() {
        type = SPACE;
    }

    Token(TokenType type1, int begin, int line1, int ordinal1) : type(type1), beginIndex(begin), line(line1), ordinal(ordinal1) {}
};

Token* tokens;
int tokenCount = 1;
int line = 1;
int character = 1;
int problems = 0;

//Функция возвращает указатель последнего токена
Token* lastToken() {
    return &tokens[tokenCount - 1];
}

void newToken(TokenType type) {
    /*if (SPACE == lastToken()->type) {
        lastToken()->type = type;
        lastToken()->line = line;
        lastToken()->beginIndex = character;
        return;
    }*/
    tokens = (Token*)realloc(tokens, sizeof(Token) * (tokenCount + 1));
    tokens[tokenCount] = Token(type, character, line, tokenCount);
    tokenCount++;
}

void newUndefinedToken(char current) {
    if (UNDEFINED == lastToken()->type) return;
    newToken(UNDEFINED);
    lastToken()->token[character - lastToken()->beginIndex] = current;
    lastToken()->token[character - lastToken()->beginIndex + 1] = '\0';
}

void tokenize() {
    tokens = (Token*)calloc(1, sizeof(Token));
    FILE* file;
    fopen_s(&file, "input.txt", "r");
    char current;
    while (true) {
        current = fgetc(file);
        character++;
        if (current == '\0' || current == EOF) break;
        if (current == '\n') {
            line++;
            character = 1;
        }
        if (current == '\n' || isspace(current) || current == '\t') {
            if (tokens[tokenCount - 1].type == SPACE) continue;
            else newToken(SPACE);
        }
        else if (current >= '0' && current <= '9' && tokens[tokenCount - 1].type == NAME) {}
        else if (current >= '0' && current <= '9') {
            if (tokens[tokenCount - 1].type != INT) newToken(INT);
        }
        else if (current == ';') newToken(SEMICOLON);
        else if (current == ':') newToken(COLON);
        else if (current == '>') newToken(MORE);
        else if (current == '<') newToken(LESS);
        else if (current == '=') {
            if (lastToken()->type == PLUS || lastToken()->type == MINUS || lastToken()->type == MULT
                || lastToken()->type == DIV || lastToken()->type == PERCENT || lastToken()->type == B_AND ||
                lastToken()->type == B_OR || lastToken()->type == XOR) {
                lastToken()->type = ASSIGNMENT;
            }
            else if (lastToken()->type == NOT) lastToken()->type = NOT_EQUAL;
            else if (lastToken()->type == ASSIGNMENT && lastToken()->token[0] == '=') lastToken()->type = EQUAL;
            else if (lastToken()->type == LESS) lastToken()->type = LESS_OR_EQUAL;
            else if (lastToken()->type == MORE) lastToken()->type = MORE_OR_EQUAL;
            else newToken(ASSIGNMENT);
        }
        else if (current == '^') newToken(XOR);
        else if (current == '*') newToken(MULT);
        else if (current == '/') newToken(DIV);
        else if (current == '%') newToken(PERCENT);
        else if (current == '&') {
            if (lastToken()->type == B_AND) lastToken()->type = AND;
            else newToken(B_AND);
        }
        else if (current == '|') {
            if (lastToken()->type == B_OR) lastToken()->type = OR;
            else newToken(B_OR);
        }
        else if (current == '+') {
            if (lastToken()->type == PLUS) lastToken()->type = INC;
            else newToken(PLUS);
        }
        else if (current == '-') {
            if (lastToken()->type == MINUS) lastToken()->type = DEC;
            else newToken(MINUS);
        }
        else if (current == ',') newToken(COMMA);
        else if (current == '(') newToken(OPEN_PARENTHESES);
        else if (current == ')') newToken(CLOSE_PARENTHESES);
        else if (current == '?') newToken(QUESTION);
        else if (isalpha(current) || current == '_') {
            if (tokens[tokenCount - 1].type == NAME) {}
            else newToken(NAME);
        }
        else {
            newUndefinedToken(current);
            continue;
        }
        lastToken()->token[character - lastToken()->beginIndex] = current;
        lastToken()->token[character - lastToken()->beginIndex + 1] = '\0';
    }
    fclose(file);
}

enum State {
    NONE,
    CONDITION,  // Первый операнд
    THEN, // Второй операнд
    ELSE, // Третий операнд
    NOT_TERNAR
};

enum ExpressionState {
    EXPECTED_NAME_OR_INT,
    EXPECTED_NAME,
    EXPECTED_OPERATOR
};

int errors = 0;
State state = NONE;
ExpressionState eState = EXPECTED_NAME_OR_INT;

void announceError(int i) {
    cout << "Error at line " << tokens[i].line << " and at column " << tokens[i].beginIndex - 1 << endl;
    // cout << "_" << endl << state << endl << tokens[i].token << endl << tokens[i].type << endl << eState << endl << "countp = " << count_p << endl;
    errors++;
}

void analyze() {
    int count_p = 0;
    for (int i = 0; i < tokenCount; i++) {
        if (tokens[i].type == SEMICOLON) {
            //cout << "line: " << tokens[i].line << "state: " << state << endl;
            if (eState != EXPECTED_OPERATOR) announceError(i);
            else if (state == THEN) announceError(i);
            else if (count_p) announceError(i);
            eState = EXPECTED_NAME_OR_INT;
            state = NONE;
            count_p = 0;
            continue;
        }
        if (state == NOT_TERNAR) {
            if (tokens[i].type == QUESTION || tokens[i].type == COLON) announceError(i);
            continue;
        }
        switch (tokens[i].type) {
        case SPACE:
            continue;
        case QUESTION:
            if (eState != EXPECTED_OPERATOR) announceError(i);
            else if (state != CONDITION) announceError(i);
            else if (count_p != 0) announceError(i);
            eState = EXPECTED_NAME_OR_INT;
            state = THEN;
            break;
        case COLON:
            if (eState != EXPECTED_OPERATOR) announceError(i);
            else if (state != THEN) announceError(i);
            else if (count_p != 0) announceError(i);
            eState = EXPECTED_NAME_OR_INT;
            state = ELSE;
            break;
        default:
            switch (eState) {
            case EXPECTED_NAME:
                if (state == NONE) {
                    if (tokens[i].type == NAME) eState = EXPECTED_OPERATOR;
                    break;
                }
                if (tokens[i].type == INC || tokens[i].type == DEC) {}
                else if (tokens[i].type == NAME)
                    eState = EXPECTED_OPERATOR;
                else if (tokens[i].type == CLOSE_PARENTHESES) announceError(i);
                else if (tokens[i].type == OPEN_PARENTHESES) {
                    count_p++;
                }
                else announceError(i);
                break;
            case EXPECTED_NAME_OR_INT:
                if (state == NONE) {
                    if (tokens[i].type == NAME) eState = EXPECTED_OPERATOR;
                    break;
                }
                if (tokens[i].type == PLUS || tokens[i].type == MINUS ||
                    tokens[i].type == MULT || tokens[i].type == B_AND) {
                }
                else if (tokens[i].type == INC || tokens[i].type == DEC) eState = EXPECTED_NAME;
                else if (tokens[i].type == NAME || tokens[i].type == INT) eState = EXPECTED_OPERATOR;
                else if (tokens[i].type == CLOSE_PARENTHESES) announceError(i);
                else if (tokens[i].type == OPEN_PARENTHESES) {
                    count_p++;
                }
                else announceError(i);
                break;
            case EXPECTED_OPERATOR:
                if (tokens[i].type == NAME && (state == NONE || state == CONDITION)) state = NOT_TERNAR;
                else if (tokens[i].type == INC || tokens[i].type == DEC) {
                    state = state == NONE ? CONDITION : state;
                }
                else {
                    switch (tokens[i].type) {
                    case ASSIGNMENT:
                    case B_OR:
                    case B_AND:
                    case OR:
                    case AND:
                    case PLUS:
                    case MINUS:
                    case MULT:
                    case DIV:
                    case PERCENT:
                    case EQUAL:
                    case NOT_EQUAL:
                    case MORE:
                    case LESS:
                    case MORE_OR_EQUAL:
                    case LESS_OR_EQUAL:
                        state = state == NONE ? CONDITION : state;
                        eState = EXPECTED_NAME_OR_INT;
                        break;
                    case OPEN_PARENTHESES:
                        announceError(i);
                        break;
                    case CLOSE_PARENTHESES:
                        if (count_p == 0) announceError(i);
                        else {
                            count_p--;
                        }
                        break;
                    default:
                        announceError(i);
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    if (state != NONE) announceError(tokenCount - 1);
}

int main() {
    tokenize();
    analyze();
    if (!errors) cout << "OK!" << endl;
    else cout << "Found " << errors << " error(-s)..." << endl;

    return 0;
}