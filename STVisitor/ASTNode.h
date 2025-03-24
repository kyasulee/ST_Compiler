//
// Created by 84648 on 2025/3/19.
//

#ifndef AST_NODE_H
#define AST_NODE_H

#include <string>
#include <vector>
#include <memory>

class ASTNode {
public:
    std::string name;
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;  // 子节点

    // 构造函数
    ASTNode(const std::string& nodeName, const std::string & nodeValue = "") : name(nodeName), value(nodeValue) {}

    // 添加子节点
    void addChildNode(std::shared_ptr<ASTNode> child) {
        children.push_back(child);
    }
};

#endif //AST_NODE_H
