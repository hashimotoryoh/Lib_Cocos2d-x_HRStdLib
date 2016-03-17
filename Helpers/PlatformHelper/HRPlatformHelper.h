//
//  HRPlatformHelper.h
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#ifndef __DevHRStdLib__HRPlatformHelper__
#define __DevHRStdLib__HRPlatformHelper__

#include "HRMacros.h"


HR_NS_BEGIN


class HRPlatformHelper
{
    // インスタンス化を禁止
    HRPlatformHelper() = delete;
    
    
public:
    /**
     * @brief OSのバージョンを取得する
     */
    static std::string getOSVersion();
    
    
};


HR_NS_END


#endif /* defined(__DevHRStdLib__HRPlatformHelper__) */
