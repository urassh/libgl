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

/* ========== params ========== */

# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

/* ========== solid objects ========== */

# include "line/gl_line.h"
# include "rect/gl_rect.h"
# include "cube/gl_cube.h"
# include "cone/gl_cone.h"
# include "cylinder/gl_cylinder.h"

/* ========== wire objects ========== */

# include "wires/rect/gl_wire_rect.h"
# include "wires/cube/gl_wire_cube.h"
# include "wires/cone/gl_wire_cone.h"
# include "wires/cylinder/gl_wire_cylinder.h"

#endif
