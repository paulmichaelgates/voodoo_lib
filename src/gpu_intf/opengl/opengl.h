/*
 * opengl.h
 */

#include <GLFW/glfw3.h>

/* Types */
typedef GLFWwindow gpu_window_h;

/* win_key_mode_uint8 */

#define GPU_INTF_KEY_NONE           0x0
#define GPU_INTF_KEY_SHIFT          GLFW_MOD_SHIFT
#define GPU_INTF_KEY_CTRL           GLFW_MOD_CONTROL
#define GPU_INTF_KEY_ALT            GLFW_MOD_ALT
#define GPU_INTF_KEY_SUPER          GLFW_MOD_SUPER
#define GPU_INTF_KEY_CAPS_LOCK      GLFW_MOD_CAPS_LOCK
#define GPU_INTF_KEY_NUM_LOCK       GLFW_MOD_NUM_LOCK
#define GPU_INTF_KEY_SPACE          GLFW_KEY_SPACE
#define GPU_INTF_KEY_APOSTROPHE     GLFW_KEY_APOSTROPHE
#define GPU_INTF_KEY_COMMA          GLFW_KEY_COMMA
#define GPU_INTF_KEY_MINUS          GLFW_KEY_MINUS
#define GPU_INTF_KEY_PERIOD         GLFW_KEY_PERIOD
#define GPU_INTF_KEY_SLASH          GLFW_KEY_SLASH
#define GPU_INTF_KEY_0              GLFW_KEY_0
#define GPU_INTF_KEY_1              GLFW_KEY_1
#define GPU_INTF_KEY_2              GLFW_KEY_2
#define GPU_INTF_KEY_3              GLFW_KEY_3
#define GPU_INTF_KEY_4              GLFW_KEY_4
#define GPU_INTF_KEY_5              GLFW_KEY_5
#define GPU_INTF_KEY_6              GLFW_KEY_6
#define GPU_INTF_KEY_7              GLFW_KEY_7
#define GPU_INTF_KEY_8              GLFW_KEY_8
#define GPU_INTF_KEY_9              GLFW_KEY_9
#define GPU_INTF_KEY_SEMICOLON      GLFW_KEY_SEMICOLON
#define GPU_INTF_KEY_EQUAL          GLFW_KEY_EQUAL
#define GPU_INTF_KEY_A              GLFW_KEY_A
#define GPU_INTF_KEY_B              GLFW_KEY_B
#define GPU_INTF_KEY_C              GLFW_KEY_C
#define GPU_INTF_KEY_D              GLFW_KEY_D
#define GPU_INTF_KEY_E              GLFW_KEY_E
#define GPU_INTF_KEY_F              GLFW_KEY_F
#define GPU_INTF_KEY_G              GLFW_KEY_G
#define GPU_INTF_KEY_H              GLFW_KEY_H
#define GPU_INTF_KEY_I              GLFW_KEY_I
#define GPU_INTF_KEY_J              GLFW_KEY_J
#define GPU_INTF_KEY_K              GLFW_KEY_K
#define GPU_INTF_KEY_L              GLFW_KEY_L
#define GPU_INTF_KEY_M              GLFW_KEY_M
#define GPU_INTF_KEY_N              GLFW_KEY_N
#define GPU_INTF_KEY_O              GLFW_KEY_O
#define GPU_INTF_KEY_P              GLFW_KEY_P
#define GPU_INTF_KEY_Q              GLFW_KEY_Q
#define GPU_INTF_KEY_R              GLFW_KEY_R
#define GPU_INTF_KEY_S              GLFW_KEY_S
#define GPU_INTF_KEY_T              GLFW_KEY_T
#define GPU_INTF_KEY_U              GLFW_KEY_U
#define GPU_INTF_KEY_V              GLFW_KEY_V
#define GPU_INTF_KEY_W              GLFW_KEY_W
#define GPU_INTF_KEY_X              GLFW_KEY_X
#define GPU_INTF_KEY_Y              GLFW_KEY_Y
#define GPU_INTF_KEY_Z              GLFW_KEY_Z
#define GPU_INTF_KEY_LEFT_BRACKET   GLFW_KEY_LEFT_BRACKET
#define GPU_INTF_KEY_BACKSLASH      GLFW_KEY_BACKSLASH
#define GPU_INTF_KEY_RIGHT_BRACKET  GLFW_KEY_RIGHT_BRACKET
#define GPU_INTF_KEY_GRAVE_ACCENT   GLFW_KEY_GRAVE_ACCENT
#define GPU_INTF_KEY_WORLD_1        GLFW_KEY_WORLD_1
#define GPU_INTF_KEY_WORLD_2        GLFW_KEY_WORLD_2