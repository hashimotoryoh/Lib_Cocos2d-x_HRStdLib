//
//  HRFileHelper.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/04.
//
//

#ifndef HRStandardLibrary_HRFileHelper_h
#define HRStandardLibrary_HRFileHelper_h

#include "cocos2d.h"


namespace HR {


class HRFileHelper
{
public:
    /**
     * @brief  ファイルパスからファイル名を取得する
     * @param  path      ファイルパス
     * @param  extension 拡張子を付けるか(デフォルト true)
     * @return ファイル名
     */
    static std::string getFileNameFromPath(const std::string &path, bool extension = true);
    
    /**
     * @brief  画像のファイルパスからテクスチャを取得する
     * @param  path 画像ファイルパス
     * @return テクスチャ
     */
    static cocos2d::Texture2D *getTexture(const std::string &path);


};


} // namespace HR

#endif
