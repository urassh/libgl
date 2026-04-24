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
