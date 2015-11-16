//
//  HRLog.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/02.
//
//

#ifndef HRStandardLibrary_HRLog_h
#define HRStandardLibrary_HRLog_h

#include "cocos2d.h"
#include "HRStringHelper.h"


/**
 * @brief 標準ログ出力。出力を実行したクラス名、メソッド名を追記して出力する。
 *
 * @param format 出力用フォーマット
 * @param ...    フォーマットに対応する出力引数
 */
#define HRLOG(format, ...)                                                                      \
{                                                                                               \
    std::string newFormat = std::string(__PRETTY_FUNCTION__) + " / " + std::string(format);     \
    CCLOG(newFormat.c_str(), ##__VA_ARGS__, "");                                                \
}


/**
 * @brief 標準エラー出力。ログ出力と同時にプログラムを停止させる。
 *
 * @param format 出力用フォーマット
 * @param ...    フォーマットに対応する出力引数
 */
#define HRERROR(format, ...)                                                    \
{                                                                               \
    std::string newFormat = std::string("HRERROR: ") + std::string(format);     \
    std::string message   = STRING_FORMAT(newFormat.c_str(), ##__VA_ARGS__);    \
    CCASSERT(false, message.c_str());                                           \
}


/**
 * @brief 標準アサーション。対象がfalseならエラーとしてプログラムを停止する。
 *
 * @param target アサーション対象
 * @param format 出力用フォーマット
 * @param ...    フォーマットに対応する出力引数
 */
#define HRASSERT(target, format, ...)                                               \
{                                                                                   \
    if (!target) {                                                                  \
        std::string newFormat = std::string("HRASSERT: ") + std::string(format);    \
        std::string message   = STRING_FORMAT(newFormat.c_str(), ##__VA_ARGS__);    \
        CCASSERT(false, message.c_str());                                           \
    }                                                                               \
}


#endif
