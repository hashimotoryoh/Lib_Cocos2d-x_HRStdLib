//
//  UIGenerator.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/12/01.
//
//

#ifndef __HRStandardLibrary__UIGenerator__
#define __HRStandardLibrary__UIGenerator__

#include "cocos2d.h"
#include "BaseLayer.h"
#include "BaseSprite.h"
#include "TouchableSprite.h"
#include "BaseLabel.h"
#include "Button.h"
#include "SwitchableButton.h"
#include "TogglableButton.h"


//namespace HR {


class UIGenerator
{
public:
    /**
     * @brief  JSONファイルからUIを作る
     * @param  jsonFilepath JSONファイルパス
     * @return UI
     */
    static HR::BaseLayer *generateUI(const std::string &jsonFilepath);
    
    /**
     * @brief  cocos2d::ValueMapに落とされたJSONデータからUIを作る
     * @param  UIData データ
     * @return UI
     */
    static HR::BaseLayer *generateUI(cocos2d::ValueMap &UIData);
    
    
private:
#pragma mark Validate Methods
    /**
     * @brief UI構成データのバリデーションチェック
     *        ただし、"children"より下層のデータのチェックは行わない
     */
//    static bool validateSelfUIData(cocos2d::ValueMap data);
//    
//    static bool validateUIDataOfCommon(cocos2d::ValueMap data);
//    static bool validateUIDataOfLayer(cocos2d::ValueMap data);
//    static bool validateUIDataOfSprite(cocos2d::ValueMap data);
//    static bool validateUIDataOfTouchableSprite(cocos2d::ValueMap data);
//    static bool validateUIDataOfLabel(cocos2d::ValueMap data);
//    static bool validateUIDataOfButton(cocos2d::ValueMap data);
//    static bool validateUIDataOfSwitchableButton(cocos2d::ValueMap data);
//    static bool validateUIDataOfTogglableButton(cocos2d::ValueMap data);
    
    
#pragma mark - UI Construct Methods
    static cocos2d::Node        *commonConstructor        (cocos2d::Node *node, cocos2d::ValueMap &data);
    static HR::BaseLayer        *constructRootLayer       (cocos2d::ValueMap &data);
    static cocos2d::Node        *constructNode            (cocos2d::ValueMap &data);
    
    static HR::BaseLayer        *constructLayer           (cocos2d::ValueMap &data);
    static HR::BaseSprite       *constructSprite          (cocos2d::ValueMap &data);
    static HR::TouchableSprite  *constructTouchableSprite (cocos2d::ValueMap &data);
    static HR::BaseLabel        *constructLabel           (cocos2d::ValueMap &data);
    static HR::Button           *constructButton          (cocos2d::ValueMap &data);
    static HR::SwitchableButton *constructSwitchableButton(cocos2d::ValueMap &data);
    static HR::TogglableButton  *constructTogglableButton (cocos2d::ValueMap &data);
    
    
    
};


//}

#endif /* defined(__HRStandardLibrary__UIGenerator__) */
