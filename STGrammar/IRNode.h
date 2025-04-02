//
// Created by 84648 on 2025/4/2.
//

#ifndef ST_BUILDER_IRNODE_H
#define ST_BUILDER_IRNODE_H

#include <string>
#include <vector>
#include <memory>

// IR节点类型
enum class IRNodeType {
    Program,
    Function,
    FunctionBlock,
    VariableDeclaration,
    Assignment, // 赋值语句
    BinaryOp, // 二元操作
    UnaryOp,  // 一元操作
    CallFunc, // 函数调用
    IfStmt,
    CaseStmt,
    WhileStmt,
    ForStmt,
    RepeatStmt,
    ReturnStmt,
    Constant,  // 常量
    Identifier, // 标识符
    ArrayAccess,
    StructAccess
};

// IR节点
struct IRNode {
    IRNodeType type;
    virtual ~IRNode() = default;
};

// 程序节点
struct ProgramNode : public IRNode {
    std::string name;
    std::vector<std::shared_ptr<IRNode>> declarations; // 变量声明
    std::vector<std::shared_ptr<IRNode>> statements;   // 语句

    ProgramNode(const std::string& name) : name(name) {
        type = IRNodeType::Program;
    }
};

// 函数节点


#endif //ST_BUILDER_IRNODE_H
