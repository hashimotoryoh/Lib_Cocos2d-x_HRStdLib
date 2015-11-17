//
//  HRMacros.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/13.
//
//

#ifndef HRStandardLibrary_HRMacros_h
#define HRStandardLibrary_HRMacros_h


//namespace HR {


/**
 * @brief  setterのみを持つのメンバ変数を宣言する
 *         CC_SYNTHESIZE_WRITEONLY的な。
 * @param  varType 型
 * @param  varName 変数名
 * @param  funName 'set'の後に続く文字
 */
#define HR_SYNTHESIZE_WRITEONLY(varType, varName, funName)\
private: varType varName;\
public: virtual void set##funName(varType var){ varName = var; }

/**
 * @brief 親クラスのメソッドをprivateでオーバーライドして隠す
 * @param methodType 返却型
 * @param methodName メソッド名
 * @param ...        そのメソッドの引数の型
 */
#define HR_DISABLE_SUPER_METHOD(methodType, methodName, ...)\
private: methodType methodName(__VA_ARGS__) override {};


//}


#endif
