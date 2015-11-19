//
//  TogglableButton.cpp
//  cocos3.4
//
//  Created by 橋本龍 on 2015/11/20.
//
//

#include "TogglableButton.hpp"


using namespace HR;
USING_NS_CC;



#pragma mark - Constructor & Destructor

TogglableButton::TogglableButton()
{
}

TogglableButton::~TogglableButton()
{
}



#pragma mark - Create & Initialize Methods

TogglableButton *TogglableButton::create()
{
    TogglableButton *pRet = new (std::nothrow) TogglableButton;
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool TogglableButton::init()
{
    if (!this->TogglableButton::init()) return false;
    
    
    
    return true;
}

TogglableButton *TogglableButton::createWithFiles(const std::string &on, const std::string &off)
{
    TogglableButton *pRet = TogglableButton::create();
    if (pRet->initWithFiles(on, off)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool TogglableButton::initWithFiles(const std::string &on, const std::string &off)
{
}