// STParserVisitor.cpp

#include "STParserVisitor.h"
#include "STParser.h"
#include "SemanticAnalyzer.h"

#include <iostream>
#include <algorithm>
#include <cctype>

const std::string SystemFuncLibPath = "/root/codes/llvm/st_builder/Standard_fbfu.json";

// 构造函数
newSTVisitor::newSTVisitor() : symbolTable(), semanticAnalyzer() {}

antlrcpp::Any newSTVisitor::visitStartpoint(STParser::StartpointContext *ctx) {
    std::cout << "Entering Global Scope" << std::endl;
    semanticAnalyzer.enterScope();  // 进入全局作用域

    // 初始化systemFbFULib
    semanticAnalyzer.getCurrentSymbolTable()->initSystemFuncLib(SystemFuncLibPath);

    // 递归访问program_list
    for (auto program: ctx->program_list()) {
        visit(program);
    }

    std::cout << "Exiting Global Scope" << std::endl;
    semanticAnalyzer.exitScope();  // 退出全局作用域

//    std::cout << "打印符号表："<< std::endl;
//    symbolTable.print();      // 打印符号表
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitProgram_list(STParser::Program_listContext *ctx) {
    if(ctx->programDecl()){
        visit(ctx->programDecl());
    } else if (ctx->functionDecl()) {
        visit(ctx->functionDecl());
    } else if (ctx->functionBlockDecl()) {
        visit(ctx->functionBlockDecl());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitProgramDecl(STParser::ProgramDeclContext *ctx) {
    // 程序名
    if (ctx->PROGRAM()) {
        std::string progName = ctx->IDENT()->getText();
        std::transform(progName.begin(), progName.end(), progName.begin(), ::toupper);

        std::cout << "Entering Program Scope: " << progName << std::endl;
        semanticAnalyzer.enterScope();  // 进入程序作用域

        if (!semanticAnalyzer.declareProgram(progName)) {
            std::cerr << "Error: Failed to declare program '" << progName << "'." << std::endl;
            return nullptr;
        }

        // 变量声明
        if (ctx->interfaceSection()) {
            visit(ctx->interfaceSection());
        }

        // 程序段
        if (ctx->bodySection()) {
            visit(ctx->bodySection());
        }

        std::cout << "Exiting Program Scope: " << progName << std::endl;
        semanticAnalyzer.exitScope();  // 退出程序作用域
    }
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
    if (ctx->assignStmt()) {
        visit(ctx->assignStmt());
    } else if (ctx->selectStmt()) {
        visit(ctx->selectStmt());
    } else if (ctx->iterationStmt()) {
        visit(ctx->iterationStmt());
    } else if (ctx->callFuncStmt()) {
        visit(ctx->callFuncStmt());
    } else if (ctx->jumpStmt()) {
        visit(ctx->jumpStmt());
    }
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitSelectStmt(STParser::SelectStmtContext *ctx) {
    std::cout << "Visiting SelectStmt:" << std::endl;

    if(ctx->ifStmt()) {
        visit(ctx->ifStmt());
    } else if (ctx->caseStmt()) {
        visit(ctx->caseStmt());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitIterationStmt(STParser::IterationStmtContext *ctx) {
    std::cout << "Visiting IterationStmt:" << std::endl;

    if (ctx->whileStmt()) {
        visit(ctx->whileStmt());
    } else if (ctx->forStmt()) {
        visit(ctx->forStmt());
    } else if (ctx->repeatStmt()) {
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
        funcName = ctx->getText();
    }
    std::transform(funcName.begin(), funcName.end(), funcName.begin(), ::toupper);

    if (!semanticAnalyzer.checkFunctionCall(funcName) && !semanticAnalyzer.checkFunctionBlockMethodCall(funcName))  {
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
    SymbolEntry* entry;
    if (ctx->prefixExpr()) {
        leftValue = ctx->prefixExpr()->getText();
        std::cout << "Left Value of AssignStmt is:" << leftValue << std::endl;

        // 查找符号
        std::transform(leftValue.begin(), leftValue.end(), leftValue.begin(), ::toupper);

        if (!semanticAnalyzer.checkVariableUsage(leftValue)) {
            std::cerr << "Error: Undefined variable: " << leftValue << std::endl;
        } else {
            entry = semanticAnalyzer.getsymbolEntryInScope(leftValue);
            std::cout << "nulll" << entry->name << entry->dataType<< std::endl;
        }
    }

    if (ctx->expr()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->expr()->getText() << std::endl;
        visit(ctx->expr());
    } else if (ctx->callFuncStmt()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->callFuncStmt()->getText() << std::endl;
        // 校验fu的返回值类型是否正确
        std::string dataType = entry->dataType;
        std::string funcName = ctx->callFuncStmt()->IDENT()->getText();
        std::transform(funcName.begin(), funcName.end(), funcName.begin(), ::toupper);
        if (!semanticAnalyzer.checkFunctionReturnType(funcName, dataType)) {
            std::cerr << dataType << "不是" << funcName << "支持的输出类型！" << std::endl;
        }

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
    if (!ctx)
        return nullptr;
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
    if (!ctx)
        return nullptr;
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
    if (!ctx)
        return nullptr;
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
    if (!ctx)
        return nullptr;
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
    if (!ctx)
        return nullptr;
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
    if (!ctx)
        return nullptr;
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
    if (!ctx)
        return nullptr;
    std::cout  << "Visiting UnaryExpr:" << std::endl;

    if (ctx->PREFIX_OP()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;
    }

    if (ctx->primary()) {
        visit(ctx->primary());
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitPrimary(STParser::PrimaryContext *ctx) {
    std::cout  << "Visiting Primary:" << std::endl;
    if(ctx->expr()) {
        visit(ctx->expr());
    } else if (ctx->IDENT()) {
        std::string identifier = ctx->IDENT()->getText();
        std::cout << "identifier is: " << identifier << std::endl;
    } else if (ctx->NUMBER()) {
        std::string number = ctx->NUMBER()->getText();
    } else if (ctx->STRING_LITERAL()) {

    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitIfStmt(STParser::IfStmtContext *ctx) {

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
            auto stat_size = ctx->statement_list().size();
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
    if (!ctx)
        return nullptr;
    std::cout << "Visiting FuncParams:" << std::endl;

    for (auto paramCtx : ctx->funcParam()) {
        visit(paramCtx);
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFuncParam(STParser::FuncParamContext *ctx) {
    if (!ctx)
        return nullptr;
    if (ctx->ARROW()) {
        // 输出引脚
        std::string outputPin = ctx->IDENT()->getText();
        std::string mappedValue = ctx->ident()->getText();

        std::transform(mappedValue.begin(), mappedValue.end(), mappedValue.begin(), ::toupper);
        if (!semanticAnalyzer.checkVariableUsage(mappedValue)) {
            std::cerr << "Error: Undefined variable " << mappedValue << std::endl;
            return nullptr;
        }
    } else if (ctx->ASSIGN()) {
        // 输入引脚
        std::string inputPin = ctx->IDENT()->getText();

        visit(ctx->expr());
        std::cout << "输入引脚有" << ctx->expr()->getText() << std::endl;
        if (!semanticAnalyzer.checkVariableUsage(ctx->expr()->getText())) {
            std::cerr << "Error: Undefined variable " << ctx->expr()->getText() << std::endl;
            return nullptr;
        }
        visit(ctx->expr());
    } else {
        visit(ctx->expr());
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

    std::string dataType;
    if (ctx->type()) {
        dataType = ctx->type()->getText(); // 基本类型
        visit(ctx->type());
    } else if (ctx->arrayType()) {
        dataType = "ARRAY";
        visit(ctx->arrayType());
    } else if (ctx->structType()) {
        dataType = "STRUCT";
        visit(ctx->structType());
    }

    std::transform(varName.begin(), varName.end(), varName.begin(), ::toupper);
    std::cout << "变量声明" << varName << std::endl;
    if (!semanticAnalyzer.declareVariable(varName, dataType)) {
        std::cerr << "Error: Variable '" << varName << "' is already declared in this scope!" << std::endl;
        return nullptr;
    }
    symbolTable.print();
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
    std::string functionName = ctx->IDENT()->getText();
    std::transform(functionName.begin(), functionName.end(), functionName.begin(), ::toupper);

    std::cout << "Entering Function Scope: " << functionName << std::endl;
    semanticAnalyzer.enterScope();  // 进入函数作用域

    std::string returnType = ctx->type()->getText();
    visit(ctx->type());

    std::cout << "函数声明" << functionName << returnType << std::endl;
    if (!semanticAnalyzer.declareFunction(functionName, returnType)) {
        std::cerr << "Error: Function '" << functionName << "' is already declared!" << std::endl;
        return nullptr;
    }


    if (ctx->interfaceSection()) {
        visit(ctx->interfaceSection());
    }

   if (ctx->bodySection()) {
       visit(ctx->bodySection());
   }

    std::cout << "Exiting Function Block Scope: " << functionName << std::endl;
    semanticAnalyzer.exitScope();
    return nullptr;
}

antlrcpp::Any newSTVisitor::visitFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) {
    std::string functionBlockName = ctx->IDENT()->getText();
    std::transform(functionBlockName.begin(), functionBlockName.end(), functionBlockName.begin(), ::toupper);

    std::cout << "Entering Function Block Scope: " << functionBlockName << std::endl;
    semanticAnalyzer.enterScope();

    std::cout << "FB声明" << functionBlockName << std::endl;
    if (!semanticAnalyzer.declareFunctionBlock(functionBlockName)) {
        std::cerr << "Error: Function Block '" << functionBlockName << "' is already declared!" << std::endl;
        return nullptr;
    }

    if (ctx->interfaceSection()) {
        visit(ctx->interfaceSection());
    }

    if (ctx->bodySection()) {
        visit(ctx->bodySection());
    }

    std::cout << "Exiting Function Block Scope: " << functionBlockName << std::endl;
    semanticAnalyzer.exitScope();  // 退出功能块作用域
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
    if (!semanticAnalyzer.declareFunction(methodName, ctx->type()->getText())){
        std::cerr << "Error: Failed to declare method " <<  methodName <<  "." << std::endl;
    }

    if (ctx->interfaceSection()) {
        visit(ctx->interfaceSection());
    }

    visit(ctx->bodySection());
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