// STParserVisitor.cpp

#include "STParserVisitor.h"
#include "STParser.h"
#include "SemanticAnalyzer.h"

#include <iostream>
#include <sstream>

// 构造函数
newSTVisitor::newSTVisitor() : symbolTable(), semanticAnalyzer() {}

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
    if (ctx->PROGRAM()) {
        std::string progName = ctx->IDENT()->getText();
        std::cout << "Visiting Program Decl:" << progName << std::endl;

        symbolTable.addSymbol(progName, SymbolType::Program, "PROGRAM", true);

        // 变量声明
        if (ctx->interfaceSection()) {
            visit(ctx->interfaceSection());
        }

        // 程序段
        if (ctx->bodySection()) {
            visit(ctx->bodySection());
        }
    }

    symbolTable.exitScope();  // 退出全局作用域
    symbolTable.print();      // 打印符号表
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitInterfaceSection(STParser::InterfaceSectionContext *ctx) {
    std::cout << "Visiting InterfaceSection:" << std::endl;

    for (auto stmt : ctx->varDeclarationBlock()) {
        visit(stmt);
    }

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

    if (!semanticAnalyzer.checkFunctionCall(funcName) && !semanticAnalyzer.checkFunctionBlockMethodCall(funcName)) {
        std::cerr << "Error: Variable '" << funcName << "' is not declared!" << std::endl;
        return nullptr;
    }

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
        if (!semanticAnalyzer.checkVariableUsage(leftValue)) {
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

    if (ctx->IF()) {
        if (ctx->expr(0)) {
            std::cout << "if condition is:" << ctx->expr(0)<< std::endl;
            visit(ctx->expr(0));
        }

        std::cout << "then branch is:" << std::endl;
        for (auto stmt : ctx->statement_list()) {
            visit(stmt);
        }

        for (auto i = 1; i <= ctx->ELSEIF().size(); i++) {
            visit(ctx->expr(i));
            visit(ctx->statement_list(i-1));
        }

        if (ctx->ELSE()) {
            int stat_size = ctx->statement_list().size();
            visit(ctx->statement_list(stat_size-1));
        }
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitCaseStmt(STParser::CaseStmtContext *ctx) {
    std::cout  << "Visiting CaseStmt:" << std::endl;

    if (ctx->CASE()) {
        std::cout << "Selector Expression:" << std::endl;
        visit(ctx->expr());

        // 处理分支列表
        if (ctx->OF()) {
            std::cout << "Processing Case List:" << std::endl;
            visit(ctx->caseList());
        }

        // 检查是否存在 ELSE 分支
        if (ctx->ELSE()) {
            std::cout << "else branch:" << std::endl;
            for (auto stmt: ctx->statement_list()) {
                visit(stmt);
            }
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

    if (ctx->FOR()) {
        if (ctx->assignStmt()) {
            visit(ctx->assignStmt());
        }

        if (ctx->expr(0)) {
            visit(ctx->expr(0));
        }

        if (ctx->BY()) {
            std::cout << "step value is:" << std::endl;
            visit(ctx->expr(1));
        } else {
            std::cout << "step value is default 1:" << std::endl;
        }

        for (auto stmt: ctx->statement_list()) {
            visit(stmt);
        }

    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitWhileStmt(STParser::WhileStmtContext *ctx) {
    std::cout << "Visiting WhileStmt:" << std::endl;

    if (ctx->WHILE()) {
        if (ctx->expr()) {
            std::cout << "while condition is" << std::endl;
            visit(ctx->expr());
        }

        for (auto stmt: ctx->statement_list()) {
            visit(stmt);
        }
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitRepeatStmt(STParser::RepeatStmtContext *ctx) {
    std::cout << "Visiting RepeatStmt" << std::endl;

    if (ctx->REPEAT()) {
        for (auto stmt: ctx->statement_list()) {
            visit(stmt);
        }

        if (ctx->expr()) {
            visit(ctx->expr());
        }
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitType(STParser::TypeContext *ctx) {
    if (ctx->basicType()) {
        visit(ctx->basicType());
    } else if (ctx->arrayType()) {
        visit(ctx->arrayType());
    } else if (ctx->structType()) {
        visit(ctx->structType());
    } else if (ctx->enumeratedType()) {
        visit(ctx->enumeratedType());
    } else if (ctx->subrangeType()) {
        visit(ctx->subrangeType());
    } else if (ctx->IDENT()) {
        std::string userDefinedType = ctx->IDENT()->getText();

        std::cout << "userDefinedType is " << userDefinedType << std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFuncParams(STParser::FuncParamsContext *ctx) {
    std::cout << "Visiting FuncParams:" << std::endl;

    for (auto paramCtx : ctx->funcParam()) {
        visit(paramCtx);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFuncParam(STParser::FuncParamContext *ctx) {
    if (ctx->ARROW()) {
        // 输出引脚
        std::string outputPin = ctx->IDENT()->getText();
        std::string mappedValue = ctx->ident()->getText();

        if (!semanticAnalyzer.checkVariableUsage(mappedValue)) {
            std::cerr << "Error: Undefined variable " << mappedValue << std::endl;
            return nullptr;
        }
    } else if (ctx->ASSIGN()) {
        // 输入引脚
        std::string inputPin = ctx->IDENT()->getText();


        visit(ctx->expr());
        if (!semanticAnalyzer.checkVariableUsage(ctx->expr()->getText())) {
            std::cerr << "Error: Undefined variable " << ctx->expr()->getText() << std::endl;
            return nullptr;
        }
        visit(ctx->expr());
    } else {
        visit(ctx->expr());
    }
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

    std::string dataType;
    if (ctx->type()) {
        visit(ctx->type());
        dataType = ctx->type()->getText(); // 基本类型
    } else if (ctx->arrayType()) {
        dataType = "ARRAY";
        visit(ctx->arrayType());
    } else if (ctx->structType()) {
        dataType = "STRUCT";
        visit(ctx->structType());
    }

    if (!semanticAnalyzer.declareVariable(varName, dataType)) {
        std::cerr << "Error: Variable '" << varName << "' is already declared in this scope!" << std::endl;
        return nullptr;
    }

    if (ctx->expr()) {
        std::string initialValue = ctx->expr()->getText();
        std::cout << "initialValue is:" << initialValue << std::endl;
        visit(ctx->expr());
        // TODO 初始值校验
    } else {
        std::cout << "No initialValue"<< std::endl;
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitBasicType(STParser::BasicTypeContext *ctx) {
    std::string typeName = ctx->getText();
    std::cout << "typeName is: " << typeName << std::endl;

    return typeName;
}

antlrcpp::Any newSTVisitor::visitArrayType(STParser::ArrayTypeContext *ctx) {
    std::cout << "Visiting ArrayType:" << std::endl;

    for (auto rangeCtx : ctx->range()) {
        visit(rangeCtx);
    }

    visit(ctx->type());
    std::string elementType = ctx->type()->getText();

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitRange(STParser::RangeContext *ctx) {
    std::string upperRange = ctx->expr(1)->getText();
    std::string lowerRange = ctx->expr(0)->getText();

    std::cout << lowerRange << ".." << upperRange << std::endl;

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitStructType(STParser::StructTypeContext *ctx) {
    std::cout << "Visiting structType:" << std::endl;

    for (auto memberCtx : ctx->structMember()) {
        visit(memberCtx);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitStructMember(STParser::StructMemberContext *ctx) {
    std::string memberName = ctx->IDENT()->getText();

    visit(ctx->type());
    std::string memberType = ctx->type()->getText();

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFunctionDecl(STParser::FunctionDeclContext *ctx) {
    symbolTable.enterScope();  // 进入函数作用域
    std::cout << "Visiting FunctionDecl" << std::endl;

    std::string functionName = ctx->IDENT()->getText();
    std::cout << "function name is:" << functionName << std::endl;

    std::string returnType = ctx->type()->getText();
    visit(ctx->type());

    if (!semanticAnalyzer.declareFunction(functionName, returnType)) {
        std::cerr << "Error: Function '" << functionName << "' is already declared!" << std::endl;
        return nullptr;
    }

    symbolTable.addSymbol(functionName, SymbolType::Function, returnType, true);

    if (ctx->interfaceSection()) {
        visit(ctx->interfaceSection());
    }

   if (ctx->bodySection()) {
       visit(ctx->bodySection());
   }

    symbolTable.exitScope();  // 退出函数作用域
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) {
    symbolTable.enterScope(); // 进入函数作用域
    std::cout << "Visiting FunctionBlockDecl" << std::endl;

    std::string functionBlockName = ctx->IDENT()->getText();
    std::cout << "function block name is:" << functionBlockName << std::endl;

    if (!semanticAnalyzer.declareFunctionBlock(functionBlockName)) {
        std::cerr << "Error: Function Block '" << functionBlockName << "' is already declared!" << std::endl;
        return nullptr;
    }
    std::cout << "添加fu定义" << std::endl;
    symbolTable.addSymbol(functionBlockName, SymbolType::FunctionBlock, "", true);

    if (ctx->interfaceSection()) {
        visit(ctx->interfaceSection());
    }

    if (ctx->bodySection()) {
        visit(ctx->bodySection());
    }

    symbolTable.exitScope();  // 退出功能块作用域
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitMethodDecl(STParser::MethodDeclContext *ctx) {
    std::string methodName;
    if (ctx->METHOD()) {
         methodName = ctx->METHOD()->getText();
    }

    // 返回类型
    visit(ctx->type());

    // 进入作用域
    semanticAnalyzer.enterScope();
    if (!semanticAnalyzer.declareFunction(methodName, ctx->type()->getText())){
        std::cerr << "Error: Failed to declare method " <<  methodName <<  "." << std::endl;
    }

    if (ctx->interfaceSection()) {
        visit(ctx->interfaceSection());
    }

    visit(ctx->bodySection());

    semanticAnalyzer.exitScope();

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitBodySection(STParser::BodySectionContext *ctx) {
    for (auto stmt : ctx->statement_list()) {
        visit(stmt);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitEnumeratedType(STParser::EnumeratedTypeContext *ctx) {
    std::cout << "  Enumerated Values: ";
    for (auto ident : ctx->IDENT()) {
        std::cout << ident->getText() << " ";
    }
    std::cout << std::endl;

    return nullptr;
}


antlrcpp::Any newSTVisitor::visitSubrangeType(STParser::SubrangeTypeContext *ctx) {
    std::cout << "  Base Type: ";
    visit(ctx->basicType());

    std::cout << "  Range: "
              << ctx->expr(0)->getText() << " .. "
              << ctx->expr(1)->getText() << std::endl;

    return nullptr;
}