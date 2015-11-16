//
//  NodeUtility.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/13.
//
//

#ifndef __HRStandardLibrary__NodeUtility__
#define __HRStandardLibrary__NodeUtility__

#include "cocos2d.h"


namespace HR {


class NodeUtility
{
public:
    /**
     * @brief  オブジェクトのワールド座標系における範囲を取得する
     * @param  node 取得したいオブジェクト
     * @return ワールド座標系における範囲
     */
    static cocos2d::Rect getAbsoluteRect(cocos2d::Node *node);
    
    /**
     * @brief  ある座標があるオブジェクトの中かどうか調べる
     * @param  point ある座標
     * @param  node  あるオブジェクト
     * @return true/false
     */
    static bool isInsideNode(const cocos2d::Vec2 &point, cocos2d::Node *node);
    
    
};


}

#endif /* defined(__HRStandardLibrary__NodeUtility__) */
