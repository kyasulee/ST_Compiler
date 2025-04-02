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

// FU节点
struct FunctionNode : public IRNode {
    std::string name;
    std::string returnType;
    std::vector<std::shared_ptr<IRNode>> parameters; // 参数定义
    std::vector<std::shared_ptr<IRNode>> body; // 函数体

    FunctionNode(const std::string& name, const std::string returnType) : name(name), returnType(returnType) {
        type = IRNodeType::Function;
    }
};

// FB节点
struct FunctionBlockNode : public IRNode {
    std::string name;
    std::vector<std::shared_ptr<IRNode>> members; // 成员变量声明
    std::vector<std::shared_ptr<IRNode>> methods; // 方法定义

    FunctionBlockNode(const std::string& name) : name(name) {
        type = IRNodeType::FunctionBlock;
    }
};

// 变量声明节点
struct VariableDeclarationNode : public IRNode {
    std::string name;
    std::string dataType;
    std::string initValue; // 可能没有初始值

    VariableDeclarationNode(const std::string& name, const std::string& dataType)
            : name(name), dataType(dataType) {
        type = IRNodeType::VariableDeclaration;
    }

    VariableDeclarationNode(const std::string& name, const std::string& dataType, std::shared_ptr<IRNode> initialValue)
            : name(name), dataType(dataType), initValue(std::move(initValue)) {
        type = IRNodeType::VariableDeclaration;
    }
};

// 赋值语句节点
struct AssignmentNode : public IRNode {
    std::shared_ptr<IRNode> target;
    std::shared_ptr<IRNode> value;

    AssignmentNode(std::shared_ptr<IRNode> target, std::shared_ptr<IRNode> value) : target(target), value(value){
        type = IRNodeType::Assignment;
    }

};

// 二元操作
struct BinaryOpNode : public IRNode {
    std::shared_ptr<IRNode> left;
    std::string op;  // 操作符
    std::shared_ptr<IRNode> right;

    BinaryOpNode(std::shared_ptr<IRNode> left, const std::string& op, std::shared_ptr<IRNode> right)
        : left(left), op(op), right(right) {
        type =  IRNodeType::BinaryOp;
    }
};

// 一元操作
struct UnaryOp : public IRNode {
    std::string op;  // 操作符
    std::shared_ptr<IRNode> operand;

    UnaryOp( const std::string& op, std::shared_ptr<IRNode> operand)
            :  op(op), operand(operand) {
        type =  IRNodeType::UnaryOp;
    }
};

// 函数调用
struct CallFuncNode : public IRNode {
    std::string funcName; // 函数名
    std::vector<std::shared_ptr<IRNode>> args; // 参数列表

    CallFuncNode(const std::string& funcName, std::vector<std::shared_ptr<IRNode>> args)
            : funcName(funcName), args(std::move(args)) {
        type = IRNodeType::CallFunc;
    }
};

// if语句
struct IfStmtNode : public IRNode {
    std::shared_ptr<IRNode> condition;
    std::vector<std::shared_ptr<IRNode>> thenBranch; // THEN
    std::vector<std::shared_ptr<IRNode>> elseBranch; // ELSE

    IfStmtNode(std::shared_ptr<IRNode> condition,
               std::vector<std::shared_ptr<IRNode>> thenBranch,
               std::vector<std::shared_ptr<IRNode>> elseBranch = {})
            : condition(std::move(condition)),
              thenBranch(std::move(thenBranch)),
              elseBranch(std::move(elseBranch)) {
        type = IRNodeType::IfStmt;
    }
};

// case语句
struct CaseStmtNode : public IRNode {
    std::shared_ptr<IRNode> selector;
    std::vector<std::pair<std::vector<std::shared_ptr<IRNode>>, std::vector<std::shared_ptr<IRNode>>>> cases; // 分支列表
    std::vector<std::shared_ptr<IRNode>> defaultBranch; // 默认分支

    CaseStmtNode(std::shared_ptr<IRNode> selector)
            : selector(std::move(selector)) {
        type = IRNodeType::CaseStmt;
    }
};

// while
struct WhileStmtNode : public IRNode {
    std::shared_ptr<IRNode> condition;
    std::vector<std::shared_ptr<IRNode>> body; // 循环体

    WhileStmtNode(std::shared_ptr<IRNode> condition, std::vector<std::shared_ptr<IRNode>> body)
            : condition(std::move(condition)), body(std::move(body)) {
        type = IRNodeType::WhileStmt;
    }
};

// for
struct ForStmtNode : public IRNode {
    std::shared_ptr<IRNode> initialization; // 初始化语句
    std::shared_ptr<IRNode> condition;     // 循环条件
    std::shared_ptr<IRNode> step;          // 步长（可选，默认为 1）
    std::vector<std::shared_ptr<IRNode>> body; // 循环体

    ForStmtNode(std::shared_ptr<IRNode> initialization,
                std::shared_ptr<IRNode> condition,
                std::shared_ptr<IRNode> step,
                std::vector<std::shared_ptr<IRNode>> body)
            : initialization(std::move(initialization)),
              condition(std::move(condition)),
              step(std::move(step)),
              body(std::move(body)) {
        type = IRNodeType::ForStmt;
    }
};

// return
struct ReturnStmtNode : public IRNode {
    std::shared_ptr<IRNode> value; // 返回值（可选）

     ReturnStmtNode(std::shared_ptr<IRNode> value = nullptr)
            : value(std::move(value)) {
        type = IRNodeType::ReturnStmt;
    }
};

// 常量
struct ConstantNode : public IRNode {
    std::string value;
    std::string datatype;

    ConstantNode(const std::string& value, const std::string& datatype) : value(value), datatype(datatype) {
        type = IRNodeType::Constant;
    }
};

// 标识符
struct IdentifierNode : public IRNode {
    std::string name;

    IdentifierNode(const std::string& name) : name(name) {
        type = IRNodeType::Identifier;
    }
};

// 数组
struct ArrayAccessNode : public IRNode {
    std::shared_ptr<IRNode> arrayName; // 数组名
    std::vector<std::shared_ptr<IRNode>> indices; // 索引列表

    ArrayAccessNode(std::shared_ptr<IRNode> arrayName, std::vector<std::shared_ptr<IRNode>> indices)
            : arrayName(std::move(arrayName)), indices(std::move(indices)) {
        type = IRNodeType::ArrayAccess;
    }
};

// 结构体
struct StructAccessNode : public IRNode {
    std::shared_ptr<IRNode> structName; // 结构体名
    std::string memberName;            // 成员名

    StructAccessNode(std::shared_ptr<IRNode> structName, const std::string& memberName)
            : structName(std::move(structName)), memberName(memberName) {
        type = IRNodeType::StructAccess;
    }
};
#endif //ST_BUILDER_IRNODE_H
