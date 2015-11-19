//
//  TogglableButton.hpp
//  cocos3.4
//
//  Created by 橋本龍 on 2015/11/20.
//
//

#ifndef TogglableButton_hpp
#define TogglableButton_hpp

#include "SwitchableButton.h"


//namespace HR {


typedef std::function<void()> ToggleCallback;


class TogglableButton : HR::SwitchableButton
{
CC_CONSTRUCTOR_ACCESS:
    TogglableButton();
    virtual ~TogglableButton();
    
    virtual bool init();
    virtual bool initWithFiles(const std::string &on, const std::string &off);
    
    
#pragma mark - Create Methods
public:
    /**
     * @brief  トグル式のボタンを生成する
     * @return トグルボタン
     */
    static TogglableButton *create();
    /**
     * @brief  トグル式のボタンを生成する
     * @param  on  オンの時の画像ファイル
     * @param  off オフの時の画像ファイル
     * @return トグルボタン
     */
    static TogglableButton *createWithFiles(const std::string &on, const std::string &off);
    
    
    
#pragma mark - Control Methods

    
    
#pragma mark - Members
#pragma mark Public Members
#pragma mark Write Only Members
    HR_SYNTHESIZE_WRITEONLY(ToggleCallback, _toggleOnCallback, ToggleOnCallback);
    HR_SYNTHESIZE_WRITEONLY(TogglableButton, _toggleOffCallback, ToggleOffCallback);
};


//}


#endif /* TogglableButton_hpp */
