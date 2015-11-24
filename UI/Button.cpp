//
//  Button.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/16.
//
//

#include "Button.h"
#include "HRLog.h"
#include "NodeUtility.h"
#include "HRFileHelper.h"


using namespace HR;
USING_NS_CC;


#pragma mark - Constructor & Destructor

Button::Button()
: _isEnableScaleEffect(true)
, _isEnableBrightnessEffect(true)
{
}

Button::~Button()
{
}



#pragma mark - Create & Initialize Methods

Button *Button::create()
{
    Button *pRet = new (std::nothrow) Button();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Button::init()
{
    if (!this->TouchableSprite::init()) return false;
    
    return true;
}

Button *Button::createWithFiles(const std::string &enabledImageFile,
                                const std::string &disabledImageFile,
                                bool scaleEffect      /* = true */,
                                bool brightnessEffect /* = true */,
                                bool isEnable         /* = true */)
{
    Button *pRet = Button::create();
    if (pRet->initWithFiles(enabledImageFile, disabledImageFile, scaleEffect, brightnessEffect, isEnable)) {
        return pRet;
    }
    
    return nullptr;
}

bool Button::initWithFiles(const std::string &enabledImageFile, const std::string &disabledImageFile, bool scaleEffect /* = true */, bool brightnessEffect /* = true */, bool isEnable /* = true */)
{
    if (!this->TouchableSprite::initWithFiles(enabledImageFile, disabledImageFile, isEnable)) return false;
    
    scaleEffect      ? this->enableScaleEffect()      : disableScaleEffect();
    brightnessEffect ? this->enableBrightnessEffect() : disableBrightnessEffect();
    
    return true;
}

Button *Button::createWithFile(const std::string &imageFile,
                               bool scaleEffect      /* = true */,
                               bool brightnessEffect /* = true */,
                               bool isEnable         /* = true */)
{
    return Button::createWithFiles(imageFile, imageFile, scaleEffect, brightnessEffect, isEnable);
}



#pragma mark - Control Methods

void Button::enableScaleEffect()
{
    if (this->_touchingStatus == TouchingStatus::Touching || this->_touchingStatus == TouchingStatus::LongTouching)
        this->switchScaleEffect(true);
    
    _isEnableScaleEffect = true;
}

void Button::disableScaleEffect()
{
    if (this->_touchingStatus == TouchingStatus::Touching || this->_touchingStatus == TouchingStatus::LongTouching)
        this->switchScaleEffect(false);
    
    _isEnableScaleEffect = false;
}

void Button::enableBrightnessEffect()
{
    if (this->_touchingStatus == TouchingStatus::Touching || this->_touchingStatus == TouchingStatus::LongTouching)
        this->switchBrightnessEffect(true);
    
    _isEnableBrightnessEffect = true;
}

void Button::disableBrightnessEffect()
{
    if (this->_touchingStatus == TouchingStatus::Touching || this->_touchingStatus == TouchingStatus::LongTouching)
        this->switchBrightnessEffect(false);
    
    _isEnableBrightnessEffect = false;
}



#pragma mark - Touch Event Methods

bool Button::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (!this->TouchableSprite::onTouchBegan(touch, event)) return false;
    // ===== Call Super Method =====
    
    this->switchTouchEffect(true);
    
    return true;
}

void Button::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    this->TouchableSprite::onTouchMoved(touch, event);
    // ===== Call Super Method =====
    
    this->switchTouchEffect(NodeUtility::isInsideNode(touch->getLocation(), this));
}

void Button::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    this->TouchableSprite::onTouchEnded(touch, event);
    // ===== Call Super Method =====
    
    this->switchTouchEffect(false);
}



#pragma mark - Easing Methods

void Button::switchScaleEffect(bool sw)
{
    if (!_isEnableScaleEffect) return;
    
    // setScale() だと元のスケールに戻せない為 runAction(ScaleTo) を使う
    // 例: setScale(0.9) -> setScale(1.1) = 0.9 x 1.1 = 0.99
    if (sw) this->runAction(ScaleTo::create(0.0f, 0.95f));
    else    this->runAction(ScaleTo::create(0.0f, 1.0f));
}

void Button::switchBrightnessEffect(bool sw)
{
    if (!_isEnableBrightnessEffect) return;
    
    if (sw) this->setColor(Color3B::GRAY);
    else    this->setColor(Color3B::WHITE);
}

void Button::switchTouchEffect(bool sw)
{
    this->switchScaleEffect(sw);
    this->switchBrightnessEffect(sw);
}
