#include <iostream>
#include <fstream>
#include "ANTLRInputStream.h"
#include "toyLexer.h"
#include "toyParser.h"
#include "toyBaseListener.h"
#include "astListener.h"


int main(int argc, char* argv[]) {

  std::string option(argv[1]);
  if (option == "tokens") {
    std::fstream in(argv[2]);
    antlr4::ANTLRInputStream input(in);
    toyLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    for (auto token : tokens.getTokens()) {
      std::cout << token->toString() << std::endl;
    }
  } else if (option == "ast") {
    std::fstream in(argv[2]);
    antlr4::ANTLRInputStream input(in);
    toyLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    toyParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.module();
    myListener listener = myListener();
    listener.fileName = argv[2];
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
  } else if (option == "mlir") {

  } 
}
