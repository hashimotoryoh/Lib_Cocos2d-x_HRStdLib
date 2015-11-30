//
//  BaseLabel.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#ifndef __HRStandardLibrary__BaseLabel__
#define __HRStandardLibrary__BaseLabel__

#include "cocos2d.h"


namespace HR {


class BaseLabel : public cocos2d::Label
{
CC_CONSTRUCTOR_ACCESS:
    BaseLabel();
    virtual ~BaseLabel();
    
    virtual bool init() override;
    
    
#pragma mark - Create Methods
public:
    static BaseLabel *create();
    
    
};


}


#endif /* defined(__HRStandardLibrary__BaseLabel__) */
