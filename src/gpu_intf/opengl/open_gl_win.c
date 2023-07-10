#include <GLFW/glfw3.h>

#include "cfg_opengl.h"
#include "generic_types.h"
#include "utl_assert.h"
#include "vdo_error.h"

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

return VDO_ERR_NONE;

}
