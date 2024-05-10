#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "Sound.h"
Sound::Sound() {}
void Sound::play(int n) {
	switch (n) {
	case 1:
		mciSendString("open \"Rectangle.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 2:
		mciSendString("open \"Square.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 3:
		mciSendString("open \"Triangle.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 4:
		mciSendString("open \"Hexagon.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 5:
		mciSendString("open \"circle.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 6:
		mciSendString("open \"Select.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 7:
		mciSendString("open \"change border color.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 8:
		mciSendString("open \"change filling color.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 9:
		mciSendString("open \"black.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 10:
		mciSendString("open \"yellow.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 11:
		mciSendString("open \"orange.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 12:
		mciSendString("open \"red.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 13:
		mciSendString("open \"green.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 14:
		mciSendString("open \"BLUE.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 15:
		mciSendString("open \"Delete.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 16:
		mciSendString("open \"Clear All.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 17:
		mciSendString("open \"Copy.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 18:
		mciSendString("open \"Cut.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 19:
		mciSendString("open \"paste.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 20:
		mciSendString("open \"Send to front.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 21:
		mciSendString("open \"Send to back.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 22:
		mciSendString("open \"Save.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 23:
		mciSendString("open \"Load.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 24:
		mciSendString("open \"Play mode.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 25:
		mciSendString("open \"Pick and Hide by Fig.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 26:
		mciSendString("open \"Pick and Hide by Fig (1).mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 27:
		mciSendString("open \"Pick and Hide by Fig (2).mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 28:
		mciSendString("open \"draw mode.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	}
	mciSendString("play mp3", NULL, 0, NULL);
	mciSendString("play mp3 wait", NULL, 0, NULL);
	mciSendString("close mp3", NULL, 0, NULL);
	return;
}