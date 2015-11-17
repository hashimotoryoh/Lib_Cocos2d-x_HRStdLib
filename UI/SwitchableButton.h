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


    typedef struct {
        std::string   key;
        std::string   imageFile;
        SBTapCallback callback;
    } SwitchPattern;
    
    
class SwitchableButton : public HR::Button
{
CC_CONSTRUCTOR_ACCESS:
    SwitchableButton();
    virtual ~SwitchableButton();
    
    virtual bool init() override;
    virtual bool initWithPatterns(std::vector<HR::SwitchPattern> patterns);
    virtual bool initWithPatterns(HR::SwitchPattern pattern1, HR::SwitchPattern pattern2, ...);
    
    
#pragma mark - Create Methods
public:
    static SwitchableButton *create();
    static SwitchableButton *createWithPatterns(std::vector<HR::SwitchPattern> patterns);
    static SwitchableButton *createWithPatterns(HR::SwitchPattern pattern1,
                                                HR::SwitchPattern pattern2,
                                                ...);
    
    
#pragma mark - Members
#pragma mark Protected Members
protected:
    /* スイッチするパターン群 */
    std::vector<HR::SwitchPattern> _switchPatterns;
    /* 現在のパターンの番号 */
    HR::SwitchPattern _currentPattern;
    std::vector<HR::SwitchPattern>::iterator _currentPatternIter;
    
    
    
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
    void switchNext(bool isCallCallback = true);
    
    /**
     * @brief キーを指定してボタンを切り替える
     * @param key キー
     */
    void switchWithKey(const std::string &key, bool isCallCallback = true);
    
    
#pragma mark - Easing Methods
private:
    /**
     * @brief キーを元にパターンを特定する
     * @patam key キー
     */
    SwitchPattern findPattern(const std::string &key);
    
    
};


}


#endif /* defined(__HRStandardLibrary__SwitchableButton__) */
