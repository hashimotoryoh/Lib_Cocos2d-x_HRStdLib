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


namespace HR {


class HRTimeHelper
{
public:
    /**
     * @brief  日付を取得する
     * @brief  フォーマットのプレースホルダーはPHPのdate()関数を踏襲 http://php.net/manual/ja/function.date.php
     * @param  format    フォーマット
     * @param  timestamp (現在)UNIXタイムスタンプ
     * @return 日付文字列
     */
    static std::string getDate(std::string format,
                               const time_t timestamp = time(NULL));
    
    /**
     * @brief  2つのUNIXタイムスタンプが表す日付が同日かどうか調べる
     * @param  timestampA UNIXタイムsタンプA
     * @param  timestampB UNIXタイムスタンプB
     * @return true/false 同/違
     */
    static bool isSameDay(const time_t timestampA,
                          const time_t timestampB);
    
    
};


}


#endif /* defined(__DevHRStdLib__HRTimeHelper__) */
