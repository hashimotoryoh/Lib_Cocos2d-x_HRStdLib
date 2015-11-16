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
     * @brief 引数をフォーマットした文字列を得る。
     * @param  format フォーマット
     * @param  ...    フォーマットに対応する引数
     * @return フォーマットされた文字列
     */
    static std::string format(const char *format, ...);


};


}


#pragma mark - MACROs

#define STRING_FORMAT(f, ...) HR::HRStringHelper::format(f, ##__VA_ARGS__);


#endif
