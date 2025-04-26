//
// Created by 84648 on 2025/4/2.
//

#ifndef ST_BUILDER_IRNODE_H
#define ST_BUILDER_IRNODE_H

#include <string>
#include <vector>
#include <memory>
#include <support/Any.h>

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
    InputPin,
    OutputPin,
    Selection, // 选择语句
    IfStmt,
    CaseStmt,
    Iteration, // 循环语句
    WhileStmt,
    ForStmt,
    RepeatStmt,
    Constant,  // 常量
    Identifier, // 标识符
    ArrayAccess,
    StructAccess,
    Method,
    Params,
    // 跳转类型节点
    JumpStmt,
    BreakStmt,
    ReturnStmt,
    ContinueStmt,
    ExitStmt,
    // 作用域类型
    GlobalScope,    // 全局作用域
    ProgramScope,   // 程序作用域
    FunctionScope,  // 函数作用域
    FBScope,        // 功能块作用域
    BlockScope,     // 普通块作用域(如if/while内部的块
    // 类型节点
    ArrayType,
    StructType,
    EnumType,
    SubRangeType,
    Body,
};

// IR节点
struct IRNode {
    IRNodeType type;
    std::vector<std::shared_ptr<IRNode>> children; // 子节点

    virtual ~IRNode() = default;

    // 增加可视化方法
    virtual std::string getGraphVizLabel() const {
        switch (type) {
            case IRNodeType::Program: return "Program";
            case IRNodeType::Function: return "Function";
            case IRNodeType::FunctionBlock: return "FunctionBlock";
            case IRNodeType::VariableDeclaration: return "VarDecl";
            case IRNodeType::Assignment: return "Assignment";
            case IRNodeType::BinaryOp: return "BinaryOp";
            case IRNodeType::UnaryOp: return "UnaryOp";
            case IRNodeType::CallFunc: return "CallFunc";
            case IRNodeType::InputPin: return "InputPin";
            case IRNodeType::OutputPin: return "OutputPin";
            case IRNodeType::Selection: return "Selection";
            case IRNodeType::IfStmt: return "IfStmt";
            case IRNodeType::CaseStmt: return "CaseStmt";
            case IRNodeType::Iteration: return "Iteration";
            case IRNodeType::WhileStmt: return "WhileStmt";
            case IRNodeType::ForStmt: return "ForStmt";
            case IRNodeType::RepeatStmt: return "RepeatStmt";
            case IRNodeType::Constant: return "Constant";
            case IRNodeType::Identifier: return "Identifier";
            case IRNodeType::ArrayAccess: return "ArrayAccess";
            case IRNodeType::StructAccess: return "StructAccess";
            case IRNodeType::Method: return "Method";
            case IRNodeType::Params: return "Params";
            case IRNodeType::JumpStmt: return "JumpStmt";
            case IRNodeType::BreakStmt: return "BreakStmt";
            case IRNodeType::ReturnStmt: return "ReturnStmt";
            case IRNodeType::ContinueStmt: return "ContinueStmt";
            case IRNodeType::ExitStmt: return "ExitStmt";
            case IRNodeType::GlobalScope: return "GlobalScope";
            case IRNodeType::ProgramScope: return "ProgramScope";
            case IRNodeType::FunctionScope: return "FunctionScope";
            case IRNodeType::FBScope: return "FBScope";
            case IRNodeType::BlockScope: return "BlockScope";
            case IRNodeType::ArrayType: return "ArrayType";
            case IRNodeType::StructType: return "StructType";
            case IRNodeType::EnumType: return "EnumType";
            case IRNodeType::SubRangeType: return "SubRangeType";
            case IRNodeType::Body: return "Body";
            default: return "IRNode";
        }
    }

    virtual std::vector<std::shared_ptr<IRNode>> getGraphVizChildren() const {
        return children;
    }

    virtual std::string getGraphVizColor() const {
        switch(type) {
            // 作用域节点 - 蓝色
            case IRNodeType::GlobalScope:
            case IRNodeType::ProgramScope:
            case IRNodeType::FunctionScope:
            case IRNodeType::FBScope:
            case IRNodeType::BlockScope:
                return "lightblue";

            // 声明类节点 - 黄色
            case IRNodeType::Program:
            case IRNodeType::Function:
            case IRNodeType::FunctionBlock:
            case IRNodeType::VariableDeclaration:
            case IRNodeType::Method:
                return "lightyellow";

            // 语句类节点 - 绿色
            case IRNodeType::Assignment:
            case IRNodeType::IfStmt:
            case IRNodeType::CaseStmt:
            case IRNodeType::WhileStmt:
            case IRNodeType::ForStmt:
            case IRNodeType::RepeatStmt:
            case IRNodeType::ReturnStmt:
            case IRNodeType::BreakStmt:
            case IRNodeType::ContinueStmt:
            case IRNodeType::ExitStmt:
                return "lightgreen";

            // 表达式类节点 - 紫色
            case IRNodeType::BinaryOp:
            case IRNodeType::UnaryOp:
            case IRNodeType::CallFunc:
            case IRNodeType::ArrayAccess:
            case IRNodeType::StructAccess:
                return "lavender";

            // 类型节点 - 粉色
            case IRNodeType::ArrayType:
            case IRNodeType::StructType:
            case IRNodeType::EnumType:
            case IRNodeType::SubRangeType:
                return "lightpink";

            // 基本元素 - 青色
            case IRNodeType::Constant:
            case IRNodeType::Identifier:
            case IRNodeType::InputPin:
            case IRNodeType::OutputPin:
            case IRNodeType::Params:
                return "lightcyan";

            default:
                return "lightgray";
        }
    }
};

extern std::vector<std::shared_ptr<IRNode>> irList;
void printIR();

// 程序节点
struct ProgramNode : public IRNode {
    std::string name;
    std::vector<std::shared_ptr<IRNode>> declarations; // 变量声明
    std::vector<std::shared_ptr<IRNode>> statements;   // 语句

    ProgramNode(const std::string& name) : name(name) {
        type = IRNodeType::Program;
    }

    // 可视化
    std::string getGraphVizLabel() const override {
        return "Program: " + name;
    }

    std::vector<std::shared_ptr<IRNode>> getGraphVizChildren() const override {
        std::vector<std::shared_ptr<IRNode>> allChildren;

        allChildren.insert(allChildren.end(), declarations.begin(), declarations.end());
        allChildren.insert(allChildren.end(), statements.begin(), statements.end());

        return allChildren;
    }

    std::string getGraphVizColor() const override {
        return "lightblue";
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

struct MethodNode : public IRNode {
    std::string name;
    std::string returnType;
    std::vector<std::shared_ptr<IRNode>> parameters;
    std::vector<std::shared_ptr<IRNode>> variables;
    std::shared_ptr<IRNode> body;

    MethodNode(const std::string& name, const std::string& returnType)
            : name(name), returnType(returnType) {
        type = IRNodeType::Method;
    }
};

// FB节点
struct FunctionBlockNode : public IRNode {
    std::string name;
    std::vector<std::shared_ptr<IRNode>> members; // 成员变量声明
    std::vector<std::shared_ptr<IRNode>> methods; // 方法定义
    std::vector<std::shared_ptr<IRNode>> variables;  // Local variables
    std::shared_ptr<IRNode> body;

    FunctionBlockNode(const std::string& name) : name(name) {
        type = IRNodeType::FunctionBlock;
    }

    void addMethod(std::shared_ptr<MethodNode> method) {
        methods.push_back(method);
    }
};



// 变量声明节点
struct VariableDeclarationNode : public IRNode {
    std::string name;
    std::string dataType;
    std::shared_ptr<IRNode> initialValue; // 可能没有初始值

    VariableDeclarationNode(const std::string& name, const std::string& dataType)
            : name(name), dataType(dataType) {
        type = IRNodeType::VariableDeclaration;
    }

    VariableDeclarationNode(const std::string& name, const std::string& dataType, std::shared_ptr<IRNode> initialValue)
            : name(name), dataType(dataType), initialValue(std::move(initialValue)) {
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

    BinaryOpNode(std::shared_ptr<IRNode> left,
                 const std::string& op,
                 std::shared_ptr<IRNode> right)
        : left(left), op(op), right(right) {
        type =  IRNodeType::BinaryOp;
    }
};

// 一元操作
struct UnaryOpNode : public IRNode {
    std::string op;  // 操作符
    std::shared_ptr<IRNode> operand;

    UnaryOpNode( const std::string& op, std::shared_ptr<IRNode> operand)
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

// InputPin
struct InputPinNode : public IRNode {
    std::string pinName;                // 引脚名称
    std::shared_ptr<IRNode> valueNode;  // 引脚值（通常是表达式）

    InputPinNode(const std::string& name, std::shared_ptr<IRNode> value)
            : pinName(name), valueNode(value) {
        type = IRNodeType::InputPin;
    }
};

// OutputPin
struct OutputPinNode : public IRNode {
    std::string pinName;       // 引脚名称
    std::string mappedVariable; // 映射的变量名

    OutputPinNode(const std::string& name, const std::string& var)
            : pinName(name), mappedVariable(var) {
        type = IRNodeType::OutputPin;
    }
};

struct SelectionNode : public IRNode {
    bool isCase;

    SelectionNode(bool isCase = false) : isCase(isCase) {
        type = IRNodeType::Selection;
    }

    void setInvalid() {
        // 可以添加标记位或状态字段
        this->isValid = false;
    }

    bool isIfStmt() const { return !isCase; }
    bool isCaseStmt() const { return isCase; }

    // 添加调试信息
    std::string getStmtType() const {
        return isCase ? "CASE" : "IF";
    }

private:
    bool isValid = true; // 表示是否为无效方法
};

// if语句
struct IfStmtNode : public IRNode {
    std::shared_ptr<IRNode> condition;
    std::vector<std::shared_ptr<IRNode>> thenBranch; // THEN
    std::vector<std::shared_ptr<IRNode>> elseBranch; // ELSE

    IfStmtNode() : condition(nullptr) {
        type = IRNodeType::IfStmt;
    }

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

    CaseStmtNode() : selector(nullptr) {
        type = IRNodeType::CaseStmt;
    }

    CaseStmtNode(std::shared_ptr<IRNode> selector,
                 std::vector<std::pair<std::vector<std::shared_ptr<IRNode>>,
                         std::vector<std::shared_ptr<IRNode>>>> cases = {},
                 std::vector<std::shared_ptr<IRNode>> defaultBranch = {})
            : selector(std::move(selector)),
              cases(std::move(cases)),
              defaultBranch(std::move(defaultBranch)) {
        type = IRNodeType::CaseStmt;
    }
};

enum IterationType {
    WHILE,
    FOR,
    REPEAT
};

struct IterationNode : public IRNode {
    IterationType iterType;

    IterationNode(IterationType type = WHILE) : iterType(type) {
        type = static_cast<IterationType>(IRNodeType::Iteration);
    }

    void setInvalid() {
        // 可以添加标记位或状态字段
        this->isValid = false;
    }

    bool isWhileStmt() const { return iterType == WHILE; }
    bool isForStmt() const { return iterType == FOR; }
    bool isRepeatStmt() const {return iterType == REPEAT; }

    std::string getStmtType() const {
        switch(iterType) {
            case WHILE: return "WHILE";
            case FOR: return "FOR";
            case REPEAT: return "REPEAT";
            default: return "UNKNOWN";
        }
    }

private:
    bool isValid = true; // 表示是否为无效方法
};

// while
struct WhileStmtNode : public IRNode {
    std::shared_ptr<IRNode> condition;
    std::vector<std::shared_ptr<IRNode>> body; // 循环体

    WhileStmtNode(std::shared_ptr<IRNode> condition,
                  std::vector<std::shared_ptr<IRNode>> body)
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

struct RepeatStmtNode : public IRNode {
    std::vector<std::shared_ptr<IRNode>> body;
    std::shared_ptr<IRNode> untilCondition;

    RepeatStmtNode(std::vector<std::shared_ptr<IRNode>> body,
                   std::shared_ptr<IRNode> untilCond)
            : body(std::move(body)), untilCondition(std::move(untilCond)) {
        type = IRNodeType::RepeatStmt;
    }
};

// jump
struct JumpStmtNode : public IRNode {
    JumpStmtNode() {
        type = IRNodeType::JumpStmt;
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

// break
struct BreakStmtNode : public IRNode {
    BreakStmtNode() {
        type = IRNodeType::BreakStmt;
    }
};

// continue
struct ContinueStmtNode : public IRNode {
    ContinueStmtNode() {
        type = IRNodeType::ContinueStmt;
    }
};

// exit
struct ExitStmtNode : public IRNode {
    ExitStmtNode() {
        type = IRNodeType::ExitStmt;
    }
};

// 常量
struct ConstantNode : public IRNode {
    std::string value;
    std::string datatype;

    ConstantNode(const std::string& value,
                 const std::string& datatype)
                 : value(value), datatype(datatype) {
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

struct ParamsNode : public IRNode {
    std::string name;
    std::string paramType;
    std::shared_ptr<IRNode> defaultValue;
    std::string refName;
    std::shared_ptr<IRNode> exprValue;


    ParamsNode(const std::string& name = "", const std::string& paramtype = "UNKNOWN")
            : name(name), paramType(paramtype) {
        type = IRNodeType::Params;
    }
};


// 基础作用域
struct ScopeNode : public IRNode {
    std::string scopeName;
    std::vector<std::shared_ptr<IRNode>> declarations; // 声明列表
    std::vector<std::shared_ptr<IRNode>> statements;   // 语句列表

    ScopeNode(IRNodeType scopeType, const std::string& name = "")
            : scopeName(name) {
        type = scopeType;
    }
};

// 全局作用域
struct GlobalScopeNode : public ScopeNode {
    GlobalScopeNode() : ScopeNode(IRNodeType::GlobalScope, "GLOBAL") {}
};

// 程序作用域
struct ProgramScopeNode : public ScopeNode {
    ProgramScopeNode(const std::string& name) : ScopeNode(IRNodeType::ProgramScope, name) {}
};

// FU作用域
struct FunctionScopeNode : public ScopeNode {
    std::string returnType;

    FunctionScopeNode(const std::string& name, const std::string& retType) :
            ScopeNode(IRNodeType::FunctionScope, name), returnType(retType) {}
};

// FB作用域
struct FBScopeNode : public ScopeNode {
    FBScopeNode(const std::string& name)
            : ScopeNode(IRNodeType::FBScope, name) {}
};

// 普通块作用域
struct BlockScopeNode : public ScopeNode {
    std::string scopeType; // VAR, VAR_INPUT等
    std::vector<std::shared_ptr<IRNode>> declarations;

    BlockScopeNode()
            : ScopeNode(IRNodeType::BlockScope) {}
};

struct ArrayTypeNode : public IRNode {
    std::vector<std::pair<std::shared_ptr<IRNode>, std::shared_ptr<IRNode>>> dimensions;
    std::string elementType;

    ArrayTypeNode() {
        type = IRNodeType::ArrayType;
    }
};

struct StructTypeNode : public IRNode {
    std::vector<std::pair<std::string, std::string>> members;

    StructTypeNode() {
        type = IRNodeType::StructType;
    }
};

struct EnumTypeNode : public IRNode {
    std::vector<std::string> values;

    EnumTypeNode() {
        type = IRNodeType::EnumType;
    }

    void addValue(const std::string& value) {
        values.push_back(value);
    }
};

struct SubrangeTypeNode : public IRNode {
    std::string baseType;
    std::shared_ptr<IRNode> lowerBound;
    std::shared_ptr<IRNode> upperBound;

    SubrangeTypeNode(std::basic_string<char> string) {
        type = IRNodeType::SubRangeType;
    }

    void setLowerBound(std::shared_ptr<IRNode> bound) {
        lowerBound = bound;
    }

    void setUpperBound(std::shared_ptr<IRNode> bound) {
        upperBound = bound;
    }
};

struct BodyNode : public IRNode {
    std::vector<std::shared_ptr<IRNode>> statements;

    BodyNode() {
        type = IRNodeType::Body;
    }

    void addStatement(std::shared_ptr<IRNode> stmt) {
        statements.push_back(stmt);
    }
};

#endif //ST_BUILDER_IRNODE_H