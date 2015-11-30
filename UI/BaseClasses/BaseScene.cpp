
//
//  BaseScene.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/30.
//
//

#include "BaseScene.h"


using namespace HR;
USING_NS_CC;



#pragma mark - Constructor & Destructor

BaseScene::BaseScene()
{
}

BaseScene::~BaseScene()
{
}



#pragma mark - Create & Initialize Methods

BaseScene *BaseScene::create()
{
    BaseScene *pRet = new (std::nothrow) BaseScene();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BaseScene::init()
{
    if (!this->Scene::init()) return false;
    
    return true;
}
