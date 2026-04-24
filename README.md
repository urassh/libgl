# libgl

OpenGL/GLUT をラップした軽量な描画ライブラリ。ソリッド・ワイヤーフレームの各種 3D オブジェクトの作成・着色・変形・描画を簡潔に書ける。

## Build

```sh
make        # libgl.a を生成
make clean  # .o を削除
make fclean # libgl.a も削除
```

## Directory Structure

```
libgl/
├── libgl.h                  # 集約ヘッダ (これだけ include すれば OK)
├── params/
│   ├── vector/              # t_vec3, gl_vec3()
│   ├── color/               # t_color, gl_color(), プリセットカラー
│   └── transform/           # t_transform, gl_rotate/translate/scale()
├── solids/                  # ソリッド (塗りつぶし) オブジェクト
│   ├── line/
│   ├── rect/
│   ├── cube/
│   ├── cone/
│   └── cylinder/
├── wires/                   # ワイヤーフレームオブジェクト
│   ├── rect/
│   ├── cube/
│   ├── cone/
│   └── cylinder/
└── group/                   # オブジェクトグループ (階層変換)
```

各ディレクトリに専用ヘッダがあり、必要なものだけ個別に include することもできる。

## Usage

`#include "libgl.h"` するだけで OpenGL/GLUT ヘッダも読み込まれる。

<details>
<summary>Before / After を比較する</summary>

<table>
<tr>
<th>Before (raw OpenGL)</th>
<th>After (libgl)</th>
</tr>
<tr>
<td>

```c
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT
            | GL_DEPTH_BUFFER_BIT);

    // 矩形を描く
    glColor3f(0.2f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, -0.3f, 0.0f);
    glVertex3f( 0.3f, -0.3f, 0.0f);
    glVertex3f( 0.3f,  0.3f, 0.0f);
    glVertex3f(-0.3f,  0.3f, 0.0f);
    glEnd();

    // 立方体を描く
    glPushMatrix();
    glRotatef(30, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // front
    glVertex3f(-0.2f, -0.2f,  0.2f);
    glVertex3f( 0.2f, -0.2f,  0.2f);
    glVertex3f( 0.2f,  0.2f,  0.2f);
    glVertex3f(-0.2f,  0.2f,  0.2f);
    // back
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f( 0.2f, -0.2f, -0.2f);
    glVertex3f( 0.2f,  0.2f, -0.2f);
    glVertex3f(-0.2f,  0.2f, -0.2f);
    // top
    glVertex3f(-0.2f,  0.2f, -0.2f);
    glVertex3f( 0.2f,  0.2f, -0.2f);
    glVertex3f( 0.2f,  0.2f,  0.2f);
    glVertex3f(-0.2f,  0.2f,  0.2f);
    // bottom
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f( 0.2f, -0.2f, -0.2f);
    glVertex3f( 0.2f, -0.2f,  0.2f);
    glVertex3f(-0.2f, -0.2f,  0.2f);
    // right
    glVertex3f( 0.2f, -0.2f, -0.2f);
    glVertex3f( 0.2f, -0.2f,  0.2f);
    glVertex3f( 0.2f,  0.2f,  0.2f);
    glVertex3f( 0.2f,  0.2f, -0.2f);
    // left
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f,  0.2f);
    glVertex3f(-0.2f,  0.2f,  0.2f);
    glVertex3f(-0.2f,  0.2f, -0.2f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}
```

</td>
<td>

```c
#include "libgl.h"

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT
            | GL_DEPTH_BUFFER_BIT);

    // 矩形を描く
    t_rect rect = gl_create_rect(
        gl_vec3(-0.3, -0.3, 0),
        gl_vec3(0.6, 0.6, 0));
    gl_color_rect(&rect,
        gl_color(0.2, 0.6, 1.0));
    gl_draw_rect(&rect);

    // 立方体を描く
    t_cube cube = gl_create_cube(
        gl_vec3(-0.2, -0.2, -0.2),
        gl_vec3(0.4, 0.4, 0.4));
    gl_color_cube(&cube, gl_green());
    gl_rotate(&cube.transform,
        gl_vec3(30, 45, 0));
    gl_draw_cube(&cube);

    glutSwapBuffers();
}
```

</td>
</tr>
</table>

</details>

コンパイル:

```sh
cc main.c -L./libgl -lgl -framework OpenGL -framework GLUT -o app
```

## API

### Solid Objects (`solids/`)

#### Create

| 関数 | 説明 |
|---|---|
| `gl_create_line(start, end)` | 線を作成 |
| `gl_create_rect(origin, size)` | 矩形を作成 |
| `gl_create_cube(origin, size)` | 立方体を作成 |
| `gl_create_cone(origin, radius, height, slices)` | 円錐を作成 |
| `gl_create_cylinder(origin, radius, height, slices)` | 円柱を作成 |

#### Color / Outline

| 関数 | 説明 |
|---|---|
| `gl_color_line(line, color)` | 線の色を設定 |
| `gl_color_rect(rect, color)` | 矩形の色を設定 |
| `gl_color_cube(cube, color)` | 立方体を単色に設定 |
| `gl_colors_cube(cube, colors[6])` | 立方体の各面を個別に着色 |
| `gl_outline_rect(rect, color)` | 矩形の枠線を設定 |
| `gl_outline_cube(cube, color)` | 立方体の枠線を設定 |
| `gl_color_cone(cone, color)` | 円錐の色を設定 |
| `gl_outline_cone(cone, color)` | 円錐の枠線を設定 |
| `gl_color_cylinder(cyl, color)` | 円柱の色を設定 |
| `gl_outline_cylinder(cyl, color)` | 円柱の枠線を設定 |

#### Draw

| 関数 | 説明 |
|---|---|
| `gl_draw_line(line)` | 線を描画 |
| `gl_draw_rect(rect)` | 矩形を描画 |
| `gl_draw_cube(cube)` | 立方体を描画 |
| `gl_draw_cone(cone)` | 円錐を描画 |
| `gl_draw_cylinder(cyl)` | 円柱を描画 |

### Wire Objects (`wires/`)

独自の型 (`t_wire_rect`, `t_wire_cube`, `t_wire_cone`, `t_wire_cylinder`) を持つ。

#### Create

| 関数 | 説明 |
|---|---|
| `gl_create_wire_rect(origin, size)` | ワイヤー矩形を作成 |
| `gl_create_wire_cube(origin, size)` | ワイヤー立方体を作成 |
| `gl_create_wire_cone(origin, radius, height)` | ワイヤー円錐を作成 (slices=12, stacks=3) |
| `gl_create_wire_cylinder(origin, radius, height)` | ワイヤー円柱を作成 (slices=12) |

#### Color / Params

| 関数 | 説明 |
|---|---|
| `gl_color_wire_rect(rect, color)` | 色を設定 |
| `gl_color_wire_cube(cube, color)` | 色を設定 |
| `gl_color_wire_cone(cone, color)` | 色を設定 |
| `gl_slices_wire_cone(cone, slices)` | 分割数を変更 |
| `gl_stacks_wire_cone(cone, stacks)` | 段数を変更 |
| `gl_color_wire_cylinder(cyl, color)` | 色を設定 |
| `gl_slices_wire_cylinder(cyl, slices)` | 分割数を変更 |

#### Draw

| 関数 | 説明 |
|---|---|
| `gl_draw_wire_rect(rect)` | ワイヤー矩形を描画 |
| `gl_draw_wire_cube(cube)` | ワイヤー立方体を描画 |
| `gl_draw_wire_cone(cone)` | ワイヤー円錐を描画 |
| `gl_draw_wire_cylinder(cyl)` | ワイヤー円柱を描画 |

### Group (`group/`)

複数のオブジェクトをグループ化し、まとめて変換・描画する。グループの origin や transform を変更すると、子オブジェクトの座標も連動する。OpenGL の行列スタックを利用しているため、グループのネスト (グループの中にグループ) も可能。

#### 型

| 型 | 説明 |
|---|---|
| `t_group_child` | 子要素 (`void *object` + 描画関数ポインタ) |
| `t_group` | グループ本体 (`origin`, `transform`, 子要素配列, `count`) |

#### API

| 関数 | 説明 |
|---|---|
| `gl_create_group(origin)` | グループを作成 |
| `gl_group_add(group, object, draw_fn)` | 子オブジェクトを追加 (最大 32 個) |
| `gl_draw_group(group)` | グループ全体を描画 |

#### 使用例

```c
t_wire_cube  cube = gl_create_wire_cube(gl_vec3(0, 0, 0), gl_vec3(1, 1, 1));
t_wire_cone  cone = gl_create_wire_cone(gl_vec3(0, 2, 0), 0.5, 1.0);

t_group group = gl_create_group(gl_vec3(0, 0, 0));
gl_group_add(&group, &cube, (void (*)(void *))gl_draw_wire_cube);
gl_group_add(&group, &cone, (void (*)(void *))gl_draw_wire_cone);

// グループごと移動 → cube と cone が一緒に動く
gl_translate(&group.transform, gl_vec3(3, 0, 0));
gl_draw_group(&group);
```

> **注意:** `t_group` は子オブジェクトへのポインタを保持するだけで、所有はしない。子オブジェクトはグループより長く生存させる必要がある。

### Params (`params/`)

#### Vector

| 関数 | 説明 |
|---|---|
| `gl_vec3(x, y, z)` | `t_vec3` を生成 |

#### Color

| 関数 | 説明 |
|---|---|
| `gl_color(r, g, b)` | `t_color` を生成 |
| `gl_red()` ... `gl_black()` | プリセットカラー |

プリセットカラー: `gl_red`, `gl_green`, `gl_blue`, `gl_yellow`, `gl_cyan`, `gl_magenta`, `gl_white`, `gl_black`

マクロ版 (`RED`, `GREEN`, `BLUE` ...) は `gl_color()` の引数として直接展開できる: `gl_color(RED)`

#### Transform

| 関数 | 説明 |
|---|---|
| `gl_rotate(tf, angle)` | 回転 (x, y, z 度) |
| `gl_translate(tf, offset)` | 平行移動 |
| `gl_scale(tf, scale)` | 拡大縮小 |

## Contributing

Pull Request 歓迎です! バグ修正、新しいオブジェクト、API の改善など気軽にどうぞ。

1. Fork して自分のブランチで作業
2. `make re` でビルドが通ることを確認
3. Pull Request を送る

## License

[MIT](LICENSE)
