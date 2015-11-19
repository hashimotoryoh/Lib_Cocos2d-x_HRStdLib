//
//  SBSwitchPattern.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/17.
//
//

#ifndef __HRStandardLibrary__SBSwitchPattern__
#define __HRStandardLibrary__SBSwitchPattern__

#include "cocos2d.h"


namespace HR {
    
    
typedef std::function<void()> SBTapCallback;


class SBSwitchPattern : public cocos2d::Ref
{
CC_CONSTRUCTOR_ACCESS:
    SBSwitchPattern();
    ~SBSwitchPattern();
    
    bool init(const std::string &key, const std::string &imageFile, SBTapCallback callback);
    
    
#pragma mark - Create Methods
public:
    /**
     * @brief  SBSwitchableButtonのパターンを生成する
     * @param  key       キー
     * @param  imageFile このパターンの時の画像ファイル
     * @param  callback  (nullptr)このパターンでタップされた時のコールバック
     * @return パターン
     */
    static SBSwitchPattern *create(const std::string &key, const std::string &imageFile, SBTapCallback callback = nullptr);
    
    
#pragma mark - Members
#pragma mark Public Members
public:
    /* キー */
    std::string _key;
    /* このパターンの時の画像ファイル */
    std::string _imageFile;
    /* スイッチした時のコールバック */
    SBTapCallback _callback;
    
    
};


}

#endif /* defined(__HRStandardLibrary__SBSwitchPattern__) */
