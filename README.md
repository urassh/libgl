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

```c
#include "libgl.h"

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 線を描く
    t_line line = gl_create_line(gl_vec3(-0.5, 0, 0), gl_vec3(0.5, 0, 0));
    gl_color_line(&line, gl_red());
    gl_draw_line(&line);

    // 矩形を描く
    t_rect rect = gl_create_rect(gl_vec3(-0.3, -0.3, 0), gl_vec3(0.6, 0.6, 0));
    gl_color_rect(&rect, gl_color(0.2, 0.6, 1.0));
    gl_outline_rect(&rect, gl_white());
    gl_draw_rect(&rect);

    // 立方体を描く
    t_cube cube = gl_create_cube(gl_vec3(-0.2, -0.2, -0.2), gl_vec3(0.4, 0.4, 0.4));
    gl_color_cube(&cube, gl_green());
    gl_rotate(&cube.transform, gl_vec3(30, 45, 0));
    gl_draw_cube(&cube);

    glutSwapBuffers();
}
```

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

### Color

| 関数 | 説明 |
|---|---|
| `gl_color_line(line, color)` | 線の色を設定 |
| `gl_color_rect(rect, color)` | 矩形の色を設定 |
| `gl_color_cube(cube, color)` | 立方体を単色に設定 |
| `gl_colors_cube(cube, colors[6])` | 立方体の各面を個別に着色 |
| `gl_outline_rect(rect, color)` | 矩形の枠線を設定 |
| `gl_outline_cube(cube, color)` | 立方体の枠線を設定 |

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

### Utility

| 関数 | 説明 |
|---|---|
| `gl_vec3(x, y, z)` | `t_vec3` を生成 |
| `gl_color(r, g, b)` | `t_color` を生成 |
| `gl_red()` / `gl_green()` / `gl_blue()` ... | プリセットカラー |

プリセットカラー: `gl_red`, `gl_green`, `gl_blue`, `gl_yellow`, `gl_cyan`, `gl_magenta`, `gl_white`, `gl_black`

マクロ版 (`RED`, `GREEN`, `BLUE` ...) は `gl_color()` の引数として直接展開できる: `gl_color(RED)`
