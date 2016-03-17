//
//  HRiOSHelper.h
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#ifndef __DevHRStdLib__HRiOSHelper__
#define __DevHRStdLib__HRiOSHelper__

#include "HRMacros.h"


HR_NS_BEGIN


class HRiOSHelper
{
    // インスタンス化を禁止
    HRiOSHelper() = delete;
    
    
public:
    /**
     * @brief OSのバージョンを取得する
     */
    static std::string getOSVersion();
    
    /**
     * @brief 端末の名称を取得する
     */
    static std::string getDeviceName();
    
    
};


HR_NS_END


#endif /* defined(__DevHRStdLib__HRiOSHelper__) */