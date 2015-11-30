# What's UIGenerator?

Cocos2d-xでのUIの組み方は、基本的にはSceneにLayerを貼って、LayerにSpriteやらLabelやらをペタペタ貼っていく感じである。
だったらJSONで一画面分全部定義してしまえば楽じゃない？ってことで作ったのがUIGenerator。

JSONを読み込んでUIを組み立てるもの。

# Parameters Description

cocos2d::Nodeが持っているsetterで指定出来るもののうち、普段使うやつが指定出来るようになってる。
KeyはJSONのキー。ValueTypeはC++で読み取る型。

## Common Parameters

ルートと子ノードで共通のパラメータ。

| Key | ValueType | Description |
|:---|:---|:---|
| width | unsigned int | 幅 |
| height| unsigned int | 高さ |
| position_x | int | x座標 |
| position_y | int | y座標 |
| anchor_x | float | アンカーポイントx (0.0f ~ 1.0f) |
| anchor_y | float | アンカーポイントy (0.0f ~ 1.0f) |
| tag | unsigned int | タグ |
| name | std::string | 名前 |
| scale | float | スケール |
| rotation | float | 回転角 |
| opacity | unsigned int | 透明度(0 ~ 255) |
| visible | bool | 表示/非表示 |

## Root Parameters

ルートはHR::BaseLayer。

| Key | ValueType | Description |
|:---|:---|:---|
|  |  |

## Children Types

子ノードのタイプ一覧。

| Key | Value | Type | Description |
|:---|:---|:---|:---|
| type | layer | HR::BaseLayer |  |
| type | sprite | HR::BaseSprite |  |
| type | touchable_sprite | HR::TouchableSprite | タッチイベントを持ったSprite |
| type | label | HR::BaseLabel |  |
| type | button | HR::Button | TouchableSpriteよりもボタンらしさをもったSprite |
| type | switchable_button | 切り替えボタン |
| type | togglable_button | トグルボタン |

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
| font_size | unsigned int | x | cocosのデフォルト値 | テキストのサイズ |
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
| long_tap | bool | x | true | ロングタップが有効か |
| continuous_tap | bool | x | false | 連続タップが有効か |
| scale_effect | bool | x | true | タッチ時に小さくするか |
| brightness_effect | bool | x | true | タッチ時に暗くするか |

### TogglableButton's Parameters

| Key | ValueType | Required | Default | Description |
|:---|:---|:---:|:---|:---|
| on_filepath | std::string | o |  | オンの時の画像ファイルパス |
| off_filepath | std::string | o |  | オフの時の画像ファイルパス |
| initial_status | bool | x | true | 初期状態 true/false = on/off |
| is_enable | bool | x | true | 有効か |
| scale_effect | bool | x | true | タッチ時に小さくするか |
| brightness_effect | bool | x | true | タッチ時に暗くするか |
| gray_scale | bool | x | true | オフの時グレースケールするか |
