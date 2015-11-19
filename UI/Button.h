//
//  Button.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/16.
//
//

/**
 * Button クラス
 *
 * extend HR::TouchableSprite
 *
 * 一般的なボタン。
 * 押下時に小さくしたり、暗くしたりする。on/off可
 */

#ifndef __HRStandardLibrary__Button__
#define __HRStandardLibrary__Button__

#include "TouchableSprite.h"


namespace HR {


class Button : public HR::TouchableSprite
{
CC_CONSTRUCTOR_ACCESS:
    Button();
    virtual ~Button();
    
    virtual bool init() override;
    virtual bool initWithFiles(const std::string &normalFile,
                               const std::string &touchedFile,
                               bool scaleEffect,
                               bool brightnessEffect,
                               bool isEnable);
//    virtual bool initWithFile(const std::string &file,
//                              bool scaleEffect         = true,
//                              bool brightnessEffect    = true,
//                              bool isEnable            = true);
    
    
public:
#pragma mark - Create Methods
    static Button *create();
    /**
     * @brief  ボタンを生成する
     * @param normal           普段の画像ファイル
     * @param touched          押下時の画像ファイル
     * @param scaleEffect      (true)押下時に小さくするか
     * @param brightnessEffect (true)押下時に暗くするか
     * @param isEnable         (true)有効か
     * @return ボタン
     */
    static Button *createWithFiles(const std::string &normalFile,
                                   const std::string &touchedFile,
                                   bool scaleEffect = true,
                                   bool brightnessEffect = true,
                                   bool isEnable = true);
    /**
     * @brief  ボタンを生成する
     * @param  filePath         画像ファイル
     * @param  scaleEffect      (true)押下時に小さくするか
     * @param  brightnessEffect (true)押下時に暗くするか
     * @param  isEnable         (true)有効か
     * @return ボタン
     */
    static Button *createWithFile(const std::string &file,
                                  bool scaleEffect = true,
                                  bool brightnessEffect = true,
                                  bool isEnable = true);

    
    
#pragma mark - Control Methods
    /**
     * @brief 押下時のスケールエフェクト有効化する
     */
    void enableScaleEffect();
    /**
     * @brief 押下時のスケールエフェクトを無効化する
     */
    void disableScaleEffect();
    
    /**
     * @brief 押下時の明暗エフェクトを有効化する
     */
    void enableBrightnessEffect();
    /**
     * @brief 押下時の明暗エフェクトを無効化する
     */
    void disableBrightnessEffect();
    
    
#pragma mark - Members
#pragma mark Read Only Members
    CC_SYNTHESIZE_READONLY(cocos2d::Texture2D*, _normalTexture, NormalTexture);
    CC_SYNTHESIZE_READONLY(cocos2d::Texture2D*, _touchedTexture, TouchedTexture);
    CC_SYNTHESIZE_READONLY(bool, _isEnableScaleEffect, IsEnableScaleEffect);
    CC_SYNTHESIZE_READONLY(bool, _isEnableBrightnessEffect, IsEnableBrightnessEffect);
    
    
#pragma mark - Touch Event Methods
protected:
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) override;
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) override;
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) override;
    
    
#pragma mark - Easing Methods
private:
    /**
     * @brief スケールエフェクトをon/off
     * @param sw on/off
     */
    void switchScaleEffect(bool sw);
    
    /**
     * @brief 明暗エフェクトをon/off
     * @param sw on/off
     */
    void switchBrightnessEffect(bool sw);
    
    /**
     * @brief スケール&明暗の両方をon/off
     * @param sw on/off
     */
    void switchTouchEffect(bool sw);
    
    
};


}


#endif /* defined(__HRStandardLibrary__Button__) */
