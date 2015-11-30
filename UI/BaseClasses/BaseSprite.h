//
//  BaseSprite.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#ifndef __HRStandardLibrary__BaseSprite__
#define __HRStandardLibrary__BaseSprite__

#include "cocos2d.h"


namespace HR {


class BaseSprite : public cocos2d::Sprite
{
CC_CONSTRUCTOR_ACCESS:
    BaseSprite();
    virtual ~BaseSprite();
    
    virtual bool init() override;
    
    
#pragma mark - Create Methods
    static BaseSprite *create();
    
    
    
};


}


#endif /* defined(__HRStandardLibrary__BaseSprite__) */
