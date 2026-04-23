# libgl

OpenGL/GLUT をラップした軽量な描画ライブラリ。線・矩形・立方体の作成・着色・変形・描画を簡潔に書ける。

## Build

```sh
make        # libgl.a を生成
make clean  # .o を削除
make fclean # libgl.a も削除
```

## Usage

`#include "libgl.h"` するだけで OpenGL/GLUT ヘッダも読み込まれる。

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
    glVertex3f(0.3f, -0.3f, 0.0f);
    glVertex3f(0.3f, 0.3f, 0.0f);
    glVertex3f(-0.3f, 0.3f, 0.0f);
    glEnd();

    // 立方体を描く (24頂点を手書き...)
    glPushMatrix();
    glRotatef(30, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // front face
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    // ... 残り5面も同様に記述
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

コンパイル:

```sh
cc main.c -L./libgl -lgl -framework OpenGL -framework GLUT -o app
```

## API

### Create

| 関数 | 説明 |
|---|---|
| `gl_create_line(start, end)` | 線を作成 |
| `gl_create_rect(origin, size)` | 矩形を作成 |
| `gl_create_cube(origin, size)` | 立方体を作成 |
| `gl_create_cone(origin, radius, height, slices)` | 円錐を作成 |
| `gl_create_cylinder(origin, radius, height, slices)` | 円柱を作成 |

### Color

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

### Transform

| 関数 | 説明 |
|---|---|
| `gl_rotate(tf, angle)` | 回転 (x, y, z 度) |
| `gl_translate(tf, offset)` | 平行移動 |
| `gl_scale(tf, scale)` | 拡大縮小 |

### Draw

| 関数 | 説明 |
|---|---|
| `gl_draw_line(line)` | 線を描画 |
| `gl_draw_rect(rect)` | 矩形を描画 |
| `gl_draw_cube(cube)` | 立方体を描画 |
| `gl_draw_cone(cone)` | 円錐を描画 |
| `gl_draw_wire_cone(cone, slices, stacks)` | 円錐をワイヤーフレームで描画 |
| `gl_draw_cylinder(cyl)` | 円柱を描画 |
| `gl_draw_wire_cylinder(cyl)` | 円柱をワイヤーフレームで描画 |
| `gl_draw_wire_rect(rect)` | 矩形をワイヤーフレームで描画 |

### Utility

| 関数 | 説明 |
|---|---|
| `gl_vec3(x, y, z)` | `t_vec3` を生成 |
| `gl_color(r, g, b)` | `t_color` を生成 |
| `gl_red()` / `gl_green()` / `gl_blue()` ... | プリセットカラー |

プリセットカラー: `gl_red`, `gl_green`, `gl_blue`, `gl_yellow`, `gl_cyan`, `gl_magenta`, `gl_white`, `gl_black`

マクロ版 (`RED`, `GREEN`, `BLUE` ...) は `gl_color()` の引数として直接展開できる: `gl_color(RED)`

## Contributing

Pull Request 歓迎です! バグ修正、新しいオブジェクト、API の改善など気軽にどうぞ。

1. Fork して自分のブランチで作業
2. `make re` でビルドが通ることを確認
3. Pull Request を送る

## License

[MIT](LICENSE)
