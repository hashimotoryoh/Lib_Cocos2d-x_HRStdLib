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


//    typedef struct {
//        std::string   key;
//        std::string   imageFile;
//        SBTapCallback callback;
//    } P;
    
    
class SwitchableButton : public HR::Button
{
CC_CONSTRUCTOR_ACCESS:
    SwitchableButton();
    virtual ~SwitchableButton();
    
    virtual bool init() override;
    virtual bool initWithPatterns(std::vector<HR::SBSwitchPattern> patterns);
    virtual bool initWithPatterns(HR::SBSwitchPattern pattern1, HR::SBSwitchPattern pattern2, ...);
    
    
#pragma mark - Create Methods
public:
    static SwitchableButton *create();
    static SwitchableButton *createWithPatterns(std::vector<HR::SBSwitchPattern> patterns);
    static SwitchableButton *createWithPatterns(HR::SBSwitchPattern pattern1,
                                                HR::SBSwitchPattern pattern2,
                                                ...);
    
    
#pragma mark - Members
#pragma mark Protected Members
protected:
    /* スイッチするパターン群 */
    std::vector<HR::SBSwitchPattern> _switchPatterns;
    /* 現在のパターン */
    HR::SBSwitchPattern _currentPattern;
    
//    std::vector<HR::P> _Ps;
//    HR::P _curP;
    
    
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
    void switchNext();
    
    /**
     * @brief キーを指定してボタンを切り替える
     * @param key キー
     */
    void switchWithKey(const std::string &key);
    
    
#pragma mark - Easing Methods
private:
    /**
     * @brief キーを元にパターンを特定する
     * @patam key キー
     */
    SBSwitchPattern *findPattern(const std::string &key);
    
    
};


}


#endif /* defined(__HRStandardLibrary__SwitchableButton__) */
