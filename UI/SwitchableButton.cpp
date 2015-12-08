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
    for (SBSwitchPattern *pattern : patterns) {
        this->addPattern(pattern);
    }
    
    return true;
}



#pragma mark - Control Methods

cocos2d::Vector<SBSwitchPattern*> SwitchableButton::getPatterns()
{
    return _switchPatterns;
}

HR::SBSwitchPattern *SwitchableButton::getPattern(const std::string &key)
{
    for (SBSwitchPattern *pattern : _switchPatterns) {
        if (pattern->_key == key) return pattern;
    }
    
    HRERROR("キー %s は登録されていません。", key.c_str());
    return nullptr;
}

void SwitchableButton::addPattern(HR::SBSwitchPattern *pattern)
{
    HRASSERT(this->isValidKey(pattern->_key), "既に同じキーで登録されているパターンがあります。");
    
    _switchPatterns.pushBack(pattern);
    
    // もし最初のパターンだったら初期化処理
    if (_switchPatterns.size() == 1) {
        _currentPattern = _switchPatterns.front();
        this->Sprite::setTexture(_currentPattern->_imageFile);
    }
}

void SwitchableButton::addPattern(const std::string &key, const std::string imageFile, SBTapCallback callback /* = nullptr */)
{
    this->addPattern(SBSwitchPattern::create(key, imageFile, callback));
}

void SwitchableButton::removePattern(const std::string &key)
{
    SBSwitchPattern *targetPattern = this->getPattern(key);
    _switchPatterns.eraseObject(targetPattern);
}

void SwitchableButton::replacePattern(HR::SBSwitchPattern *pattern)
{
    this->replacePattern(pattern->_key, pattern->_imageFile, nullptr);
}

void SwitchableButton::replacePattern(const std::string &key, const std::string &newImageFile, SBTapCallback newCallback)
{
    SBSwitchPattern *targetPattern = this->getPattern(key);
    targetPattern->_imageFile = newImageFile;
    targetPattern->_callback  = newCallback;
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
    
    _currentPattern = this->getPattern(key);
    
    this->Sprite::setTexture(_currentPattern->_imageFile);
}

void SwitchableButton::setCallbackWithKey(const std::string &key, HR::SBTapCallback callback)
{
    if (this->isNewKey(key)) {
        HRLOG("次のキーは登録されていません。: %s", key.c_str());
        return;
    }
    
    this->getPattern(key)->_callback = callback;
}



#pragma mark - Tap Event Methods

void SwitchableButton::onTapped()
{
    this->switchNext();
}



#pragma mark - Easing Methods

bool SwitchableButton::isValidKey(const std::string &key)
{
    // 既に登録してあるパターンのキーと重複してたらダメ
    if (!this->isNewKey(key)) return false;
    
    return true;
}

bool SwitchableButton::isNewKey(const std::string &key)
{
    for (SBSwitchPattern *pattern : _switchPatterns) {
        if (pattern->_key == key) {
            return false;
        }
    }
    
    return true;
}
