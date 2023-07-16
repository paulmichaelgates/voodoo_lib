#include <glad/glad.h>      // must be included before GLFW/glfw3.h
#include <GLFW/glfw3.h>
#include "string.h"

#include "cfg_opengl.h"
#include "generic_types.h"
#include "utl_assert.h"
#include "voodoo.h"
#include "vdo_error.h"
#include "gpu.h"

/* Variables */
static gpu_window_h * s_windows[ VDO_MAX_WINDOWS ];
static uint32         s_registered_windows;

/* Procedures */
static vdo_error_t make_context_current(vdo_win_id_t16 win_id);

/*
 * gpu_init
 * Description: init the underlying graphics card interface - OpenGl 
 */
vdo_error_t gpu_init()
{
/*
 * Local variables
 */
int major, minor, revision;

/*
 * Validate libraries match expected project configuration (see cfg_opengl.h for
 * current opengl configurations)
 */
glfwGetVersion(&major, &minor, &revision);
utl_assert((major = OPENGL_VERSION_MAJOR) && (minor = OPENGL_VERSION_MINOR), 
            "Supported OpenGL version is 3.3, prefered revision is 8");

if( !glfwInit() )
    {
    utl_assert
        (FALSE,
        "Failed to initialize GLFW. This probably means the library was not found. Ensure that "
        "the .dylib library is built (e.g., libglfw.3.3.dylib) and properly linked.");   
    
    return VDO_ERR_INIT;
    }

/*
 * Use core OpenGL. Legacy is not supported by voodoo lib
 */
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

/* Forward compatibilty hint may be needed for MacOS */
#ifdef __APPLE__
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

/*
 * Initialize the function pointers for OpenGL
 */
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
    return VDO_ERR_INIT;
    }  

s_registered_windows = 0;

return VDO_ERR_NONE;

}

/*
 * gpu_create_win
 * 
 * Description: Creates a window object
 * 
 */
vdo_error_t gpu_create_win(vdo_window_h * win_h, int width, int height, char * const title)
{
/* Local variables */
GLFWwindow   * glfw_window;
vdo_win_id_t16 win_id;

if(!win_h)
    {
    return VDO_ERR_PARM;
    }

if(s_registered_windows >= VDO_MAX_WINDOWS)
    {
    return VDO_ERR_WIN;
    }

glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);    // TODO monitor and share
if(NULL == glfw_window)
    {
    glfwTerminate();
    return VDO_ERR_WIN_INIT;
    }

/*
 * Store the window for later use and return user id
 */
win_id = s_registered_windows;
s_windows[ s_registered_windows ] = (gpu_window_h *)glfw_window;
s_registered_windows++;

/*
 * Set up the return window handle for ths user
 */
win_h->id = win_id;
memset(win_h->key_maps, 0, sizeof(win_h->key_maps));

return VDO_ERR_NONE;
}

/*
 * make_context_current
 */
static vdo_error_t make_context_current(vdo_win_id_t16 win_id)
{
/* Input validation */
if( ( win_id >= VDO_MAX_WINDOWS )
||  ( win_id >= s_registered_windows ) )
    {
    return VDO_ERR_WIN;
    }

glfwMakeContextCurrent((GLFWwindow *)s_windows[win_id]);
if((gpu_window_h *)glfwGetCurrentContext() != s_windows[ win_id ])
    {
    return VDO_ERR_WIN;
    }

return VDO_ERR_NONE;

}