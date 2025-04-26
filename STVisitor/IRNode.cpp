//
// Created by 84648 on 2025/4/7.
//
#include <iostream>

#include "IRNode.h"

// 定义全局 IR 列表
std::vector<std::shared_ptr<IRNode>> irList;

void printIR() {
    for (const auto& node : irList) {
        if (node->type == IRNodeType::VariableDeclaration) {
            auto varDeclNode = std::static_pointer_cast<VariableDeclarationNode>(node);
            std::cout << "Variable Declaration: " << varDeclNode->name
                      << ", Type: " << varDeclNode->dataType;
            if (varDeclNode->initialValue) {
                std::cout << ", Initial Value: ";
                if (varDeclNode->initialValue->type == IRNodeType::Constant) {
                    auto constNode = std::static_pointer_cast<ConstantNode>(varDeclNode->initialValue);
                    std::cout << constNode->value;
                }
            }
            std::cout << std::endl;
        }
    }
}