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


namespace HR {


class HRValueHelper
{
#pragma mark - Static Methods
public:
#pragma mark Check Is Equal (cocos2d::Value) A and B
    /**
     * @brief  Valueの中身が等しいか調べる
     * @param  value1 値1
     * @param  value2 値2
     * @return true/false 同/違
     */
    static bool isEqual(const cocos2d::Value &value1,
                        const cocos2d::Value &value2);
    
    /**
     * @brief  ValueVectorの中身が等しいか調べる
     * @param  vector1       ベクター1
     * @param  vector2       ベクター2
     * @param  considerOrder (false)順序を考慮するか
     * @return true/false 同/違
     */
    static bool isEqual(const cocos2d::ValueVector &vector1,
                        const cocos2d::ValueVector &vector2,
                        const bool considerOrder = false)
    {
        return HRValueHelper::isEqualVector(vector1, vector2, considerOrder);
    };
    
    /**
     * @brief  ValueMapの中身が全て等しいか調べる
     * @param  map1 マップ1
     * @param  map2 マップ2
     * @return true/false 同/違
     */
    static bool isEqual(const cocos2d::ValueMap &map1,
                        const cocos2d::ValueMap &map2)
    {
        return HRValueHelper::isEqualMap(map1, map2);
    };
    
    /**
     * @brief  ValueMapIntKeyの中身が全て等しいか調べる
     * @param  map1 マップ1
     * @param  map2 マップ2
     * @return true/false 同/違
     */
    static bool isEqual(const cocos2d::ValueMapIntKey &map1,
                        const cocos2d::ValueMapIntKey &map2)
    {
        return HRValueHelper::isEqualIntKeyMap(map1, map2);
    };
    
    
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
                            const int key);
    
    
#pragma mark Check Is Contains Value In Vector
    /**
     * @brief  ValueVector中にValueが存在するか調べる
     * @param  vector 対象のValueVector
     * @param  value  値
     * @return true/false 存在する/しない
     */
    static bool isContainsValue(const cocos2d::ValueVector &vector,
                                const cocos2d::Value value);
    static bool isContainsValue(const cocos2d::ValueVector &vector, const cocos2d::ValueMap &mapValue)             { return HRValueHelper::isContainsValue(vector, cocos2d::Value(mapValue));       };
    static bool isContainsValue(const cocos2d::ValueVector &vector, const cocos2d::ValueVector &vectorValue)       { return HRValueHelper::isContainsValue(vector, cocos2d::Value(vectorValue));    };
    static bool isContainsValue(const cocos2d::ValueVector &vector, const cocos2d::ValueMapIntKey &intKeyMapValue) { return HRValueHelper::isContainsValue(vector, cocos2d::Value(intKeyMapValue)); };
    
    
#pragma mark etc
    /**
     * @brief  Value::Typeを型名に変換する
     * @param  type
     * @return 型名
     */
    static const std::string translateValueType(const cocos2d::Value::Type type);
    
    
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
                              const bool considerOrder = false);
    
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
    
    
};


}

#endif /* HRValueHelper_h */
