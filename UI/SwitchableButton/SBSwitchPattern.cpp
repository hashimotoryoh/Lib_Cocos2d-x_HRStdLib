//
//  SBSwitchPattern.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/17.
//
//

#include "SBSwitchPattern.h"
#include "HRConfig.h"


using namespace HR;
USING_NS_CC;



#pragma mark - Constructor & Destructor

SBSwitchPattern::SBSwitchPattern()
: _key(STRING_UNSET)
, _imageFile(STRING_UNSET)
, _callback(nullptr)
{
}

SBSwitchPattern::~SBSwitchPattern()
{
}



#pragma mark - Create & Initialize Methods

SBSwitchPattern *SBSwitchPattern::create(const std::string &key, const std::string &imageFile, SBTapCallback callback /* = nullptr */)
{
    SBSwitchPattern *pRet = new (std::nothrow) SBSwitchPattern();
    if (pRet && pRet->init(key, imageFile, callback)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool SBSwitchPattern::init(const std::string &key, const std::string &imageFile, SBTapCallback callback)
{
    _key       = key;
    _imageFile = imageFile;
    _callback  = callback;
    
    return true;
}
