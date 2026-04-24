# Params — ベクトル・カラー・トランスフォーム

libgl の全オブジェクトが共通で使う基本型。

## Vector

### 型定義

```c
typedef struct s_vec3 {
    float x;
    float y;
    float z;
} t_vec3;

typedef struct s_vec2 {
    float x;
    float y;
} t_vec2;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_vec3 gl_vec3(float x, float y, float z)` | 3D ベクトルを生成 |
| `t_vec2 gl_vec2(float x, float y)` | 2D ベクトルを生成 |

### 使用例

```c
t_vec3 pos = gl_vec3(1.0, 2.0, 3.0);
t_vec2 pos2d = gl_vec2(0.5, 0.5);
```

---

## Color

### 型定義

```c
typedef struct s_color {
    float r;
    float g;
    float b;
} t_color;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_color gl_color(float r, float g, float b)` | 任意の RGB カラーを生成 (各 0.0〜1.0) |
| `t_color gl_red(void)` | プリセット: 赤 |
| `t_color gl_green(void)` | プリセット: 緑 |
| `t_color gl_blue(void)` | プリセット: 青 |
| `t_color gl_yellow(void)` | プリセット: 黄 |
| `t_color gl_cyan(void)` | プリセット: シアン |
| `t_color gl_magenta(void)` | プリセット: マゼンタ |
| `t_color gl_white(void)` | プリセット: 白 |
| `t_color gl_black(void)` | プリセット: 黒 |

### マクロ版プリセット

`gl_color()` の引数として直接展開できるマクロも用意されている:

```c
// マクロ版は gl_color() の引数として使う
t_color c = gl_color(RED);     // gl_color(1.0f, 0.0f, 0.0f) と同じ
t_color c = gl_color(CYAN);    // gl_color(0.0f, 1.0f, 1.0f) と同じ
```

利用可能なマクロ: `RED`, `GREEN`, `BLUE`, `YELLOW`, `CYAN`, `MAGENTA`, `WHITE`, `BLACK`

### 使用例

```c
// 関数版 — 戻り値を変数に入れてから渡す
t_color sky = gl_blue();
gl_color_cube(&cube, sky);

// マクロ版 — gl_color() と組み合わせて任意の色も簡潔に書ける
gl_color_rect(&rect, gl_color(0.2, 0.6, 1.0));
```

---

## Transform

3D オブジェクトは `t_transform`、2D オブジェクトは `t_2d_transform` を持つ。各オブジェクトの `.transform` フィールドに対して操作する。

### 型定義

```c
typedef struct s_transform {
    t_vec3 rotation;  // 各軸の回転角度 (度)
    t_vec3 offset;    // 平行移動量
    t_vec3 scale;     // 拡大縮小率 (初期値 {1,1,1})
} t_transform;

typedef struct s_2d_transform {
    float  rotation;  // 回転角度 (度)
    t_vec2 offset;    // 平行移動量
    t_vec2 scale;     // 拡大縮小率 (初期値 {1,1})
} t_2d_transform;
```

### 3D Transform 関数

| シグネチャ | 説明 |
|---|---|
| `void gl_rotate(t_transform *tf, t_vec3 angle)` | 回転を設定 (x, y, z 度) |
| `void gl_translate(t_transform *tf, t_vec3 offset)` | 平行移動を設定 |
| `void gl_scale(t_transform *tf, t_vec3 scale)` | 拡大縮小率を設定 |

### 2D Transform 関数

| シグネチャ | 説明 |
|---|---|
| `void gl_2d_rotate(t_2d_transform *tf, float angle)` | 回転を設定 (度) |
| `void gl_2d_translate(t_2d_transform *tf, t_vec2 offset)` | 平行移動を設定 |
| `void gl_2d_scale(t_2d_transform *tf, t_vec2 scale)` | 拡大縮小率を設定 |

### 使用例

```c
t_cube cube = gl_new_cube(gl_vec3(0, 0, 0), gl_vec3(1, 1, 1));
gl_rotate(&cube.transform, gl_vec3(30, 45, 0));    // X軸30度, Y軸45度
gl_translate(&cube.transform, gl_vec3(2, 0, 0));    // X方向に2移動
gl_scale(&cube.transform, gl_vec3(1.5, 1.5, 1.5));  // 1.5倍に拡大

t_2d_rect rect = gl_new_2d_rect(gl_vec2(0, 0), gl_vec2(1, 1));
gl_2d_rotate(&rect.transform, 45.0);                // 45度回転
gl_2d_translate(&rect.transform, gl_vec2(100, 50));  // 移動
```

---

## Object Type

全オブジェクトの先頭フィールドに `t_object_type type` がある。`void *` からオブジェクトの種類を判定するのに使える。

```c
typedef enum e_object_type {
    GL_TYPE_LINE,
    GL_TYPE_RECT,
    GL_TYPE_CUBE,
    GL_TYPE_CONE,
    GL_TYPE_CYLINDER,
    GL_TYPE_WIRE_RECT,
    GL_TYPE_WIRE_CUBE,
    GL_TYPE_WIRE_CONE,
    GL_TYPE_WIRE_CYLINDER,
    GL_TYPE_GROUP,
    GL_TYPE_2D_LINE,
    GL_TYPE_2D_RECT,
    GL_TYPE_2D_WIRE_RECT
} t_object_type;
```

---

## Label

全オブジェクトは `char label[GL_LABEL_MAX]` (最大 32 文字) を持つ。ラベルは `gl_group_find()` によるオブジェクト検索に使える。

```c
#define GL_LABEL_MAX 32
```
