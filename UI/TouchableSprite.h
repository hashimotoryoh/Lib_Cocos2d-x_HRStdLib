//
//  TouchableSprite.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/12.
//
//

/**
 * HR::TouchableSprite
 *
 * extend cocos2d::Sprite
 *
 * タッチイベントを持ったSpriteクラス。
 * 画像ファイルパスを渡して生成する。
 * タッチ開始、スワイプ、タッチ終了のコールバックを設定できる。
 * 連打、長押しも検知できる。
 */

#ifndef __HRStandardLibrary__TouchableSprite__
#define __HRStandardLibrary__TouchableSprite__

#include "cocos2d.h"
#include "HRMacros.h"


namespace HR {


typedef std::function<bool(cocos2d::Ref *ref)> TSTouchBeganCallback;
typedef std::function<void(cocos2d::Ref *ref)> TSTouchCallback;
typedef std::function<void(unsigned int times)> TSTapCallback;
typedef std::function<void()> TSLongTapCallback;


/* タッチ状況 */
enum class TouchingStatus {
    Virgin,             // タッチされてない
    Touching,           // タッチ中
    LongTouching,       // 長押し中
    InvalidTouching,    // スワイプなどで外に出ている, タッチ中に無効化された
};


class TouchableSprite : public cocos2d::Sprite
{
CC_CONSTRUCTOR_ACCESS:
    TouchableSprite();
    virtual ~TouchableSprite();
    
    virtual bool init() override;
    virtual bool initWithFiles(const std::string &enabledFile,
                               const std::string &disabledFile,
                               bool isEnable);
    
    
#pragma mark - Create Methods
public:
    static TouchableSprite *create();
    /**
     * @brief  タッチイベントを持ったSpriteを生成する
     * @param  enabledFilePath  タッチ有効時の画像ファイル
     * @param  disabledFilePath タッチ無効時の画像ファイル
     * @param  isEnable         (true)生成時有効か
     * @return タッチイベントを持ったSprite
     */
    static TouchableSprite *createWithFiles(const std::string &enabledFile,
                                            const std::string &disabledFile,
                                            bool isEnable = true);
    /**
     * @brief  タッチイベントを持ったSpriteを生成する
     * @param  filePath 画像ファイル
     * @param  isEnable (true)生成時有効か
     * @return タッチイベントを持ったSprite
     */
    static TouchableSprite *createWithFile(const std::string &file,
                                           bool isEnable = true);
    
    
#pragma mark - Control Methods
public:
#pragma mark Override Methods
    void setVisible(bool visible) override;
#pragma mark Original Methods
    /**
     * @brief タッチイベントを有効化する
     */
    void enable();
    /**
     * @brief タッチイベントを無効化する
     */
    void disable();
    
    /**
     * @brief 連続タップを有効化する
     */
    virtual void enableContinuousTap();
    /**
     * @brief 連続タップを無効化する
     */
    virtual void disableContinuousTap();
    
    /**
     * @brief ロングタップを有効化する (setter/getterがあるが、他に合わせてこちらも用意)
     */
    virtual void enableLongTap();
    /**
     * @brief ロングタップを無効化する (setter/getterがあるが、他に合わせてこちらも用意)
     */
    virtual void disableLongTap();
    
    
#pragma mark - Members
#pragma mark Public Members
    /* 長押し可能か */
    CC_SYNTHESIZE(bool, _isEnableLongTap, IsEnableLongTap);
    /* 長押し判定する時間 (この時間以上タッチで長押し判定) */
    CC_SYNTHESIZE(float, _longTapThreshold, LongTapThreshold);
    /* 連続タップ判定する時間 (1stタッチからこの時間以内に2ndタッチで連続タップ判定) */
    CC_SYNTHESIZE(float, _continuousTapThreshold, ContinuousTapThreshold);
#pragma mark Read Only Members
    /* タップ有効時の画像ファイル */
    CC_SYNTHESIZE_READONLY(std::string, _enabledImage, EnabledImage);
    /* タップ無効時の画像ファイル */
    CC_SYNTHESIZE_READONLY(std::string, _disabledImage, DisabledImage);
    /* タップが有効か */
    CC_SYNTHESIZE_READONLY(bool, _isEnable, IsEnable);
    /* 連続タップ可能か */
    CC_SYNTHESIZE_READONLY(bool, _isEnableContinuousTap, IsEnableContinuousTap);
#pragma mark Write Only Members
    /* タッチ開始時のコールバック */
    HR_SYNTHESIZE_WRITEONLY(TSTouchBeganCallback, _touchBeganCallback, TouchBeganCallback);
    /* ロングタッチ時のコールバック */
    HR_SYNTHESIZE_WRITEONLY(TSTouchCallback, _longTouchCallback, LongTouchCallback);
    /* タッチ終了時のコールバック */
    HR_SYNTHESIZE_WRITEONLY(TSTouchCallback, _touchEndedCallback, TouchEndedCallback);
    /* タップ時のコールバック (連続タップ数を渡す) */
    HR_SYNTHESIZE_WRITEONLY(TSTapCallback, _tapCallback, TapCallback);
    /* ロングタップ時のコールバック */
    HR_SYNTHESIZE_WRITEONLY(TSLongTapCallback, _longTapCallback, LongTapCallback);
#pragma mark Protected Members
protected:
    /* タッチイベントのリスナ */
    cocos2d::EventListenerTouchOneByOne *_listener;
    /* 現在のタッチ状況 */
    TouchingStatus _touchingStatus;
    /* 現在何連続タップ中か */
    unsigned int _continuousTapCount;
    
    
#pragma mark - Touch Event Methods
protected:
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

    
#pragma mark - Easing Methods
private:
    /**
     * @brief ロングタップ判定を予約する
     */
    void reserveLongTap();
    /**
     * @brief ロングタップ判定予約を解除する
     */
    void cancelLongTapReservation();
    
    /**
     * @brief 連続タップ判定を予約する
     */
    void reserveContinuousTap();
    /**
     * @brief 連続タップ判定予約を解除する
     */
    void cancelContinuousTapReservation();
    
    
};


}

#endif /* defined(__HRStandardLibrary__TouchableSprite__) */
