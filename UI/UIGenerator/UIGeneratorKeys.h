//
//  UIGeneratorKeys.h
//  HRStandardLibrary
//
//  Created by c1790 on 2015/12/01.
//
//

#ifndef HRStandardLibrary_UIGeneratorKeys_h
#define HRStandardLibrary_UIGeneratorKeys_h


namespace UIGeneratorKey {


#pragma mark Common Parameter Keys
    const char* PARAM_KEY_WIDTH    = "width";
    const char* PARAM_KEY_HEIGHT   = "height";
    const char* PARAM_KEY_POS_X    = "position_x";
    const char* PARAM_KEY_POS_Y    = "position_y";
    const char* PARAM_KEY_ANCHOR_X = "anchor_x";
    const char* PARAM_KEY_ANCHOR_Y = "anchor_y";
    const char* PARAM_KEY_TAG      = "tag";
    const char* PARAM_KEY_NAME     = "name";
    const char* PARAM_KEY_SCALE    = "scale";
    const char* PARAM_KEY_ROTATION = "rotation";
    const char* PARAM_KEY_OPACITY  = "opacity";
    const char* PARAM_KEY_VISIBLE  = "visible";
    const char* PARAM_KEY_CHILDREN = "children";
    const char* PARAM_KEY_TYPE     = "type";

#pragma mark Layer's Parameter Keys
    const char* CHILD_TYPE_LAYER = "layer";

#pragma mark Sprite's Parameter Keys
    const char* CHILD_TYPE_SPRITE = "sprite";
    const char* PARAM_KEY_FILEPATH = "filepath";

#pragma mark TouchableSprite's Parameter Keys
    const char* CHILD_TYPE_TOUCHABLE_SPRITE = "touchable_sprite";
    const char* PARAM_KEY_ENABLED_FILEPATH  = "enabled_filepath";
    const char* PARAM_KEY_DISABLED_FILEPATH = "diabled_filepath";
    const char* PARAM_KEY_IS_ENABLE         = "is_enable";
    const char* PARAM_KEY_LONG_TAP          = "long_tap";
    const char* PARAM_KEY_CONTINUOUS_TAP    = "continuous_tap";

#pragma mark Label's Parameter Keys
    const char* CHILD_TYPE_LABEL       = "label";
    const char* PARAM_KEY_TEXT         = "text";
    const char* PARAM_KEY_FONT_PATH    = "font_path";
    const char* PARAM_KEY_FONT_SIZE    = "font_size";
    const char* PARAM_KEY_FONT_COLOR_R = "font_color_r";
    const char* PARAM_KEY_FONT_COLOR_G = "font_color_g";
    const char* PARAM_KEY_FONT_COLOR_B = "font_color_b";
    const char* PARAM_KEY_TEXT_ALIGN   = "text_alignment";

#pragma mark Button's Parameter Keys
    const char* CHILD_TYPE_BUTTON           = "button";
    //const char* PARAM_KEY_ENABLED_FILEPATH  = "enabled_filepath";
    //const char* PARAM_KEY_DISABLED_FILEPATH = "diabled_filepath";
    //const char* PARAM_KEY_IS_ENABLE         = "is_enable";
    //const char* PARAM_KEY_LONG_TAP          = "long_tap";
    //const char* PARAM_KEY_CONTINUOUS_TAP    = "continuous_tap";
    const char* PARAM_KEY_SCALE_EFFECT      = "scale_effect";
    const char* PARAM_KEY_BRIGHTNESS_EFFECT = "brightness_effect";

#pragma mark SwitchableButton's Parameter Keys
    const char* CHILD_TYPE_SWITCHABLE_BUTTON = "switchable_button";
    const char* PARAM_KEY_PATTERNS           = "patterns";
    const char* PARAM_KEY_PATTERN_KEY        = "key";
    const char* PARAM_KEY_PATTERN_FILEPATH   = "filepath";
    //const char* PARAM_KEY_IS_ENABLE          = "is_enable";
    //const char* PARAM_KEY_SCALE_EFFECT       = "scale_effect";
    //const char* PARAM_KEY_BRIGHTNESS_EFFECT  = "brightness_effect";

#pragma mark TogglableButton's Parameter Keys
    const char* CHILD_TYPE_TOGGLABLE_BUTTON = "togglable_button";
    const char* PARAM_KEY_ON_FILEPATH       = "on_filepath";
    const char* PARAM_KEY_OFF_FILEPATH      = "off_filepath";
    const char* PARAM_KEY_INIT_STATE        = "initial_state";
    //const char* PARAM_KEY_IS_ENABLE         = "is_enable";
    //const char* PARAM_KEY_SCALE_EFFECT      = "scale_effect";
    //const char* PARAM_KEY_BRIGHTNESS_EFFECT = "brightness_effect";
    const char* PARAM_KEY_GRAY_SCALE        = "gray_scale";


}

#endif
