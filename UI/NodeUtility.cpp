//
//  NodeUtility.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/11/13.
//
//

#include "NodeUtility.h"

using namespace HR;
USING_NS_CC;


cocos2d::Rect NodeUtility::getAbsoluteRect(cocos2d::Node *node)
{
    Size nodeSize     = node->getBoundingBox().size;
    Point absPosition = node->convertToWorldSpaceAR(Point::ZERO);
    
    Rect absRect;
    absRect.origin = Point(absPosition.x - (nodeSize.width *node->getAnchorPoint().x),
                           absPosition.y - (nodeSize.height*node->getAnchorPoint().y));
    absRect.size   = nodeSize;
    
    return absRect;
}


bool NodeUtility::isInsideNode(const cocos2d::Point &point, cocos2d::Node *node)
{
    Rect absRect = NodeUtility::getAbsoluteRect(node);
    return absRect.containsPoint(point);
}