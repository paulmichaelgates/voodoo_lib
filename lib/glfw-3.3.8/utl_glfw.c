#include <GLFW/glfw3.h>

/*
 * utl_glfw_fb_sz_maintain_vp
 *
 * Frame Buffer Size Maintain Viewport Callback. Maintains the Viewport when
 * the window is resized. Intended for use in set framebuffer size callback.
 * 
 * Ex.
 * glfwSetFramebufferSizeCallback(window, utl_glfw_fb_sz_maintain_vp);  
 * 
 */
void utl_glfw_fb_sz_maintain_vp(GLFWwindow* window, int width, int height)
{
glViewport(0, 0, width, height);
} /* utl_glfw_fb_sz_maintain_vp() */