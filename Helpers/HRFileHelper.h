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
     * @brief ファイルが存在するかチェックする
     *        エラーログを統一する為
     * @param path       ファイルパス
     * @param isContinue (false)ログ出力だけしてエラーにはしないか
     */
    static void checkIsFileExists(const std::string &path, bool isContinue = false);
    
    /**
     * @brief  ファイルをテキストファイルとして読み込む
     * @param  path ファイルパス
     * @retrun テキストファイルの内容
     */
    static std::string getStringFromFile(const std::string &path);
    
    /**
     * @brief  文字列をテキストファイルに書き込む
     * @param  str       文字列
     * @param  path      書き込み先パス
     * @param  overwrite (true)既に存在した場合上書きするか
     * @return 書き込みが成功したか
     */
    static void saveStringToFile(const std::string &str, const std::string &path, bool overwrite = true);
    
    /**
     * @brief  ファイルパスからファイル名を取得する
     * @param  path      ファイルパス
     * @param  extension 拡張子を付けるか(デフォルト true)
     * @return ファイル名
     */
    static std::string getFileNameFromPath(const std::string &path, bool extension = true);
    
    /**
     * @brief  ファイルパスからディレクトリ構成を取得する
     * @param  path ファイルパス
     * @return ディレクトリの配列
     */
    static std::vector<std::string> getDirectoriesFromPath(const std::string &path);
    
    /**
     * @brief  画像のファイルパスからテクスチャを取得する
     * @param  path 画像ファイルパス
     * @return テクスチャ
     */
    static cocos2d::Texture2D *getTexture(const std::string &path);


};


} // namespace HR

#endif
