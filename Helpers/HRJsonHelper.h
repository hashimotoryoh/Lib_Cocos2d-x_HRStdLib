//
//  HRJsonHelper.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/02.
//
//

#ifndef HRStandardLibrary_HRJsonHelper_h
#define HRStandardLibrary_HRJsonHelper_h

#include "cocos2d.h"
#include "json/document.h"
#include "HRLog.h"

namespace HR {

    
enum class JSONType {
    Object,
    Array,
    String,
    Int,
    Double,
    Bool,
    Null,
    
    Unknown
};


class HRJsonHelper
{
public:
    /**
     * @brief JSON文字列を解析してcocos2d::Valueに落としこむ。
     *
     * @param  jsonString JSON文字列
     * @return 解析したJSON
     */
    static cocos2d::Value parseJsonStringToValue(const std::string &jsonString);
    
    /**
     * @brief JSONファイルを解析してcocos2d::Valueに落としこむ。
     *
     * @param  jsonFilePath JSONファイルのパス
     * @return 解析したJSON
     */
    static cocos2d::Value parseJsonFileToValue(const std::string &jsonFilePath);
    
    /**
     * @brief JSON値をcocos2d::Valueに変換する。
     *
     * @param  jsonValue JSON値
     * @return 変換したValue
     */
    static cocos2d::Value convertJsonValueToValue(const rapidjson::Value &jsonValue);
    
    /**
     * @brief JSON値のタイプを取得する。
     *
     * @param  jsonValue JSON値
     * @return タイプ
     */
    static JSONType getJsonType(const rapidjson::Value &jsonValue);

    
private:
    
#pragma mark JSON Value Convert Methods
    
    static cocos2d::ValueMap convertJsonValueToMap(const rapidjson::Value &jsonValue)
    {
        cocos2d::ValueMap map;
        for (rapidjson::Value::ConstMemberIterator itr = jsonValue.MemberonBegin();
             itr != jsonValue.MemberonEnd();
             ++itr)
        {
            cocos2d::Value value = convertJsonValueToValue(itr->value);
            map.insert(std::make_pair(itr->name.GetString(), value));
        }
        
        return map;
    }
    
    static cocos2d::ValueVector convertJsonValueToVector(const rapidjson::Value &jsonValue)
    {
        cocos2d::ValueVector vector;
        for (rapidjson::Value::ConstValueIterator itr = jsonValue.onBegin();
             itr != jsonValue.onEnd();
             ++itr)
        {
            cocos2d::Value value = convertJsonValueToValue(*itr);
            vector.push_back(value);
        }
        
        return vector;
    }
    
    static std::string convertJsonValueToString(const rapidjson::Value &jsonValue) { return jsonValue.GetString(); }
    static int         convertJsonValueToInt(const rapidjson::Value &jsonValue)    { return jsonValue.GetInt();    }
    static double      convertJsonValueToDouble(const rapidjson::Value &jsonValue) { return jsonValue.GetDouble(); }
    static bool        convertJsonValueToBool(const rapidjson::Value &jsonValue)   { return jsonValue.GetBool();   }


};


} // namespace HR

#endif
