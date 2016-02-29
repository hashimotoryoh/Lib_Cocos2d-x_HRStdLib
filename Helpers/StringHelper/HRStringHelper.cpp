//
//  HRStringHelper.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/05.
//
//

#include "HRStringHelper.h"


const char *WEEKDAY_EN[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
const char *MONTH_EN[]   = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


using namespace HR;


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
        int i = digits;
        while (i--)
            ret = "0" + ret;
        
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

std::string HRStringHelper::getDate(std::string format,
                                    time_t timestamp /* = -1   */)
{
    timestamp = (timestamp == -1) ? time(NULL) : timestamp;
    struct tm *time = localtime(&timestamp);
    
    // フォーマットはPHPのdate()関数を踏襲
    std::string Y = HRStringHelper::intToString(1900 + time->tm_year);      // 西暦 4桁
    std::string y = HRStringHelper::intToString(time->tm_year % 100);       // 西暦 下2桁
    std::string m = HRStringHelper::intToString(time->tm_mon + 1, 2);       // 月 2桁
    std::string n = HRStringHelper::intToString(time->tm_mon + 1);          // 月
    std::string F = MONTH_EN[time->tm_mon];                                 // 月 英語
    std::string M = F.substr(0, 3);                                         // 月 英語 3文字
    std::string d = HRStringHelper::intToString(time->tm_mday, 2);          // 日 2桁
    std::string j = HRStringHelper::intToString(time->tm_mday);             // 日
    std::string l = WEEKDAY_EN[time->tm_wday];                              // 曜日 英語
    std::string D = l.substr(0, 3);                                         // 曜日 英語 3文字
    std::string H = HRStringHelper::intToString(time->tm_hour, 2);          // 時 24時間表記 2桁
    std::string G = HRStringHelper::intToString(time->tm_hour);             // 時 24時間表記
    std::string h = HRStringHelper::intToString((time->tm_hour <= 12) ? time->tm_hour : time->tm_hour-12, 2);   // 時 12時間表記 2桁
    std::string g = HRStringHelper::intToString((time->tm_hour <= 12) ? time->tm_hour : time->tm_hour-12);      // 時 12時間表記
    std::string i = HRStringHelper::intToString(time->tm_min, 2);           // 分 2桁
    std::string s = HRStringHelper::intToString(time->tm_sec, 2);           // 秒 2桁
    std::string a = (time->tm_hour <= 12) ? "am" : "pm";                    // 午前/午後 英語 小文字
    std::string A = (time->tm_hour <= 12) ? "AM" : "PM";                    // 午前/午後 英語 大文字
    
    // !!!: 順番に意味あり
    format = HRStringHelper::replacePlaceholder(format, "Y", Y);
    format = HRStringHelper::replacePlaceholder(format, "y", y);
    format = HRStringHelper::replacePlaceholder(format, "m", m);
    format = HRStringHelper::replacePlaceholder(format, "n", n);
    format = HRStringHelper::replacePlaceholder(format, "d", d);
    format = HRStringHelper::replacePlaceholder(format, "j", j);
    format = HRStringHelper::replacePlaceholder(format, "H", H);
    format = HRStringHelper::replacePlaceholder(format, "G", G);
    format = HRStringHelper::replacePlaceholder(format, "h", h);
    format = HRStringHelper::replacePlaceholder(format, "g", g);
    format = HRStringHelper::replacePlaceholder(format, "i", i);
    format = HRStringHelper::replacePlaceholder(format, "s", s);
    format = HRStringHelper::replacePlaceholder(format, "a", a);
    format = HRStringHelper::replacePlaceholder(format, "F", F);
    format = HRStringHelper::replacePlaceholder(format, "M", M);
    format = HRStringHelper::replacePlaceholder(format, "l", l);
    format = HRStringHelper::replacePlaceholder(format, "D", D);
    format = HRStringHelper::replacePlaceholder(format, "A", A);
    
    return format;
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
