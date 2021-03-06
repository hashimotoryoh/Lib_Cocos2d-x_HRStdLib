# What's UIGenerator?

Cocos2d-xでのUIの組み方は、基本的にはSceneにLayerを貼って、LayerにSpriteやらLabelやらをペタペタ貼っていく感じである。
だったらJSONで一画面分全部定義してしまえば楽じゃない？ってことで作ったのがUIGenerator。

JSONを読み込んでUIを組み立てるもの。

# Parameters Description

cocos2d::Nodeが持っているsetterで指定出来るもののうち、普段使うやつが指定出来るようになってる。
KeyはJSONのキー。ValueTypeはC++で読み取る型。

## Common Parameters

ルートと子ノードで共通のパラメータ。

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| width | unsigned int | x | 指定無し | 幅 |
| height| unsigned int | x | 指定無し | 高さ |
| position_x | float | x | 0.0f | x座標 |
| position_y | float | x | 0.0f | y座標 |
| anchor_x | float | x | 0.5f | アンカーポイントx (0.0f ~ 1.0f) |
| anchor_y | float | x | 0.5f | アンカーポイントy (0.0f ~ 1.0f) |
| tag | unsigned int | x | 指定無し | タグ |
| name | std::string | x | 指定無し | 名前 |
| scale | float | x | 指定無し | スケール |
| rotation | float | x | 指定なし | 回転角 |
| opacity | unsigned int | x | 指定無し | 透明度(0 ~ 255) |
| visible | bool | x | 指定無し | 表示/非表示 |

## Root Parameters

ルートはHR::BaseLayer。

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
|  |  |  |  |

## Children Types

子ノードのタイプ一覧。

| Key | Value | Type | Description |
|:---|:---|:---|:---|
| type | layer | HR::BaseLayer |  |
| type | sprite | HR::BaseSprite |  |
| type | touchable_sprite | HR::TouchableSprite | タッチイベントを持ったSprite |
| type | label | HR::BaseLabel |  |
| type | button | HR::Button | TouchableSpriteよりもボタンらしさをもったSprite |
| type | switchable_button | HR::SwitchableButton | 切り替えボタン |
| type | togglable_button | HR::TogglableButton | トグルボタン |

## Child Node Parameters

### Layer's Parameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
|  |  |  |  |  |

### Sprite's Parameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| filepath | std::string | o |  | 画像ファイルパス |

### TouchableSprite's Parameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| enabled_filepath | std::string | o |  | タッチ有効時の画像ファイルパス |
| disabled_filepath | std::string | x | enabled_filepath | タッチ無効時の画像ファイルパス |
| is_enable | bool | x | true | 有効か |
| long_tap | bool | x | true | ロングタップが有効か |
| continuous_tap | bool | x | false | 連続タップが有効か |

### Label's Parameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| text | std::string | o |  | テキスト |
| font_path | std::string | x | fonts/Marker Felt.ttf | フォントファイルパス |
| font_size | float | x | 24.0f | テキストのサイズ |
| font_color_r | unsigned int | x | 0 | テキストの色R値(0~255) |
| font_color_g | unsigned int | x | 0 | テキストの色G値(0~255) |
| font_color_b | unsigned int | x | 0 | テキストの色B値(0~255) |
| text_alignment | enum(left, center, right) | x | left | テキスト位置 |

### Button's Patameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| enabled_filepath | std::string | o |  | タッチ有効時の画像ファイルパス |
| disabled_filepath | std::string | x | enabled_filepath | タッチ無効時の画像ファイルパス |
| is_enable | bool | x | true | 有効か |
| long_tap | bool | x | true | ロングタップが有効か |
| continuous_tap | bool | x | false | 連続タップが有効か |
| scale_effect | bool | x | true | タッチ時に小さくするか |
| brightness_effect | bool | x | true | タッチ時に暗くするか |

### SwitchableButton's Parameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| patterns | JSON Array | o |  | 切り替えパターン郡<br />次のパターンの配列 |
| patterns.key | std::string | o |  | パターンのキー |
| patterns.filepath | std::string | o |  | パターンの画像ファイルパス |
| is_enable | bool | x | true | 有効か |
| scale_effect | bool | x | true | タッチ時に小さくするか |
| brightness_effect | bool | x | true | タッチ時に暗くするか |

### TogglableButton's Parameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| on_filepath | std::string | o |  | オンの時の画像ファイルパス |
| off_filepath | std::string | x | on_filepath | オフの時の画像ファイルパス |
| initial_state | bool | x | true | 初期状態 true/false = on/off |
| is_enable | bool | x | true | 有効か |
| scale_effect | bool | x | true | タッチ時に小さくするか |
| brightness_effect | bool | x | true | タッチ時に暗くするか |
| gray_scale | bool | x | true | オフの時グレースケールするか |

# How to set callbacks

UIGeneratorで生成したボタンとかにコールバックを設定するには、タグを振っておいて、 ```getChildByTag()``` メソッド使って取り出せば良い。

```JSON
{
    "width"      : 1136,
    "height"     : 640,
    "position_x" : 0.0,
    "position_y" : 0.0,
    "anchor_x"   : 0.0,
    "anchor_y"   : 0.0,
    "children"   : [
        {
            "type"             : "button",
            "enabled_filepath" : "HelloWorld.png",
            "position_x"       : 568.0,
            "position_y"       : 320.0,
            "anchor_x"         : 0.5,
            "anchor_y"         : 0.5,
            "tag"              : 8410
        }
    ]
}
```

```C++
HR::BaseLayer *mainLayer = HR::UIGenerator::generateUI("sample.json");

HR::Button *button = dynamic_cast<HR::Button*>(mainLayer->getChildByTag(8410));
button->setTapCallback([]() {
    HRLOG("タグ 8410 のボタンが押された。");
});
```
