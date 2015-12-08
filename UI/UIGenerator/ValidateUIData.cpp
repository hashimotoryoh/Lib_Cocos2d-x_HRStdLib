//
//  ValidateUIData.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/12/01.
//
//

#include "ValidateUIData.h"
#include "HRLog.h"
#include "HRValueHelper.h"


using namespace HR;
USING_NS_CC;


bool ValidateUIData::validateRequired(cocos2d::ValueMap &data, std::vector<std::string> keys)
{
    bool result = true;
    
    for (std::string key : keys) {
        if (!HRValueHelper::isExistsKey(data, key)) {
            HRLOG("次のキーがありません。: %s", key.c_str());
            result = false;
        }
    }
    
    return result;
}


bool ValidateUIData::validateType(cocos2d::ValueMap &data, const char *key, cocos2d::Value::Type expectedType)
{
    if (!ValidateUIData::validateRequired(data, {std::string(key)})) return false;
    
    Value::Type type = data.at(key).getType();
    if (type != expectedType) {
        // FLOAT と DOUBLE は等価として扱う救済措置
        if ((expectedType == Value::Type::FLOAT || expectedType == Value::Type::DOUBLE)
            && (type == Value::Type::FLOAT || type == Value::Type::DOUBLE)) {
            return true;
        }
        
        HRLOG("\"%s\" は %s でなければいけません。: %s", key, HRValueHelper::translateValueType(expectedType).c_str(), HRValueHelper::translateValueType(type).c_str());
        return false;
    }
    
    return true;
}


bool ValidateUIData::validateCouple(cocos2d::ValueMap &data, const char *one, const char *another)
{
    if (HRValueHelper::isExistsKey(data, one) != HRValueHelper::isExistsKey(data, another)) {
        HRLOG("%s と %s は、どちらか一方のみを指定することは出来ません。", one, another);
        return false;
    }
    return true;
}
