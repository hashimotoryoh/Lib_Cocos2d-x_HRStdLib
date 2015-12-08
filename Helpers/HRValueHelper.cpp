//
//  HRValueHelper.cpp
//  HRStdLibDev
//
//  Created by Ryoh Hashimoto on 2015/11/16.
//
//

#include "HRValueHelper.h"
#include "HRLog.h"


using namespace HR;
USING_NS_CC;


bool HRValueHelper::isExistsKey(const cocos2d::ValueMap vm, const std::string &key)
{
    return vm.find(key) != vm.end();
}


const std::string HRValueHelper::translateValueType(cocos2d::Value::Type type)
{
    switch (type) {
        case Value::Type::NONE:        return "NONE";
        case Value::Type::BYTE:        return "BYTE";
        case Value::Type::INTEGER:     return "INTEGER";
        case Value::Type::FLOAT:       return "FLOAT";
        case Value::Type::DOUBLE:      return "DOUBLE";
        case Value::Type::BOOLEAN:     return "BOOLEAN";
        case Value::Type::STRING:      return "STRING";
        case Value::Type::VECTOR:      return "VECTOR";
        case Value::Type::MAP:         return "MAP";
        case Value::Type::INT_KEY_MAP: return "INT_KEY_MAP";
    }
    
    HRLOG("次に対応するValue::Typeは存在しません。: %d", type);
    return "ERROR";
}
