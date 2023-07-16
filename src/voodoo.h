/*
██╗   ██╗ ██████╗  ██████╗ ██████╗   ██████╗  ██████╗
██║   ██║██╔═══██╗██╔═══██╗██╔═══██╗██╔═══██╗██╔═══██╗
██║   ██║██║   ██║██║   ██║██║   ██║██║   ██║██║   ██║
██║   ██║██║   ██║██║   ██║██║   ██║██║   ██║██║   ██║
╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝ ╚██████╔╝╚██████╔╝
 ╚════╝  ╚═════╝  ╚═════╝ ╚═════╝   ╚═════╝  ╚═════╝
 _       _ _
| |     (_) |
| |      _| |__   ____ _____  ____ _   _
| |     | |  _ \ / ___|____ |/ ___) | | |
| |_____| | |_) ) |   / ___ | |   | |_| |
|_______)_|____/|_|   \_____|_|    \__  |
                                  (____/

 All core functionality is available through this header file.
 E.g., Creating a window, adding elements, registering key call-
 backs, etc.

 Must call vdo_init() to initialize library.
 */

#ifndef VOODOO_H
#define VOODOO_H

#include "vdo_error.h"
#include "generic_types.h"

/*
 * Literal costants
 */
#define VDO_MAX_KEY_MAPS 16     /* Max values are arbitrary for now... */
#define VDO_MAX_WINDOWS  100

/********************************************************************************
                                    Types
********************************************************************************/

typedef uint16 vdo_win_id_t16;

typedef uint8 vdo_win_type_t8;
enum
    {
    VDO_WIN_TYPE_GUI,
    VDO_WIN_TYPE_COUNT,
    };

typedef struct
    {
    int             key_maps[VDO_MAX_KEY_MAPS];     /* Window key maps */
    vdo_win_id_t16  id;                             /* Key to window obj */
    vdo_win_type_t8 type;                           /* Window type */
    } vdo_window_h;                                 /* Window handle */

/********************************************************************************
                                    Procedures
********************************************************************************/

/* Initialization */
vdo_error_t vdo_win_create(vdo_window_h * win_h, int width, int height, char * const title, vdo_win_type_t8 type);
vdo_error_t vdo_init(void);

/* Key press */
void vdo_reg_key_bind(vdo_window_h window, int key, int action); // TODO callback function

/* GUI */
vdo_error_t vdo_gui_add_button(vdo_window_h * win, uint32 x, uint32 y, uint32 width, uint32 height, char * const text);

#endif /* VOODOO_H */
