//
//  HRStringHelper.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/05.
//
//

#include "HRStringHelper.h"


USING_NS_HR;


bool HRStringHelper::isEqualChar(const char *char1, const char *char2)
{
    return (strcmp(char1, char2) == 0);
}

std::string HRStringHelper::format(const char *format, ...)
{
    int size = ((int)strlen(format)) * 2 + 50;   // Use a rubric appropriate for your code
    
    std::string ret;
    va_list args;
    
    while (1) {
        ret.resize(size);
        va_start(args, format);
        int n = vsnprintf((char *)ret.data(), size, format, args);
        va_end(args);
        
        if (n > -1 && n < size) {
            ret.resize(n);
            return ret;
        }
        if (n > -1) size = n+1;
        else        size *= 2;
    }
    
    return ret;
}

std::string HRStringHelper::intToString(int num,
                                        int digits /* = 0 */)
{
    std::stringstream ss;
    ss << num;
    std::string ret = ss.str();
    
    if (digits) {
        // まず指定桁数だけ0を左に付ける
        // この時点で retの桁数 = numの桁数+digits ∴retの桁数>digits という考え
        int i = digits;
        while (i--)
            ret = "0" + ret;
        
        // ケツから指定桁切り取る
        ret = ret.substr(ret.length()-digits, digits);
    }
    
    return ret;
}

std::string HRStringHelper::replacePlaceholder(const std::string &subject,
                                               const std::string &placeholder,
                                               const std::string &word)
{
    std::string ret = subject;
    
    size_t pos = 0;
    while ((pos = ret.find(placeholder, pos)) != std::string::npos) {
        ret.replace(pos, placeholder.length(), word);
        pos += word.length();
    }
    
    return ret;
}

std::string HRStringHelper::stringFormat(const std::string &str,
                                         unsigned int unit,
                                         const std::string &delimiter,
                                         bool reverse /* = false */)
{
    std::string ret;
    int i = 1;
    
    if (reverse) {
        // 後ろから
        const auto begin = str.rbegin();
        const auto end   = str.rend();
        for (auto iter=begin; iter!=end; iter++) {
            ret = (*iter) + ret;
            if (i%unit == 0 && iter+1 != end) ret = delimiter + ret;
            i++;
        }
    }
    else {
        // 前から
        const auto begin = str.begin();
        const auto end   = str.end();
        for (auto iter=begin; iter!=end; iter++) {
            ret = ret + (*iter);
            if (i%unit == 0 && iter+1 != end) ret = ret + delimiter;
            i++;
        }
    }
    
    return ret;
}

std::string HRStringHelper::multiByteStringFormat(const std::string &str,
                                                  unsigned int unit,
                                                  const std::string &delimiter,
                                                  bool reverse /* = false */)
{
    // TODO: 未実装
}

std::string HRStringHelper::numberFormat(int num)
{
    unsigned int absNum = std::abs(num);
    std::string ret = HRStringHelper::stringFormat(HRStringHelper::intToString(absNum), 3, ",", true);
    
    return (num > 0) ? ret : "-"+ret;
}

cocos2d::Color3B HRStringHelper::convertToColor(const std::string &colorCode)
{
    // #が付いていれば落とす
    std::string code = (colorCode.length() == 7) ? colorCode.substr(1, 6) : colorCode;
    
    std::stringstream codeR, codeG, codeB;
    int r, g, b;
    
    codeR << code.substr(0, 2);
    codeR >> std::hex >> r;
    
    codeG << code.substr(2, 2);
    codeG >> std::hex >> g;
    
    codeB << code.substr(4, 2);
    codeB >> std::hex >> b;
    
    return cocos2d::Color3B(r, g, b);
}
