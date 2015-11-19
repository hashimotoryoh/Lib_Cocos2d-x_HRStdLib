//
//  SwitchableButton.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/16.
//
//

#ifndef __HRStandardLibrary__SwitchableButton__
#define __HRStandardLibrary__SwitchableButton__

#include "Button.h"
#include "SBSwitchPattern.h"
#include "HRLog.h"


namespace HR {

    
class SwitchableButton : public HR::Button
{
CC_CONSTRUCTOR_ACCESS:
    SwitchableButton();
    virtual ~SwitchableButton();
    
    virtual bool init() override;
    virtual bool initWithPatterns(cocos2d::Vector<HR::SBSwitchPattern*> patterns);
    
    
#pragma mark - Create Methods
public:
    static SwitchableButton *create();
    /**
     * @brief  切り替え可能ボタンを生成する
     * @param  patterns 切り替えパターンのベクター
     * @return 切り替えボタン
     */
    static SwitchableButton *createWithPatterns(cocos2d::Vector<HR::SBSwitchPattern*> patterns);
    
    
#pragma mark - Members
#pragma mark Protected Members
protected:
    /* スイッチするパターン群 */
    cocos2d::Vector<HR::SBSwitchPattern*> _switchPatterns;
    /* 現在のパターン */
    HR::SBSwitchPattern *_currentPattern;
    
    
#pragma mark - Control Methods
#pragma mark Override Methods
    HR_DISABLE_SUPER_METHOD(void, enableContinuousTap, void);
    HR_DISABLE_SUPER_METHOD(void, disableContinuousTap, void);
    HR_DISABLE_SUPER_METHOD(void, enableLongTap, void);
    HR_DISABLE_SUPER_METHOD(void, disableLongTap, void);
    
    HR_DISABLE_SUPER_METHOD(void, setTouchBeganCallback, TSTouchBeganCallback);
    HR_DISABLE_SUPER_METHOD(void, setLongTouchCallback, TSTouchCallback);
    HR_DISABLE_SUPER_METHOD(void, setTouchEndedCallback, TSTouchCallback);
    HR_DISABLE_SUPER_METHOD(void, setLongTapCallback, TSLongTapCallback);
#pragma matk Original Methods
public:
    /**
     * @brief パターンを追加する
     * @param pattern パターン
     */
    void addPattern(HR::SBSwitchPattern *pattern);
    
    /**
     * @brief パターンを追加する
     * @param key       キー
     * @param imageFile 画像ファイル
     * @param callback  (nullptr)コールバック
     */
    void addPattern(const std::string &key, const std::string imageFile, SBTapCallback callback = nullptr);
    
    /**
     * @brief ボタンを切り替える
     * @param isCallCallback 現在のパターンのコールバックを呼ぶか
     */
    void switchNext(bool isCallCallback = true);
    
    /**
     * @brief キーを指定してボタンを切り替える
     * @param key            キー
     * @param isCallCallback 現在のパターンのコールバックを呼ぶか
     */
    void switchWithKey(const std::string &key, bool isCallCallback = true);
    
    
#pragma mark - Tap Event Methods
private:
    /**
     * @brief タップされた時の挙動
     */
    void onTapped();
    
    /**
     * @brief  キーが有効なものかチェックする
     * @param  key チェックするキー
     * @return true/false = 有効/無効
     */
    bool isValidKey(const std::string &key);
    
    
};


}


#endif /* defined(__HRStandardLibrary__SwitchableButton__) */
