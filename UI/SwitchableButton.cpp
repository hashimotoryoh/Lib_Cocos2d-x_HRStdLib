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
: _switchPatterns(cocos2d::Vector<SBSwitchPattern*>())
, _currentPattern(nullptr)
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
    
    this->setTapCallback([this](unsigned int times) { this->onTapped(); });
    
    return true;
}

SwitchableButton *SwitchableButton::createWithPatterns(cocos2d::Vector<SBSwitchPattern*> patterns)
{
    SwitchableButton *pRet = SwitchableButton::create();
    if (pRet->initWithPatterns(patterns))
        return pRet;
    /* else */
        return nullptr;
}

bool SwitchableButton::initWithPatterns(cocos2d::Vector<SBSwitchPattern*> patterns)
{
    // TODO: キーの被りが無いか調べる
    
    _switchPatterns = patterns;
    _currentPattern = _switchPatterns.front();
    
    if (!this->Button::initWithFiles(_currentPattern->_imageFile, _currentPattern->_imageFile, true, true, true)) return false;
    
    return true;
}



#pragma mark - Control Methods

void SwitchableButton::addPattern(HR::SBSwitchPattern *pattern)
{
    // TODO: キーの被りが無いかチェックする
    
    _switchPatterns.pushBack(pattern);
    
    // もし最初のパターンだったら初期化処理
    if (_switchPatterns.size() == 1) {
        _currentPattern = _switchPatterns.front();
        this->setTexture(_currentPattern->_imageFile);
    }
}

void SwitchableButton::addPattern(const std::string &key, const std::string imageFile, SBTapCallback callback /* = nullptr */)
{
    this->addPattern(SBSwitchPattern::create(key, imageFile, callback));
}

void SwitchableButton::switchNext(bool isCallCallback /* = true  */)
{
    Vector<HR::SBSwitchPattern*>::iterator iter = _switchPatterns.find(_currentPattern);
    SBSwitchPattern *nextPattern = (iter+1 != _switchPatterns.end()) ? *(iter+1) : _switchPatterns.front();
    this->switchWithKey(nextPattern->_key);
}

void SwitchableButton::switchWithKey(const std::string &key, bool isCallCallback /* = true  */)
{
    if (isCallCallback && _currentPattern->_callback) _currentPattern->_callback();
    
    for (SBSwitchPattern *pattern : _switchPatterns) {
        if (pattern->_key == key) _currentPattern = pattern;
    }
    
    this->setTexture(_currentPattern->_imageFile);
}



#pragma mark - Tap Event Methods

void SwitchableButton::onTapped()
{
    this->switchNext();
}