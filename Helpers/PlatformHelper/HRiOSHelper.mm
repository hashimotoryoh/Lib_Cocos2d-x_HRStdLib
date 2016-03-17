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
    NSString *osVersion = [[UIDevice currentDevice] systemVersion];
    return [osVersion UTF8String];
}
