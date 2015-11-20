////
////  TogglableButton.h
////  HRStandardLibrary
////
////  Created by c1790 on 2015/11/20.
////
////
//
//#ifndef __HRStandardLibrary__TogglableButton__
//#define __HRStandardLibrary__TogglableButton__
//
//#include "SwitchableButton.h"
//
//
////namespace HR {
//
//
///**
// * トグル時のコールバック
// * 引数で状態を受け取る
// * on  -> off : false
// * off -> on  : true
// */
//typedef std::function<void(bool)> ToggledCallback;
//
//
//class TogglableButton : public HR::Button
//{
//CC_CONSTRUCTOR_ACCESS:
//    TogglableButton();
//    virtual ~TogglableButton();
//    
//    virtual bool initWithFiles(const std::string &on, const std::string &off, ToggledCallback callback);
//    virtual bool initWithFile(const std::string &imageFile, ToggledCallback callback);
//    
//    
//#pragma mark - Create Methods
//public:
//    /**
//     * @brief  トグルボタンを生成する
//     * @param  on  オンの時の画像ファイル
//     * @param  off オフの時の画像ファイル
//     * @param  callback  (nullptr)コールバック
//     * @return トグルボタン
//     */
//    static TogglableButton *createWithFiles(const std::string &on, const std::string &off, ToggledCallback callback = nullptr);
//    
//    /**
//     * @brief  トグルボタンを生成する
//     * @param  imageFile 画像ファイル
//     * @param  callback  (nullptr)コールバック
//     * @return トグルボタン
//     */
//    static TogglableButton *createWithFile(const std::string &imageFile, ToggledCallback callback = nullptr);
//    
//    
//#pragma mark - Members
//#pragma mark Read Only Members
//    /* トグル状態(2値なのでbool) */
//    CC_SYNTHESIZE_READONLY(bool, _toggleStatus, ToggleStatus);
//#pragma mark Write Only Members
//    /* トグル時のコールバック */
//    HR_SYNTHESIZE_WRITEONLY(ToggledCallback, _toggledCallback, ToggledCallback);
//#pragma mark Private Members
//private:
//    /* オンの時のテクスチャ */
//    cocos2d::Texture2D *_onTexture;
//    /* オフの時のテクスチャ */
//    cocos2d::Texture2D *_offTexture;
//    
//    
//#pragma mark - Control Methods
//#pragma mark Override Methods
//#pragma mark Original Methods
//    
//    
//};
//
//
////}
//
//#endif /* defined(__HRStandardLibrary__TogglableButton__) */
