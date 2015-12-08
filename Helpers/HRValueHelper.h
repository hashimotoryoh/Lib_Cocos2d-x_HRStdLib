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
public:
    /**
     * @brief  ValueMapにキーが存在するか調べる
     * @param  vm  対象のValueMap
     * @param  key キー
     * @return true/false
     */
    static bool isExistsKey(const cocos2d::ValueMap vm, const std::string &key);
    
    /**
     * @brief  Value::Typeを型名に変換する
     * @param  type
     * @return 型名
     */
    static const std::string translateValueType(cocos2d::Value::Type type);
    
    
};


}

#endif /* HRValueHelper_h */
