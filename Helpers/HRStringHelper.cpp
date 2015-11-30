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

std::string HRStringHelper::intToString(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

std::string HRStringHelper::stringFormat(const std::string &str, unsigned int unit, const std::string &delimiter)
{
    int size = (int)str.size();
    
    std::string ret;
    for (int i =  1; i < size + 1 ; i++){
        std::string tmp = str.substr(i-1,1);
        if ((size - i + 1) % unit == 0 && i != 1) ret.append(delimiter);
        ret.append(tmp);
    }
    return ret;
}
