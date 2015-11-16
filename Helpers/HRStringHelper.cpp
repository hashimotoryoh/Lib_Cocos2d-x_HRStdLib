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
