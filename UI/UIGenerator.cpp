//
//  UIGenerator.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/12/01.
//
//

#include "UIGenerator.h"
#include "UIGeneratorKeys.h"
#include "UIGeneratorDefaults.h"
#include "HRJsonHelper.h"
#include "HRValueHelper.h"


using namespace HR;
using namespace UIGeneratorKey;
using namespace UIGeneratorDefault;
USING_NS_CC;



#pragma mark - Generate Methods

BaseLayer *UIGenerator::generateUI(const std::string &jsonFilepath)
{
    return generateUI(HRJsonHelper::parseJsonFileToValue(jsonFilepath).asValueMap());
}

BaseLayer *UIGenerator::generateUI(cocos2d::ValueMap &UIData)
{
    BaseLayer *ret = constructLayer(UIData);
    
    if (HRValueHelper::isExistsKey(UIData, PARAM_KEY_CHILDREN)) {
        HRASSERT((UIData.at(PARAM_KEY_CHILDREN).getType() == Value::Type::VECTOR),
                 "\"children\"はvector(array)でなければいけません。");
        
        ValueVector childrenData = UIData.at(PARAM_KEY_CHILDREN).asValueVector();
        for (Value childData : childrenData) ret->addChild(constructNode(childData.asValueMap()));
    }
    
    return ret;
}



#pragma mark - UI Construct Methods

cocos2d::Node *UIGenerator::commonConstructor(cocos2d::Node *node, cocos2d::ValueMap &data)
{
    // 幅・高さ
    // TODO: couple width & hegiht
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_WIDTH) && HRValueHelper::isExistsKey(data, PARAM_KEY_HEIGHT)) {
        // TODO: width -> unsigned int?
        // TODO: hegiht -> unsigned int?
        unsigned int width  = data.at(PARAM_KEY_WIDTH).asInt();
        unsigned int hegiht = data.at(PARAM_KEY_HEIGHT).asInt();
        node->setContentSize(Size(width, hegiht));
    }
    
    // ポジション
    // TODO: couple pos_x & pos_y
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_POS_X) && HRValueHelper::isExistsKey(data, PARAM_KEY_POS_Y)) {
        // TODO: pos_x -> float?
        // TODO: pos_y -> float?
        float pos_x = data.at(PARAM_KEY_POS_X).asFloat();
        float pos_y = data.at(PARAM_KEY_POS_Y).asFloat();
        node->setPosition(Vec2(pos_x, pos_y));
    }
    else node->setPosition(Vec2(PARAM_DEFAULT_VALUE_POS_X, PARAM_DEFAULT_VALUE_POS_Y));
    
    // アンカーポイント
    // TODO: couple anchor_x & anchor_y
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_ANCHOR_X) && HRValueHelper::isExistsKey(data, PARAM_KEY_ANCHOR_Y)) {
        // TODO: anchor_x -> float?
        // TODO: anchor_y -> float?
        float anchor_x = data.at(PARAM_KEY_ANCHOR_X).asFloat();
        float anchor_y = data.at(PARAM_KEY_ANCHOR_Y).asFloat();
        node->setAnchorPoint(Vec2(anchor_x, anchor_y));
    }
    else node->setAnchorPoint(Vec2(PARAM_DEFAULT_VALUE_ANCHOR_X, PARAM_DEFAULT_VALUE_ANCHOR_Y));
    
    // タグ
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_TAG)) {
        // TODO: tag -> unsigned int?
        unsigned int tag = data.at(PARAM_KEY_TAG).asInt();
        node->setTag(tag);
    }
    
    // 名前
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_NAME)) {
        // TODO: nane -> std::string?
        std::string name = data.at(PARAM_KEY_NAME).asString();
        node->setName(name);
    }
    
    // スケール
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_SCALE)) {
        // TODO: scale -> float?
        float scale = data.at(PARAM_KEY_SCALE).asFloat();
        node->setScale(scale);
    }
    
    // ローテーション
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_ROTATION)) {
        // TODO: rotation -> float?
        float rotation = data.at(PARAM_KEY_ROTATION).asFloat();
        node->setRotation(rotation);
    }
    
    // 透明度
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_OPACITY)) {
        // TODO: opacity -> unsigned int?
        unsigned int opacity = data.at(PARAM_KEY_OPACITY).asInt();
        node->setOpacity(opacity);
    }
    
    // 表示/非表示
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_VISIBLE)) {
        // TODO: visible -> bool?
        bool visible = data.at(PARAM_KEY_VISIBLE).asBool();
        node->setVisible(visible);
    }
    
    return node;
}

BaseLayer *UIGenerator::constructRootLayer(cocos2d::ValueMap &data)
{
    // MARK: 現在特にRootLayerだけの処理は無し
    return constructLayer(data);
}

Node *UIGenerator::constructNode(cocos2d::ValueMap &data)
{
    // TODO: validate required type
    HRASSERT((data.at(PARAM_KEY_TYPE).getType() == Value::Type::STRING),
             "\"type\"はstringでなければいけません。");
    
    std::string type = data.at(PARAM_KEY_TYPE).asString();
    if      (type == CHILD_TYPE_LAYER)             constructLayer(data);
    else if (type == CHILD_TYPE_SPRITE)            constructSprite(data);
    else if (type == CHILD_TYPE_TOUCHABLE_SPRITE)  constructTouchableSprite(data);
    else if (type == CHILD_TYPE_LABEL)             constructLabel(data);
    else if (type == CHILD_TYPE_BUTTON)            constructButton(data);
    else if (type == CHILD_TYPE_SWITCHABLE_BUTTON) constructSwitchableButton(data);
    else if (type == CHILD_TYPE_TOGGLABLE_BUTTON)  constructTogglableButton(data);
    /* else */
    HRERROR("\"type\"が不正です。: %s", type.c_str());
    
    return nullptr;
}


BaseLayer *UIGenerator::constructLayer(cocos2d::ValueMap &data)
{
    BaseLayer *ret = dynamic_cast<BaseLayer*>(commonConstructor(BaseLayer::create(), data));
    
    // MARK: Layer特有の指定項目は現在特に無し
    
    return ret;
}

BaseSprite *UIGenerator::constructSprite(cocos2d::ValueMap &data)
{
    // 画像ファイルパス
    // TODO: validate required filepath
    HRASSERT((data.at(PARAM_KEY_FILEPATH).getType() == Value::Type::STRING),
             "\"filepath\"はstringでなければいけません。");
    std::string filepath = data.at(PARAM_KEY_FILEPATH).asString();
    
    BaseSprite *ret = dynamic_cast<BaseSprite*>(commonConstructor(BaseSprite::create(filepath), data));
    
    return ret;
}

TouchableSprite *UIGenerator::constructTouchableSprite(cocos2d::ValueMap &data)
{
    // 有効時画像ファイルパス
    // TODO: validate requred enabled_filepath
    HRASSERT((data.at(PARAM_KEY_ENABLED_FILEPATH).getType() == Value::Type::STRING),
             "\"enabled_filepath\"はstringでなければいけません。");
    std::string enabledFilepath = data.at(PARAM_KEY_ENABLED_FILEPATH).asString();
    
    // 無効時画像ファイルパス
    std::string disabledFilepath = enabledFilepath;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_DISABLED_FILEPATH)) {
        HRASSERT((data.at(PARAM_KEY_DISABLED_FILEPATH).getType() == Value::Type::STRING),
                 "\"disabled_filepath\"はstringでなければいけません。");
        disabledFilepath = data.at(PARAM_KEY_DISABLED_FILEPATH).asString();
    }
    
    // 初期有効か
    bool isEnable = true;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_IS_ENABLE)) {
        HRASSERT((data.at(PARAM_KEY_IS_ENABLE).getType() == Value::Type::BOOLEAN),
                 "\"is_enable\"はboolでなければいけません。");
        isEnable = data.at(PARAM_KEY_IS_ENABLE).asBool();
    }
    
    
    TouchableSprite *ret = dynamic_cast<TouchableSprite*>(commonConstructor(TouchableSprite::createWithFiles(enabledFilepath, disabledFilepath, isEnable), data));
    
    
    // ロングタップを有効にするか
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_LONG_TAP)) {
        HRASSERT((data.at(PARAM_KEY_LONG_TAP).getType() == Value::Type::BOOLEAN),
                 "\"long_tap\"はboolでなければいけません。");
        bool isEnableLongTap = data.at(PARAM_KEY_LONG_TAP).asBool();
        if (isEnableLongTap) ret->enableLongTap();
    }
    
    // 連打を有効にするか
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_CONTINUOUS_TAP)) {
        HRASSERT((data.at(PARAM_KEY_CONTINUOUS_TAP).getType() == Value::Type::BOOLEAN),
                 "\"continuous_tap\"はboolでなければいけません。");
        bool isEnableContinuousTap = data.at(PARAM_KEY_CONTINUOUS_TAP).asBool();
        if (isEnableContinuousTap) ret->enableContinuousTap();
    }
    
    return ret;
}

BaseLabel *UIGenerator::constructLabel(cocos2d::ValueMap &data)
{
    // テキスト
    // TODO: validate requred text
    HRASSERT((data.at(PARAM_KEY_TEXT).getType() == Value::Type::STRING),
             "\"text\"はstringでなければいけません。");
    std::string text = data.at(PARAM_KEY_TEXT).asString();
    
    // フォント
    std::string fontPath = PARAM_DEFAULT_VALUE_FONT_PATH;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_FONT_PATH)) {
        HRASSERT((data.at(PARAM_KEY_FONT_PATH).getType() == Value::Type::STRING),
                 "\"font_path\"はstringでなければいけません。");
        fontPath = data.at(PARAM_KEY_FONT_PATH).asString();
    }
    
    // フォントサイズ
    float fontSize = PARAM_DEFAULT_VALUE_FONT_SIZE;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_FONT_SIZE)) {
        HRASSERT((data.at(PARAM_KEY_FONT_SIZE).getType() == Value::Type::FLOAT),
                 "\"font_size\"はfloatでなければいけません。");
        fontSize = data.at(PARAM_KEY_FONT_SIZE).asFloat();
    }
    
    
    BaseLabel *ret = dynamic_cast<BaseLabel*>(commonConstructor(BaseLabel::create(text, fontPath, fontSize), data));
    
    
    // 文字色
    
}



