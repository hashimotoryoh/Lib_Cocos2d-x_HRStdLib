//
//  TouchableSprite.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/12.
//
//

#include "TouchableSprite.h"
#include "HRConfig.h"
#include "UIClassConfig.h"
#include "HRLog.h"
#include "NodeUtility.h"


using namespace HR;
USING_NS_CC;


#pragma mark - Constructor & Destructor

TouchableSprite::TouchableSprite()
: _isEnableLongTap(true)
, _longTapThreshold(DEFAULT_LONG_TOUCH_THRESHOLD)
, _continuousTapThreshold(DEFAULT_CONTINUOUS_TAP_THRESHOLD)
, _enabledImageFile(STRING_UNSET)
, _disabledImageFile(STRING_UNSET)
, _isEnable(true)
, _isEnableContinuousTap(false)
, _touchBeganCallback(nullptr)
, _longTouchCallback(nullptr)
, _touchEndedCallback(nullptr)
, _tapCallback(nullptr)
, _longTapCallback(nullptr)
, _listener(nullptr)
, _touchingStatus(TouchingStatus::Virgin)
, _continuousTapCount(UNSIGNED_INTEGER_UNSET)
{
}

TouchableSprite::~TouchableSprite()
{
}



#pragma mark - Create & Initialize Methods

TouchableSprite *TouchableSprite::create()
{
    TouchableSprite *pRet = new (std::nothrow) TouchableSprite();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool TouchableSprite::init()
{
    if (!this->Sprite::init()) return false;
    
    // タッチイベントのリスナを登録する
    _listener = EventListenerTouchOneByOne::create();
    _listener->onTouchBegan = CC_CALLBACK_2(TouchableSprite::onTouchBegan, this);
    _listener->onTouchMoved = CC_CALLBACK_2(TouchableSprite::onTouchMoved, this);
    _listener->onTouchEnded = CC_CALLBACK_2(TouchableSprite::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithFixedPriority(_listener, 1);
    
    return true;
}

TouchableSprite *TouchableSprite::createWithFiles(const std::string &enabledImageFile,
                                                  const std::string &disabledImageFile,
                                                  bool isEnable /* = true */)
{
    TouchableSprite *pRet = TouchableSprite::create();
    if (pRet->initWithFiles(enabledImageFile, disabledImageFile, isEnable)) {
        return pRet;
    }
    
    return nullptr;
}

bool TouchableSprite::initWithFiles(const std::string &enabledImageFile, const std::string &disabledImageFile, bool isEnable /* = true */)
{
    // TODO: ファイルの存在確認
    _enabledImageFile  = enabledImageFile;
    _disabledImageFile = disabledImageFile;
    _isEnable          = isEnable;
    
    this->Sprite::setTexture(_isEnable ? _enabledImageFile : _disabledImageFile);
    
    return true;
}

TouchableSprite *TouchableSprite::createWithFile(const std::string &imageFile,
                                                 bool isEnable /* = true */)
{
    return TouchableSprite::createWithFiles(imageFile, imageFile, isEnable);
}



#pragma mark - Control Methods
#pragma mark Override Methods

void TouchableSprite::setVisible(bool visible)
{
    this->Sprite::setVisible(visible);
    // ==============================
    
    // 見えないものはタッチ出来ないということで
    visible ? this->enable() : this->disable();
}


#pragma mark Original Methods

void TouchableSprite::enable()
{
    if (_isEnable) { HRLOG("既にenableです。"); return; }
    
    _eventDispatcher->addEventListenerWithFixedPriority(_listener, 1);
    _isEnable = true;
    
    this->Sprite::setTexture(_enabledImageFile);
}

void TouchableSprite::disable()
{
    if (!_isEnable) { HRLOG("既にdisableです。"); return; }
    
    _eventDispatcher->removeEventListener(_listener);
    _isEnable = false;
    
    this->Sprite::setTexture(_disabledImageFile);
}

void TouchableSprite::enableContinuousTap()
{
    if (_isEnableContinuousTap) { HRLOG("既にenableです。"); return; }
    
    _isEnableContinuousTap = true;
    _continuousTapCount    = 0;
}

void TouchableSprite::disableContinuousTap()
{
    if (!_isEnableContinuousTap) { HRLOG("既にdisableです。"); return; }
    
    _isEnableContinuousTap = false;
    _continuousTapCount    = UNSIGNED_INTEGER_UNSET;
}

void TouchableSprite::enableLongTap()
{
    if (_isEnableLongTap) { HRLOG("既にenableです。"); return; }
    
    _isEnableLongTap = true;
}

void TouchableSprite::disableLongTap()
{
    if (!_isEnableLongTap) { HRLOG("既にdisableです。"); return; }
    
    _isEnableLongTap = false;
}

void TouchableSprite::setEnabledTexture(const std::string &imageFile)
{
    // TODO: ファイルの存在を確認する
    _enabledImageFile = imageFile;
    if (_isEnable) this->Sprite::setTexture(_enabledImageFile);
}

void TouchableSprite::setDisabledTexture(const std::string &imageFile)
{
    // TODO: ファイルの存在を確認する
    _disabledImageFile = imageFile;
    if (!_isEnable) this->Sprite::setTexture(_disabledImageFile);
}

void TouchableSprite::setTexture(const std::string &enabled, const std::string &disabled)
{
    this->setEnabledTexture(enabled);
    this->setDisabledTexture(disabled);
}



#pragma mark - Touch Event Methods

bool TouchableSprite::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (!_isEnable || // 有効か？
        !this->isVisible() || // 表示されているか？
        !NodeUtility::isInsideNode(touch->getLocation(), this)) return false; // タッチされたのはthisの中か？
    
    if (_touchBeganCallback && !_touchBeganCallback(this)) return false;
    
    // ここまででタッチ開始許可
    
    _touchingStatus = TouchingStatus::Touching;
    
    // 長押しの処理
    if (_isEnableLongTap) this->reserveLongTap();
    
    
    return true;
}

void TouchableSprite::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (NodeUtility::isInsideNode(touch->getLocation(), this)) {
        // this内の移動だったら特に何もしない
        if (_touchingStatus == TouchingStatus::Touching ||
            _touchingStatus == TouchingStatus::LongTouching) return;
        
        _touchingStatus = TouchingStatus::Touching;
        
        // 長押しの処理
        if (_isEnableLongTap) this->reserveLongTap();
    }
    else {
        _touchingStatus = TouchingStatus::InvalidTouching;
        
        // 長押し解除
        this->cancelLongTapReservation();
    }
}

void TouchableSprite::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (!_isEnable ||                                             // 有効か？
        !this->isVisible() ||                                     // 表示されているか？
        !NodeUtility::isInsideNode(touch->getLocation(), this) || // タッチエンドポイントはthisの中か？
        _touchingStatus == TouchingStatus::Virgin ||
        _touchingStatus == TouchingStatus::InvalidTouching) return;
    
    // ここまででタッチ終了許可
    
    // 長押し解除
    this->cancelLongTapReservation();
    
    // タッチエンドのコールバックはタップとは関係無いので実行
    if (_touchEndedCallback) _touchEndedCallback(this);
    
    // ロングタップ判定(優先)
    if (_isEnableLongTap && _touchingStatus == TouchingStatus::LongTouching) {
        if (_longTapCallback) _longTapCallback();
        return;
    }
    
    // 連続タップ判定
    if (_isEnableContinuousTap) {
        _continuousTapCount++;
        
        this->cancelContinuousTapReservation();
        this->reserveContinuousTap();
    }
    // 連続タップ無効時は times = 0, 連続タップ時は times >= 1
    if (_tapCallback) _tapCallback(_continuousTapCount);
}



#pragma mark - Easing Methods

void TouchableSprite::reserveLongTap()
{
    this->scheduleOnce([this](float dt) {
        _touchingStatus = TouchingStatus::LongTouching;
        if (_longTouchCallback) _longTouchCallback(this);
    }, _longTapThreshold, "KeyOfLongTapReservation");
}

void TouchableSprite::cancelLongTapReservation()
{
    this->unschedule("KeyOfLongTapReservation");
}

void TouchableSprite::reserveContinuousTap()
{
    this->scheduleOnce([this](float dt) {
        _continuousTapCount = 0;
    }, _continuousTapThreshold, "KeyOfContinuousTapReservation");
}

void TouchableSprite::cancelContinuousTapReservation()
{
    this->unschedule("KeyOfContinuousTapReservation");
}
