//
//  HRTimeHelper.h
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/01.
//
//

#ifndef __DevHRStdLib__HRTimeHelper__
#define __DevHRStdLib__HRTimeHelper__

#include <stdio.h>
#include "HRMacros.h"


HR_NS_BEGIN


struct HMSTime {
    int hour   = 0;
    int minute = 0;
    int second = 0;
};


class HRTimeHelper
{
    // インスタンス化を禁止
    HRTimeHelper() = delete;
    
    
public:
    /**
     * @brief  日付を取得する
     * @brief  フォーマットのプレースホルダーはPHPのdate()関数を踏襲 http://php.net/manual/ja/function.date.php
     * @param  format    フォーマット
     * @param  timestamp (現在)UNIXタイムスタンプ
     * @return 日付文字列
     */
    static std::string getDate(const std::string &format,
                               time_t timestamp = time(NULL));
    
    /**
     * @brief  2つのUNIXタイムスタンプが表す日付が同日かどうか調べる
     * @param  timestampA UNIXタイムsタンプA
     * @param  timestampB UNIXタイムスタンプB
     * @return true/false 同/違
     */
    static bool isSameDay(time_t timestampA,
                          time_t timestampB);
    
    /**
     * @brief  秒数を時分秒に変換する
     * @param  time 秒数[s]
     * @return 時間構造体 struct tm
     */
    static HR::HMSTime convertToTime(time_t s);
    
    
};


HR_NS_END


#endif /* defined(__DevHRStdLib__HRTimeHelper__) */
