
// Generated from toy.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "toyParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by toyParser.
 */
class  toyListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterModule(toyParser::ModuleContext *ctx) = 0;
  virtual void exitModule(toyParser::ModuleContext *ctx) = 0;

  virtual void enterExpression(toyParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(toyParser::ExpressionContext *ctx) = 0;

  virtual void enterIdentifierexpr(toyParser::IdentifierexprContext *ctx) = 0;
  virtual void exitIdentifierexpr(toyParser::IdentifierexprContext *ctx) = 0;

  virtual void enterReturnExpression(toyParser::ReturnExpressionContext *ctx) = 0;
  virtual void exitReturnExpression(toyParser::ReturnExpressionContext *ctx) = 0;

  virtual void enterTensorLiteral(toyParser::TensorLiteralContext *ctx) = 0;
  virtual void exitTensorLiteral(toyParser::TensorLiteralContext *ctx) = 0;

  virtual void enterLiteralList(toyParser::LiteralListContext *ctx) = 0;
  virtual void exitLiteralList(toyParser::LiteralListContext *ctx) = 0;

  virtual void enterStructLiteral(toyParser::StructLiteralContext *ctx) = 0;
  virtual void exitStructLiteral(toyParser::StructLiteralContext *ctx) = 0;

  virtual void enterDecl(toyParser::DeclContext *ctx) = 0;
  virtual void exitDecl(toyParser::DeclContext *ctx) = 0;

  virtual void enterType(toyParser::TypeContext *ctx) = 0;
  virtual void exitType(toyParser::TypeContext *ctx) = 0;

  virtual void enterFundefinition(toyParser::FundefinitionContext *ctx) = 0;
  virtual void exitFundefinition(toyParser::FundefinitionContext *ctx) = 0;

  virtual void enterPrototype(toyParser::PrototypeContext *ctx) = 0;
  virtual void exitPrototype(toyParser::PrototypeContext *ctx) = 0;

  virtual void enterDecl_list(toyParser::Decl_listContext *ctx) = 0;
  virtual void exitDecl_list(toyParser::Decl_listContext *ctx) = 0;

  virtual void enterBlock(toyParser::BlockContext *ctx) = 0;
  virtual void exitBlock(toyParser::BlockContext *ctx) = 0;

  virtual void enterBlock_expr(toyParser::Block_exprContext *ctx) = 0;
  virtual void exitBlock_expr(toyParser::Block_exprContext *ctx) = 0;

  virtual void enterStructdefine(toyParser::StructdefineContext *ctx) = 0;
  virtual void exitStructdefine(toyParser::StructdefineContext *ctx) = 0;


};

