//
//  HRApplicationHelper.h
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/17.
//
//

#ifndef __DevHRStdLib__HRApplicationHelper__
#define __DevHRStdLib__HRApplicationHelper__

#include "HRMacros.h"
#include "cocos2d.h"


HR_NS_BEGIN


class HRApplicationHelper
{
    // インスタンス化を禁止
    HRApplicationHelper() = delete;
    
    
public:
    /**
     * @brief OSのバージョンを取得する
     */
    static std::string getOSVersion();
    
    /**
     * @brief 端末の名称を取得する
     */
    static std::string getDeviceName();
    
    
    /**
     * @brief ネットワーク情報を取得する
     */
    static cocos2d::ValueMap getNetworkInfo();
    static constexpr char *NETWORK_INFO_KEY_CARRIER_NAME        = (char*)"CarrierName";
    static constexpr char *NETWORK_INFO_KEY_MOBILE_COUNTRY_CODE = (char*)"MobileCountryCode";
    static constexpr char *NETWORK_INFO_KEY_MOBILE_NETWORK_CODE = (char*)"MobileNetworkCode";
    static constexpr char *NETWORK_INFO_KEY_ISO_COUNTRY_CODE    = (char*)"ISOCountryCode";
    static constexpr char *NETWORK_INFO_KEY_ALLOWS_VOIP         = (char*)"AllowsVOIP";
    
    /**
     * @brief アプリのバージョンを取得する
     */
    static std::string getApplicationVersion();
    
    /**
     * @brief アプリのビルドバージョンを取得する
     */
    static std::string getBuildVersion();
    
    /**
     * @brief 文字列をクリップボードにコピーする
     */
    static void copyToClipboard(const std::string& text);
    
    
};


HR_NS_END


#endif /* defined(__DevHRStdLib__HRApplicationHelper__) */
