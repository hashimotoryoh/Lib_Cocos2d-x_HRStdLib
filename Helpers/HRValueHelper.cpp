//
//  HRValueHelper.cpp
//  HRStdLibDev
//
//  Created by Ryoh Hashimoto on 2015/11/16.
//
//

#include "HRValueHelper.h"


using namespace HR;
USING_NS_CC;


bool HRValueHelper::isExistsKey(const cocos2d::ValueMap vm, const std::string &key)
{
    return vm.find(key) != vm.end();
}