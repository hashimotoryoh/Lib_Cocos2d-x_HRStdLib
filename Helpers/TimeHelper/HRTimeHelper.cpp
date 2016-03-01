//
//  HRTimeHelper.cpp
//  DevHRStdLib
//
//  Created by c1790 on 2016/03/01.
//
//

#include "HRTimeHelper.h"
#include "HRStringHelper.h"


const char *WEEKDAY_EN[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
const char *MONTH_EN[]   = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


USING_NS_CC;
using namespace HR;


std::string HRTimeHelper::getDate(std::string format,
                                  time_t timestamp /* = -1 */)
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
