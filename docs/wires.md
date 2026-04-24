# Wire Objects — ワイヤーフレーム 3D オブジェクト

`wires/` 以下のオブジェクト。輪郭線のみで描画される。

## 共通パターン

ソリッドオブジェクトと同じ命名規則に従う。詳細は [solids.md](solids.md) の「共通パターン」を参照。

> ワイヤーオブジェクトには `outline` 関数はない (そもそも輪郭線のみ)。

---

## Wire Rect

### 型定義

```c
typedef struct s_wire_rect {
    t_object_type type;       // GL_TYPE_WIRE_RECT
    char          label[32];
    t_vec3        origin;
    t_vec3        size;
    t_color       color;
    t_transform   transform;
} t_wire_rect;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_wire_rect gl_new_wire_rect(t_vec3 origin, t_vec3 size)` | ワイヤー矩形を作成 |
| `t_wire_rect gl_new_wire_rect_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きで作成 |
| `t_wire_rect *gl_alloc_wire_rect(t_vec3 origin, t_vec3 size)` | ヒープに確保 |
| `t_wire_rect *gl_alloc_wire_rect_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_wire_rect(t_wire_rect *rect)` | 解放 |
| `bool gl_label_wire_rect(t_wire_rect *rect, const char *label)` | ラベルを設定 |
| `void gl_color_wire_rect(t_wire_rect *rect, t_color color)` | 色を設定 |
| `void gl_draw_wire_rect(t_wire_rect *rect)` | 描画 |

### 使用例

```c
t_wire_rect rect = gl_new_wire_rect(gl_vec3(0, 0, 0), gl_vec3(1, 1, 0));
gl_color_wire_rect(&rect, gl_white());
gl_draw_wire_rect(&rect);
```

---

## Wire Cube

### 型定義

```c
typedef struct s_wire_cube {
    t_object_type type;       // GL_TYPE_WIRE_CUBE
    char          label[32];
    t_vec3        origin;
    t_vec3        size;
    t_color       color;
    t_transform   transform;
} t_wire_cube;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_wire_cube gl_new_wire_cube(t_vec3 origin, t_vec3 size)` | ワイヤー立方体を作成 |
| `t_wire_cube gl_new_wire_cube_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きで作成 |
| `t_wire_cube *gl_alloc_wire_cube(t_vec3 origin, t_vec3 size)` | ヒープに確保 |
| `t_wire_cube *gl_alloc_wire_cube_with_label(t_vec3 origin, t_vec3 size, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_wire_cube(t_wire_cube *cube)` | 解放 |
| `bool gl_label_wire_cube(t_wire_cube *cube, const char *label)` | ラベルを設定 |
| `void gl_color_wire_cube(t_wire_cube *cube, t_color color)` | 色を設定 |
| `void gl_draw_wire_cube(t_wire_cube *cube)` | 描画 |

### 使用例

```c
t_wire_cube cube = gl_new_wire_cube(gl_vec3(-0.5, -0.5, -0.5), gl_vec3(1, 1, 1));
gl_color_wire_cube(&cube, gl_green());
gl_rotate(&cube.transform, gl_vec3(30, 45, 0));
gl_draw_wire_cube(&cube);
```

---

## Wire Cone

### 型定義

```c
typedef struct s_wire_cone {
    t_object_type type;       // GL_TYPE_WIRE_CONE
    char          label[32];
    t_vec3        origin;     // 底面中心の座標
    float         radius;
    float         height;
    int           slices;     // 底面の分割数 (デフォルト 12)
    int           stacks;     // 高さ方向の段数 (デフォルト 3)
    t_color       color;
    t_transform   transform;
} t_wire_cone;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_wire_cone gl_new_wire_cone(t_vec3 origin, float radius, float height)` | ワイヤー円錐を作成 (slices=12, stacks=3) |
| `t_wire_cone gl_new_wire_cone_with_label(t_vec3 origin, float radius, float height, const char *label)` | ラベル付きで作成 |
| `t_wire_cone *gl_alloc_wire_cone(t_vec3 origin, float radius, float height)` | ヒープに確保 |
| `t_wire_cone *gl_alloc_wire_cone_with_label(t_vec3 origin, float radius, float height, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_wire_cone(t_wire_cone *cone)` | 解放 |
| `bool gl_label_wire_cone(t_wire_cone *cone, const char *label)` | ラベルを設定 |
| `void gl_color_wire_cone(t_wire_cone *cone, t_color color)` | 色を設定 |
| `void gl_slices_wire_cone(t_wire_cone *cone, int slices)` | 底面の分割数を変更 |
| `void gl_stacks_wire_cone(t_wire_cone *cone, int stacks)` | 高さ方向の段数を変更 |
| `void gl_draw_wire_cone(t_wire_cone *cone)` | 描画 |

> **注意:** ソリッド版の `gl_new_cone` は `slices` 引数を取るが、ワイヤー版はデフォルト値 (12) が使われる。変更したい場合は生成後に `gl_slices_wire_cone()` を呼ぶ。

### 使用例

```c
t_wire_cone cone = gl_new_wire_cone(gl_vec3(0, 0, 0), 0.5, 1.0);
gl_color_wire_cone(&cone, gl_magenta());
gl_slices_wire_cone(&cone, 24);  // より滑らかに
gl_draw_wire_cone(&cone);
```

---

## Wire Cylinder

### 型定義

```c
typedef struct s_wire_cylinder {
    t_object_type type;       // GL_TYPE_WIRE_CYLINDER
    char          label[32];
    t_vec3        origin;     // 底面中心の座標
    float         radius;
    float         height;
    int           slices;     // 分割数 (デフォルト 12)
    t_color       color;
    t_transform   transform;
} t_wire_cylinder;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_wire_cylinder gl_new_wire_cylinder(t_vec3 origin, float radius, float height)` | ワイヤー円柱を作成 (slices=12) |
| `t_wire_cylinder gl_new_wire_cylinder_with_label(t_vec3 origin, float radius, float height, const char *label)` | ラベル付きで作成 |
| `t_wire_cylinder *gl_alloc_wire_cylinder(t_vec3 origin, float radius, float height)` | ヒープに確保 |
| `t_wire_cylinder *gl_alloc_wire_cylinder_with_label(t_vec3 origin, float radius, float height, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_wire_cylinder(t_wire_cylinder *cyl)` | 解放 |
| `bool gl_label_wire_cylinder(t_wire_cylinder *cyl, const char *label)` | ラベルを設定 |
| `void gl_color_wire_cylinder(t_wire_cylinder *cyl, t_color color)` | 色を設定 |
| `void gl_slices_wire_cylinder(t_wire_cylinder *cyl, int slices)` | 分割数を変更 |
| `void gl_draw_wire_cylinder(t_wire_cylinder *cyl)` | 描画 |

### 使用例

```c
t_wire_cylinder cyl = gl_new_wire_cylinder(gl_vec3(0, 0, 0), 0.3, 2.0);
gl_color_wire_cylinder(&cyl, gl_yellow());
gl_slices_wire_cylinder(&cyl, 32);
gl_draw_wire_cylinder(&cyl);
```
