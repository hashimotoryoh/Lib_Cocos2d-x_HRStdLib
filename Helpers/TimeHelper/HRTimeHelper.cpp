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


USING_NS_HR;
USING_NS_CC;


std::string HRTimeHelper::getDate(const std::string &format,
                                  time_t timestamp /* = time(NULL) */)
{
    std::string ret = format;
    
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
    ret = HRStringHelper::replacePlaceholder(ret, "Y", Y);
    ret = HRStringHelper::replacePlaceholder(ret, "y", y);
    ret = HRStringHelper::replacePlaceholder(ret, "m", m);
    ret = HRStringHelper::replacePlaceholder(ret, "n", n);
    ret = HRStringHelper::replacePlaceholder(ret, "d", d);
    ret = HRStringHelper::replacePlaceholder(ret, "j", j);
    ret = HRStringHelper::replacePlaceholder(ret, "H", H);
    ret = HRStringHelper::replacePlaceholder(ret, "G", G);
    ret = HRStringHelper::replacePlaceholder(ret, "h", h);
    ret = HRStringHelper::replacePlaceholder(ret, "g", g);
    ret = HRStringHelper::replacePlaceholder(ret, "i", i);
    ret = HRStringHelper::replacePlaceholder(ret, "s", s);
    ret = HRStringHelper::replacePlaceholder(ret, "a", a);
    ret = HRStringHelper::replacePlaceholder(ret, "F", F);
    ret = HRStringHelper::replacePlaceholder(ret, "M", M);
    ret = HRStringHelper::replacePlaceholder(ret, "l", l);
    ret = HRStringHelper::replacePlaceholder(ret, "D", D);
    ret = HRStringHelper::replacePlaceholder(ret, "A", A);
    
    return ret;
}


bool HRTimeHelper::isSameDay(time_t timestampA,
                             time_t timestampB)
{
    struct tm *timeA = localtime(&timestampA);
    struct tm *timeB = localtime(&timestampB);
    
    const bool isSameYear  = (timeA->tm_year == timeB->tm_year);
    const bool isSameMonth = (timeA->tm_mon  == timeB->tm_mon);
    const bool isSameDay   = (timeA->tm_mday == timeB->tm_mday);
    
    return (isSameYear && isSameMonth && isSameDay);
}

HMSTime HRTimeHelper::convertToTime(time_t s)
{
    HMSTime ret;
    
    ret.second = (int)(s % 60);
    ret.minute = (int)((s % 3600) / 60);
    ret.hour   = (int)(s / 3600);
    
    return ret;
}
