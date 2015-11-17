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


class SBSwitchPattern
{
CC_CONSTRUCTOR_ACCESS:
public:
    SBSwitchPattern();
    SBSwitchPattern(const std::string &key,
                    const std::string &imageFile,
                    SBTapCallback callback);
    ~SBSwitchPattern();
    
    bool init(const std::string &imageFile, SBTapCallback callback);
    
    
#pragma mark - Create Methods
public:
    /**
     * @brief  SBSwitchableButtonのパターンを生成する
     * @param  imageFile このパターンの時の画像ファイル
     * @param  callback  このパターンでタップされたとくのコールバック
     * @return パターン
     */
    static SBSwitchPattern *create(const std::string &imageFile, SBTapCallback callback);
    
    
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
