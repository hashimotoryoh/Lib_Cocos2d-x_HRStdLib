//
//  HRApplicationHelper.cpp
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#include "HRApplicationHelper.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "HRiOSHelper.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
//#include "AndroidHelper.h"
#endif
#include "HRConfig.h"
#include "HRLog.h"


USING_NS_HR;
USING_NS_CC;


std::string HRApplicationHelper::getOSVersion()
{
    std::string version = STRING_UNSET;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    version = HRiOSHelper::getOSVersion();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return version;
}


std::string HRApplicationHelper::getDeviceName()
{
    std::string deviceName = STRING_UNSET;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    deviceName = HRiOSHelper::getDeviceName();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return deviceName;
}


ValueMap HRApplicationHelper::getNetworkInfo()
{
    ValueMap info = ValueMap();
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    info = HRiOSHelper::getNetworkInfo();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return info;
}


std::string HRApplicationHelper::getApplicationVersion()
{
    std::string version = STRING_UNSET;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    version = HRiOSHelper::getApplicationVersion();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return version;
}


std::string HRApplicationHelper::getBuildVersion()
{
    std::string version;
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    version = HRiOSHelper::getBuildVersion();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    return version;
}


void HRApplicationHelper::copyToClipboard(const std::string &text)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    HRiOSHelper::copyToClipboard(text);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    HRLOG("文字列[%s]をクリップボードにコピーしました。", text.c_str());
}
