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
    
    virtual bool init(const std::string &filepath);
    
    
#pragma mark - Create Methods
public:
    static BaseSprite *create(const std::string &filepath);
    
    
    
};


}


#endif /* defined(__HRStandardLibrary__BaseSprite__) */
