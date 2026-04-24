# Group — オブジェクトグループ

複数のオブジェクトをグループ化し、まとめて変換・描画する。グループの `origin` や `transform` を変更すると、子オブジェクトの座標も連動する。OpenGL の行列スタックを利用しているため、グループのネスト (グループの中にグループ) も可能。

## 型定義

```c
#define GROUP_MAX_CHILDREN 64

typedef struct s_group_child {
    void *object;
    void (*draw)(void *object);   // 描画関数ポインタ
} t_group_child;

typedef struct s_group {
    t_object_type type;           // GL_TYPE_GROUP
    char          label[32];
    t_vec3        origin;
    t_transform   transform;
    t_group_child children[GROUP_MAX_CHILDREN];
    int           count;          // 現在の子要素数
} t_group;
```

## 関数

| シグネチャ | 説明 |
|---|---|
| `t_group gl_new_group(t_vec3 origin)` | グループを作成 |
| `t_group gl_new_group_with_label(t_vec3 origin, const char *label)` | ラベル付きで作成 |
| `t_group *gl_alloc_group(t_vec3 origin)` | ヒープに確保 |
| `t_group *gl_alloc_group_with_label(t_vec3 origin, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_group(t_group *group)` | 解放 |
| `bool gl_label_group(t_group *group, const char *label)` | ラベルを設定 |
| `void gl_group_add(t_group *group, void *object, void (*draw)(void *))` | 子オブジェクトを追加 (最大 64 個) |
| `void *gl_group_find(t_group *group, const char *label)` | ラベルでオブジェクトを検索 (BFS) |
| `void gl_draw_group(t_group *group)` | グループ全体を描画 |

## 使用例

### 基本的な使い方

```c
// オブジェクトを作成 (グループに追加するのでヒープに確保)
t_wire_cube *cube = gl_alloc_wire_cube(gl_vec3(0, 0, 0), gl_vec3(1, 1, 1));
t_wire_cone *cone = gl_alloc_wire_cone(gl_vec3(0, 2, 0), 0.5, 1.0);

gl_color_wire_cube(cube, gl_white());
gl_color_wire_cone(cone, gl_yellow());

// グループにまとめる
t_group group = gl_new_group(gl_vec3(0, 0, 0));
gl_group_add(&group, cube, (void (*)(void *))gl_draw_wire_cube);
gl_group_add(&group, cone, (void (*)(void *))gl_draw_wire_cone);

// グループごと移動・回転 → 子オブジェクト全体が連動する
gl_translate(&group.transform, gl_vec3(3, 0, 0));
gl_rotate(&group.transform, gl_vec3(0, 45, 0));
gl_draw_group(&group);

// 後片付け
gl_free_wire_cube(cube);
gl_free_wire_cone(cone);
```

### ラベルによるオブジェクト検索

```c
t_wire_cube *cube = gl_alloc_wire_cube_with_label(
    gl_vec3(0, 0, 0), gl_vec3(1, 1, 1), "body");
t_wire_cone *cone = gl_alloc_wire_cone_with_label(
    gl_vec3(0, 2, 0), 0.5, 1.0, "hat");

t_group group = gl_new_group(gl_vec3(0, 0, 0));
gl_group_add(&group, cube, (void (*)(void *))gl_draw_wire_cube);
gl_group_add(&group, cone, (void (*)(void *))gl_draw_wire_cone);

// ラベルで検索 (BFS でネストされたグループ内も探索)
t_wire_cone *found = (t_wire_cone *)gl_group_find(&group, "hat");
if (found)
    gl_color_wire_cone(found, gl_red());
```

### グループのネスト

```c
t_group arm = gl_new_group(gl_vec3(1, 0, 0));
gl_group_add(&arm, upper_arm, (void (*)(void *))gl_draw_cube);
gl_group_add(&arm, lower_arm, (void (*)(void *))gl_draw_cube);

t_group body = gl_new_group(gl_vec3(0, 0, 0));
gl_group_add(&body, torso, (void (*)(void *))gl_draw_cube);
gl_group_add(&body, &arm, (void (*)(void *))gl_draw_group);

// body を回転すると arm (とその子) も一緒に回転する
gl_rotate(&body.transform, gl_vec3(0, 30, 0));
gl_draw_group(&body);
```

## 所有権に関する注意

- `t_group` は子オブジェクトへの**ポインタを保持するだけで、所有はしない**。
- 子オブジェクトはグループより長く生存させる必要がある。
- `gl_free_group()` はグループ自体のメモリのみ解放し、子オブジェクトは解放しない。
- グループにスタック上のオブジェクト (`gl_new_*`) を追加する場合、そのオブジェクトが関数スコープを抜ける前にグループの描画を完了させること。長期間保持するなら `gl_alloc_*` を使う。
