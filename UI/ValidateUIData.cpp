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


bool ValidateUIData::validateCouple(cocos2d::ValueMap data, const char *one, const char *another)
{
    if (HRValueHelper::isExistsKey(data, one) == HRValueHelper::isExistsKey(data, another)) {
        HRLOG("%s と %s は、どちらか一方のみを指定することは出来ません。", one, another);
        return false;
    }
    return true;
}
