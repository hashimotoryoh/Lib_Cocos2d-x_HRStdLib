//
//  BaseSprite.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#include "BaseSprite.h"


using namespace HR;
USING_NS_CC;



#pragma mark - Constructor & Destructor

BaseSprite::BaseSprite()
{
}

BaseSprite::~BaseSprite()
{
}



#pragma mark - Create & Initialize Methods

BaseSprite *BaseSprite::create(const std::string &filepath)
{
    BaseSprite *pRet = new (std::nothrow) BaseSprite();
    if (pRet && pRet->init(filepath)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BaseSprite::init(const std::string &filepath)
{
    if (!this->Sprite::initWithFile(filepath)) return false;
    
    return true;
}
