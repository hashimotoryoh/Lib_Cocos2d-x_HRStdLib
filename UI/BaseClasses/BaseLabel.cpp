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

BaseLabel *BaseLabel::create(const std::string &text, const std::string &fontPath, float fontSize)
{
    BaseLabel *pRet = new (std::nothrow) BaseLabel();
    if (pRet && pRet->init(text, fontPath, fontSize)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BaseLabel::init(const std::string &text, const std::string &fontPath, float fontSize)
{
    if (!this->Label::init() || !this->setTTFConfig(TTFConfig(fontPath.c_str(), fontSize))) return false;
    
    this->setString(text);
    
    return true;
}
