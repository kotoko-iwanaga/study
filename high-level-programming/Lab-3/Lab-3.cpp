#include "parser/Parser.cpp"
#include "utils/FileReader.cpp"
#include <conio.h>

void test_lexer();
void menu();

int main() {
  
  bool end = false;
  Parser parser;
  while (end != true) {
      menu();
      char choice = _getch();
      switch (choice) {
      case '1':
          parser.parse_file("./__tests__/01-empty.txt");
          break;
      case '2':
          parser.parse_file("./__tests__/02-comments.txt");
          break;
      case '3':
          parser.parse_file("./__tests__/03-class-empty.txt");
          break;
      case '4':
          parser.parse_file("./__tests__/04-class-empty-struct.txt");
          break;
      case '5':
          parser.parse_file("./__tests__/05-class-empty-union.txt");
          break;
      case '6':
          parser.parse_file("./__tests__/06-class-outer-methods.txt");
          break;
      case '7':
          parser.parse_file("./__tests__/07-class-full.txt");
          break;
      case '8':
          parser.parse_file("./__tests__/08-union-full.txt");
          break;
      case '9':
          parser.parse_file("./__tests__/09-struct-full.txt");
          break;

      case 'a':
          parser.parse_file("./__tests__/10-class-invalid-end.txt");
          break;
      case 'b':
          parser.parse_file("./__tests__/11-class-method-invalid-args.txt");
          break;
      case 'c':
          parser.parse_file("./__tests__/12-class-invalid-outer-method.txt");
          break;
      case 'd':
          parser.parse_file("./__tests__/13-class-method-invalid-end.txt");
          break;
      case 'e':
          parser.parse_file("./__tests__/14-class-invalid-noname.txt");
          break;
      case 'f':
          parser.parse_file("./__tests__/15-union-invalid-end.txt");
          break;
      case 'g':
          parser.parse_file("./__tests__/16-union-invalid-method-args.txt");
          break;
      case 'h':
          parser.parse_file("./__tests__/17-union-method-invalid-end.txt");
          break;
      case 'i':
          parser.parse_file("./__tests__/18-not-existing-union-method.txt");
          break;
      case 'j':
          parser.parse_file("./__tests__/19-struct-invalid-end.txt");
          break;
      case 'k':
          parser.parse_file("./__tests__/20-struct-outer-method-invalid-end.txt");
          break;
      case 'l':
          parser.parse_file("./__tests__/21-no-class-declaration.txt");
          break;

      case 'x':
          parser.parse_file("no-such-file.txt");
          break;
      case 'z':
          end = true;
          break;
      case 'y':
          test_lexer();
          break;
      default:
          std::cout << "Wrong option, please try again" << std::endl;
      }
      putchar('\n');
  }
  
  
}

void menu() {
  std::cout << "Tests with success" << std::endl;
  std::cout << "1) Empty file" << std::endl;
  std::cout << "2) Comments" << std::endl;
  std::cout << "3) Empty class" << std::endl;
  std::cout << "4) Empty struct" << std::endl;
  std::cout << "5) Empty union" << std::endl;
  std::cout << "6) Outer methods" << std::endl;
  std::cout << "7) Full class" << std::endl;
  std::cout << "8) Full union" << std::endl;
  std::cout << "9) Full struct" << std::endl;
  std::cout << "Test with errors" << std::endl;
  std::cout << "a) Invalid end" << std::endl;
  std::cout << "b) Incorrect arguments" << std::endl;
  std::cout << "c) Invalid outer method" << std::endl;
  std::cout << "d) Invalid end" << std::endl;
  std::cout << "e) Class without name" << std::endl;
  std::cout << "f) Union with invalid end" << std::endl;
  std::cout << "g) Union method with invalid arguments" << std::endl;
  std::cout << "h) Union method with invalid end" << std::endl;
  std::cout << "i) Union doesn't exist, but method is" << std::endl;
  std::cout << "j) Struct with invalid end" << std::endl;
  std::cout << "k) Struct out method with invalid end" << std::endl;
  std::cout << "l) No word 'class' declared" << std::endl;
  std::cout << "Misc" << std::endl;
  std::cout << "x) Test for no existing file" << std::endl;
  std::cout << "y) Lexer test" << std::endl;
  std::cout << "z) Exit\n" << std::endl;
  
}

void test_lexer() {
  Tokenizer tokenizer;

  auto tokens = tokenizer.get_tokens_from_string(
      "  // comment \n"
      "/* long \n"
      "comment */ \n"
      "class Foo { void ha() {}};\n\n"

      "Foo::bar() {}");

  for (auto token : tokens) {
      token.print();
  }
}