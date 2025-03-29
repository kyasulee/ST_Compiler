// STParserVisitor.cpp

#include "STParserVisitor.h"
#include "STParser.h"

#include <iostream>


// 构造函数
newSTVisitor::newSTVisitor() : symbolTable() {}

antlrcpp::Any newSTVisitor::visitStartpoint(STParser::StartpointContext *ctx) {
    std::cout << "Visiting Startpoint:" <<  std::endl;

    // 递归访问program_list
    for (auto program: ctx->program_list()) {
        visit(program);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitProgram_list(STParser::Program_listContext *ctx) {
    std::cout << "Visiting Program_list:" << std::endl;

    if(ctx->programDecl()){
        std::cout << "Visiting programDecl:" << std::endl;
        visit(ctx->programDecl());
    } else if (ctx->functionDecl()) {
        std::cout << "Visiting functionDecl:" << std::endl;
        visit(ctx->functionDecl());
    } else if (ctx->functionBlockDecl()) {
        std::cout << "Visiting functionBlockDecl:" << std::endl;
        visit(ctx->functionBlockDecl());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitProgramDecl(STParser::ProgramDeclContext *ctx) {
    symbolTable.enterScope();  // 进入全局作用域
    // 程序名
    std::string progName = ctx->IDENT()->getText();
    std::cout << "Visiting Program Decl:" << progName << std::endl;

    symbolTable.addSymbol(progName, SymbolType::Program, "PROGRAM", true);

    // 变量声明
    if(ctx->declarationStmt()) {
        visit(ctx->declarationStmt());
    }

    for(auto stmt: ctx->statement_list()) {
        visit(stmt);
    }

    symbolTable.exitScope();  // 退出全局作用域
    symbolTable.print();      // 打印符号表
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitStatement_list(STParser::Statement_listContext *ctx) {
    std::cout << "Visiting Statement_list:" << std::endl;

    if (ctx->assignStmt()) {
        std::cout << "now is assignStmt" << std::endl;
        visit(ctx->assignStmt());
    } else if (ctx->selectStmt()) {
        std::cout << "now is selectStmt" << std::endl;
        visit(ctx->selectStmt());
    } else if (ctx->iterationStmt()) {
        std::cout << "now is iterationStmt" << std::endl;
        visit(ctx->iterationStmt());
    } else if (ctx->callFuncStmt()) {
        std::cout << "now is callFuncStmt" << std::endl;
        visit(ctx->callFuncStmt());
    } else if (ctx->jumpStmt()) {
        std::cout << "now is jumpStmt" << std::endl;
        visit(ctx->jumpStmt());
    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitSelectStmt(STParser::SelectStmtContext *ctx) {
    std::cout << "Visiting SelectStmt:" << std::endl;

    if(ctx->ifStmt()) {
        std::cout << "now found if statement" << std::endl;
        visit(ctx->ifStmt());
    } else if (ctx->caseStmt()) {
        std::cout << "now found case statement" << std::endl;
        visit(ctx->caseStmt());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitIterationStmt(STParser::IterationStmtContext *ctx) {
    std::cout << "Visiting IterationStmt:" << std::endl;

    if (ctx->whileStmt()) {
        std::cout << "now found while statement" << std::endl;
        visit(ctx->whileStmt());
    } else if (ctx->forStmt()) {
        std::cout << "now found for statement" << std::endl;
        visit(ctx->forStmt());
    } else if (ctx->repeatStmt()) {
        std::cout << "now found repeat statement" << std::endl;
        visit(ctx->repeatStmt());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitCallFuncStmt(STParser::CallFuncStmtContext *ctx) {
    std::cout << "Visiting CallFuncStmt:" << std::endl;

    std::string funcName;
    if (ctx->IDENT()) {
        funcName = ctx->IDENT()->getText();
    } else {
        funcName = ctx->getText(); // 'AND' | 'OR' | 'XOR' | 'MOD' | 'NOT'
    }
    std::cout << "function name is:" << funcName << std::endl;

    if (ctx->funcParams()) {
        std::cout << "now visiting funcParams" << std::endl;
        visit(ctx->funcParams());
    } else {
        std::cout << "there is no parameters provided" << std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitJumpStmt(STParser::JumpStmtContext *ctx) {
    std::cout << "Visiting JumpStmt:" << std::endl;

    if (ctx->getText() == "BREAK") {
        std::cout << "Found BREAK Statement" << std::endl;
    } else if (ctx->getText() == "RETURN") {
        std::cout << "Found RETURN Statement" << std::endl;
    } else if (ctx->getText() == "CONTINUE") {
        std::cout << "Found CONTINUE Statement" << std::endl;
    } else if (ctx->getText() == "EXIT") {
        std::cout << "Found EXIT Statement" << std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitAssignStmt(STParser::AssignStmtContext *ctx) {
    std::cout << "Visiting AssignStmt:" << std::endl;

    std::string leftValue;
    if (ctx->prefixExpr()) {
        leftValue = ctx->prefixExpr()->getText();
        std::cout << "Left Value of AssignStmt is:" << leftValue << std::endl;

        // 查找符号
        SymbolEntry* entry = symbolTable.lookupSymbol(leftValue);
        if (!entry) {
            std::cerr << "Error: Undefined variable: " << leftValue << std::endl;
        }
    }

    if (ctx->expr()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->expr()->getText() << std::endl;
        visit(ctx->expr());
    } else if (ctx->callFuncStmt()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->callFuncStmt()->getText() << std::endl;
        visit(ctx->callFuncStmt());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitPrefixExpr(STParser::PrefixExprContext *ctx) {
    std::cout << "Visiting PrefixExpr:" << std::endl;

    std::string identifier;
    if (ctx->ident()) {
        identifier = ctx->ident()->getText();
        std::cout << "identifier is:" << identifier << std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitExpr(STParser::ExprContext *ctx) {
    std::cout << "Visiting Expr:" << std::endl;

    if (ctx->orExpr()) {
        visit(ctx->orExpr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitOrExpr(STParser::OrExprContext *ctx) {
    std::cout  << "Visiting OrExpr:" << std::endl;

    if (ctx->orExpr() && ctx->andExpr()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;

        visit(ctx->orExpr());
        visit(ctx->andExpr());
    } else {
        visit(ctx->andExpr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitAndExpr(STParser::AndExprContext *ctx) {
    std::cout  << "Visiting AddExpr:" << std::endl;

    if (ctx->andExpr() && ctx->equalExpr()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;

        visit(ctx->andExpr());
        visit(ctx->equalExpr());
    } else {
        visit(ctx->equalExpr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitEqualExpr(STParser::EqualExprContext *ctx) {
    std::cout  << "Visiting EqualExpr:" << std::endl;

    if (ctx->equalExpr() && ctx->relationExpr()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;

        visit(ctx->equalExpr());
        visit(ctx->relationExpr());
    } else {
        visit(ctx->relationExpr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitRelationExpr(STParser::RelationExprContext *ctx) {
    std::cout  << "Visiting RelationExpr:" << std::endl;

    if (ctx->relationExpr() && ctx->addExpr()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;

        visit(ctx->relationExpr());
        visit(ctx->addExpr());
    } else {
        visit(ctx->addExpr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitAddExpr(STParser::AddExprContext *ctx) {
    std::cout  << "Visiting AddExpr:" << std::endl;

    if (ctx->addExpr() && ctx->multipliExpr()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;

        visit(ctx->addExpr());
        visit(ctx->multipliExpr());
    } else {
        visit(ctx->multipliExpr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitMultipliExpr(STParser::MultipliExprContext *ctx) {
    std::cout  << "Visiting MultipliExpr:" << std::endl;

    if (ctx->unaryExpr() && ctx->multipliExpr()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;

        visit(ctx->multipliExpr());
        visit(ctx->unaryExpr());
    } else {
        visit(ctx->unaryExpr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitUnaryExpr(STParser::UnaryExprContext *ctx) {
    std::cout  << "Visiting UnaryExpr:" << std::endl;

    std::string op = ctx->getText();
    std::cout << "operator is:" << op << std::endl;

    visit(ctx->primary());

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitPrimary(STParser::PrimaryContext *ctx) {
    std::cout  << "Visiting Primary:" << std::endl;
    if(ctx->expr()) {
        visit(ctx->expr());
    } else if (ctx->IDENT()) {
        std::string identifier = ctx->IDENT()->getText();
    } else if (ctx->NUMBER()) {
        std::string number = ctx->NUMBER()->getText();
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitIfStmt(STParser::IfStmtContext *ctx) {
    std::cout  << "Visiting IfStmt:" << std::endl;

    std::cout << "if condition is:" << ctx->expr()->getText() << std::endl;
    visit(ctx->expr());

    std::cout << "then branch is:" << std::endl;
    for (auto stmt : ctx->statement_list()) {
        visit(stmt);
    }

    if (ctx->getText() == "ELSE") {
        std::cout << "else branch is:" << std::endl;
        for (auto stmt : ctx->statement_list()) {
            visit(stmt);
        }
    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitCaseStmt(STParser::CaseStmtContext *ctx) {
    std::cout  << "Visiting CaseStmt:" << std::endl;

    std::cout << "Selector Expression:" << std::endl;
    visit(ctx->expr());

    // 处理分支列表
    std::cout << "Processing Case List:" << std::endl;
    visit(ctx->caseList());

    // 检查是否存在 ELSE 分支
    if (ctx->getText() == "ELSE") {
        std::cout << "else branch:" << std::endl;
        for (auto stmt : ctx->statement_list()) {
            visit(stmt);
        }
    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitCaseList(STParser::CaseListContext *ctx) {
    std::cout  << "Visiting CaseList:" << std::endl;

    for (size_t i = 0; i < ctx->caseValues().size(); i++) {
        std::cout << "case values:" << std::endl;
        visit(ctx->caseValues(i));

        std::cout << "case Statements:" << std::endl;
        visit(ctx->statement_list(i));
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitCaseValues(STParser::CaseValuesContext *ctx) {
    std::cout  << "Visiting CaseValues:" << std::endl;

    for (auto value : ctx->expr()) {
        std::cout << "value is:" << value->getText() << std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitForStmt(STParser::ForStmtContext *ctx) {
    std::cout << "Visiting ForStmt:" << std::endl;

    if (ctx->assignStmt()) {
        visit(ctx->assignStmt());
    }
    if (ctx->expr(0)) {
        visit(ctx->expr(0));
    }

    if (ctx->getText() == "BY") {
        std::cout << "step value is:" << std::endl;
        visit(ctx->expr(1));
    } else  {
        std::cout << "step value is default 1:" << std::endl;
    }

    for(auto stmt : ctx->statement_list()) {
        visit(stmt);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitWhileStmt(STParser::WhileStmtContext *ctx) {
    std::cout << "Visiting WhileStmt:" << std::endl;

    if (ctx->expr()) {
        std::cout << "while condition is" << std::endl;
        visit(ctx->expr());
    }

    for(auto stmt : ctx->statement_list()) {
        visit(stmt);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitRepeatStmt(STParser::RepeatStmtContext *ctx) {
    std::cout << "Visiting RepeatStmt" << std::endl;

    for(auto stmt : ctx->statement_list()) {
        visit(stmt);
    }

    if (ctx->expr()) {
        visit(ctx->expr());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitType(STParser::TypeContext *ctx) {
    std::cout << "Visiting Type:" << ctx->getText() << std::endl;

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFuncParams(STParser::FuncParamsContext *ctx) {
    std::cout << "Visiting FuncParams:" << std::endl;

    for (size_t i = 0; i < ctx->children.size(); i++) {
        auto child = ctx->children[i];

        if (auto identCtx = dynamic_cast<STParser::IdentContext*>(child)) {
            std::string paramName = identCtx->getText();
            std::cout << "paramName is:" << paramName << std::endl;

            if (i + 1 < ctx->children.size()) {
                auto nextChild = ctx->children[i + 1];
                if (nextChild->getText() == ":=") {
                    std::cout << ":=";
                    visit(ctx->expr(i / 2));
                    ++i;
                } else if (nextChild->getText() == "=>") {
                    std::cout << "=>";
                    if (i + 2 < ctx->children.size()) {
                        auto mappedIdent = ctx->children[i + 2];
                        std::cout << mappedIdent->getText();
                        i += 2;
                    } else {
                        std::cout << "no value provided" << std::endl;
                    }
                } else {
                    std::cout << "no value provided" << std::endl;
                }
            } else if (auto exprCtx = dynamic_cast<STParser::ExprContext*>(child)){
                std::cout << "Expression Parameter: ";
                visit(exprCtx);  // 访问表达式
                std::cout << std::endl;
            }
        }
    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitIdenti(STParser::IdentiContext *ctx) {
    std::cout << "Visiting simple identifier" << std::endl;

    std::string identifier = ctx->IDENT()->getText();
    std::cout << "identifier is:" << identifier << std::endl;

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitArray(STParser::ArrayContext *ctx) {
    std::cout << "Visiting array" << std::endl;

    std::string arrayName = ctx->IDENT()->getText();
    std::cout << "arrayName is:" << arrayName << std::endl;

    for (auto idxExpr : ctx->expr()) {
        visit(idxExpr);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitStruct(STParser::StructContext *ctx) {
    std::cout << "Visiting struct" << std::endl;

    visit(ctx->ident(0));

    visit(ctx->ident(1));

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitDeclarationStmt(STParser::DeclarationStmtContext *ctx) {
    std::cout << "Visiting DeclarationStmt" << std::endl;

    if(ctx->varDeclaration()) {
        visit(ctx->varDeclaration());
    } else if (ctx->varDeclarationBlock()) {
        visit(ctx->varDeclarationBlock());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitVarDeclarationBlock(STParser::VarDeclarationBlockContext *ctx) {
    std::cout << "Visiting DeclarationBlock" << std::endl;

    for (auto stmt:ctx->varDeclaration()) {
        visit(stmt);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitVarDeclaration(STParser::VarDeclarationContext *ctx) {
    std::cout << "Visiting VarDeclaration" << std::endl;

    std::string varName = ctx->IDENT()->getText();
    std::cout << "varName is:" << varName << std::endl;

    std::string dataType = ctx->type()->getText();
    visit(ctx->type());

    symbolTable.addSymbol(varName, SymbolType::Variable, dataType, true);

    if (ctx->NUMBER()) {
        std::string initialValue = ctx->NUMBER()->getText();
        std::cout << "initialValue is:" << initialValue << std::endl;
    } else {
        std::cout << "No initialValue"<< std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFunctionDecl(STParser::FunctionDeclContext *ctx) {
    symbolTable.enterScope();  // 进入函数作用域
    std::cout << "Visiting FunctionDecl" << std::endl;

    std::string functionName = ctx->IDENT()->getText();
    std::cout << "function name is:" << functionName << std::endl;

    std::string returnType = ctx->type()->getText();
    visit(ctx->type());

    symbolTable.addSymbol(functionName, SymbolType::Function, returnType, false);

    for (auto varBlock : ctx->varDeclarationBlock()) {
        visit(varBlock);
    }

    for (auto stmt : ctx->statement_list()) {
        visit(stmt);
    }

    // 添加功能块成员
    for (auto varDecl : ctx->varDeclarationBlock()) {
        std::string memberName = varDecl->getText();
        symbolTable.addFunctionMember(functionName, memberName);
    }

    symbolTable.exitScope();  // 退出函数作用域
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) {
    symbolTable.enterScope(); // 进入函数作用域
    std::cout << "Visiting FunctionBlockDecl" << std::endl;

    std::string functionBlockName = ctx->IDENT()->getText();
    std::cout << "function block name is:" << functionBlockName << std::endl;

    symbolTable.addSymbol(functionBlockName, SymbolType::FunctionBlock, "FUNCTION_BLOCK", true);

    for (auto varBlock : ctx->varDeclarationBlock()) {
        visit(varBlock);
    }

    // 添加功能块成员
    for (auto varDecl : ctx->varDeclarationBlock()) {
        std::string memberName = varDecl->getText();
        symbolTable.addFunctionBlockMember(functionBlockName, memberName);
    }

    for(auto stmt : ctx->statement_list()) {
        visit(stmt);
    }

    symbolTable.exitScope();  // 退出功能块作用域
    return nullptr;
}