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
#include "HRPlatformHelper.h"


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
    info[HRPlatformHelper::NETWORK_INFO_KEY_CARRIER_NAME]        = [[carrier carrierName] UTF8String];
    info[HRPlatformHelper::NETWORK_INFO_KEY_MOBILE_COUNTRY_CODE] = [[carrier mobileCountryCode] UTF8String];
    info[HRPlatformHelper::NETWORK_INFO_KEY_MOBILE_NETWORK_CODE] = [[carrier mobileNetworkCode] UTF8String];
    info[HRPlatformHelper::NETWORK_INFO_KEY_ISO_COUNTRY_CODE]    = [[carrier isoCountryCode] UTF8String];
    info[HRPlatformHelper::NETWORK_INFO_KEY_ALLOWS_VOIP]         = [carrier allowsVOIP];
    
    return info;
}
