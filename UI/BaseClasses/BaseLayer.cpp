//
//  BaseLayer.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#include "BaseLayer.h"


using namespace HR;
USING_NS_CC;



#pragma mark - Constructor & Destructor

BaseLayer::BaseLayer()
{
}

BaseLayer::~BaseLayer()
{
}



#pragma mark - Create & initialize Methods

BaseLayer *BaseLayer::create()
{
    BaseLayer *pRet = new (std::nothrow) BaseLayer();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BaseLayer::init()
{
    if (this->Layer::init()) return false;
    
    return true;
}
