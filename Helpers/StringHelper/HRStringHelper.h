//
//  HRStringHelper.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/05.
//
//

#ifndef __HRStandardLibrary__HRStringHelper__
#define __HRStandardLibrary__HRStringHelper__


namespace HR {


class HRStringHelper
{
public:
    /**
     * @brief  char型文字列が同じかどうか比較する
     * @param  char1 文字列
     * @param  char2 文字列
     * @return true/false
     */
    static bool isEqualChar(const char *char1, const char *char2);
    
    /**
     * @brief  引数をフォーマットした文字列を得る。
     * @param  format フォーマット
     * @param  ...    フォーマットに対応する引数
     * @return フォーマットされた文字列
     */
    static std::string format(const char *format, ...);
    
    /**
     * @brief  数値を文字列に変換する
     *         to_string()がAndroidで非対応な為
     * @param  num 数値
     * @return 文字列
     */
    static std::string intToString(int num);
    
    /**
     * @brief  文字列の指定文字数毎にデリミタを挟む
     * @param  str       文字列
     * @param  unit      挟む間隔
     * @param  delimiter デリミタ
     * @param  reverse   (false)後ろから数えるか
     * @return 整形後の文字列
     */
    static std::string stringFormat(const std::string &str, unsigned int unit, const std::string &delimiter, bool reverse = false);
    
    /**
     * @brief  数値の3桁毎にカンマを挿入する
     * @param  num 数値
     * @return カンマ挿入後の数値
     */
    static std::string numberFormat(int num);


};


}


#pragma mark - MACROs

#define STRING_FORMAT(f, ...) HR::HRStringHelper::format(f, ##__VA_ARGS__);


#endif
