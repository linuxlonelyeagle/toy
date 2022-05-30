
// Generated from toy.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "toyListener.h"


/**
 * This class provides an empty implementation of toyListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  toyBaseListener : public toyListener {
public:

  virtual void enterModule(toyParser::ModuleContext * /*ctx*/) override { }
  virtual void exitModule(toyParser::ModuleContext * /*ctx*/) override { }

  virtual void enterExpression(toyParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(toyParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterIdentifierexpr(toyParser::IdentifierexprContext * /*ctx*/) override { }
  virtual void exitIdentifierexpr(toyParser::IdentifierexprContext * /*ctx*/) override { }

  virtual void enterReturnExpression(toyParser::ReturnExpressionContext * /*ctx*/) override { }
  virtual void exitReturnExpression(toyParser::ReturnExpressionContext * /*ctx*/) override { }

  virtual void enterTensorLiteral(toyParser::TensorLiteralContext * /*ctx*/) override { }
  virtual void exitTensorLiteral(toyParser::TensorLiteralContext * /*ctx*/) override { }

  virtual void enterLiteralList(toyParser::LiteralListContext * /*ctx*/) override { }
  virtual void exitLiteralList(toyParser::LiteralListContext * /*ctx*/) override { }

  virtual void enterStructLiteral(toyParser::StructLiteralContext * /*ctx*/) override { }
  virtual void exitStructLiteral(toyParser::StructLiteralContext * /*ctx*/) override { }

  virtual void enterDecl(toyParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(toyParser::DeclContext * /*ctx*/) override { }

  virtual void enterType(toyParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(toyParser::TypeContext * /*ctx*/) override { }

  virtual void enterFundefinition(toyParser::FundefinitionContext * /*ctx*/) override { }
  virtual void exitFundefinition(toyParser::FundefinitionContext * /*ctx*/) override { }

  virtual void enterPrototype(toyParser::PrototypeContext * /*ctx*/) override { }
  virtual void exitPrototype(toyParser::PrototypeContext * /*ctx*/) override { }

  virtual void enterDecl_list(toyParser::Decl_listContext * /*ctx*/) override { }
  virtual void exitDecl_list(toyParser::Decl_listContext * /*ctx*/) override { }

  virtual void enterBlock(toyParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(toyParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlock_expr(toyParser::Block_exprContext * /*ctx*/) override { }
  virtual void exitBlock_expr(toyParser::Block_exprContext * /*ctx*/) override { }

  virtual void enterStructdefine(toyParser::StructdefineContext * /*ctx*/) override { }
  virtual void exitStructdefine(toyParser::StructdefineContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

