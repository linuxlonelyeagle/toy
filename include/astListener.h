#include "toyBaseListener.h"
#include <iostream>

class myListener : public toyBaseListener {

  virtual void enterModule(toyParser::ModuleContext * ctx) override {
    printDepth(1);
    depthP += change;
    std::cout << "Module:" << std::endl;
  }
  virtual void enterFundefinition(toyParser::FundefinitionContext * ctx) override {
    printDepth(depthP);
    depthP += change;
    std::cout << "Function" << std::endl;
  }
  virtual void exitFundefinition(toyParser::FundefinitionContext * ctx) override { 
    depthP -= change;
  }
  virtual void enterPrototype(toyParser::PrototypeContext * ctx) override {
    printDepth(depthP);
    std::cout << "Proto " + std::string("\'") + ctx->Identifier()->toString() + "\'" 
    << " @" + fileName  + ":" <<  ctx->Identifier()->getSymbol()->getLine() << ":" << ctx->Identifier()->getSymbol()->getCharPositionInLine() 
    << std::endl;
    printDepth(depthP);
    std::cout << "Parans:[";
    if (ctx->decl_list() != nullptr && ctx->decl_list()->decl_list() != nullptr) {
      auto i = ctx->decl_list();
      while (i) {
        std::cout << i->Identifier()->toString() << " ";
        i = i->decl_list();
      }
      std::cout << "\b";  
    }
    std::cout << "]" << std::endl; 
 }

  virtual void enterBlock(toyParser::BlockContext * ctx) override {
    printDepth(depthP);
    depthP += change;
    std::cout << "Block {" << std::endl; 

  }

  virtual void exitBlock(toyParser::BlockContext * ctx) override {
    depthP-=2;
    printDepth(depthP);
    std::cout << "}" << std::endl;
  }

  virtual void enterReturnExpression(toyParser::ReturnExpressionContext * ctx) override { 
    printDepth(depthP);
    depthP+=change;
    std::cout << "return @" + fileName << ":" 
    << ctx->getStart()->getLine() << ":" << ctx->getStart()->getCharPositionInLine() 
    << std::endl;

  }

  virtual void exitReturnExpression(toyParser::ReturnExpressionContext * ctx) override { 
    depthP-=change;
  }

  virtual void enterDecl(toyParser::DeclContext * ctx) override { 
    if (ctx->Var()) {
      printDepth(depthP);
      depthP+=change;
      std::cout << "Decl: " + ctx->Identifier(0)->toString();
      
      if (ctx->type()) {   
        std::cout << "<";
        auto flag = true;
        for (auto i = 0; i < ctx->type()->Number().size(); i++) {
          flag = false;
          std::cout << ctx->type()->Number()[i]->toString() << ",";
        }
        if (!flag)
        std::cout << "\b>" << " @" + fileName + ":" << ctx->getStart()->getLine() << ":" << ctx->getStart()->getCharPositionInLine() << std::endl;
        else 
        std::cout << ">" << " @" + fileName + ":" << ctx->getStart()->getLine() << ":" << ctx->getStart()->getCharPositionInLine() << std::endl;
      } else {
        std::cout << "<>" << " @" + fileName + ":" << ctx->getStart()->getLine() << ":" << ctx->getStart()->getCharPositionInLine()  << std::endl; 
      }
    } else if (ctx->Identifier(1)) {
      printDepth(depthP);
      depthP+=change;
      std::cout << "Struct Literal:" << std::endl;
      
    }
  }
  
  virtual void exitDecl(toyParser::DeclContext * ctx) override { 
    if (ctx->Var()) {
      depthP-=change;
    } else if (ctx->Identifier(1)) {
      depthP-=change;
    }
  }

  
  virtual void enterTensorLiteral(toyParser::TensorLiteralContext * ctx) override { 
    if (tensorFlag && ctx->Sbracket_open()) {
      printDepth(depthP);
      std::cout << "Literal: ";
      tensorFlag = false;
    }
    if (ctx->Sbracket_open()) {
      std::cout << "[";
      numberSbracket++;
    }

    if (ctx->Number()) {   
      if (numberSbracket)   // 如果数字在[]里面
      std::cout << ctx->Number()->toString() << ",";     
      else {
        printDepth(depthP);
        std::cout << ctx->Number()->toString() << " @" +fileName + ":"
        << ctx->Number()->getSymbol()->getLine() << ":" << ctx->Number()->getSymbol()->getCharPositionInLine()
        << std::endl; 
      }
    }     
  }
  virtual void exitTensorLiteral(toyParser::TensorLiteralContext * ctx) override { 
    if (ctx->Sbracket_close()) {
      numberSbracket--;
      if (numberSbracket) {
        std::cout << "\b] @" + fileName + ":"
        << ctx->Sbracket_open()->getSymbol()->getLine() << ":"
        << ctx->Sbracket_open()->getSymbol()->getCharPositionInLine();
      } else {
        std::cout << "] @" + fileName + ":"
        << ctx->Sbracket_open()->getSymbol()->getLine() << ":"
        << ctx->Sbracket_open()->getSymbol()->getCharPositionInLine();
      } 

      if (!numberSbracket) {
        std::cout << std::endl;
        tensorFlag = true;
      }
    } 
  }

  virtual void enterExpression(toyParser::ExpressionContext * ctx) override { 
    if (ctx->Dian()) {
      printDepth(depthP);
      std::cout << "Binop: " << ctx->Dian()->toString() +" @" + fileName + ":"
      << ctx->Dian()->getSymbol()->getLine() << ":" << ctx->Dian()->getSymbol()->getCharPositionInLine()
      << std::endl;
      depthP += change;

    } else if (ctx->MulDiv()) {
      printDepth(depthP);
      std::cout << "Binop: " << ctx->MulDiv()->toString() +" @" + fileName + ":"
      << ctx->MulDiv()->getSymbol()->getLine() << ":" << ctx->MulDiv()->getSymbol()->getCharPositionInLine() 
      << std::endl;
      depthP += change;
    } else if (ctx->AddSub()) {
      printDepth(depthP);
      std::cout << "Binop: " << ctx->AddSub()->toString() + " @" + fileName + ":"
      << ctx->AddSub()->getSymbol()->getLine() << ":" << ctx->AddSub()->getSymbol()->getCharPositionInLine() 
      << std::endl;
      depthP += change;
    }
  }
    
  virtual void exitExpression(toyParser::ExpressionContext * ctx) override { 
    if (ctx->Dian() || ctx->MulDiv() || ctx->AddSub()) 
      depthP -= change;
  }

  virtual void enterIdentifierexpr(toyParser::IdentifierexprContext * ctx) override { 
    if  (ctx->Parenthese_open()) {  //如果是函数调用
      printDepth(depthP);
      std::cout << "Call " << ctx->Identifier()->toString() << "[ @" + fileName +":"
      << ctx->Identifier()->getSymbol()->getLine() << ":" << ctx->Identifier()->getSymbol()->getCharPositionInLine()
      << std::endl;
      depthP += change;
    } else {  //如果不是函数调用
      printDepth(depthP);
      std::cout << "var: " + ctx->Identifier()->toString() + " @" + fileName +":"
      << ctx->Identifier()->getSymbol()->getLine() << ":" << ctx->Identifier()->getSymbol()->getCharPositionInLine() << std::endl;
      depthP += change;      
    }
  }

  virtual void exitIdentifierexpr(toyParser::IdentifierexprContext * ctx) override { 
    if (ctx->Parenthese_open()) {
      depthP-=change;
      printDepth(depthP);
      std::cout << "]" << std::endl;
    } else {
      depthP -= change;
    }
  }

  virtual void enterStructdefine(toyParser::StructdefineContext * ctx) override { 
    printDepth(depthP);
    std::cout << "struct: " << ctx->Identifier()->toString() << " @" + fileName + ":" << 
     ctx->getStart()->getLine() << ":"  << ctx->getStart()->getCharPositionInLine() << std::endl;
    depthP += change;
    printDepth(depthP);
    depthP += change;
    std::cout << "Variables: [" << std::endl;  
    
  }
  virtual void exitStructdefine(toyParser::StructdefineContext * ctx) override { 
    depthP -= change;
    printDepth(depthP);
    std::cout << "]" << std::endl;
    depthP -= change;
  }
  

    // 用来计算需要打印的缩进的数量
    size_t depthP;
    size_t change = 2;
    bool tensorFlag = true;
    size_t numberSbracket;
    //用来输出缩进
    void printDepth(int n) {
    for (auto i = 0; i < n ; i++) 
      std::cout << ' ';
    }
    public:
    // 用来保存源文件的名称
    std::string fileName;
};


