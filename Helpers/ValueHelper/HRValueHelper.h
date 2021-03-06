//
//  HRValueHelper.h
//  HRStdLibDev
//
//  Created by Ryoh Hashimoto on 2015/11/16.
//
//

#ifndef HRValueHelper_h
#define HRValueHelper_h

#include "cocos2d.h"
#include "HRMacros.h"


HR_NS_BEGIN


class HRValueHelper
{
    // インスタンス化を禁止
    HRValueHelper() = delete;
    
    
#pragma mark - Static Methods
public:
#pragma mark Dump cocos2d::Value Type Method (for DEBUG)
    /**
     * @brief Valueの中身を良い感じに出力する
     * @brief マクロ化済み HR_VALUE_LOG
     * @param value 出力するValue
     */
    static void valueDump(const cocos2d::Value& value);
    static void valueDump(const cocos2d::ValueVector& vector) { HRValueHelper::valueDump(cocos2d::Value(vector)); };
    static void valueDump(const cocos2d::ValueMap& map)       { HRValueHelper::valueDump(cocos2d::Value(map));    };
    static void valueDump(const cocos2d::ValueMapIntKey& map) { HRValueHelper::valueDump(cocos2d::Value(map));    };
    
    
#pragma mark Check Is Equal (cocos2d::Value) A and B
    /**
     * @brief  Valueの中身が等しいか調べる
     * @param  value1 値1
     * @param  value2 値2
     * @return true/false 同/違
     */
    static bool isEqual(const cocos2d::Value &value1,
                        const cocos2d::Value &value2);
    static bool isEqual(const cocos2d::ValueVector &vector1,
                        const cocos2d::ValueVector &vector2,
                        bool considerOrder = false)          { return HRValueHelper::isEqualVector(vector1, vector2, considerOrder); };
    static bool isEqual(const cocos2d::ValueMap &map1,
                        const cocos2d::ValueMap &map2)       { return HRValueHelper::isEqualMap(map1, map2);                         };
    static bool isEqual(const cocos2d::ValueMapIntKey &map1,
                        const cocos2d::ValueMapIntKey &map2) { return HRValueHelper::isEqualIntKeyMap(map1, map2);                   };
    
    
#pragma mark Check Is Exists Key In Map
    /**
     * @brief  ValueMapにキーが存在するか調べる
     * @param  map  対象のValueMap
     * @param  key  キー
     * @return true/false
     */
    static bool isExistsKey(const cocos2d::ValueMap &map,
                            const std::string &key);
    
    /**
     * @brief  ValueMapIntKeyにキーが存在するか調べる
     * @param  map  対象のValueMapIntKey
     * @param  key  キー
     * @return true/false
     */
    static bool isExistsKey(const cocos2d::ValueMapIntKey &map,
                            int key);
    
    
#pragma mark Check Is Contains Value In Vector
    /**
     * @brief  ValueVector中にValueが存在するか調べる
     * @param  vector 対象のValueVector
     * @param  value  値
     * @return true/false 存在する/しない
     */
    static bool isContainsValue(const cocos2d::ValueVector &vector,
                                const cocos2d::Value &value);
    static bool isContainsValue(const cocos2d::ValueVector &vector, const cocos2d::ValueMap &mapValue)             { return HRValueHelper::isContainsValue(vector, cocos2d::Value(mapValue));       };
    static bool isContainsValue(const cocos2d::ValueVector &vector, const cocos2d::ValueVector &vectorValue)       { return HRValueHelper::isContainsValue(vector, cocos2d::Value(vectorValue));    };
    static bool isContainsValue(const cocos2d::ValueVector &vector, const cocos2d::ValueMapIntKey &intKeyMapValue) { return HRValueHelper::isContainsValue(vector, cocos2d::Value(intKeyMapValue)); };
    
    
#pragma mark etc
    /**
     * @brief  Value::Typeを型名に変換する
     * @param  type
     * @return 型名
     */
    static const std::string translateValueType(cocos2d::Value::Type type);
    
    
#pragma mark - Private Methods
private:
    /**
     * @brief  ValueVectorの中身が全て等しいか調べる
     * @param  vector1       ベクター1
     * @param  vector2       ベクター2
     * @param  considerOrder (false)順序を考慮するか(する/しない)
     * @return true/false 同/違
     */
    static bool isEqualVector(const cocos2d::ValueVector vector1,
                              const cocos2d::ValueVector vector2,
                              bool considerOrder = false);
    
    /**
     * @brief  ValueMapの中身が全て等しいか調べる
     * @param  map1 マップ1
     * @param  map2 マップ2
     * @return true/false 同/違
     */
    static bool isEqualMap(const cocos2d::ValueMap &map1,
                           const cocos2d::ValueMap &map2);
    
    /**
     * @brief  ValueMapIntKeyの中身が全て等しいか調べる
     * @param  map1 マップ1
     * @param  map2 マップ2
     * @return true/false 同/違
     */
    static bool isEqualIntKeyMap(const cocos2d::ValueMapIntKey &map1,
                                 const cocos2d::ValueMapIntKey &map2);
    
    /**
     * @brief  ダンプテキストを再帰的に取得する
     * @param  value 対象のValue
     * @param  level (1)階層
     * @return ダンプテキスト
     */
    static std::string getDumpText(const cocos2d::Value& value,
                                   unsigned int level = 1);
    
    
};


HR_NS_END


#define HR_VALUE_LOG(value) \
{ \
    HRValueHelper::valueDump(value); \
}


#endif /* HRValueHelper_h */
