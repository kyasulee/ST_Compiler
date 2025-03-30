//
// Created by 84648 on 2025/3/30.
//

#ifndef ST_BUILDER_ANYTYPECHECK_H
#define ST_BUILDER_ANYTYPECHECK_H

#include <iostream>
#include <unordered_set>

enum class DataType {
    SINT,   // 8-bit signed integer
    INT,    // 16-bit signed integer
    DINT,   // 32-bit signed integer
    LINT,   // 64-bit signed integer
    USINT,  // 8-bit unsigned integer
    UINT,   // 16-bit unsigned integer
    UDINT,  // 32-bit unsigned integer
    ULINT,  // 64-bit unsigned integer
    REAL,     // 32-bit floating point
    LREAL,    // 64-bit floating point
    BOOL,     // Boolean
    STRING,   // String
    WSTRING,  // Wide string
    TIME,     // Time duration
    DATE     // Date
};

// ANY_INT
class ANY_INT {
private:
    static const std::unordered_set<DataType> validTypes;

public:
    static bool isPartOf(DataType type);
};

// 初始化静态成员变量
const std::unordered_set<DataType> ANY_INT::validTypes = {
        DataType::SINT,
        DataType::INT,
        DataType::DINT,
        DataType::LINT,
        DataType::USINT,
        DataType::UINT,
        DataType::UDINT,
        DataType::ULINT
};

// ANY_REAL
class ANY_REAL {
private:
    static const std::unordered_set<DataType> validTypes;

public:
    static bool isPartOf(DataType type);
};

const std::unordered_set<DataType> ANY_REAL::validTypes = {
        DataType::REAL,
        DataType::LREAL
};

// ANY_NUM
class ANY_NUM {
private:
    static const std::unordered_set<DataType> validTypes;

public:
    static bool isPartOf(DataType type);
};

const std::unordered_set<DataType> ANY_NUM::validTypes = {
        DataType::SINT,
        DataType::INT,
        DataType::DINT,
        DataType::LINT,
        DataType::USINT,
        DataType::UINT,
        DataType::UDINT,
        DataType::ULINT,
        DataType::REAL,
        DataType::LREAL
};

#endif //ST_BUILDER_ANYTYPECHECK_H
