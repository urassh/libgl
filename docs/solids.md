# Solid Objects — 塗りつぶし 3D オブジェクト

`solids/` 以下のオブジェクト。塗りつぶしで描画される。

## 共通パターン

全ソリッドオブジェクトは以下の共通インターフェースを持つ:

| パターン | 説明 |
|---|---|
| `gl_new_<type>(...)` | スタック上にオブジェクトを生成して返す |
| `gl_new_<type>_with_label(..., label)` | ラベル付きでスタック上に生成 |
| `gl_alloc_<type>(...)` | ヒープに確保して返す (`malloc`) |
| `gl_alloc_<type>_with_label(..., label)` | ラベル付きでヒープに確保 |
| `gl_free_<type>(ptr)` | `gl_alloc_*` で確保したオブジェクトを解放 |
| `gl_label_<type>(ptr, label)` | ラベルを設定 (31文字まで、成功で `true`) |
| `gl_color_<type>(ptr, color)` | 色を設定 |
| `gl_draw_<type>(ptr)` | 描画 |

> **`gl_new_*` vs `gl_alloc_*`:** グループに追加するオブジェクトなど、ポインタで保持する必要がある場合は `gl_alloc_*` を使う。関数スコープ内で完結する場合は `gl_new_*` で十分。

---

## Line

### 型定義

```c
typedef struct s_line {
    t_object_type type;       // GL_TYPE_LINE
    char          label[32];
    t_vec3        start;      // 始点
    t_vec3        end;        // 終点
    t_color       color;
    t_transform   transform;
} t_line;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_line gl_new_line(t_vec3 start, t_vec3 end)` | 線を作成 |
| `t_line gl_new_line_with_label(t_vec3 start, t_vec3 end, const char *label)` | ラベル付きで作成 |
| `t_line *gl_alloc_line(t_vec3 start, t_vec3 end)` | ヒープに確保 |
| `t_line *gl_alloc_line_with_label(t_vec3 start, t_vec3 end, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_line(t_line *line)` | 解放 |
| `bool gl_label_line(t_line *line, const char *label)` | ラベルを設定 |
| `void gl_color_line(t_line *line, t_color color)` | 色を設定 |
| `void gl_draw_line(t_line *line)` | 描画 |

### 使用例

```c
t_line line = gl_new_line(gl_vec3(0, 0, 0), gl_vec3(1, 1, 0));
gl_color_line(&line, gl_red());
gl_draw_line(&line);
```

---

## Rect

### 型定義

```c
typedef struct s_rect {
    t_object_type type;          // GL_TYPE_RECT
    char          label[32];
    t_vec3        origin;        // 左下の座標
    t_vec3        size;          // 幅・高さ・奥行き
    t_color       color;
    bool          has_outline;
    t_color       outline_color;
    t_transform   transform;
} t_rect;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_rect gl_new_rect(t_vec3 origin, t_vec3 size)` | 矩形を作成 |
| `t_rect gl_new_rect_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きで作成 |
| `t_rect *gl_alloc_rect(t_vec3 origin, t_vec3 size)` | ヒープに確保 |
| `t_rect *gl_alloc_rect_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_rect(t_rect *rect)` | 解放 |
| `bool gl_label_rect(t_rect *rect, const char *label)` | ラベルを設定 |
| `void gl_color_rect(t_rect *rect, t_color color)` | 色を設定 |
| `void gl_outline_rect(t_rect *rect, t_color color)` | 枠線を設定 |
| `void gl_draw_rect(t_rect *rect)` | 描画 |

### 使用例

```c
t_rect rect = gl_new_rect(gl_vec3(-0.5, -0.5, 0), gl_vec3(1, 1, 0));
gl_color_rect(&rect, gl_color(0.2, 0.6, 1.0));
gl_outline_rect(&rect, gl_black());
gl_draw_rect(&rect);
```

---

## Cube

### 型定義

```c
typedef struct s_cube {
    t_object_type type;          // GL_TYPE_CUBE
    char          label[32];
    t_vec3        origin;        // 左下手前の座標
    t_vec3        size;          // 幅・高さ・奥行き
    t_color       colors[6];     // 各面の色
    bool          has_outline;
    t_color       outline_color;
    t_transform   transform;
} t_cube;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_cube gl_new_cube(t_vec3 origin, t_vec3 size)` | 立方体を作成 |
| `t_cube gl_new_cube_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きで作成 |
| `t_cube *gl_alloc_cube(t_vec3 origin, t_vec3 size)` | ヒープに確保 |
| `t_cube *gl_alloc_cube_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_cube(t_cube *cube)` | 解放 |
| `bool gl_label_cube(t_cube *cube, const char *label)` | ラベルを設定 |
| `void gl_color_cube(t_cube *cube, t_color color)` | 全面を単色に設定 |
| `void gl_colors_cube(t_cube *cube, t_color colors[6])` | 各面を個別に着色 |
| `void gl_outline_cube(t_cube *cube, t_color color)` | 枠線を設定 |
| `void gl_draw_cube(t_cube *cube)` | 描画 |

### 使用例

```c
// 単色の立方体
t_cube cube = gl_new_cube(gl_vec3(0, 0, 0), gl_vec3(1, 1, 1));
gl_color_cube(&cube, gl_green());
gl_rotate(&cube.transform, gl_vec3(30, 45, 0));
gl_draw_cube(&cube);

// 各面を別の色にする
t_color face_colors[6] = {
    gl_red(), gl_green(), gl_blue(),
    gl_yellow(), gl_cyan(), gl_magenta()
};
gl_colors_cube(&cube, face_colors);
```

---

## Cone

### 型定義

```c
typedef struct s_cone {
    t_object_type type;          // GL_TYPE_CONE
    char          label[32];
    t_vec3        origin;        // 底面中心の座標
    float         radius;        // 底面の半径
    float         height;        // 高さ
    int           slices;        // 底面の分割数 (多いほど滑らか)
    t_color       color;
    bool          has_outline;
    t_color       outline_color;
    t_transform   transform;
} t_cone;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_cone gl_new_cone(t_vec3 origin, float radius, float height, int slices)` | 円錐を作成 |
| `t_cone gl_new_cone_with_label(t_vec3 origin, float radius, float height, int slices, const char *label)` | ラベル付きで作成 |
| `t_cone *gl_alloc_cone(t_vec3 origin, float radius, float height, int slices)` | ヒープに確保 |
| `t_cone *gl_alloc_cone_with_label(t_vec3 origin, float radius, float height, int slices, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_cone(t_cone *cone)` | 解放 |
| `bool gl_label_cone(t_cone *cone, const char *label)` | ラベルを設定 |
| `void gl_color_cone(t_cone *cone, t_color color)` | 色を設定 |
| `void gl_outline_cone(t_cone *cone, t_color color)` | 枠線を設定 |
| `void gl_draw_cone(t_cone *cone)` | 描画 |

### 使用例

```c
t_cone cone = gl_new_cone(gl_vec3(0, 0, 0), 0.5, 1.0, 24);
gl_color_cone(&cone, gl_yellow());
gl_draw_cone(&cone);
```

---

## Cylinder

### 型定義

```c
typedef struct s_cylinder {
    t_object_type type;          // GL_TYPE_CYLINDER
    char          label[32];
    t_vec3        origin;        // 底面中心の座標
    float         radius;        // 半径
    float         height;        // 高さ
    int           slices;        // 分割数
    t_color       color;
    bool          has_outline;
    t_color       outline_color;
    t_transform   transform;
} t_cylinder;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_cylinder gl_new_cylinder(t_vec3 origin, float radius, float height, int slices)` | 円柱を作成 |
| `t_cylinder gl_new_cylinder_with_label(t_vec3 origin, float radius, float height, int slices, const char *label)` | ラベル付きで作成 |
| `t_cylinder *gl_alloc_cylinder(t_vec3 origin, float radius, float height, int slices)` | ヒープに確保 |
| `t_cylinder *gl_alloc_cylinder_with_label(t_vec3 origin, float radius, float height, int slices, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_cylinder(t_cylinder *cyl)` | 解放 |
| `bool gl_label_cylinder(t_cylinder *cyl, const char *label)` | ラベルを設定 |
| `void gl_color_cylinder(t_cylinder *cyl, t_color color)` | 色を設定 |
| `void gl_outline_cylinder(t_cylinder *cyl, t_color color)` | 枠線を設定 |
| `void gl_draw_cylinder(t_cylinder *cyl)` | 描画 |

### 使用例

```c
t_cylinder cyl = gl_new_cylinder(gl_vec3(0, 0, 0), 0.3, 2.0, 24);
gl_color_cylinder(&cyl, gl_cyan());
gl_outline_cylinder(&cyl, gl_black());
gl_draw_cylinder(&cyl);
```
