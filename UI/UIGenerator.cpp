//
//  UIGenerator.cpp
//  HRStandardLibrary
//
//  Created by c1790 on 2015/12/01.
//
//

#include "UIGenerator.h"
#include "UIGeneratorKeys.h"
#include "UIGeneratorValues.h"
#include "UIGeneratorDefaults.h"
#include "ValidateUIData.h"
#include "HRJsonHelper.h"
#include "HRValueHelper.h"


using namespace HR;
using namespace UIGeneratorKey;
using namespace UIGeneratorValue;
using namespace UIGeneratorDefault;
USING_NS_CC;


const char *VALIDATION_FAILED_MESSAGE = "バリデートに失敗しました。";



#pragma mark - Generate Methods

BaseLayer *UIGenerator::generateUI(const std::string &jsonFilepath)
{
    HRLOG("");
    HRLOG("");
    HRLOG("=============== %s のUI生成 開始 ===============", jsonFilepath.c_str());
    HRLOG("");
    HRLOG("");
    
    BaseLayer *ret = generateUI(HRJsonHelper::parseJsonFileToValue(jsonFilepath).asValueMap());
    
    HRLOG("");
    HRLOG("");
    HRLOG("=============== %s のUI生成 終了 ===============", jsonFilepath.c_str());
    HRLOG("");
    HRLOG("");
    
    return ret;
}

BaseLayer *UIGenerator::generateUI(cocos2d::ValueMap &UIData)
{
    BaseLayer *ret = constructLayer(UIData);
    
    return ret;
}



#pragma mark - UI Construct Methods

cocos2d::Node *UIGenerator::commonConstructor(cocos2d::Node *node, cocos2d::ValueMap &data)
{
    // 幅・高さ
    if (ValidateUIData::validateCouple(data, PARAM_KEY_WIDTH, PARAM_KEY_HEIGHT)
        && (HRValueHelper::isExistsKey(data, PARAM_KEY_WIDTH) && HRValueHelper::isExistsKey(data, PARAM_KEY_HEIGHT))) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_WIDTH, Value::Type::INTEGER), VALIDATION_FAILED_MESSAGE);
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_HEIGHT, Value::Type::INTEGER), VALIDATION_FAILED_MESSAGE);
        
        unsigned int width  = data.at(PARAM_KEY_WIDTH).asInt();
        unsigned int hegiht = data.at(PARAM_KEY_HEIGHT).asInt();
        node->setContentSize(Size(width, hegiht));
    }
    
    // ポジション
    ValidateUIData::validateCouple(data, PARAM_KEY_POS_X, PARAM_KEY_POS_Y);
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_POS_X) && HRValueHelper::isExistsKey(data, PARAM_KEY_POS_Y)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_POS_X, Value::Type::FLOAT), VALIDATION_FAILED_MESSAGE);
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_POS_Y, Value::Type::FLOAT), VALIDATION_FAILED_MESSAGE);
        
        float pos_x = data.at(PARAM_KEY_POS_X).asFloat();
        float pos_y = data.at(PARAM_KEY_POS_Y).asFloat();
        node->setPosition(Vec2(pos_x, pos_y));
    }
    else node->setPosition(Vec2(PARAM_DEFAULT_VALUE_POS_X, PARAM_DEFAULT_VALUE_POS_Y));
    
    // アンカーポイント
    ValidateUIData::validateCouple(data, PARAM_KEY_ANCHOR_X, PARAM_KEY_ANCHOR_Y);
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_ANCHOR_X) && HRValueHelper::isExistsKey(data, PARAM_KEY_ANCHOR_Y)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_ANCHOR_X, Value::Type::FLOAT), VALIDATION_FAILED_MESSAGE);
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_ANCHOR_Y, Value::Type::FLOAT), VALIDATION_FAILED_MESSAGE);
        
        float anchor_x = data.at(PARAM_KEY_ANCHOR_X).asFloat();
        float anchor_y = data.at(PARAM_KEY_ANCHOR_Y).asFloat();
        node->setAnchorPoint(Vec2(anchor_x, anchor_y));
    }
    else node->setAnchorPoint(Vec2(PARAM_DEFAULT_VALUE_ANCHOR_X, PARAM_DEFAULT_VALUE_ANCHOR_Y));
    
    // タグ
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_TAG)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_TAG, Value::Type::INTEGER), VALIDATION_FAILED_MESSAGE);
        
        unsigned int tag = data.at(PARAM_KEY_TAG).asInt();
        node->setTag(tag);
    }
    
    // 名前
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_NAME)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_NAME, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        
        std::string name = data.at(PARAM_KEY_NAME).asString();
        node->setName(name);
    }
    
    // スケール
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_SCALE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_SCALE, Value::Type::FLOAT), VALIDATION_FAILED_MESSAGE);
        
        float scale = data.at(PARAM_KEY_SCALE).asFloat();
        node->setScale(scale);
    }
    
    // ローテーション
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_ROTATION)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_ROTATION, Value::Type::FLOAT), VALIDATION_FAILED_MESSAGE);
        
        float rotation = data.at(PARAM_KEY_ROTATION).asFloat();
        node->setRotation(rotation);
    }
    
    // 透明度
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_OPACITY)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_OPACITY, Value::Type::INTEGER), VALIDATION_FAILED_MESSAGE);
        
        unsigned int opacity = data.at(PARAM_KEY_OPACITY).asInt();
        node->setOpacity(opacity);
    }
    
    // 表示/非表示
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_VISIBLE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_VISIBLE, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool visible = data.at(PARAM_KEY_VISIBLE).asBool();
        node->setVisible(visible);
    }
    
    
    // 子ノード
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_CHILDREN)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_CHILDREN, Value::Type::VECTOR), VALIDATION_FAILED_MESSAGE);
        ValueVector children = data.at(PARAM_KEY_CHILDREN).asValueVector();
        for (Value child : children) {
            HRASSERT((child.getType() == Value::Type::MAP),
                     "\"children\"はmapでなければいけません。");
            node->addChild(constructNode(child.asValueMap()));
        }
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
    HRASSERT(ValidateUIData::validateRequired(data, {
        PARAM_KEY_TYPE
    }), VALIDATION_FAILED_MESSAGE);
    HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_TYPE, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
    
    std::string type = data.at(PARAM_KEY_TYPE).asString();
    if      (type == CHILD_TYPE_LAYER)             return constructLayer(data);
    else if (type == CHILD_TYPE_SPRITE)            return constructSprite(data);
    else if (type == CHILD_TYPE_TOUCHABLE_SPRITE)  return constructTouchableSprite(data);
    else if (type == CHILD_TYPE_LABEL)             return constructLabel(data);
    else if (type == CHILD_TYPE_BUTTON)            return constructButton(data);
    else if (type == CHILD_TYPE_SWITCHABLE_BUTTON) return constructSwitchableButton(data);
    else if (type == CHILD_TYPE_TOGGLABLE_BUTTON)  return constructTogglableButton(data);
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
    HRASSERT(ValidateUIData::validateRequired(data, {
        PARAM_KEY_FILEPATH
    }), VALIDATION_FAILED_MESSAGE);
    
    // 画像ファイルパス
    HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
    std::string filepath = data.at(PARAM_KEY_FILEPATH).asString();
    
    BaseSprite *ret = dynamic_cast<BaseSprite*>(commonConstructor(BaseSprite::create(filepath), data));
    
    return ret;
}

TouchableSprite *UIGenerator::constructTouchableSprite(cocos2d::ValueMap &data)
{
    HRASSERT(ValidateUIData::validateRequired(data, {
        PARAM_KEY_ENABLED_FILEPATH
    }), VALIDATION_FAILED_MESSAGE);
    
    // 有効時画像ファイルパス
    HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_ENABLED_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
    std::string enabledFilepath = data.at(PARAM_KEY_ENABLED_FILEPATH).asString();
    
    // 無効時画像ファイルパス
    std::string disabledFilepath = enabledFilepath;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_DISABLED_FILEPATH)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_DISABLED_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        
        disabledFilepath = data.at(PARAM_KEY_DISABLED_FILEPATH).asString();
    }
    
    // 初期有効か
    bool isEnable = true;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_IS_ENABLE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_IS_ENABLE, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        isEnable = data.at(PARAM_KEY_IS_ENABLE).asBool();
    }
    
    
    TouchableSprite *ret = dynamic_cast<TouchableSprite*>(commonConstructor(TouchableSprite::createWithFiles(enabledFilepath, disabledFilepath, isEnable), data));
    
    
    // ロングタップを有効にするか
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_LONG_TAP)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_LONG_TAP, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool isEnableLongTap = data.at(PARAM_KEY_LONG_TAP).asBool();
        isEnableLongTap ? ret->enableLongTap() : ret->disableLongTap();
    }
    
    // 連打を有効にするか
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_CONTINUOUS_TAP)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_CONTINUOUS_TAP, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool isEnableContinuousTap = data.at(PARAM_KEY_CONTINUOUS_TAP).asBool();
        isEnableContinuousTap ? ret->enableContinuousTap() : ret->disableContinuousTap();
    }
    
    return ret;
}

BaseLabel *UIGenerator::constructLabel(cocos2d::ValueMap &data)
{
    HRASSERT(ValidateUIData::validateRequired(data, {
        PARAM_KEY_TEXT
    }), VALIDATION_FAILED_MESSAGE);
    
    // テキスト
    HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_TEXT, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
    std::string text = data.at(PARAM_KEY_TEXT).asString();
    
    // フォント
    std::string fontPath = PARAM_DEFAULT_VALUE_FONT_PATH;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_FONT_PATH)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_FONT_PATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        
        fontPath = data.at(PARAM_KEY_FONT_PATH).asString();
    }
    
    // フォントサイズ
    float fontSize = PARAM_DEFAULT_VALUE_FONT_SIZE;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_FONT_SIZE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_FONT_SIZE, Value::Type::FLOAT), VALIDATION_FAILED_MESSAGE);
        
        fontSize = data.at(PARAM_KEY_FONT_SIZE).asFloat();
    }
    
    
    BaseLabel *ret = dynamic_cast<BaseLabel*>(commonConstructor(BaseLabel::create(text, fontPath, fontSize), data));
    
    
    // 文字色
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_FONT_COLOR_R)
        && HRValueHelper::isExistsKey(data, PARAM_KEY_FONT_COLOR_G)
        && HRValueHelper::isExistsKey(data, PARAM_KEY_FONT_COLOR_B)) {
        
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_FONT_COLOR_R, Value::Type::INTEGER), VALIDATION_FAILED_MESSAGE);
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_FONT_COLOR_G, Value::Type::INTEGER), VALIDATION_FAILED_MESSAGE);
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_FONT_COLOR_B, Value::Type::INTEGER), VALIDATION_FAILED_MESSAGE);
        
        GLubyte r = data.at(PARAM_KEY_FONT_COLOR_R).asInt();
        GLubyte g = data.at(PARAM_KEY_FONT_COLOR_G).asInt();
        GLubyte b = data.at(PARAM_KEY_FONT_COLOR_B).asInt();
        ret->setTextColor(Color4B(Color3B(r, g, b)));
        
    }
    
    // 寄せ
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_TEXT_ALIGN)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_TEXT_ALIGN, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        
        TextHAlignment align = convertAlignment(data.at(PARAM_KEY_TEXT_ALIGN).asString());
        ret->setAlignment(align);
    }
    
    return ret;
}

Button *UIGenerator::constructButton(cocos2d::ValueMap &data)
{
    HRASSERT(ValidateUIData::validateRequired(data, {
        PARAM_KEY_ENABLED_FILEPATH
    }), VALIDATION_FAILED_MESSAGE);
    
    // 有効時画像ファイルパス
    HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_ENABLED_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
    std::string enabledFilepath = data.at(PARAM_KEY_ENABLED_FILEPATH).asString();
    
    // 無効時画像ファイルパス
    std::string disabledFilepath = enabledFilepath;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_DISABLED_FILEPATH)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_DISABLED_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        
        disabledFilepath = data.at(PARAM_KEY_DISABLED_FILEPATH).asString();
    }
    
    // 初期有効か
    bool isEnable = true;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_IS_ENABLE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_IS_ENABLE, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        isEnable = data.at(PARAM_KEY_IS_ENABLE).asBool();
    }
    
    
    Button *ret = dynamic_cast<Button*>(commonConstructor(Button::createWithFiles(enabledFilepath, disabledFilepath, isEnable), data));
    
    
    // ロングタップを有効にするか
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_LONG_TAP)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_LONG_TAP, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool isEnableLongTap = data.at(PARAM_KEY_LONG_TAP).asBool();
        isEnableLongTap ? ret->enableLongTap() : ret->disableLongTap();
    }
    
    // 連打を有効にするか
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_CONTINUOUS_TAP)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_CONTINUOUS_TAP, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool isEnableContinuousTap = data.at(PARAM_KEY_CONTINUOUS_TAP).asBool();
        isEnableContinuousTap ? ret->enableContinuousTap() : ret->disableContinuousTap();
    }
    
    // スケールエフェクト
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_SCALE_EFFECT)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_SCALE_EFFECT, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool scaleEffect = data.at(PARAM_KEY_SCALE_EFFECT).asBool();
        scaleEffect ? ret->enableScaleEffect() : ret->disableScaleEffect();
    }
    
    // 明暗エフェクト
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_BRIGHTNESS_EFFECT)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_BRIGHTNESS_EFFECT, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool brightnessEffect = data.at(PARAM_KEY_BRIGHTNESS_EFFECT).asBool();
        brightnessEffect ? ret->enableBrightnessEffect() : ret->disableBrightnessEffect();
    }
    
    return ret;
}

SwitchableButton *UIGenerator::constructSwitchableButton(cocos2d::ValueMap &data)
{
    HRASSERT(ValidateUIData::validateRequired(data, {
        PARAM_KEY_PATTERNS
    }), VALIDATION_FAILED_MESSAGE);
    
    // パターン群
    HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_PATTERNS, Value::Type::VECTOR), VALIDATION_FAILED_MESSAGE);
    ValueVector patternsData = data.at(PARAM_KEY_PATTERNS).asValueVector();
    Vector<SBSwitchPattern*> patterns;
    
    // パターン一つ一つ
    for (Value patternData : patternsData) {
        ValueMap pattern = patternData.asValueMap();
        HRASSERT(ValidateUIData::validateRequired(pattern, {
            PARAM_KEY_PATTERN_KEY,
            PARAM_KEY_PATTERN_FILEPATH
        }), VALIDATION_FAILED_MESSAGE);
        
        // キー
        HRASSERT(ValidateUIData::validateType(pattern, PARAM_KEY_PATTERN_KEY, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        std::string key = pattern.at(PARAM_KEY_PATTERN_KEY).asString();
        
        // 画像ファイルパス
        HRASSERT(ValidateUIData::validateType(pattern, PARAM_KEY_PATTERN_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        std::string filepath = pattern.at(PARAM_KEY_PATTERN_FILEPATH).asString();
        
        patterns.pushBack(SBSwitchPattern::create(key, filepath));
    }
    
    
    SwitchableButton *ret = dynamic_cast<SwitchableButton*>(commonConstructor(SwitchableButton::createWithPatterns(patterns), data));
    
    
    // 初期有効か
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_IS_ENABLE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_IS_ENABLE, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool isEnable = data.at(PARAM_KEY_IS_ENABLE).asBool();
        isEnable ? ret->enable() : ret->disable();
    }
    
    // スケールエフェクト
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_SCALE_EFFECT)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_SCALE_EFFECT, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool scaleEffect = data.at(PARAM_KEY_SCALE_EFFECT).asBool();
        scaleEffect ? ret->enableScaleEffect() : ret->disableScaleEffect();
    }
    
    // 明暗エフェクト
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_BRIGHTNESS_EFFECT)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_BRIGHTNESS_EFFECT, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool brightnessEffect = data.at(PARAM_KEY_BRIGHTNESS_EFFECT).asBool();
        brightnessEffect ? ret->enableBrightnessEffect() : ret->disableBrightnessEffect();
    }
    
    return ret;
}

TogglableButton *UIGenerator::constructTogglableButton(cocos2d::ValueMap &data)
{
    HRASSERT(ValidateUIData::validateRequired(data, {
        PARAM_KEY_ON_FILEPATH
    }), VALIDATION_FAILED_MESSAGE);
    
    // オンの時の画像ファイルパス
    HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_ON_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
    std::string onFilepath = data.at(PARAM_KEY_ON_FILEPATH).asString();
    
    // オフの時の画像ファイルパス
    std::string offFilepath = onFilepath;
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_OFF_FILEPATH)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_OFF_FILEPATH, Value::Type::STRING), VALIDATION_FAILED_MESSAGE);
        
        offFilepath = data.at(PARAM_KEY_OFF_FILEPATH).asString();
    }
    
    
    TogglableButton *ret = dynamic_cast<TogglableButton*>(commonConstructor(TogglableButton::createWithFiles(onFilepath, offFilepath), data));
    
    
    // 初期状態
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_INIT_STATE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_INIT_STATE, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool initState = data.at(PARAM_KEY_INIT_STATE).asBool();
        initState ? ret->turnOn() : ret->turnOff();
    }
    
    // 初期有効か
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_IS_ENABLE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_IS_ENABLE, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool isEnable = data.at(PARAM_KEY_IS_ENABLE).asBool();
        isEnable ? ret->enable() : ret->disable();
    }
    
    // スケールエフェクト
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_SCALE_EFFECT)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_SCALE_EFFECT, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool scaleEffect = data.at(PARAM_KEY_SCALE_EFFECT).asBool();
        scaleEffect ? ret->enableScaleEffect() : ret->disableScaleEffect();
    }
    
    // 明暗エフェクト
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_BRIGHTNESS_EFFECT)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_BRIGHTNESS_EFFECT, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool brightnessEffect = data.at(PARAM_KEY_BRIGHTNESS_EFFECT).asBool();
        brightnessEffect ? ret->enableBrightnessEffect() : ret->disableBrightnessEffect();
    }
    
    // オフの時のグレースケール
    if (HRValueHelper::isExistsKey(data, PARAM_KEY_GRAY_SCALE)) {
        HRASSERT(ValidateUIData::validateType(data, PARAM_KEY_GRAY_SCALE, Value::Type::BOOLEAN), VALIDATION_FAILED_MESSAGE);
        
        bool grayScale = data.at(PARAM_KEY_GRAY_SCALE).asBool();
        ret->setIsGrayScale(grayScale);
    }
    
    return ret;
}


TextHAlignment UIGenerator::convertAlignment(const std::string &strAlign)
{
    if      (strAlign == PARAM_VALUE_TEXT_ALIGN_LEFT)   return TextHAlignment::LEFT;
    else if (strAlign == PARAM_VALUE_TEXT_ALIGN_CENTER) return TextHAlignment::CENTER;
    else if (strAlign == PARAM_VALUE_TEXT_ALIGN_RIGHT)  return TextHAlignment::RIGHT;
    /* else */
    return TextHAlignment::LEFT;
}
