//
//  BaseLayer.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#ifndef __HRStandardLibrary__BaseLayer__
#define __HRStandardLibrary__BaseLayer__

#include "cocos2d.h"


namespace HR {


class BaseLayer : public cocos2d::Layer
{
CC_CONSTRUCTOR_ACCESS:
    BaseLayer();
    virtual ~BaseLayer();
    
    virtual bool init() override;
    
    
#pragma mark - Create Methods
public:
    static BaseLayer *create();
    
    
};


}


#endif /* defined(__HRStandardLibrary__BaseLayer__) */
