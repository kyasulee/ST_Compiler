#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "STGrammar/STParser.h"
#include "STGrammar/STLexer.h"
#include "STGrammar/STBaseVisitor.h"
#include "STParserVisitor.h"

int main(int argc, const char* argv[]) {
    std::fstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    antlr4::ANTLRInputStream input(inputFile);
    inputFile.close();

    // 词法分析器
    STLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    // 语法分析器
    STParser parser(&tokens);

    antlr4::tree::ParseTree* tree = parser.startpoint();

//    std::cout << "parse tree:" << std::endl;
//    std::cout << tree->toStringTree(&parser) << std::endl;

    // 遍历语法树
    newSTVisitor visitor;
    visitor.visit(tree);

    return 0;
}

