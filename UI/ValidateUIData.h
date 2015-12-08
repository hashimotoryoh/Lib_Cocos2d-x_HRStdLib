//
//  ValidateUIData.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/12/01.
//
//

#ifndef __HRStandardLibrary__ValidateUIData__
#define __HRStandardLibrary__ValidateUIData__

#include "cocos2d.h"


namespace HR {


class ValidateUIData
{
public:
    /**
     * @brief  必須項目をバリデートする
     * @param  data データ
     * @param  keys 調べるキー郡
     * @return バリデート結果
     */
    static bool validateRequired(cocos2d::ValueMap &data, std::vector<std::string> keys);
    
    /**
     * @brief  型をバリデートする
     * @param  data         データ
     * @param  key          調べるキー
     * @param  expectedType 期待する型
     * @return バリデート結果
     */
    static bool validateType(cocos2d::ValueMap &data, const char *key, cocos2d::Value::Type expectedType);
    
    /**
     * @brief  ニコイチ的なデータをバリデートする
     *         片方だけ指定されている場合にfalseを返す
     * @param  data    UIデータ
     * @param  one     片方のキー
     * @param  another もう片方のキー
     * @return バリデート結果
     */
    static bool validateCouple(cocos2d::ValueMap &data, const char *one, const char *another);
    
    
};


}

#endif /* defined(__HRStandardLibrary__ValidateUIData__) */
