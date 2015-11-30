//
//  HRStringHelper.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/05.
//
//

#include "HRStringHelper.h"

using namespace HR;


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

std::string HRStringHelper::intToString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
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

std::string HRStringHelper::numberFormat(int num)
{
    unsigned int absNum = std::abs(num);
    std::string ret = HRStringHelper::stringFormat(HRStringHelper::intToString(absNum), 3, ",", true);
    
    return (num > 0) ? ret : "-"+ret;
}
