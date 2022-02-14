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
#include <wups.h>
#include "main.h"
#include <utils/logger.h>
#include <utils/StringTools.h>
#include <vpad/input.h>
#include <coreinit/screen.h>
#include <coreinit/title.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <wups.h>
#include <nsysnet/socket.h>
#include <coreinit/systeminfo.h>

#include <utils/logger.h>
#include "main.h"

#define WII_U_MENU_TITLE_ID_JAP (0x0005000E10162B00)
#define WII_U_MENU_TITLE_ID_EUR (0x0005000010176A00)
#define WII_U_MENU_TITLE_ID_USA (0x0005000010176900)

/****************************************************************************
Overlay Void
 ****************************************************************************/
void SplashScreen_callback(wups_overlay_options_type_t screen, void * args){
    int32_t i=0;

    while(i<100){
        WUPS_Overlay_OSScreenClear(screen);
        
        WUPS_Overlay_PrintTextOnScreen(screen, 15,0,"(`  |  |-    ,_  |)|    .,_");
        WUPS_Overlay_PrintTextOnScreen(screen, 15,1,"_)|)|(||_()()||  | |L|(||||");
        WUPS_Overlay_PrintTextOnScreen(screen, 15,2,"  |                   _|   ");
        WUPS_Overlay_PrintTextOnScreen(screen, 15,4,"Made by RGeeK, Version 0.20");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,6,"Press L + R + X to enable speed cheat");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,7,"Press L + R + Y to disable speed cheat");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,8,"Press L + R + A to enable jump cheat");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,9,"Press L + R + B to disable jump cheat");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,10,"Press L + R + UP to use instant special cheat");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,15,"This menu will disappear in 100 seconds: %d",i);

        WUPS_Overlay_FlipBuffers(screen);
        
        i++;
    }
}

/****************************************************************************
Wrong titleID Message Display Void
 ****************************************************************************/
void BadTitleID(wups_overlay_options_type_t screen, void * args){
    int b = 0;
        
        while(b<50){
        WUPS_Overlay_OSScreenClear(screen);
        
        WUPS_Overlay_PrintTextOnScreen(screen, 0,0,"Please launch Splatoon before using this plugin...");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,15,"This menu will disappear in 50 seconds: %d",b);

        WUPS_Overlay_FlipBuffers(screen);
        
        b++;
        }
    }

/****************************************************************************
Speed Cheat Voids, this cheat was made by Red
 ****************************************************************************/
void SpeedEnable(wups_overlay_options_type_t screen, void * args){
    int *address = (int * ) 0x105EBE40;
    WUPS_KernelWrite(address, 0x3F100000);
    int b = 0;
        
        while(b<50){
        WUPS_Overlay_OSScreenClear(screen);
        
        WUPS_Overlay_PrintTextOnScreen(screen, 0,0,"Speed Cheat is enable...");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,15,"This menu will disappear in 50 seconds: %d",b);

        WUPS_Overlay_FlipBuffers(screen);
        
        b++;
        }
    }

void SpeedDisable(wups_overlay_options_type_t screen, void * args){
    int32_t a = 0;
    int *address = (int * ) 0x105EBE40;
     WUPS_KernelWrite(address, 0x3F000000);
        
        while(a<50){
        WUPS_Overlay_OSScreenClear(screen);
        
        WUPS_Overlay_PrintTextOnScreen(screen, 0,0,"Speed Cheat is disable...");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,15,"This menu will disappear in 50 seconds: %d",a);

        WUPS_Overlay_FlipBuffers(screen);
        
        a++;
        }
    }

/****************************************************************************
Jump Cheat Voids, this cheat was made by ShadowBlue4
 ****************************************************************************/
void JumpEnable(wups_overlay_options_type_t screen, void * args){
    int32_t a = 0;
    int *address = (int * ) 0x105EC2E4;
     WUPS_KernelWrite(address, 0x41000000);
        
        while(a<50){
        WUPS_Overlay_OSScreenClear(screen);
        
        WUPS_Overlay_PrintTextOnScreen(screen, 0,0,"Jump Cheat is enable...");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,15,"This menu will disappear in 50 seconds: %d",a);

        WUPS_Overlay_FlipBuffers(screen);
        
        a++;
        }
    }

void JumpDisable(wups_overlay_options_type_t screen, void * args){
    int32_t a = 0;
    int *address = (int * ) 0x105EC2E4;
     WUPS_KernelWrite(address, 0x3F933333);
        
        while(a<50){
        WUPS_Overlay_OSScreenClear(screen);
        
        WUPS_Overlay_PrintTextOnScreen(screen, 0,0,"Jump Cheat is disable...");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,15,"This menu will disappear in 50 seconds: %d",a);

        WUPS_Overlay_FlipBuffers(screen);
        
        a++;
        }
    }
/****************************************************************************
Instant Special Voids, this cheat was made by Unknow
 ****************************************************************************/
    void InstantSpecial(wups_overlay_options_type_t screen, void * args){
    int32_t a = 0;
    int *address = (int * ) 0x105EBFA8;
     WUPS_KernelWrite(address, 0xBF400000);
        
        while(a<50){
        WUPS_Overlay_OSScreenClear(screen);
        
        WUPS_Overlay_PrintTextOnScreen(screen, 0,0,"Instant special injected...");
        WUPS_Overlay_PrintTextOnScreen(screen, 0,15,"This menu will disappear in 50 seconds: %d",a);

        WUPS_Overlay_FlipBuffers(screen);
        
        a++;
        }
    }

/****************************************************************************
Button Detect Void
 ****************************************************************************/
uint8_t gCallbackCooldown __attribute__((section(".data"))) = 0;

DECL_FUNCTION(int32_t, VPADRead, int32_t chan, VPADStatus *buffer, uint32_t buffer_size, int32_t *error) {
    uint64_t titleID = OSGetTitleID();
    int32_t result = real_VPADRead(chan, buffer, buffer_size, error);
    uint32_t btnsoverlay = VPAD_BUTTON_L | VPAD_BUTTON_R | VPAD_BUTTON_DOWN;
    uint32_t btnsspeedenable = VPAD_BUTTON_L | VPAD_BUTTON_X | VPAD_BUTTON_R;
    uint32_t btnsspeeddisable = VPAD_BUTTON_L | VPAD_BUTTON_Y | VPAD_BUTTON_R;
    uint32_t btnsjumpenable = VPAD_BUTTON_L | VPAD_BUTTON_A | VPAD_BUTTON_R;
    uint32_t btnsjumpdisable = VPAD_BUTTON_L | VPAD_BUTTON_B | VPAD_BUTTON_R;
    uint32_t btnspecialenable = VPAD_BUTTON_L | VPAD_BUTTON_UP | VPAD_BUTTON_R;
    bool titleisSplatoon = false;

    if(titleID == WII_U_MENU_TITLE_ID_JAP || titleID == WII_U_MENU_TITLE_ID_USA || titleID == WII_U_MENU_TITLE_ID_EUR){
        titleisSplatoon = true;
    }
    else if (result > 0 && ((buffer[0].hold & (btnsoverlay)) == btnsoverlay) || ((buffer[0].hold & (btnsspeedenable)) == btnsspeedenable) || ((buffer[0].hold & (btnsspeeddisable)) == btnsspeeddisable) || ((buffer[0].hold & (btnsjumpdisable)) == btnsjumpdisable) || ((buffer[0].hold & (btnsjumpenable)) == btnsjumpenable) && gCallbackCooldown == 0 )
    {
     WUPS_OpenOverlay(WUPS_OVERLAY_DRC_AND_TV ,BadTitleID, &buffer);
    }
            if(result > 0 && ((buffer[0].hold & (btnsoverlay)) == btnsoverlay) && gCallbackCooldown == 0 && titleisSplatoon == true){
                gCallbackCooldown = 0x3C;
                WUPS_OpenOverlay(WUPS_OVERLAY_DRC_AND_TV ,SplashScreen_callback, &buffer);
            }
            if(result > 0 && ((buffer[0].hold & (btnsspeedenable)) == btnsspeedenable) && gCallbackCooldown == 0 && titleisSplatoon == true){
                gCallbackCooldown = 0x3C;
                WUPS_OpenOverlay(WUPS_OVERLAY_DRC_AND_TV ,SpeedEnable, &buffer);
            }
            if(result > 0 && ((buffer[0].hold & (btnsspeeddisable)) == btnsspeeddisable) && gCallbackCooldown == 0 && titleisSplatoon == true){
                gCallbackCooldown = 0x3C;
                WUPS_OpenOverlay(WUPS_OVERLAY_DRC_AND_TV ,SpeedDisable, &buffer);
            }
            if(result > 0 && ((buffer[0].hold & (btnsjumpenable)) == btnsjumpenable) && gCallbackCooldown == 0 && titleisSplatoon == true){
                gCallbackCooldown = 0x3C;
                WUPS_OpenOverlay(WUPS_OVERLAY_DRC_AND_TV ,JumpEnable, &buffer);
            }
            if(result > 0 && ((buffer[0].hold & (btnsjumpdisable)) == btnsjumpdisable) && gCallbackCooldown == 0 && titleisSplatoon == true){
                gCallbackCooldown = 0x3C;
                WUPS_OpenOverlay(WUPS_OVERLAY_DRC_AND_TV ,JumpDisable, &buffer);
            }
            if(result > 0 && ((buffer[0].hold & (btnspecialenable)) == btnspecialenable) && gCallbackCooldown == 0 && titleisSplatoon == true){
                gCallbackCooldown = 0x3C;
                WUPS_OpenOverlay(WUPS_OVERLAY_DRC_AND_TV ,InstantSpecial, &buffer);
            }
            if(gCallbackCooldown > 0){
                gCallbackCooldown--;
        }

    return result;
}

WUPS_MUST_REPLACE(VPADRead,          WUPS_LOADER_LIBRARY_VPAD,       VPADRead);
