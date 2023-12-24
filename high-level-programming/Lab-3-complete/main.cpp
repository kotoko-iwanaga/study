#include "parser/Parser.cpp"
#include "utils/FileReader.cpp"

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

int main(int argc, char** argv) {
  if (argc == 1) {
    // test_lexer();

    Parser parser;

    parser.parse_file("./__tests__/01-empty.txt");
    parser.parse_file("./__tests__/02-trash.txt");
    parser.parse_file("./__tests__/03-class-empty.txt");
    parser.parse_file("./__tests__/04-class-empty-struct.txt");
    parser.parse_file("./__tests__/05-class-empty-union.txt");
    parser.parse_file("./__tests__/06-class-outer-methods.txt");
    parser.parse_file("./__tests__/07-class-full.txt");

    // files with errors
    parser.parse_file("./__tests__/10-class-invalid-end.txt");
    parser.parse_file("./__tests__/11-class-method-invalid-args.txt");
    parser.parse_file("./__tests__/12-class-invalid-outer-method.txt");
    parser.parse_file("no-such-file.txt");
  }

  if (argc == 2) {
    Parser parser;
    parser.parse_file(argv[1]);
  }

  if (argc > 2) {
    std::cout << "please pass filename as param to executable" << std::endl;
    exit(1);
  }
}
