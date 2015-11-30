//
//  BaseLabel.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#include "BaseLabel.h"


using namespace HR;
USING_NS_CC;



#pragma mark - Constructor & Destructor

BaseLabel::BaseLabel()
{
}

BaseLabel::~BaseLabel()
{
}



#pragma mark - Create & Initialize Methods

BaseLabel *BaseLabel::create()
{
    BaseLabel *pRet = new (std::nothrow) BaseLabel();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BaseLabel::init()
{
    if (!this->Label::init()) return false;
    
    return true;
}
