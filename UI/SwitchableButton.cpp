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
, _currentPattern(SwitchPattern{"", nullptr})
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
    SwitchPattern firstPattern = patterns.at(0);
    if (!this->Button::initWithFiles(firstPattern.imageFile, firstPattern.imageFile, true, true, true)) return false;
    
//    _switchPatterns = patterns;
//    _currentPattern = firstPattern;
    
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
    
    if (!this->SwitchableButton::initWithPatterns(switchPatterns)) return false;
    
    return true;
}
