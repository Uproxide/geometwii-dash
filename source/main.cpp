#include "header/init.hpp"

#include <iostream> 
#include <unistd.h> 

#include "cubeSpr_png.h"
#include "groundSpr_png.h"
#include "SpeedPortSpr_png.h"
#include "halfSpeedPortSpr_png.h"
#include "blockSpr_png.h"
#include "yellowOrbSpr_png.h"

GameWindow gwd;

Image cube;
Image ground;
Image oneSpeed;
Image halfSpeed;
Image block;
Image yellowOrb;

Sprite cubeSpr;
Sprite groundSpr;

Sprite object1;
Sprite object2;
Sprite object3;
Sprite object4;
Sprite object5;
Sprite object6;
Sprite object7;
Sprite object8;
Sprite object9;
Sprite object10;

int cubeY = 350;
int force = 14;
int speed = 6;
int groundPosX = 0;
int speedPosX = 640;
int jumpFrame = 0;
int frame = 0;

int cubeOldY;

bool jump = false;

int main(int argc, char **argv) {
    Initialise();

    fatInitDefault();
	gwd.InitVideo();
    gwd.SetBackground((GXColor){52, 190, 237, 255});
	
	LayerManager manager(3);
    
    if(cube.LoadImage(cubeSpr_png) != IMG_LOAD_ERROR_NONE) 
    cube.LoadImage(cubeSpr_png);
    ground.LoadImage(groundSpr_png);
    oneSpeed.LoadImage(SpeedPortSpr_png);
    halfSpeed.LoadImage(halfSpeedPortSpr_png);
    block.LoadImage(blockSpr_png);
        
    cubeSpr.SetImage(&cube);
    groundSpr.SetImage(&ground);

    groundSpr.SetPosition(0, 440);
    groundSpr.SetStretchHeight(3);
    groundSpr.SetStretchWidth(3);
    cubeSpr.SetPosition(100, cubeY);
    cubeSpr.SetStretchHeight(1.5);
    cubeSpr.SetStretchWidth(1.5);

    object1.SetImage(&block);
    object1.SetPosition(640, 355);
    object1.SetVisible(false);
    object1.SetStretchHeight(1.5);
    object1.SetStretchWidth(1.5);

    manager.Append(&cubeSpr);
    manager.Append(&object1);
    manager.Append(&groundSpr);

    WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

    while(1) {
        cubeOldY = cubeSpr.GetY();

        frame += 1;

        if (frame >= 256) {
            object1.SetVisible(true);
            speedPosX -= speed;
            object1.SetPosition(speedPosX, 355);
        }

        WPAD_ScanPads();
		u32 pressed = WPAD_ButtonsDown(WPAD_CHAN_0);
        u32 held = WPAD_ButtonsHeld(WPAD_CHAN_0);

        if (groundPosX == -768) {
            groundPosX = 0;
        } else {
            groundPosX -= speed;
        } // ground movement

        if (pressed & WPAD_BUTTON_A) {
            if (!jump) {
                jump = true; // jump if jump = false and Button A is pressed
            } 
        }

        if (pressed & WPAD_BUTTON_HOME) {
            exit(69); // i wonder what this does (has sex with cooper)
        }

        if (jump) {
            cubeY -= force;
            force -= 1;

            // force - frames 
            // frames = total force + 1

            if (force == -14) {
                jump = false;
                force = 14;
                cubeY = 350;
                cubeSpr.SetPosition(100, 350);
            } else {
                cubeSpr.SetPosition(100, cubeY);
            }
        }

        if (cubeSpr.CollidesWith(&object1)) {
            if (object1.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object1.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object1.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        }
        if (cubeSpr.CollidesWith(&object2)) {
            if (object2.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object2.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object2.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        }
        if (cubeSpr.CollidesWith(&object3)) {
            if (object3.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object3.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object3.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        } 
        if (cubeSpr.CollidesWith(&object4)) {
            if (object4.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object4.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object4.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        } 
        if (cubeSpr.CollidesWith(&object5)) {
            if (object5.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object5.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object5.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        } 
        if (cubeSpr.CollidesWith(&object6)) {
            if (object6.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object6.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object6.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        }  
        if (cubeSpr.CollidesWith(&object7)) {
            if (object7.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object7.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object7.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        }  
        if (cubeSpr.CollidesWith(&object8)) {
            if (object8.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object8.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object8.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        }  
        if (cubeSpr.CollidesWith(&object9)) {
            if (object9.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object9.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object9.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        }  
        if (cubeSpr.CollidesWith(&object10)) {
            if (object10.GetImage() == &halfSpeed) {
                speed = 3; // set speed 3 (half) if touch half speed portal
            } else if (object10.GetImage() == &oneSpeed) {
                speed = 6; // set speed 6 (1x) if touch 1x speed portal
            } else if (object10.GetImage() == &cube) {
                cubeSpr.SetY(cubeOldY);
            }
        }

        groundSpr.SetPosition(groundPosX, 440);
 
        manager.Draw(0, 0); // dont touch
	    gwd.Flush(); // dont touch - finishes the rendered frame
    }

    manager.Draw(0, 0); // dont touch - draws all layers in the layer manager
	gwd.Flush(); // dont touch - finishes the rendered frame

    usleep(16670); // 60fps

    return 0;
}