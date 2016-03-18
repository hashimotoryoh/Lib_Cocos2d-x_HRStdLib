//
//  HRiOSHelper.mm
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#include "HRiOSHelper.h"
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#include "HRApplicationHelper.h"


USING_NS_HR;
USING_NS_CC;


std::string HRiOSHelper::getOSVersion()
{
    return [[[UIDevice currentDevice] systemVersion] UTF8String];
}


std::string HRiOSHelper::getDeviceName()
{
    return [[[UIDevice currentDevice] name] UTF8String];
}


ValueMap HRiOSHelper::getNetworkInfo()
{
    CTCarrier* carrier = [[[CTTelephonyNetworkInfo alloc] init] subscriberCellularProvider];
    
    ValueMap info;
    info[HRApplicationHelper::NETWORK_INFO_KEY_CARRIER_NAME]        = [[carrier carrierName] UTF8String];
    info[HRApplicationHelper::NETWORK_INFO_KEY_MOBILE_COUNTRY_CODE] = [[carrier mobileCountryCode] UTF8String];
    info[HRApplicationHelper::NETWORK_INFO_KEY_MOBILE_NETWORK_CODE] = [[carrier mobileNetworkCode] UTF8String];
    info[HRApplicationHelper::NETWORK_INFO_KEY_ISO_COUNTRY_CODE]    = [[carrier isoCountryCode] UTF8String];
    info[HRApplicationHelper::NETWORK_INFO_KEY_ALLOWS_VOIP]         = [carrier allowsVOIP];
    
    return info;
}


std::string HRiOSHelper::getApplicationVersion()
{
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"] UTF8String];
}


std::string HRiOSHelper::getBuildVersion()
{
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"] UTF8String];
}


void HRiOSHelper::copyToClipboard(const std::string &text)
{
    [[UIPasteboard generalPasteboard] setString:[NSString stringWithUTF8String:text.c_str()]];
}
