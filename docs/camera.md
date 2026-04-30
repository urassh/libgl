# Camera — 視点と投影

シーンを「どこから・どんなレンズで」見るかを表現するコンポーネント。`gl_apply_*` を呼ぶと OpenGL の `Projection` / `ModelView` 行列が設定される。透視投影と平行投影で型が分かれている。

## 透視投影 (Perspective)

遠近感のある通常の 3D 描画用。`fovy` (垂直画角) でレンズの広さを指定する。

### 型定義

```c
typedef struct s_perspective_camera {
    t_object_type type;       // GL_TYPE_PERSPECTIVE_CAMERA
    char          label[32];
    t_vec3        eye;        // カメラ位置
    t_vec3        target;     // 注視点
    t_vec3        up;         // 上方向 (default: (0,1,0))
    float         fovy;       // 垂直画角 [deg] (default: 45)
    float         aspect;     // 横/縦 (default: 1.0)
    float         near_clip;  // ニアクリップ (default: 0.1)
    float         far_clip;   // ファークリップ (default: 100)
} t_perspective_camera;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_perspective_camera gl_new_perspective_camera(t_vec3 eye, t_vec3 target)` | 既定値で作成 |
| `t_perspective_camera gl_new_perspective_camera_with_label(t_vec3 eye, t_vec3 target, const char *label)` | ラベル付きで作成 |
| `t_perspective_camera *gl_alloc_perspective_camera(t_vec3 eye, t_vec3 target)` | ヒープに確保 |
| `t_perspective_camera *gl_alloc_perspective_camera_with_label(t_vec3 eye, t_vec3 target, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_perspective_camera(t_perspective_camera *cam)` | 解放 |
| `bool gl_label_perspective_camera(t_perspective_camera *cam, const char *label)` | ラベルを設定 |
| `void gl_perspective_camera_look_at(t_perspective_camera *cam, t_vec3 eye, t_vec3 target, t_vec3 up)` | 視点・注視点・上方向をまとめて更新 |
| `void gl_perspective_camera_lens(t_perspective_camera *cam, float fovy, float aspect, float near_clip, float far_clip)` | レンズ設定をまとめて更新 |
| `void gl_apply_perspective_camera(t_perspective_camera *cam)` | Projection / ModelView 行列を適用 |

## 平行投影 (Ortho)

遠近感のない描画用。CAD・2.5D ゲーム・UI 風表示などに。`ortho_size` は表示領域の **半高さ** で、横幅は `ortho_size * aspect` から決まる。

### 型定義

```c
typedef struct s_ortho_camera {
    t_object_type type;       // GL_TYPE_ORTHO_CAMERA
    char          label[32];
    t_vec3        eye;
    t_vec3        target;
    t_vec3        up;         // (default: (0,1,0))
    float         ortho_size; // 半高さ (default: 1.0)
    float         aspect;     // 横/縦 (default: 1.0)
    float         near_clip;  // (default: 0.1)
    float         far_clip;   // (default: 100)
} t_ortho_camera;
```

### 関数

| シグネチャ | 説明 |
|---|---|
| `t_ortho_camera gl_new_ortho_camera(t_vec3 eye, t_vec3 target)` | 既定値で作成 |
| `t_ortho_camera gl_new_ortho_camera_with_label(t_vec3 eye, t_vec3 target, const char *label)` | ラベル付きで作成 |
| `t_ortho_camera *gl_alloc_ortho_camera(t_vec3 eye, t_vec3 target)` | ヒープに確保 |
| `t_ortho_camera *gl_alloc_ortho_camera_with_label(t_vec3 eye, t_vec3 target, const char *label)` | ラベル付きでヒープに確保 |
| `void gl_free_ortho_camera(t_ortho_camera *cam)` | 解放 |
| `bool gl_label_ortho_camera(t_ortho_camera *cam, const char *label)` | ラベルを設定 |
| `void gl_ortho_camera_look_at(t_ortho_camera *cam, t_vec3 eye, t_vec3 target, t_vec3 up)` | 視点・注視点・上方向をまとめて更新 |
| `void gl_ortho_camera_lens(t_ortho_camera *cam, float ortho_size, float aspect, float near_clip, float far_clip)` | レンズ設定をまとめて更新 |
| `void gl_apply_ortho_camera(t_ortho_camera *cam)` | Projection / ModelView 行列を適用 |

## 使用例

### 透視投影で立方体を見る

```c
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    t_perspective_camera cam = gl_new_perspective_camera(
        gl_vec3(3, 2, 5), gl_vec3(0, 0, 0));
    gl_perspective_camera_lens(&cam, 45.0f, 16.0f / 9.0f, 0.1f, 100.0f);
    gl_apply_perspective_camera(&cam);

    t_cube cube = gl_new_cube(gl_vec3(0, 0, 0), gl_vec3(1, 1, 1));
    gl_color_cube(&cube, gl_green());
    gl_draw_cube(&cube);

    glutSwapBuffers();
}
```

### 平行投影に切り替え

```c
t_ortho_camera cam = gl_new_ortho_camera(
    gl_vec3(0, 0, 5), gl_vec3(0, 0, 0));
gl_ortho_camera_lens(&cam, 2.0f, 16.0f / 9.0f, 0.1f, 100.0f);
gl_apply_ortho_camera(&cam);
```

### 視点だけ動かす (アニメーション)

```c
static float angle = 0.0f;
angle += 1.0f;

t_vec3 eye = gl_vec3(5.0f * cosf(angle * M_PI / 180.0f), 2.0f,
                     5.0f * sinf(angle * M_PI / 180.0f));
gl_perspective_camera_look_at(&cam, eye, gl_vec3(0, 0, 0), gl_vec3(0, 1, 0));
gl_apply_perspective_camera(&cam);
```

## 注意

- `gl_apply_*` は **`Projection` と `ModelView` の両方を上書き** する。グループ描画前 (display の最初) に呼ぶのが基本。
- `gl_apply_*` は内部で `glLoadIdentity()` を呼んでから設定するため、それ以前のプロジェクション行列は失われる。
- カメラは `t_group` には追加しない (描画ではなく行列セットアップのため)。
