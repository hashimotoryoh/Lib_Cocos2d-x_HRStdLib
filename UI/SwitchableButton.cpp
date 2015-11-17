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
: _switchPatterns(std::vector<SwitchPattern>())
, _currentPattern(SwitchPattern{})
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

SwitchableButton *SwitchableButton::createWithPatterns(std::vector<SwitchPattern> patterns)
{
    SwitchableButton *pRet = SwitchableButton::create();
    if (pRet->initWithPatterns(patterns))
        return pRet;
    /* else */
        return nullptr;
}

bool SwitchableButton::initWithPatterns(std::vector<SwitchPattern> patterns)
{
    // TODO: キーの被りが無いか調べる
    
    SwitchPattern firstPattern = patterns.front();
    if (!this->Button::initWithFiles(firstPattern.imageFile, firstPattern.imageFile, true, true, true)) return false;
    
    _switchPatterns = patterns;
    _currentPattern = firstPattern;
    _currentPatternIter = patterns.begin();
    
    return true;
}

SwitchableButton *SwitchableButton::createWithPatterns(SwitchPattern pattern1,
                                                       SwitchPattern pattern2,
                                                       ...)
{
    SwitchableButton *pRet = SwitchableButton::create();
    if (pRet->initWithPatterns(pattern1, pattern2))
        return pRet;
    /* else */
        return nullptr;
}

bool SwitchableButton::initWithPatterns(SwitchPattern pattern1, SwitchPattern pattern2, ...)
{
    std::vector<SwitchPattern> switchPatterns;
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

void SwitchableButton::switchNext(bool isCallCallback /* = true  */)
{
    // 次のパターンのキーを取得する
    std::vector<SwitchPattern>::iterator nextIter = std::next(_currentPatternIter);
    std::string nextKey = ((SwitchPattern)*nextIter).key;
    
    this->switchWithKey(nextKey, isCallCallback);
}

void SwitchableButton::switchWithKey(const std::string &key, bool isCallCallback /* = true  */)
{
    if (isCallCallback) _currentPattern.callback();
    
    // 指定されたキーのパターンが無ければ何もしない
    SwitchPattern nextPattern = this->findPattern(key);
    if (nextPattern.key == "") return;
    
    this->setTexture(nextPattern.imageFile);
    _currentPattern = nextPattern;
}



#pragma mark - Easing Methods

SwitchPattern SwitchableButton::findPattern(const std::string &key)
{
    for (SwitchPattern pattern : _switchPatterns) {
        if (pattern.key == key) return pattern;
    }
    
    return SwitchPattern{};
}
