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


//}


#endif
