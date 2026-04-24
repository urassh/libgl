# libgl

OpenGL/GLUT をラップした軽量な描画ライブラリ。3D/2D オブジェクトの作成・着色・変形・グループ化・描画を簡潔に書ける。

## Build

```sh
make        # libgl.a を生成
make clean  # .o を削除
make fclean # libgl.a も削除
```

## Quick Start

`#include "libgl.h"` するだけで全機能が使える (OpenGL/GLUT ヘッダも読み込まれる)。

```c
#include "libgl.h"

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 立方体を作って描画
    t_cube cube = gl_new_cube(gl_vec3(0, 0, 0), gl_vec3(1, 1, 1));
    gl_color_cube(&cube, gl_green());
    gl_rotate(&cube.transform, gl_vec3(30, 45, 0));
    gl_draw_cube(&cube);

    // ワイヤーフレームの円錐
    t_wire_cone cone = gl_new_wire_cone(gl_vec3(2, 0, 0), 0.5, 1.0);
    gl_color_wire_cone(&cone, gl_yellow());
    gl_draw_wire_cone(&cone);

    glutSwapBuffers();
}
```

<details>
<summary>libgl なしで同じ描画を書いた場合</summary>

```c
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 立方体を描画
    glPushMatrix();
    glRotatef(30, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // front
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 1.0f);
    // back
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    // top
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 1.0f);
    // bottom
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    // right
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    // left
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // ワイヤーフレームの円錐を描画
    int slices = 12;
    float radius = 0.5f;
    float height = 1.0f;
    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    // 底面の円
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < slices; i++)
    {
        float angle = 2.0f * M_PI * i / slices;
        glVertex3f(radius * cosf(angle), 0.0f,
                   radius * sinf(angle));
    }
    glEnd();
    // 頂点への母線
    glBegin(GL_LINES);
    for (int i = 0; i < slices; i++)
    {
        float angle = 2.0f * M_PI * i / slices;
        glVertex3f(radius * cosf(angle), 0.0f,
                   radius * sinf(angle));
        glVertex3f(0.0f, height, 0.0f);
    }
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}
```

</details>

コンパイル:

```sh
cc main.c -L./libgl -lgl -framework OpenGL -framework GLUT -o app
```

## API ドキュメント

| ドキュメント | 内容 |
|---|---|
| [Params](docs/params.md) | ベクトル (`t_vec3`/`t_vec2`)、カラー (`t_color`)、トランスフォーム、Object Type、Label |
| [Solid Objects](docs/solids.md) | 塗りつぶし 3D オブジェクト — Line, Rect, Cube, Cone, Cylinder |
| [Wire Objects](docs/wires.md) | ワイヤーフレーム 3D オブジェクト — Wire Rect/Cube/Cone/Cylinder |
| [2D Objects](docs/2d.md) | 2D オブジェクト — 2D Line, 2D Rect, 2D Wire Rect |
| [Group](docs/group.md) | オブジェクトグループ — 階層変換、ラベル検索、ネスト |

## 設計の概要

- **命名規則:** `gl_new_<type>()` でスタック上に生成、`gl_alloc_<type>()` でヒープに確保、`gl_draw_<type>()` で描画
- **ラベル:** 全オブジェクトに `label` フィールドがあり、`gl_group_find()` で名前検索できる
- **トランスフォーム:** 各オブジェクトの `.transform` フィールドに対して `gl_rotate()` / `gl_translate()` / `gl_scale()` を適用
- **グループ:** `t_group` で複数オブジェクトをまとめて変換・描画。ネスト可能

## Directory Structure

```
libgl/
├── libgl.h              # 集約ヘッダ (これだけ include すれば OK)
├── docs/                # API ドキュメント
├── params/
│   ├── object_type/     # t_object_type enum
│   ├── vector/          # t_vec3, t_vec2
│   ├── color/           # t_color, プリセットカラー
│   └── transform/       # t_transform, t_2d_transform
├── solids/              # 塗りつぶし 3D オブジェクト
│   ├── line/
│   ├── rect/
│   ├── cube/
│   ├── cone/
│   └── cylinder/
├── wires/               # ワイヤーフレーム 3D オブジェクト
│   ├── rect/
│   ├── cube/
│   ├── cone/
│   └── cylinder/
├── 2d/                  # 2D オブジェクト
│   ├── line/
│   ├── rect/
│   └── wire_rect/
└── group/               # オブジェクトグループ
```

## Contributing

Pull Request 歓迎です! バグ修正、新しいオブジェクト、API の改善など気軽にどうぞ。

1. Fork して自分のブランチで作業
2. `make re` でビルドが通ることを確認
3. Pull Request を送る

## License

[MIT](LICENSE)
