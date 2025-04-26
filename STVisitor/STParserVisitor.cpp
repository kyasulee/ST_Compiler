// STParserVisitor.cpp

#include "STParserVisitor.h"
#include "STParser.h"
#include "SemanticAnalyzer.h"
#include "IRNode.h"

#include <iostream>
#include <algorithm>
#include <cctype>

const std::string SystemFuncLibPath = "/root/codes/llvm/st_builder/Standard_fbfu.json";

// 构造函数
newSTVisitor::newSTVisitor() : symbolTable(), semanticAnalyzer() {}

antlrcpp::Any newSTVisitor::visitStartpoint(STParser::StartpointContext *ctx) {
    auto globalScope = std::make_shared<GlobalScopeNode>();

    std::cout << "Entering Global Scope" << std::endl;
    semanticAnalyzer.enterScope();  // 进入全局作用域

    // 初始化systemFbFULib
    semanticAnalyzer.getCurrentSymbolTable()->initSystemFuncLib(SystemFuncLibPath);

    // 递归访问program_list
    for (auto program: ctx->program_list()) {
        auto programNode = visit(program);
        if (programNode.is<std::shared_ptr<IRNode>>()) {
            globalScope->statements.push_back(programNode.as<std::shared_ptr<IRNode>>());
        }
    }

    std::cout << "Exiting Global Scope" << std::endl;
    semanticAnalyzer.exitScope();  // 退出全局作用域

    return globalScope;
}

antlrcpp::Any newSTVisitor::visitProgram_list(STParser::Program_listContext *ctx) {
    std::cout << "Visiting Program_list: " << ctx->getText() <<std::endl;
    if(ctx->programDecl()){
       return visit(ctx->programDecl());
    }
    if (ctx->functionDecl()) {
        return visit(ctx->functionDecl());
    }
    if (ctx->functionBlockDecl()) {
        return visit(ctx->functionBlockDecl());
    }

    // 返回空的BlockScope节点作为默认情
    return std::make_shared<BlockScopeNode>();
}

antlrcpp::Any newSTVisitor::visitProgramDecl(STParser::ProgramDeclContext *ctx) {
    if (!ctx->PROGRAM()) {
        return std::make_shared<BlockScopeNode>();
    }

    std::string progName = ctx->IDENT()->getText();
    std::transform(progName.begin(), progName.end(), progName.begin(), ::toupper);

    // 创建程序节点
    auto programNode = std::make_shared<ProgramNode>(progName);

    std::cout << "Entering Program Scope: " << progName << std::endl;
    semanticAnalyzer.enterScope();  // 进入程序作用域

    if (!semanticAnalyzer.declareProgram(progName)) {
        std::cerr << "Error: Failed to declare program '" << progName << "'." << std::endl;
        return programNode;  // 标记错误，同时返回节点
    }

    // 变量声明
    if (ctx->interfaceSection()) {
        auto interfaceNode = visit(ctx->interfaceSection());
        if (interfaceNode.is<std::shared_ptr<IRNode>>()) {
            programNode->declarations.push_back(interfaceNode.as<std::shared_ptr<IRNode>>());
        }
    }

    // 程序段
    if (ctx->bodySection()) {
        auto bodyNode = visit(ctx->bodySection());
        if (bodyNode.is<std::shared_ptr<IRNode>>()) {
            programNode->statements.push_back(bodyNode.as<std::shared_ptr<IRNode>>());
        }
    }

    std::cout << "Exiting Program Scope: " << progName << std::endl;
    semanticAnalyzer.exitScope();  // 退出程序作用域

    irList.push_back(programNode);

    return programNode;
}

antlrcpp::Any newSTVisitor::visitInterfaceSection(STParser::InterfaceSectionContext *ctx) {
    std::cout << "Visiting InterfaceSection:" << ctx->getText() << std::endl;

    auto interfaceBlock = std::make_shared<BlockScopeNode>();

    for (auto stmt : ctx->varDeclarationBlock()) {
        auto declNode = visitVarDeclarationBlock(stmt);
        if (declNode.isNotNull() && declNode.is<std::shared_ptr<IRNode>>()) {
            interfaceBlock->declarations.push_back(declNode.as<std::shared_ptr<IRNode>>());

            irList.push_back(declNode.as<std::shared_ptr<IRNode>>());
        } else {
            std::cerr << "Error: Invalid declaration in interface section" << std::endl;
            return interfaceBlock;
        }
    }

    return interfaceBlock;
}

antlrcpp::Any newSTVisitor::visitStatement_list(STParser::Statement_listContext *ctx) {
    auto stmtBlock = std::make_shared<BlockScopeNode>();

    if (ctx->assignStmt()) {
        auto assignNode = visit(ctx->assignStmt());
        if (assignNode.is<std::shared_ptr<IRNode>>()) {
            stmtBlock->statements.push_back(assignNode.as<std::shared_ptr<IRNode>>());
        }
    }
    else if (ctx->selectStmt()) {
        auto selectNode =visit(ctx->selectStmt());
        if (selectNode.is<std::shared_ptr<IRNode>>()) {
            stmtBlock->statements.push_back(selectNode.as<std::shared_ptr<IRNode>>());
        }
    }
    else if (ctx->iterationStmt()) {
        auto iterNode =visit(ctx->iterationStmt());
        if (iterNode.is<std::shared_ptr<IRNode>>()) {
            stmtBlock->statements.push_back(iterNode.as<std::shared_ptr<IRNode>>());
        }
    } else if (ctx->callFuncStmt()) {
        auto callFuncNode = visit(ctx->callFuncStmt());
        if (callFuncNode.is<std::shared_ptr<IRNode>>()) {
            stmtBlock->statements.push_back(callFuncNode.as<std::shared_ptr<IRNode>>());
        }
    } else if (ctx->jumpStmt()) {
        auto jumpNode = visit(ctx->jumpStmt());
        if (jumpNode.is<std::shared_ptr<IRNode>>()) {
            stmtBlock->statements.push_back(jumpNode.as<std::shared_ptr<IRNode>>());
        }
    }
    return stmtBlock;
}

antlrcpp::Any newSTVisitor::visitSelectStmt(STParser::SelectStmtContext *ctx) {
    if (!ctx) {
        auto invalidNode = std::make_shared<SelectionNode>(false);
        invalidNode->setInvalid();
        return invalidNode;
    }
    std::cout << "Visiting SelectStmt:" << ctx->getText()  << std::endl;

    if(ctx->ifStmt()) {
        auto ifNode = std::make_shared<SelectionNode>(false);

        auto ifContent = visitIfStmt(ctx->ifStmt());
        if (ifContent.is<std::shared_ptr<IRNode>>()) {
            ifNode->children.push_back(ifContent.as<std::shared_ptr<IRNode>>());
        } else {
            ifNode->setInvalid();
        }

        return ifNode;
    }
    else if (ctx->caseStmt()) {
        auto caseNode = std::make_shared<SelectionNode>(true);

        auto caseContent = visitCaseStmt(ctx->caseStmt());
        if (caseContent.is<std::shared_ptr<IRNode>>()) {
            caseNode->children.push_back(caseContent.as<std::shared_ptr<IRNode>>());
        } else {
            caseNode->setInvalid();
        }
        return caseNode;
    }

    auto defaultNode = std::make_shared<SelectionNode>(false);
    defaultNode->setInvalid();
    return defaultNode;
}

antlrcpp::Any newSTVisitor::visitIterationStmt(STParser::IterationStmtContext *ctx) {
    if (!ctx) {
        auto invalidNode = std::make_shared<IterationNode>();
        invalidNode->setInvalid();
        return invalidNode;
    }

    std::cout << "Visiting IterationStmt:" << ctx->getText() << std::endl;

    if (ctx->whileStmt()) {
        auto whileNode = std::make_shared<IterationNode>(IterationType::WHILE);

        auto whileContent = visitWhileStmt(ctx->whileStmt());
        if (whileContent.is<std::shared_ptr<IRNode>>()) {
            whileNode->children.push_back(whileContent.as<std::shared_ptr<IRNode>>());
        } else {
            whileNode->setInvalid();
        }
        return whileNode;
    }
    else if (ctx->forStmt()) {
        auto forNode = std::make_shared<IterationNode>(IterationType::FOR);

        auto forContent = visitForStmt(ctx->forStmt());
        if (forContent.is<std::shared_ptr<IRNode>>()) {
            forNode->children.push_back(forContent.as<std::shared_ptr<IRNode>>());
        } else {
            forNode->setInvalid();
        }
        return forNode;
    }
    else if (ctx->repeatStmt()) {
        auto repeatNode = std::make_shared<IterationNode>(IterationType::REPEAT);

        auto repeatContent = visit(ctx->repeatStmt());
        if (repeatContent.is<std::shared_ptr<IRNode>>()) {
            repeatNode->children.push_back(repeatContent.as<std::shared_ptr<IRNode>>());
        } else {
            repeatNode->setInvalid();
        }
        return repeatNode;
    }

    auto iterationNode = std::make_shared<IterationNode>();
    iterationNode->setInvalid();
    return iterationNode;
}

antlrcpp::Any newSTVisitor::visitCallFuncStmt(STParser::CallFuncStmtContext *ctx) {
    std::cout << "Visiting CallFuncStmt:" << ctx->getText() << std::endl;

    std::string funcName;
    if (ctx->IDENT()) {
        funcName = ctx->IDENT()->getText();
    } else {
        funcName = ctx->getText();
    }
    std::transform(funcName.begin(), funcName.end(), funcName.begin(), ::toupper);

    // 检查函数是否已声明
    if (!semanticAnalyzer.checkFunctionCall(funcName) && !semanticAnalyzer.checkFunctionBlockMethodCall(funcName))  {
        std::cerr << "Error: Variable '" << funcName << "' is not declared!" << std::endl;
        return nullptr;
    }

    std::vector<std::shared_ptr<IRNode>> args;
    if (ctx->funcParams()) {
        std::cout << "now visiting funcParams" << std::endl;
        for (auto paramCtx : ctx->funcParams()->funcParam()) {
            auto paramNode = visitFuncParam(paramCtx);
            std::cout << "aaa========" << paramNode.is<std::shared_ptr<IRNode>>() << paramNode.isNotNull()<< std::endl;
            if (paramNode.is<std::shared_ptr<IRNode>>()) {
                args.push_back(paramNode.as<std::shared_ptr<IRNode>>());
            } else {
                std::cerr << "Error: Invalid parameter in function call" << std::endl;
            }
        }
    } else {
        std::cout << "there is no parameters provided" << std::endl;
    }

    auto callfuncNode = std::make_shared<CallFuncNode>(funcName, std::move(args));

    return callfuncNode;
}

antlrcpp::Any newSTVisitor::visitJumpStmt(STParser::JumpStmtContext *ctx) {
    if (!ctx) {
        return std::make_shared<BreakStmtNode>(); // 默认返回无效的break节点
    }
    std::cout << "Visiting JumpStmt:" << ctx->getText() << std::endl;

    if (ctx->BREAK()) {
        std::cout << "Found BREAK Statement" << std::endl;
        return std::make_shared<BreakStmtNode>();
    }
    if (ctx->RETURN()) {
        std::cout << "Found RETURN Statement" << std::endl;
        std::shared_ptr<IRNode> returnValue;

        if (ctx->expr()) {
            auto result = visitExpr(ctx->expr());
            if (result.is<std::shared_ptr<IRNode>>()) {
                returnValue = result.as<std::shared_ptr<IRNode>>();
            }
        }

        return std::make_shared<ReturnStmtNode>(returnValue);
    }

    if (ctx->getText() == "CONTINUE") {
        std::cout << "Found CONTINUE Statement" << std::endl;
        return std::make_shared<ContinueStmtNode>();
    }

    if (ctx->getText() == "EXIT") {
        std::cout << "Found EXIT Statement" << std::endl;
        return std::make_shared<ExitStmtNode>();
    }

    return std::make_shared<JumpStmtNode>();
}

antlrcpp::Any newSTVisitor::visitAssignStmt(STParser::AssignStmtContext *ctx) {
    std::cout << "Visiting AssignStmt:" << ctx->getText() << std::endl;

    if (!ctx->prefixExpr()) {
        return std::make_shared<AssignmentNode>(nullptr, nullptr); // 无效赋值
    }

    std::string leftValue = ctx->prefixExpr()->getText();
    std::cout << "Left Value of AssignStmt is:" << leftValue << std::endl;
    std::transform(leftValue.begin(), leftValue.end(), leftValue.begin(), ::toupper);

    SymbolEntry* entry = nullptr;
    if (!semanticAnalyzer.checkVariableUsage(leftValue)) {
        std::cerr << "Error: Undefined variable: " << leftValue << std::endl;
    } else {
        entry = semanticAnalyzer.getsymbolEntryInScope(leftValue);
        if (entry) {
            std::cout << "Symbol entry found - Name: " << entry->name
                      << ", Type: " << entry->dataType << std::endl;
        }
    }

    std::shared_ptr<IRNode> valueNode;
    if (ctx->expr()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->expr()->getText() << std::endl;;
        auto result = visitExpr(ctx->expr());
        if (result.is<std::shared_ptr<IRNode>>()) {
            valueNode = result.as<std::shared_ptr<IRNode>>();
        } else {
            std::cerr << "1Error: Invalid type returned from visitVarDeclaration" << std::endl;
        }
    }
    else if (ctx->callFuncStmt()) {
        std::cout << "Right Value of AssignStmt is:" << ctx->callFuncStmt()->getText() << std::endl;
        auto result = visitCallFuncStmt(ctx->callFuncStmt());
        if (result.is<std::shared_ptr<IRNode>>()) {
            valueNode = result.as<std::shared_ptr<IRNode>>();

            // 校验fu的返回值类型是否正确
            std::string dataType = entry->dataType;
            std::string funcName = ctx->callFuncStmt()->IDENT()->getText();
            std::transform(funcName.begin(), funcName.end(), funcName.begin(), ::toupper);
            if (!semanticAnalyzer.checkFunctionReturnType(funcName, dataType)) {
                std::cerr << dataType << "不是" << funcName << "支持的输出类型！" << std::endl;
            }
        }
    }

    auto assignmentNode = std::make_shared<AssignmentNode>(std::make_shared<IdentifierNode>(leftValue), valueNode);

    return assignmentNode;
}

antlrcpp::Any newSTVisitor::visitPrefixExpr(STParser::PrefixExprContext *ctx) {
    if (!ctx || !ctx->ident()) {
        return std::make_shared<IdentifierNode>(""); // 返回无效标识符节点
    }
    std::cout << "Visiting PrefixExpr:" << ctx->getText() << std::endl;

    auto identResult = visit(ctx->ident());
    if (identResult.is<std::shared_ptr<IRNode>>()) {
        return identResult;
    }

    return std::make_shared<IdentifierNode>("");
}

antlrcpp::Any newSTVisitor::visitExpr(STParser::ExprContext *ctx) {
    if (!ctx)
        return std::make_shared<ConstantNode>("0", "INT");
    std::cout << "Visiting Expr:" << ctx->getText() << std::endl;

    if (ctx->orExpr()) {
        auto orResult = visitOrExpr(ctx->orExpr());
        if (orResult.is<std::shared_ptr<IRNode>>()) {
            return orResult;
        }
    }

    return std::make_shared<ConstantNode>("0", "INT"); // 默认返回0
}

antlrcpp::Any newSTVisitor::visitOrExpr(STParser::OrExprContext *ctx) {
    if (!ctx)
        return std::make_shared<ConstantNode>("false", "BOOL");

    std::cout  << "Visiting OrExpr:" << std::endl;

    if (ctx->orExpr() && ctx->andExpr()) {
        std::string op = ctx->getText();
        std::cout << "operator is:" << op << std::endl;

        auto left = visitOrExpr(ctx->orExpr());
        auto right = visitAndExpr(ctx->andExpr());

        if (left.is<std::shared_ptr<IRNode>>() && right.is<std::shared_ptr<IRNode>>()) {
            auto leftNode = left.as<std::shared_ptr<IRNode>>();
            auto rightNode = right.as<std::shared_ptr<IRNode>>();

            return std::make_shared<BinaryOpNode>(leftNode, op, rightNode);
        } else {
            std::cerr << "Error: Invalid operands in OR expression" << std::endl;
        }
    }

    auto AndExprNode = visitAndExpr(ctx->andExpr());
    return AndExprNode;
}

antlrcpp::Any newSTVisitor::visitAndExpr(STParser::AndExprContext *ctx) {
    if (!ctx)
        return std::make_shared<ConstantNode>("false", "BOOL");
    std::cout  << "Visiting AddExpr:" << ctx->getText() << std::endl;

    // 单操作数
    if (!ctx->andExpr()) {
        return visit(ctx->equalExpr());
    }

    // AND运算
    auto leftOperand = visit(ctx->andExpr());
    auto rightOperand = visit(ctx->equalExpr());

    if (!leftOperand.is<std::shared_ptr<IRNode>>() || !rightOperand.is<std::shared_ptr<IRNode>>()) {
        return std::make_shared<ConstantNode>("false", "BOOL");
    }

    auto leftNode = leftOperand.as<std::shared_ptr<IRNode>>();
    auto rightNode = rightOperand.as<std::shared_ptr<IRNode>>();

    return std::make_shared<BinaryOpNode>(leftNode, "AND", rightNode);;
}

antlrcpp::Any newSTVisitor::visitEqualExpr(STParser::EqualExprContext *ctx) {
    if (!ctx) {
        return std::make_shared<ConstantNode>("false", "BOOL");
    }
    std::cout  << "Visiting EqualExpr:" << ctx->getText() << std::endl;

    if (!ctx->equalExpr()) {
        return visit(ctx->relationExpr());
    }

    std::string op;
    if (ctx->EQ()) {
        op = "=";
    } else if (ctx->NEQ()) {
        op = "!=";
    } else {
        std::cerr << "Error: Unknown equality operator at line "
                  << ctx->getStart()->getLine() << std::endl;
        return std::make_shared<ConstantNode>("false", "BOOL");
    }

    auto left = visit(ctx->equalExpr());
    auto right = visit(ctx->relationExpr());

    if (left.is<std::shared_ptr<IRNode>>() && right.is<std::shared_ptr<IRNode>>()) {
        return std::make_shared<BinaryOpNode>(
                left.as<std::shared_ptr<IRNode>>(),
                op,
                right.as<std::shared_ptr<IRNode>>());
    }

    return std::make_shared<ConstantNode>("false", "BOOL");;
}

antlrcpp::Any newSTVisitor::visitRelationExpr(STParser::RelationExprContext *ctx) {
    if (!ctx) {
        return std::make_shared<ConstantNode>("false", "BOOL");
    }
    std::cout  << "Visiting RelationExpr:" << ctx->getText() << std::endl;

    if (!ctx->relationExpr()) {
        return visit(ctx->addExpr());
    }

    std::string op;
    if (ctx->GT()) op = ">";
    else if (ctx->GTE()) op = ">=";
    else if (ctx->LT())   op = "<";
    else if (ctx->LTE())  op = "<=";
    else {
        std::cerr << "Error: Unknown relational operator at line "
                  << ctx->getStart()->getLine() << std::endl;
        return std::make_shared<ConstantNode>("false", "BOOL");
    }

    auto left = visit(ctx->relationExpr());
    auto right = visit(ctx->addExpr());
    if (left.is<std::shared_ptr<IRNode>>() && right.is<std::shared_ptr<IRNode>>()) {
        return std::make_shared<BinaryOpNode>(
                left.as<std::shared_ptr<IRNode>>(),
                op,
                right.as<std::shared_ptr<IRNode>>()
        );
    }

    return std::make_shared<ConstantNode>("false", "BOOL");
}

antlrcpp::Any newSTVisitor::visitAddExpr(STParser::AddExprContext *ctx) {
    if (!ctx) {
        return std::make_shared<ConstantNode>("false", "BOOL");
    }
    std::cout  << "Visiting AddExpr:" << ctx->getText() << std::endl;

    if (!ctx->addExpr()){
        return visit(ctx->multipliExpr());
    }

    std::string op;
    if (ctx->ADD()) op = "+";
    else if (ctx->SUB())  op = '-';

    auto left = visit(ctx->addExpr());
    auto right = visit(ctx->multipliExpr());
    if (left.is<std::shared_ptr<IRNode>>() && right.is<std::shared_ptr<IRNode>>()) {
        return std::make_shared<BinaryOpNode>(
                left.as<std::shared_ptr<IRNode>>(),
                op,
                right.as<std::shared_ptr<IRNode>>());
    }

    return std::make_shared<ConstantNode>("0", "INT");
}

antlrcpp::Any newSTVisitor::visitMultipliExpr(STParser::MultipliExprContext *ctx) {
    if (!ctx) {
        return std::make_shared<ConstantNode>("0", "INT");
    }
    std::cout  << "Visiting MultipliExpr:" << ctx->getText() << std::endl;

    if (!ctx->multipliExpr()) {
        return visit(ctx->unaryExpr());
    }

    std::string op;
    if (ctx->MUL()) op = "*";
    else if (ctx->DIV()) op = "/";
    else if (ctx->EXP()) op = "**";
    else if (ctx->MOD()) op = "MOD";
    else if (ctx->SHL()) op = "SHL";
    else if (ctx->SHR()) op = "SHR";

    auto left = visit(ctx->multipliExpr());
    auto right = visit(ctx->unaryExpr());

    if (left.is<std::shared_ptr<IRNode>>() && right.is<std::shared_ptr<IRNode>>()) {
        return std::make_shared<BinaryOpNode>(
                left.as<std::shared_ptr<IRNode>>(),
                op,
                right.as<std::shared_ptr<IRNode>>()
        );
    }

    return std::make_shared<ConstantNode>("0", "INT");
}

antlrcpp::Any newSTVisitor::visitUnaryExpr(STParser::UnaryExprContext *ctx) {
    if (!ctx) {
        return std::make_shared<ConstantNode>("0", "INT");
    }
    std::cout  << "Visiting UnaryExpr:" << ctx->getText() << std::endl;

    if (ctx->PREFIX_OP()) {
        std::string op = ctx->PREFIX_OP()->getText();

        auto operand = visit(ctx->primary());
        if (operand.is<std::shared_ptr<IRNode>>()) {
            return std::make_shared<UnaryOpNode>(
                    op,
                    operand.as<std::shared_ptr<IRNode>>());
        }
    }

    return visit(ctx->primary());
}

antlrcpp::Any newSTVisitor::visitPrimary(STParser::PrimaryContext *ctx) {
    std::cout  << "Visiting Primary:" << ctx->getText() << std::endl;
    if(ctx->expr()) {
        visitExpr(ctx->expr());
    } else if (ctx->IDENT()) {
        std::string identifier = ctx->IDENT()->getText();
        return std::make_shared<IdentifierNode>(identifier);
    } else if (ctx->NUMBER()) {
        std::string number = ctx->NUMBER()->getText();
        return std::make_shared<ConstantNode>(number, "Literal");
    } else if (ctx->STRING_LITERAL()) {
        std::string str = ctx->STRING_LITERAL()->getText();
        return std::make_shared<ConstantNode>(str, "String");
    }

    return nullptr;
}

antlrcpp::Any newSTVisitor::visitIfStmt(STParser::IfStmtContext *ctx) {
    if (!ctx || !ctx->IF()) {
        return std::make_shared<IfStmtNode>();
    }
    std::cout << "Processing IF statement at line " << ctx->getStart()->getLine() << std::endl;

    std::shared_ptr<IRNode> conditionNode;
    if (ctx->expr(0)) {
        auto condResult = visit(ctx->expr(0));
        if (condResult.is<std::shared_ptr<IRNode>>()) {
            conditionNode = condResult.as<std::shared_ptr<IRNode>>();
        } else {
            std::cerr << "Error: Invalid condition expression in IF statement" << std::endl;
            conditionNode = std::make_shared<ConstantNode>("false", "BOOL");
        }
    } else {
        std::cerr << "Warning: Missing condition in IF statement" << std::endl;
        conditionNode = std::make_shared<ConstantNode>("false", "BOOL");
    }

    std::vector<std::shared_ptr<IRNode>> thenStmts;
    for (auto stmt : ctx->statement_list()) {
        auto stmtResult = visit(stmt);
        if (stmtResult.is<std::shared_ptr<IRNode>>()) {
            thenStmts.push_back(stmtResult.as<std::shared_ptr<IRNode>>());
        }
    }

    std::vector<std::shared_ptr<IRNode>> elseStatements;
    for (auto i = 1; i <= ctx->ELSEIF().size(); i++) {
        auto elseifCond = visit(ctx->expr(i));
        auto elseifBlock = visit(ctx->statement_list(i));

        if (elseifCond.is<std::shared_ptr<IRNode>>() && elseifBlock.is<std::shared_ptr<IRNode>>()) {
            auto cond = elseifCond.as<std::shared_ptr<IRNode>>();
            auto block = elseifBlock.as<std::shared_ptr<IRNode>>();
            // 将ELSEIF转换为嵌套的IF
            auto nestedIf = std::make_shared<IfStmtNode>(
                    cond,
                    std::vector<std::shared_ptr<IRNode>>{block},
                    elseStatements
            );
            elseStatements = {nestedIf};
        }
    }

    if (ctx->ELSE()) {
        size_t elseIndex = ctx->statement_list().size() - 1;
        auto elseResult = visit(ctx->statement_list(elseIndex));
        if (elseResult.is<std::shared_ptr<IRNode>>()) {
            elseStatements.push_back(elseResult.as<std::shared_ptr<IRNode>>());
        }
    }

    auto resultIfNode = std::make_shared<IfStmtNode>(conditionNode, thenStmts, elseStatements);
    return resultIfNode;
}

antlrcpp::Any newSTVisitor::visitCaseStmt(STParser::CaseStmtContext *ctx) {
    if (!ctx || !ctx->CASE()) {
        return std::make_shared<CaseStmtNode>();
    }
    std::cout  << "Visiting CaseStmt:" << ctx->getText() << std::endl;

    std::shared_ptr<IRNode> selectorNode;
    if (ctx->expr()) {
        std::cout << "Selector Expression:" << std::endl;
        auto selectorResult = visit(ctx->expr());
        if (selectorResult.is<std::shared_ptr<IRNode>>()) {
            selectorNode = selectorResult.as<std::shared_ptr<IRNode>>();
        } else {
            std::cerr << "Error: Invalid selector expression" << std::endl;
            selectorNode = std::make_shared<ConstantNode>("0", "INT");
        }
    } else {
        std::cerr << "Warning: Missing selector in CASE statement" << std::endl;
        selectorNode = std::make_shared<ConstantNode>("0", "INT");
    }

    // 处理分支列表
    std::vector<std::pair<std::vector<std::shared_ptr<IRNode>>,
            std::vector<std::shared_ptr<IRNode>>>> cases;
    std::vector<std::shared_ptr<IRNode>> defaultBranch;
    if (ctx->OF() && ctx->caseList()) {
        std::cout << "Processing Case List:" << std::endl;
        for (size_t i = 0; i < ctx->caseList()->caseValues().size(); i++) {
            auto caseValues = ctx->caseList()->caseValues(i);
            auto caseStmts = ctx->caseList();

            std::vector<std::shared_ptr<IRNode>> valueNodes;
            for (auto value : caseValues->expr()) {
                std::cout << "Case Value：" << value->getText() << std::endl;
                auto valueResult = visit(value);
                if (valueResult.is<std::shared_ptr<IRNode>>()) {
                    valueNodes.push_back(valueResult.as<std::shared_ptr<IRNode>>());
                }
            }

            std::vector<std::shared_ptr<IRNode>> stmtNodes;
            for (auto stmt : caseStmts->statement_list()) {
                auto stmtResult = visit(stmt);
                if (stmtResult.is<std::shared_ptr<IRNode>>()) {
                    stmtNodes.push_back(stmtResult.as<std::shared_ptr<IRNode>>());
                }
            }

            if (!valueNodes.empty()) {
                cases.emplace_back(std::move(valueNodes), std::move(stmtNodes));
            }
        }
    }

    // 检查是否存在 ELSE 分支
    if (ctx->ELSE()) {
        std::cout << "else branch:" << std::endl;
        size_t elseIndex = ctx->statement_list().size() - 1;
        for (auto stmt : ctx->statement_list()) {
            auto stmtResult = visit(stmt);
            if (stmtResult.is<std::shared_ptr<IRNode>>()) {
                defaultBranch.push_back(stmtResult.as<std::shared_ptr<IRNode>>());
            }
        }
    }
    auto resultCaseNode = std::make_shared<CaseStmtNode>(selectorNode,cases,defaultBranch);
    return resultCaseNode;
}

antlrcpp::Any newSTVisitor::visitCaseList(STParser::CaseListContext *ctx) {
    // 创建存储所有case对的vector
    std::vector<std::pair<std::vector<std::shared_ptr<IRNode>>, std::vector<std::shared_ptr<IRNode>>>> casePairs;
    if (!ctx) {
        return casePairs;
    }

    std::cout  << "Visiting CaseList:" << ctx->getText() << std::endl;

    for (size_t i = 0; i < ctx->caseValues().size(); i++) {
        // 处理case值
        std::cout << "case values:" << ctx-> caseValues(i) << std::endl;
        auto valueResult = visitCaseValues(ctx->caseValues(i));
        std::vector<std::shared_ptr<IRNode>> valueNode;
        if (valueResult.is<std::vector<std::shared_ptr<IRNode>>>()) {
            valueNode = valueResult.as<std::vector<std::shared_ptr<IRNode>>>();
        }

        // 处理语句块
        std::cout << "case Statements:" << ctx->statement_list(i) << std::endl;
        std::vector<std::shared_ptr<IRNode>> stmtNodes;
        if (i < ctx->statement_list().size()) {
            for (auto stmt : ctx->statement_list())  {
                auto stmtResult = visit(stmt);
                if (stmtResult.is<std::shared_ptr<IRNode>>()) {
                    stmtNodes.push_back(stmtResult.as<std::shared_ptr<IRNode>>());
                }
            }
        }

       if (!valueNode.empty()) {
           casePairs.emplace_back(std::move(valueNode), std::move(stmtNodes));
       }
    }
    return casePairs;
}

antlrcpp::Any newSTVisitor::visitCaseValues(STParser::CaseValuesContext *ctx) {
    std::vector<std::shared_ptr<IRNode>> valueNodes;

    if (!ctx) {
        return valueNodes;
    }

    std::cout  << "Visiting CaseValues:" << ctx->getText() << std::endl;

    for (auto value : ctx->expr()) {
        std::cout << "value is:" << value->getText() << std::endl;
        auto valueResult = visit(value);
        if (valueResult.is<std::shared_ptr<IRNode>>()) {
            valueNodes.push_back(valueResult.as<std::shared_ptr<IRNode>>());
        } else {
            std::cerr << "Error: Invalid case value expression" << std::endl;
        }
    }

    return valueNodes;
}

antlrcpp::Any newSTVisitor::visitForStmt(STParser::ForStmtContext *ctx) {
    if (!ctx || !ctx->FOR()) {
        std::cerr << "Error: Invalid FOR statement" << std::endl;
        return std::make_shared<ForStmtNode>(
                nullptr, nullptr, nullptr, std::vector<std::shared_ptr<IRNode>>()
        );
    }
    std::cout << "Visiting ForStmt:" << ctx->getText() << std::endl;

    // 初始化语句
    std::shared_ptr<IRNode> initNode = nullptr;
    if (ctx->assignStmt()) {
        auto initResult = visit(ctx->assignStmt());
        if (initResult.is<std::shared_ptr<IRNode>>()) {
            initNode = initResult.as<std::shared_ptr<IRNode>>();
        }
    }

    // 终止条件
    std::shared_ptr<IRNode> endNode = nullptr;
    if (ctx->expr(0)) {
        auto endResult = visit(ctx->expr(0));
        if (endResult.is<std::shared_ptr<IRNode>>()) {
            endNode = endResult.as<std::shared_ptr<IRNode>>();
        }
    }

    // 步长
    std::shared_ptr<IRNode> stepNode = nullptr;
    if (ctx->BY() && ctx->expr().size() > 1) {
        auto stepResult = visit(ctx->expr(1));
        if (stepResult.is<std::shared_ptr<IRNode>>()) {
            stepNode = stepResult.as<std::shared_ptr<IRNode>>();
        }
    } else {
        // 默认步长为1
        stepNode = std::make_shared<ConstantNode>("1", "INT");
    }

    // 循环体
    std::vector<std::shared_ptr<IRNode>> bodyNodes;
    for (auto stmt : ctx->statement_list()) {
        auto stmtResult = visit(stmt);
        if (stmtResult.is<std::shared_ptr<IRNode>>()) {
            bodyNodes.push_back(stmtResult.as<std::shared_ptr<IRNode>>());
        }
    }

    auto forNode = std::make_shared<ForStmtNode>(
            initNode,
            endNode,
            stepNode,
            std::move(bodyNodes));
    return forNode;
}

antlrcpp::Any newSTVisitor::visitWhileStmt(STParser::WhileStmtContext *ctx) {
    if (!ctx || !ctx->WHILE()) {
        return std::make_shared<WhileStmtNode>(nullptr, std::vector<std::shared_ptr<IRNode>>());
    }

    // 条件表达式
    std::shared_ptr<IRNode> condition = nullptr;
    if (ctx->expr()) {
        auto condResult = visit(ctx->expr());
        if (condResult.is<std::shared_ptr<IRNode>>()) {
            condition = condResult.as<std::shared_ptr<IRNode>>();
        }
    }

    // 循环体
    std::vector<std::shared_ptr<IRNode>> body;
    for (auto stmt : ctx->statement_list()) {
        auto stmtResult = visit(stmt);
        if (stmtResult.is<std::shared_ptr<IRNode>>()) {
            body.push_back(stmtResult.as<std::shared_ptr<IRNode>>());
        }
    }

    auto whileNode = std::make_shared<WhileStmtNode>(condition, std::move(body));
    return whileNode;
}

antlrcpp::Any newSTVisitor::visitRepeatStmt(STParser::RepeatStmtContext *ctx) {
    if (!ctx || !ctx->REPEAT()) {
        return std::make_shared<RepeatStmtNode>(std::vector<std::shared_ptr<IRNode>>(), nullptr);
    }
    std::cout << "Visiting RepeatStmt" << ctx->getText() << std::endl;

    // 循环体
    std::vector<std::shared_ptr<IRNode>> body;
    for (auto stmt : ctx->statement_list()) {
        auto stmtResult = visit(stmt);
        if (stmtResult.is<std::shared_ptr<IRNode>>()) {
            body.push_back(stmtResult.as<std::shared_ptr<IRNode>>());
        }
    }

    // 终止条件
    std::shared_ptr<IRNode> condition = nullptr;
    if (ctx->expr()) {
        auto condResult = visit(ctx->expr());
        if (condResult.is<std::shared_ptr<IRNode>>()) {
            condition = condResult.as<std::shared_ptr<IRNode>>();
        }
    }

    auto repeatNode = std::make_shared<RepeatStmtNode>(std::move(body), condition);
    return repeatNode;
}

antlrcpp::Any newSTVisitor::visitType(STParser::TypeContext *ctx) {
    if (!ctx) {
        return std::string("UNKNOWN");
    }

    if (ctx->basicType()) {
        return visit(ctx->basicType());
    } else if (ctx->arrayType()) {
        visit(ctx->arrayType());
    } else if (ctx->structType()) {
        visit(ctx->structType());
    } else if (ctx->enumeratedType()) {
        visit(ctx->enumeratedType());
    } else if (ctx->subrangeType()) {
        visit(ctx->subrangeType());
    } else if (ctx->IDENT()) {
        std::string typeName = ctx->IDENT()->getText();
        std::transform(typeName.begin(), typeName.end(), typeName.begin(), ::toupper);

        return typeName;
    }
    return std::string("UNKNOWN");
}

antlrcpp::Any newSTVisitor::visitFuncParams(STParser::FuncParamsContext *ctx) {
    if (!ctx)
        return std::make_shared<ParamsNode>("INVALID", "UNKNOWN");
    std::cout << "Visiting FuncParams:" << ctx->getText() << std::endl;

    std::vector<std::shared_ptr<ParamsNode>> params;

    for (auto paramCtx : ctx->funcParam()) {
        auto paramsResult = visit(paramCtx);
        if (paramsResult.is<std::shared_ptr<ParamsNode>>()) {
            params.push_back(paramsResult.as<std::shared_ptr<ParamsNode>>());
        }
    }

    return params;
}

antlrcpp::Any newSTVisitor::visitFuncParam(STParser::FuncParamContext *ctx) {
    if (!ctx)
        return std::make_shared<ParamsNode>("INVALID", "UNKNOWN");

    auto paramNode = std::make_shared<ParamsNode>();

    if (ctx->ARROW()) {
        // 输出引脚
        std::string outputPin = ctx->IDENT()->getText();
        std::transform(outputPin.begin(), outputPin.end(), outputPin.begin(), ::toupper);
        std::string mappedValue = ctx->ident()->getText();
        std::transform(mappedValue.begin(), mappedValue.end(), mappedValue.begin(), ::toupper);

        paramNode->name = outputPin;
        paramNode->refName = mappedValue;
        paramNode->paramType = "VAR_OUTPUT";

        if (!semanticAnalyzer.checkVariableUsage(mappedValue)) {
            std::cerr << "Error: Undefined variable " << mappedValue << std::endl;
            return nullptr;
        }
    } else if (ctx->ASSIGN()) {
        // 输入引脚
        std::string inputPin = ctx->IDENT()->getText();
        std::transform(inputPin.begin(), inputPin.end(), inputPin.begin(), ::toupper);

        auto exprNode = visitExpr(ctx->expr());

        if (!semanticAnalyzer.checkVariableUsage(ctx->expr()->getText())) {
            std::cerr << "Error: Undefined variable " << ctx->expr()->getText() << std::endl;
            return nullptr;
        }

        paramNode->name = inputPin;
        paramNode->paramType = "VAR_INPUT";

        if (exprNode.is<std::shared_ptr<IRNode>>()) {
            paramNode->defaultValue = exprNode.as<std::shared_ptr<IRNode>>();
        }
    } else if (ctx->expr()) {
        auto exprResult = visit(ctx->expr());
        paramNode->paramType = "EXPRESSION";

        if (exprResult.is<std::shared_ptr<IRNode>>()) {
            paramNode->exprValue = exprResult.as<std::shared_ptr<IRNode>>();
        }
    } else {
        paramNode->name = "UNKNOWN_PARAM";
        paramNode->paramType = "UNKNOWN";
    }

    return paramNode;
}

antlrcpp::Any newSTVisitor::visitIdenti(STParser::IdentiContext *ctx) {
    if (!ctx || !ctx->IDENT()) {
        return std::make_shared<IdentifierNode>("");
    }

    std::string id = ctx->IDENT()->getText();
    std::transform(id.begin(), id.end(), id.begin(), ::toupper);
    std::cout << "Processing identifier: " << id << std::endl;

    // 符号表检查
    if (!semanticAnalyzer.checkVariableUsage(id)) {
        std::cerr << "Error: Undefined variable '" << id << "' at line "
                  << ctx->getStart()->getLine() << std::endl;
    }

    return std::make_shared<IdentifierNode>(id);
}

antlrcpp::Any newSTVisitor::visitArray(STParser::ArrayContext *ctx) {
    if (!ctx || !ctx->IDENT()) {
        return std::make_shared<IdentifierNode>("");
    }

    std::string arrayName = ctx->IDENT()->getText();
    std::transform(arrayName.begin(), arrayName.end(), arrayName.begin(), ::toupper);
    std::cout << "arrayName is:" << arrayName << std::endl;

    std::vector<std::shared_ptr<IRNode>> indices; // 索引
    for (auto idxExpr : ctx->expr()) {
        auto indexRes = visitExpr(idxExpr);
        if (indexRes.is<std::shared_ptr<IRNode>>()) {
            indices.push_back(indexRes.as<std::shared_ptr<IRNode>>());
        }
    }

    // 符号表检查
    if (!semanticAnalyzer.checkVariableUsage(arrayName)) {
        std::cerr << "Error: Undefined array '" << arrayName << "' at line "
                  << ctx->getStart()->getLine() << std::endl;
    }

    return std::make_shared<ArrayAccessNode>(std::make_shared<IdentifierNode>(arrayName), std::move(indices));
}

antlrcpp::Any newSTVisitor::visitStruct(STParser::StructContext *ctx) {
    if (!ctx || ctx->ident().size() != 2) {
        return std::make_shared<IdentifierNode>("");
    }

    // 结构体
    auto structRes = visit(ctx->ident(0));
    if (!structRes.is<std::shared_ptr<IRNode>>()) {
        return std::make_shared<IdentifierNode>("");
    }

    // 成员
    auto memberRes = visit(ctx->ident(1));
    if (!memberRes.is<std::shared_ptr<IRNode>>()) {
        return std::make_shared<IdentifierNode>("");
    }

    std::string memberName = ctx->ident(1)->getText();
    std::transform(memberName.begin(), memberName.end(), memberName.begin(), ::toupper);

    return std::make_shared<StructAccessNode>(structRes.as<std::shared_ptr<IRNode>>(), memberName);
}

antlrcpp::Any newSTVisitor::visitDeclarationStmt(STParser::DeclarationStmtContext *ctx) {
    if (!ctx) {
        return std::make_shared<VariableDeclarationNode>("", "");
    }
    std::cout << "Visiting DeclarationStmt" << ctx->getText() << std::endl;

    // 变量声明块
    if(ctx->varDeclarationBlock()) {
        auto blockRes = visitVarDeclarationBlock(ctx->varDeclarationBlock());
        if (blockRes.is<std::shared_ptr<IRNode>>()) {
            return blockRes;
        }
    }

    // 单个变量声明
    if (ctx->varDeclaration()) {
        auto declRes = visitVarDeclaration(ctx->varDeclaration());
        if (declRes.is<std::shared_ptr<IRNode>>()) {
            return declRes;
        }
    }

    return std::make_shared<VariableDeclarationNode>("", "");
}

antlrcpp::Any newSTVisitor::visitVarDeclarationBlock(STParser::VarDeclarationBlockContext *ctx) {
    if (!ctx) {
        return std::make_shared<BlockScopeNode>();
    }
    std::cout << "Visiting DeclarationBlock" << ctx->getText() << std::endl;

    std::string varKind;
    if (ctx->VAR()) {
        varKind = "VAR";
    } else if (ctx->VAR_INPUT()) {
        varKind = "VAR_INPUT";
    } else if (ctx->VAR_OUTPUT()) {
        varKind = "VAR_OUTPUT";
    } else if (ctx->VAR_IN_OUT()) {
        varKind = "VAR_IN_OUT";
    } else if (ctx->VAR_TEMP()) {
        varKind = "VAR_TEMP";
    }

    auto blockNode = std::make_shared<BlockScopeNode>();
    blockNode->scopeType = varKind;

    for (auto stmt:ctx->varDeclaration()) {
        auto declNode = visitVarDeclaration(stmt);
        if (declNode.isNotNull() && declNode.is<std::shared_ptr<IRNode>>()) {
            blockNode->declarations.push_back(declNode.as<std::shared_ptr<IRNode>>());
        } else {
            std::cerr << "Error: Invalid declaration in varDeclarationBlock" << std::endl;
        }
    }

    return blockNode;
}

antlrcpp::Any newSTVisitor::visitVarDeclaration(STParser::VarDeclarationContext *ctx) {
    if (!ctx || !ctx->IDENT()) {
        return std::make_shared<VariableDeclarationNode>("", "");
    }
    std::cout << "Visiting VarDeclaration" << ctx->getText() << std::endl;

    std::string varName = ctx->IDENT()->getText();
    std::transform(varName.begin(), varName.end(), varName.begin(), ::toupper);

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
    } else {
        std::cerr << "Error: Missing type specification for variable '"
                  << varName << "'" << std::endl;
        dataType = "UNKNOWN";
    }

    // 初始化表达式
    std::shared_ptr<IRNode> initialValueNode;
    std::shared_ptr<IRNode> varDeclNode;
    if (ctx->expr()) {
        std::string initialValue = ctx->expr()->getText();
        std::cout << "initialValue is:" << initialValue << std::endl;
        auto result = visitExpr(ctx->expr());
       if (result.is<std::shared_ptr<IRNode>>()) {
           initialValueNode = result.as<std::shared_ptr<IRNode>>();
       }
        varDeclNode = std::make_shared<VariableDeclarationNode>(varName, dataType, initialValueNode);
        // TODO 初始值校验
    } else {
        std::cout << "No initialValue"<< std::endl;
        varDeclNode = std::make_shared<VariableDeclarationNode>(varName, dataType);
    }
    std::cout << "打印IR Node" << std::endl;
    printIR();

    // 检查变量是否已声明
    std::cout << "变量声明" << varName << std::endl;
    if (!semanticAnalyzer.declareVariable(varName, dataType)) {
        std::cerr << "Error: Variable '" << varName << "' is already declared in this scope!" << std::endl;
        return nullptr;
    }
    symbolTable.print();

    return varDeclNode;
}

antlrcpp::Any newSTVisitor::visitBasicType(STParser::BasicTypeContext *ctx) {
    if (!ctx) {
        std::cerr << "Error: Invalid basic type specification" << std::endl;
        return std::string("UNKNOWN");
    }

    std::string typeName = ctx->getText();
    std::transform(typeName.begin(), typeName.end(), typeName.begin(), ::toupper);
    std::cout << "typeName is: " << typeName << std::endl;

    // 基础类型检查
    static const std::set<std::string> validTypes = {
            "BOOL", "BYTE", "WORD", "DWORD", "LWORD",
            "SINT", "INT", "DINT", "LINT",
            "USINT", "UINT", "UDINT", "ULINT",
            "REAL", "LREAL",
            "TIME", "DATE", "TOD", "DT",
            "STRING"
    };

    if (validTypes.find(typeName) == validTypes.end()) {
        std::cerr << "Warning: Unrecognized basic type '" << typeName
                  << "' at line " << ctx->getStart()->getLine() << std::endl;
    }

    std::cout << "Processing basic type: " << typeName
              << " at line " << ctx->getStart()->getLine() << std::endl;


    return typeName;
}

antlrcpp::Any newSTVisitor::visitArrayType(STParser::ArrayTypeContext *ctx) {
    if (!ctx) {
        return std::make_shared<ArrayTypeNode>();
    }
    std::cout << "Visiting ArrayType:"<< ctx->getText()  << std::endl;

    auto arrayNode = std::make_shared<ArrayTypeNode>();

    // 处理维度范围
    for (auto rangeCtx : ctx->range()) {
        auto rangeResult = visitRange(rangeCtx);
        if (rangeResult.is<std::pair<std::shared_ptr<IRNode>, std::shared_ptr<IRNode>>>()) {
            arrayNode->dimensions.push_back(
                    rangeResult.as<std::pair<std::shared_ptr<IRNode>, std::shared_ptr<IRNode>>>()
                    );
        }
    }

    // 处理元素类型
    if (ctx->type()) {
        auto elemTypeResult = visit(ctx->type());
        if (elemTypeResult.is<std::string>()) {
            arrayNode->elementType = elemTypeResult.as<std::string>();
        }
    }

    return arrayNode;
}

antlrcpp::Any newSTVisitor::visitRange(STParser::RangeContext *ctx) {
    if (!ctx || ctx->expr().size() != 2) {
        return std::make_pair(
                std::make_shared<ConstantNode>("0", "INT"),
                std::make_shared<ConstantNode>("0", "INT")
        );
    }

    auto upperRange = visit(ctx->expr(1));
    auto lowerRange = visit(ctx->expr(0));

    std::shared_ptr<IRNode> upper = nullptr;
    std::shared_ptr<IRNode> lower = nullptr;

    if (lowerRange.is<std::shared_ptr<IRNode>>()) {
        lower = lowerRange.as<std::shared_ptr<IRNode>>();
    }
    if (upperRange.is<std::shared_ptr<IRNode>>()) {
        upper = upperRange.as<std::shared_ptr<IRNode>>();
    }

    return std::make_pair(lower, upper);
}

antlrcpp::Any newSTVisitor::visitStructType(STParser::StructTypeContext *ctx) {
    if (!ctx) {
        return std::make_shared<StructTypeNode>();
    }
    std::cout << "Visiting structType:" << ctx->getText() << std::endl;

    auto structNode = std::make_shared<StructTypeNode>();

    for (auto memberCtx : ctx->structMember()) {
        auto memberResult = visitStructMember(memberCtx);
        if (memberResult.is<std::pair<std::string, std::string>>()) {
            auto member = memberResult.as<std::pair<std::string, std::string>>();
            structNode->members.push_back(member);
        }
    }

    return structNode;
}

antlrcpp::Any newSTVisitor::visitStructMember(STParser::StructMemberContext *ctx) {
    if (!ctx || !ctx->IDENT()) {
        return std::make_pair("", "UNKNOWN");
    }
    std::string memberName = ctx->IDENT()->getText();
    std::transform(memberName.begin(), memberName.end(), memberName.begin(), ::toupper);

    std::string memberType = "UNKNOWN";
    if (ctx->type()) {
        auto typeResult = visit(ctx->type());
        if (typeResult.is<std::string>()) {
            memberType = typeResult.as<std::string>();
        } else if (typeResult.is<std::shared_ptr<IRNode>>()) {
            auto typeNode = typeResult.as<std::shared_ptr<IRNode>>();
            if (auto arrayNode = std::dynamic_pointer_cast<ArrayTypeNode>(typeNode)) {
                memberType = "ARRAY";
            } else if (auto structNode = std::dynamic_pointer_cast<StructTypeNode>(typeNode)) {
                memberType = "STRUCT";
            }
        }
    }

    return std::make_pair(memberName, memberType);
}

antlrcpp::Any newSTVisitor::visitFunctionDecl(STParser::FunctionDeclContext *ctx) {
    if (!ctx || !ctx->IDENT()) {
        return std::make_shared<FunctionNode>("", "UNKNOWN");
    }
    std::string functionName = ctx->IDENT()->getText();
    std::transform(functionName.begin(), functionName.end(), functionName.begin(), ::toupper);

    std::cout << "Entering Function Scope: " << functionName << std::endl;
    semanticAnalyzer.enterScope();  // 进入函数作用域

    std::string returnType = ctx->type()->getText();
    if (ctx->type()) {
        auto typeResult = visit(ctx->type());
        if (typeResult.is<std::string>()) {
            returnType = typeResult.as<std::string>();
        }
    }

    std::cout << "函数声明" << functionName << returnType << std::endl;
    if (!semanticAnalyzer.declareFunction(functionName, returnType)) {
        std::cerr << "Error: Function '" << functionName << "' is already declared!" << std::endl;
        return nullptr;
    }

    auto funcNode = std::make_shared<FunctionNode>(functionName, returnType);

    if (ctx->interfaceSection()) {
        auto interfaceResult = visit(ctx->interfaceSection());
    }

   if (ctx->bodySection()) {
       auto bodyResult = visit(ctx->bodySection());
   }

    std::cout << "Exiting Function Block Scope: " << functionName << std::endl;
    semanticAnalyzer.exitScope();

    return funcNode;
}

antlrcpp::Any newSTVisitor::visitFunctionBlockDecl(STParser::FunctionBlockDeclContext *ctx) {
    if (!ctx || !ctx->IDENT()) {
        return std::make_shared<FunctionBlockNode>("");
    }

    std::string functionBlockName = ctx->IDENT()->getText();
    std::transform(functionBlockName.begin(), functionBlockName.end(), functionBlockName.begin(), ::toupper);

    std::cout << "Entering Function Block Scope: " << functionBlockName << std::endl;
    semanticAnalyzer.enterScope();

    std::cout << "FB声明" << functionBlockName << std::endl;
    if (!semanticAnalyzer.declareFunctionBlock(functionBlockName)) {
        std::cerr << "Error: Function Block '" << functionBlockName << "' is already declared!" << std::endl;
        return nullptr;
    }

    auto fbNode = std::make_shared<FunctionBlockNode>(functionBlockName);

    if (ctx->interfaceSection()) {
        auto interfaceResult = visit(ctx->interfaceSection());
    }

    if (ctx->bodySection()) {
        auto bodyResult = visit(ctx->bodySection());
    }

    for (auto methodCtx : ctx->methodDecl()) {
        auto methodResult = visit(methodCtx);
        if (methodResult.is<std::shared_ptr<MethodNode>>()) {
            fbNode->addMethod(methodResult.as<std::shared_ptr<MethodNode>>());
        }
    }

    std::cout << "Exiting Function Block Scope: " << functionBlockName << std::endl;
    semanticAnalyzer.exitScope();  // 退出功能块作用域
    return fbNode;
}

antlrcpp::Any newSTVisitor::visitMethodDecl(STParser::MethodDeclContext *ctx) {
    if (!ctx || !ctx->IDENT()) {
        return std::make_shared<MethodNode>("", "UNKNOWN");
    }

    std::string methodName;
    std::transform(methodName.begin(), methodName.end(), methodName.begin(), ::toupper);

    // 进入作用域
    if (!semanticAnalyzer.declareFunction(methodName, ctx->type()->getText())){
        std::cerr << "Error: Failed to declare method " <<  methodName <<  "." << std::endl;
    }

    std::string returnType = "UNKNOWN";
    if (ctx->type()) {
        auto typeResult = visit(ctx->type());
        if (typeResult.is<std::string>()) {
            returnType = typeResult.as<std::string>();
        }
    }

    auto methodNode = std::make_shared<MethodNode>(methodName, returnType);

    if (ctx->interfaceSection()) {
        auto interfaceResult = visit(ctx->interfaceSection());
    }

    // 返回类型
    if (ctx->bodySection()) {
        auto bodyResult = visit(ctx->bodySection());
        // Process method body
    }

    return methodNode;
}

antlrcpp::Any newSTVisitor::visitBodySection(STParser::BodySectionContext *ctx) {
    auto bodyNode = std::make_shared<BodyNode>();

    for (auto stmt : ctx->statement_list()) {
        auto stmtResult = visit(stmt);
        if (stmtResult.is<std::shared_ptr<IRNode>>()) {
            bodyNode->addStatement(stmtResult.as<std::shared_ptr<IRNode>>());
        }
    }

    return bodyNode;
}

antlrcpp::Any newSTVisitor::visitEnumeratedType(STParser::EnumeratedTypeContext *ctx) {
    auto enumNode = std::make_shared<EnumTypeNode>();

    std::cout << "  Enumerated Values: " << ctx->getText() << std::endl;
    for (auto ident : ctx->IDENT()) {
        std::string enumValue = ident->getText();
        std::transform(enumValue.begin(), enumValue.end(), enumValue.begin(), ::toupper);
        enumNode->addValue(enumValue);
    }
    std::cout << std::endl;

    return enumNode;
}


antlrcpp::Any newSTVisitor::visitSubrangeType(STParser::SubrangeTypeContext *ctx) {
    std::string baseType = ctx->basicType()->getText();

    auto lowerResult = visit(ctx->expr(0));
    auto upperResult = visit(ctx->expr(1));

    auto subrangeNode = std::make_shared<SubrangeTypeNode>(baseType);

    if (lowerResult.is<std::shared_ptr<IRNode>>()) {
        subrangeNode->setLowerBound(lowerResult.as<std::shared_ptr<IRNode>>());
    }

    if (upperResult.is<std::shared_ptr<IRNode>>()) {
        subrangeNode->setUpperBound(upperResult.as<std::shared_ptr<IRNode>>());
    }

    return subrangeNode;
}