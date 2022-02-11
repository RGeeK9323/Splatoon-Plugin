/****************************************************************************
 * Copyright (C) 2022 RGeeK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <wups.h>
#include <stdio.h>
#include <nsysnet/socket.h>

#include <utils/logger.h>
#include "main.h"

WUPS_PLUGIN_NAME("Splatoon Plugin");
WUPS_PLUGIN_DESCRIPTION("An plugin for Splatoon.");
WUPS_PLUGIN_VERSION("v0.1");
WUPS_PLUGIN_AUTHOR("RGeeK");
WUPS_PLUGIN_LICENSE("GPL");

WUPS_ALLOW_OVERLAY()

ON_APPLICATION_START(args){
    socket_lib_init();
    log_init();
    
    DEBUG_FUNCTION_LINE("PLUGIN INIT DONE.\n");
}
