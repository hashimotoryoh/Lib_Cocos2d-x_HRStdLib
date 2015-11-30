//
//  BaseScene.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#ifndef __HRStandardLibrary__BaseScene__
#define __HRStandardLibrary__BaseScene__

#include "cocos2d.h"


namespace HR {


class BaseScene : public cocos2d::Scene
{
CC_CONSTRUCTOR_ACCESS:
    BaseScene();
    virtual ~BaseScene();
    
    virtual bool init() override;
    
    
#pragma mark - Create Methods
public:
    static BaseScene *create();
    
    
};


}


#endif /* defined(__HRStandardLibrary__BaseScene__) */
