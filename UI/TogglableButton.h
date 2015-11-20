//
//  TogglableButton.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/20.
//
//

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
     * @param  callback    コールバック
     * @param  isGrayScale オフの時のグレースケールするか
     * @return トグルボタン
     */
    static TogglableButton *createWithFiles(const std::string &on,
                                            const std::string &off,
                                            ToggledCallback callback,
                                            bool isGrayScale = false);
    
    /**
     * @brief  トグルボタンを生成する
     * @param  imageFile 画像ファイル
     * @param  callback  コールバック
     * @return トグルボタン
     */
    static TogglableButton *createWithFile(const std::string &imageFile,
                                           ToggledCallback callback);
    
    
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
#pragma mark Protected Members
protected:
    
    
#pragma mark - Control Methods
#pragma mark Override Methods
#pragma mark Original Methods
    
    
#pragma mark - Tap Event Methods
protected:
    virtual void toggle();
    
    
};


}

#endif /* defined(__HRStandardLibrary__TogglableButton__) */
