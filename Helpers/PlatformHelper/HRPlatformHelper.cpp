//
//  HRPlatformHelper.cpp
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#include "HRPlatformHelper.h"
#include "cocos2d.h"
#include "HRConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "HRiOSHelper.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
//#include "AndroidHelper.h"
#endif


USING_NS_HR;


std::string HRPlatformHelper::getOSVersion()
{
    std::string version = STRING_UNSET;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    version = HRiOSHelper::getOSVersion();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return version;
}


std::string HRPlatformHelper::getDeviceName()
{
    std::string deviceName = STRING_UNSET;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    deviceName = HRiOSHelper::getDeviceName();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return deviceName;
}
