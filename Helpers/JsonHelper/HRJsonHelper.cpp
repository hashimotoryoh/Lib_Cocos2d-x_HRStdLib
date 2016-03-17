//
//  HRJsonHelper.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/02.
//
//

#include "HRJsonHelper.h"


USING_NS_HR;


cocos2d::Value HRJsonHelper::parseJsonStringToValue(const std::string &jsonString)
{
    rapidjson::Document doc;
    
    bool hasParseError = doc.Parse<0>(jsonString.c_str()).HasParseError();
    HRASSERT(!hasParseError, "JSONの解析に失敗しました。: %s", doc.GetParseError());
    
    return HRJsonHelper::convertJsonValueToValue(doc);
}


cocos2d::Value HRJsonHelper::parseJsonFileToValue(const std::string &jsonFilePath)
{
    std::string jsonString = cocos2d::FileUtils::getInstance()->getStringFromFile(jsonFilePath);
    return parseJsonStringToValue(jsonString);
}


cocos2d::Value HRJsonHelper::convertJsonValueToValue(const rapidjson::Value &jsonValue)
{
    JSONType type = HRJsonHelper::getJsonType(jsonValue);
    
    switch (type) {
        case JSONType::Object: return cocos2d::Value(convertJsonValueToMap(jsonValue));
        case JSONType::Array : return cocos2d::Value(convertJsonValueToVector(jsonValue));
        case JSONType::String: return cocos2d::Value(convertJsonValueToString(jsonValue));
        case JSONType::Int   : return cocos2d::Value(convertJsonValueToInt(jsonValue));
        case JSONType::Double: return cocos2d::Value(convertJsonValueToDouble(jsonValue));
        case JSONType::Bool  : return cocos2d::Value(convertJsonValueToBool(jsonValue));
        case JSONType::Null  : return cocos2d::Value::Null;
            
        case JSONType::Unknown: // ↓↓↓
        default:
            HRERROR("JSON値の変換に失敗しました。JSON値の型が不明です。");
    }
    
    return cocos2d::Value::Null;
}


JSONType HRJsonHelper::getJsonType(const rapidjson::Value &jsonValue)
{
    if      (jsonValue.IsObject()) return JSONType::Object;
    else if (jsonValue.IsArray())  return JSONType::Array;
    else if (jsonValue.IsString()) return JSONType::String;
    else if (jsonValue.IsInt())    return JSONType::Int;
    else if (jsonValue.IsNumber()) return JSONType::Double;
    else if (jsonValue.IsBool())   return JSONType::Bool;
    else if (jsonValue.IsNull())   return JSONType::Null;
    
    /* else */                     return JSONType::Unknown;
}
