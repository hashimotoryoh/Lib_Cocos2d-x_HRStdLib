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


void HRFileHelper::checkIsFileExists(const std::string &path, bool isContinue /* = false */)
{
    if (FileUtils::getInstance()->isFileExist(path)) return;
    
    if (isContinue) { HRLOG("次のファイルは存在しませんが続行します。: %s", path.c_str()); }
    else            { HRERROR("次のファイルは存在しません。: %s", path.c_str()); }
}

std::string HRFileHelper::getStringFromFile(const std::string &path)
{
    HRFileHelper::checkIsFileExists(path);
    
    return FileUtils::getInstance()->getStringFromFile(path);
}

void HRFileHelper::saveStringToFile(const std::string &str, const std::string &path, bool overwrite /* = true */)
{
    // 書き込み可能ディレクトリの取得
    std::string fullPath = CCFileUtils::getInstance()->getWritablePath() + path;
    
    // TODO: pathにディレクトリ構成が含まれていた場合、そのディレクトリを作成する
    
    if (FileUtils::getInstance()->isFileExist(fullPath)) {
        HRLOG("書き込み先のファイルが既に存在します。: %s", path.c_str());
        if (overwrite) { HRLOG("  └─>上書きします。"); }
        else           { return; }
    }
    
    // 書き込み処理
    std::vector<char> buffer;
    std::copy(str.begin(), str.end(), std::back_inserter(buffer));
    FILE *fp = fopen(fullPath.c_str(), "wb");
    fwrite(&buffer[0], sizeof(char), buffer.size(), fp);
    fclose(fp);
}

std::string HRFileHelper::getFileNameFromPath(const std::string &path, bool extension /* = true */)
{
    HRFileHelper::checkIsFileExists(path, true);
    
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

std::vector<std::string> HRFileHelper::getDirectoriesFromPath(const std::string &path)
{
    HRFileHelper::checkIsFileExists(path, true);
    
    std::vector<std::string> directories;
    size_t current = 0;
    size_t cutPoint = current;
    
    while ((cutPoint = path.find_first_of("/", current)) != std::string::npos) {
        directories.push_back(std::string(path, current, cutPoint-current));
        current = cutPoint+1;
    }
    
    return directories;
}

cocos2d::Texture2D *HRFileHelper::getTexture(const std::string &path)
{
    HRFileHelper::checkIsFileExists(path);
    
    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(path);
    HRASSERT(texture, "画像のファイルパスが不正です。: %s", path.c_str());
    return texture;
}
