//
//  HRPlatformHelper.cpp
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#include "HRPlatformHelper.h"
#include "cocos2d.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "HRiOSHelper.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
//#include "AndroidHelper.h"
#endif


USING_NS_HR;


std::string HRPlatformHelper::getOSVersion()
{
    std::string version;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    version = HRiOSHelper::getOSVersion();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return version;
}
