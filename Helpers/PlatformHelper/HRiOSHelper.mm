//
//  HRiOSHelper.mm
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#include "HRiOSHelper.h"


USING_NS_HR;


std::string HRiOSHelper::getOSVersion()
{
    return [[[UIDevice currentDevice] systemVersion] UTF8String];
}


std::string HRiOSHelper::getDeviceName()
{
    return [[[UIDevice currentDevice] name] UTF8String];
}
