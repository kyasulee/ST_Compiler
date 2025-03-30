//
// Created by 84648 on 2025/3/30.
//
#include "AnyTypeCheck.h"

bool ANY_INT::isPartOf(DataType type) {
    return validTypes.find(type) != validTypes.end();
}

bool ANY_REAL::isPartOf(DataType type) {
    return validTypes.find(type) != validTypes.end();
}

bool ANY_NUM::isPartOf(DataType type) {
    return validTypes.find(type) != validTypes.end();
}