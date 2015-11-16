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


namespace HR {


/** 切り替えた時のコールバック */
typedef std::function<void()> SBSwitchedCallback;


/* 切り替えパターン */
struct SwitchPattern {
    const std::string &imageFile;
    SBSwitchedCallback *callback;
};


class SwitchableButton : public HR::Button
{
CC_CONSTRUCTOR_ACCESS:
    SwitchableButton();
    virtual ~SwitchableButton();
    
    virtual bool init() override;
    virtual bool initWithPatterns(std::vector<SwitchPattern> patterns);
    virtual bool initWithPatterns(SwitchPattern pattern1, SwitchPattern pattern2, ...);
    
    
#pragma mark - Create Methods
public:
    static SwitchableButton *create();
    static SwitchableButton *createWithPatterns(std::vector<SwitchPattern> patterns);
    static SwitchableButton *createWithPatterns(SwitchPattern pattern1,
                                                SwitchPattern pattern2,
                                                ...);
    
    
#pragma mark - Members
#pragma mark Protected Members
protected:
    /* スイッチするパターン群 */
    std::vector<SwitchPattern> _switchPatterns;
    /* 現在のパターン */
    SwitchPattern _currentPattern;
    
    
};


}


#endif /* defined(__HRStandardLibrary__SwitchableButton__) */
