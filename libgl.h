#ifndef LIBGL_H
# define LIBGL_H

# ifdef __APPLE__
#  define GL_SILENCE_DEPRECATION
#  include <GLUT/glut.h>
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
# else
#  include "GL/glut.h"
#  include "GL/gl.h"
#  include "GL/glu.h"
# endif

/* ========== label ========== */

# define GL_LABEL_MAX 32

/* ========== params ========== */

# include "params/object_type/gl_object_type.h"
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

/* ========== solid objects ========== */

# include "solids/line/gl_line.h"
# include "solids/rect/gl_rect.h"
# include "solids/cube/gl_cube.h"
# include "solids/cone/gl_cone.h"
# include "solids/cylinder/gl_cylinder.h"

/* ========== group ========== */

# include "group/gl_group.h"

/* ========== wire objects ========== */

# include "wires/rect/gl_wire_rect.h"
# include "wires/cube/gl_wire_cube.h"
# include "wires/cone/gl_wire_cone.h"
# include "wires/cylinder/gl_wire_cylinder.h"

/* ========== 2d objects ========== */

# include "2d/line/gl_2d_line.h"
# include "2d/rect/gl_2d_rect.h"
# include "2d/wire_rect/gl_2d_wire_rect.h"

#endif
