

//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/20.
//
//

#include "TogglableButton.h"
#include "HRConfig.h"
#include "HRFileHelper.h"


using namespace HR;
USING_NS_CC;



#pragma mark - Constructor & Destructor

TogglableButton::TogglableButton()
: _toggleStatus(false)
, _onImageFile(STRING_UNSET)
, _offImageFile(STRING_UNSET)
, _toggledCallback(nullptr)
, _isGrayScale(false)
{
}

TogglableButton::~TogglableButton()
{
}



#pragma mark - Create & Initialize Methods

TogglableButton *TogglableButton::create()
{
    TogglableButton *pRet = new (std::nothrow) TogglableButton();
    if (pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool TogglableButton::init()
{
    if (!this->SwitchableButton::init()) return false;
    
    _toggleStatus    = true;
    _isGrayScale     = true;
    _toggledCallback = nullptr;
    
    return true;
}

TogglableButton *TogglableButton::createWithFiles(const std::string &on,
                                                  const std::string &off,
                                                  ToggledCallback callback /* = nullptr */,
                                                  bool isGrayScale /* = true */)
{
    TogglableButton *pRet = TogglableButton::create();
    if (pRet->initWithFiles(on, off, callback, isGrayScale)) {
        return pRet;
    }
    
    return nullptr;
}

bool TogglableButton::initWithFiles(const std::string &on, const std::string &off, ToggledCallback callback, bool isGrayScale /* = true */)
{
    // on/offのパターンのSwitchableButtonを生成する
    this->addPattern(SBSwitchPattern::create( "on",  on, [this]() { this->toggle(); }));
    this->addPattern(SBSwitchPattern::create("off", off, [this]() { this->toggle(); }));
    
    _toggledCallback = callback;
    _isGrayScale = isGrayScale;
    
    return  true;
}

TogglableButton *TogglableButton::createWithFile(const std::string &imageFile,
                                                ToggledCallback callback /* = nullptr */)
{
    return TogglableButton::createWithFiles(imageFile, imageFile, callback, true);
}



#pragma mark - Control Methods

#pragma mark Original Methods

void TogglableButton::toggle()
{
    _toggleStatus = !_toggleStatus;
    
    if(!_toggleStatus && _isGrayScale) this->setColor(Color3B::GRAY);
    else                               this->setColor(Color3B::WHITE);
    
    // on->offならfalse, off->onならtrueを渡してコールバックを実行
    if (_toggledCallback) _toggledCallback(_toggleStatus);
}

void TogglableButton::turnOn()
{
    // 現状をオフにしてトグルすることでオンにする
    _toggleStatus = false;
    this->toggle();
}

void TogglableButton::turnOff()
{
    // 現状をオンにしてトグルすることでオフにする
    _toggleStatus = true;
    this->toggle();
}



#pragma mark - Touch Event Methods

void TogglableButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    this->SwitchableButton::onTouchEnded(touch, event);
    // ===== Call Super Method =====
    
    // 親クラスのonTouchEnded()ではタッチエンドで白に戻すが、
    // TogglableButtonではオフ状態にグレーのままの場合がある
    if (_isGrayScale && !_toggleStatus) this->setColor(Color3B::GRAY);
}
