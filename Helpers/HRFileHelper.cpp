//
//  HRFileHelper.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/04.
//
//

#include "HRFileHelper.h"
#include "HRLog.h"


using namespace HR;
USING_NS_CC;


std::string HRFileHelper::getFileNameFromPath(const std::string &path, bool extension /* = true */)
{
    std::string fileName;
    size_t current = 0;
    size_t cutPoint = current;
    
    // ディレクトリ情報を除去
    while (cutPoint != std::string::npos) {
        // "/"を見つけたらそれ以降の文字列をfileNameにする
        // "/"が無くなるまで繰り返す
        cutPoint = path.find_first_of("/", current);
        
        fileName = std::string(path, current, path.length());
        current = cutPoint+1;
    }
    
    // 拡張子を除去
    if (!extension) {
        // 最後の"."以降を除く
        if ((cutPoint=fileName.find_last_of(".")) != std::string::npos) fileName = std::string(fileName, 0, cutPoint);
    }
    
    return fileName;
}

cocos2d::Texture2D *HRFileHelper::getTexture(const std::string &path)
{
    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(path);
    HRASSERT(texture, "画像のファイルパスが不正です。: %s", path.c_str());
    return texture;
}
