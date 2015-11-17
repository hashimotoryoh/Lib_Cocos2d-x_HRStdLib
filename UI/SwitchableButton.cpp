//
//  SwitchableButton.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/16.
//
//

#include "SwitchableButton.h"
//#include "HRConfig.h"


using namespace HR;
USING_NS_CC;


#pragma mark - Constructor & Destructor

SwitchableButton::SwitchableButton()
: _switchPatterns(std::vector<SBSwitchPattern>())
, _currentPattern(SBSwitchPattern())
{
}

SwitchableButton::~SwitchableButton()
{
}



#pragma mark - Create & Initialize Methods

SwitchableButton *SwitchableButton::create()
{
    SwitchableButton *pRet = new (std::nothrow) SwitchableButton();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool SwitchableButton::init()
{
    if (!this->Button::init()) return false;
    
    // 切り替えボタンは連打、長押し判定はさせない
    this->disableContinuousTap();
    this->disableLongTap();
    
    this->setTapCallback([this](unsigned int times) {
        this->switchNext();
    });
    
    return true;
}

SwitchableButton *SwitchableButton::createWithPatterns(std::vector<SBSwitchPattern> patterns)
{
    SwitchableButton *pRet = SwitchableButton::create();
    if (pRet->initWithPatterns(patterns))
        return pRet;
    /* else */
        return nullptr;
}

bool SwitchableButton::initWithPatterns(std::vector<SBSwitchPattern> patterns)
{
    // TODO: キーの被りが無いか調べる
    
    SBSwitchPattern firstPattern = *(patterns.begin());
    if (!this->Button::initWithFiles(firstPattern._imageFile, firstPattern._imageFile, true, true, true)) return false;
    
    _switchPatterns = patterns;
    _currentPattern = firstPattern;
    
    return true;
}

SwitchableButton *SwitchableButton::createWithPatterns(SBSwitchPattern pattern1,
                                                       SBSwitchPattern pattern2,
                                                       ...)
{
    SwitchableButton *pRet = SwitchableButton::create();
    if (pRet->initWithPatterns(pattern1, pattern2))
        return pRet;
    /* else */
        return nullptr;
}

bool SwitchableButton::initWithPatterns(SBSwitchPattern pattern1, SBSwitchPattern pattern2, ...)
{
    std::vector<SBSwitchPattern> switchPatterns;
    switchPatterns.push_back(pattern1);
    switchPatterns.push_back(pattern2);
    
//    va_list patterns;
//    va_start(patterns, pattern2);
//    switchPatterns.pushBack(va_arg(patterns, SBSwitchPattern));
//    va_end(patterns);
    
    if (!this->SwitchableButton::initWithPatterns(switchPatterns)) return false;
    
    return true;
}



#pragma mark - Control Methods

void SwitchableButton::switchNext()
{
    _currentPattern._callback();
    
    // 次のパターンに移る
    if (!this->findPattern("hoge")) {
        HRLOG("key 'hoge' is nothing");
    }
    
    this->setTexture(_currentPattern._imageFile);
}



#pragma mark - Easing Methods

SBSwitchPattern *SwitchableButton::findPattern(const std::string &key)
{
    for (auto itr : _switchPatterns) {
        SBSwitchPattern pattern = (SBSwitchPattern)itr;
        if (pattern._key == key) return &pattern;
    }
    
    return nullptr;
}