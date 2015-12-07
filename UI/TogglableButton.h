//
//  TogglableButton.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/20.
//
//

/**
 * HR::TogglableButton
 *
 * extend HR::SwitchableButton
 *
 * トグル型のボタンクラス。
 * on/off切り替えとかに使う。
 */

#ifndef __HRStandardLibrary__TogglableButton__
#define __HRStandardLibrary__TogglableButton__

#include "SwitchableButton.h"


namespace HR {


/**
 * トグル時のコールバック
 * 引数で状態を受け取る
 * on  -> off : false
 * off -> on  : true
 */
typedef std::function<void(bool)> ToggledCallback;


class TogglableButton : public HR::SwitchableButton
{
CC_CONSTRUCTOR_ACCESS:
    TogglableButton();
    virtual ~TogglableButton();
    
    virtual bool init() override;
    virtual bool initWithFiles(const std::string &on,
                               const std::string &off,
                               ToggledCallback callback,
                               bool isGrayScale = false);
    
    
#pragma mark - Create Methods
public:
    /**
     * @brief  トグルボタンを生成する
     * @return トグルボタン
     */
    static TogglableButton *create();
    
    /**
     * @brief  トグルボタンを生成する
     * @param  on          オンの時の画像ファイル
     * @param  off         オフの時の画像ファイル
     * @param  callback    (nullptr)コールバック
     * @param  isGrayScale (true)オフの時のグレースケールするか
     * @return トグルボタン
     */
    static TogglableButton *createWithFiles(const std::string &on,
                                            const std::string &off,
                                            ToggledCallback callback = nullptr,
                                            bool isGrayScale = true);
    
    /**
     * @brief  トグルボタンを生成する
     * @param  imageFile 画像ファイル
     * @param  callback  (nullptr)コールバック
     * @return トグルボタン
     */
    static TogglableButton *createWithFile(const std::string &imageFile,
                                           ToggledCallback callback = nullptr);
    
    
#pragma mark - Members
#pragma mark Read Only Members
    /* トグル状態(2値なのでbool) */
    CC_SYNTHESIZE_READONLY(bool, _toggleStatus, ToggleStatus);
    /* オンの時の画像ファイル */
    CC_SYNTHESIZE_READONLY(std::string, _onImageFile, OnImageFile);
    /* オフの時の画像ファイル */
    CC_SYNTHESIZE_READONLY(std::string, _offImageFile, OffImageFile);
#pragma mark Write Only Members
    /* トグル時のコールバック */
    HR_SYNTHESIZE_WRITEONLY(ToggledCallback, _toggledCallback, ToggledCallback);
#pragma mark Read & Write Members
    /* オフの時にグレースケールするか */
    CC_SYNTHESIZE(bool, _isGrayScale, IsGrayScale);
    
    
#pragma mark - Control Methods
#pragma mark Original Methods
    /**
     * @brief トグルする
     */
    virtual void toggle();
    
    /**
     * @brief 強制的にオンにする
     */
    virtual void turnOn();
    
    /**
     * @brief 強制的にオフにする
     */
    virtual void turnOff();
    
    
};


}

#endif /* defined(__HRStandardLibrary__TogglableButton__) */
