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


bool HRValueHelper::isEqual(const cocos2d::Value &value1,
                            const cocos2d::Value &value2)
{
    // 型が違えばもう違う
    if (value1.getType() != value2.getType()) return false;
    
    /***** 以下、value1とvalue2の型が等しいことは保証される *****/
    
    switch (value1.getType()) {
        case Value::Type::NONE:        return true;     // 中身が無いので比較する必要無し
        case Value::Type::BYTE:        return (value1.asByte()   == value2.asByte());
        case Value::Type::INTEGER:     return (value1.asInt()    == value2.asInt());
        case Value::Type::FLOAT:       return (value1.asFloat()  == value2.asFloat());
        case Value::Type::DOUBLE:      return (value1.asDouble() == value2.asDouble());
        case Value::Type::BOOLEAN:     return (value1.asBool()   == value2.asBool());
        case Value::Type::STRING:      return (value1.asString() == value2.asString());
        case Value::Type::VECTOR:      return HRValueHelper::isEqualVector(value1.asValueVector(), value2.asValueVector());
        case Value::Type::MAP:         return HRValueHelper::isEqualMap(value1.asValueMap(), value2.asValueMap());
        case Value::Type::INT_KEY_MAP: return HRValueHelper::isEqualIntKeyMap(value1.asIntKeyMap(), value2.asIntKeyMap());
    }
    
    HRERROR("cocos2d::Value型の値のタイプが不正です。: value1: %d, value2: %d", value1.getType(), value2.getType());
    return false;
}


bool HRValueHelper::isExistsKey(const cocos2d::ValueMap &map,
                                const std::string &key)
{
    return map.find(key) != map.end();
}

bool HRValueHelper::isExistsKey(const cocos2d::ValueMapIntKey &map,
                                const int key)
{
    return map.find(key) != map.end();
}


bool HRValueHelper::isContainsValue(const cocos2d::ValueVector &vector,
                                    const cocos2d::Value &value)
{
    for (Value comparison : vector)
        // 同値が見つかった時点でtrueを返却
        if (HRValueHelper::isEqual(value, comparison)) return true;
    
    return false;
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



#pragma mark - Private Methods

bool HRValueHelper::isEqualVector(const cocos2d::ValueVector vector1,
                                  const cocos2d::ValueVector vector2,
                                  bool considerOrder /* = false */)
{
    // 要素数が違えばもう違う
    if (vector1.size() != vector2.size()) return false;
    
    /***** 以下、vector1とvector2の要素数が等しいことは保証される *****/
    
    if (considerOrder) {
        // 順序を考慮する場合
        // vector1, vector2の同じ要素番号に格納されている値が、全て同じなら同じ。
        for (unsigned int i=0; i<vector1.size(); i++)
            // 一つでも違えば違う。
            if (!HRValueHelper::isEqual(vector1.at(i), vector2.at(i))) return false;
    }
    else {
        // 順序を考慮しない場合
        // 要素数が等しいことは保証されているので、value1の要素が全てvalue2に入っていれば同じ。
        for (Value childValue1 : vector1)
            // 一つでも違えば違う。
            if (!HRValueHelper::isContainsValue(vector2, childValue1)) return false;
    }
    
    return true;
}


bool HRValueHelper::isEqualMap(const cocos2d::ValueMap &map1,
                               const cocos2d::ValueMap &map2)
{
    // 要素数が違えばもう違う
    if (map1.size() != map2.size()) return false;
    
    /**** 以下、map1とmap2の要素数が等しいことは保証される *****/
    
    // 要素数が等しいことは保証されているので、value1の全ての要素について
    //   - 同じキーが有る
    //   - そのキーに対する値が等しい
    // なら同じ。
    for (std::pair<std::string, Value> pair : map1) {
        const std::string key        = pair.first;
        const Value       childValue = pair.second;
        // 一つでも違えば違う。
        if (!HRValueHelper::isExistsKey(map2, key)
            ||
            !HRValueHelper::isEqual(childValue, map2.at(key))) return false;
    }
    
    return true;
}


bool HRValueHelper::isEqualIntKeyMap(const cocos2d::ValueMapIntKey &map1,
                                     const cocos2d::ValueMapIntKey &map2)
{
    // 要素数が違えばもう違う
    if (map1.size() != map2.size()) return false;
    
    /**** 以下、map1とmap2の要素数が等しいことは保証される *****/
    
    // 要素数が等しいことは保証されているので、value1の全ての要素について
    //   - 同じキーが有る
    //   - そのキーに対する値が等しい
    // なら同じ。
    for (std::pair<int, Value> pair : map1) {
        const int key          = pair.first;
        const Value childValue = pair.second;
        // 一つでも違えば違う。
        if (!HRValueHelper::isExistsKey(map2, key)
            ||
            !HRValueHelper::isEqual(childValue, map2.at(key))) return false;
    }
    
    return true;
}
