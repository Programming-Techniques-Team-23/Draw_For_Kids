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
		mciSendString("open \"Border.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 8:
		mciSendString("open \"Fill.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 9:
		mciSendString("open \"Black.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 10:
		mciSendString("open \"Yellow.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 11:
		mciSendString("open \"Orange.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 12:
		mciSendString("open \"Red.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 13:
		mciSendString("open \"Green.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 14:
		mciSendString("open \"Blue.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 15:
		mciSendString("open \"Delete.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 16:
		mciSendString("open \"Clear.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 17:
		mciSendString("open \"Copy.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 18:
		mciSendString("open \"Cut.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 19:
		mciSendString("open \"Paste.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 20:
		mciSendString("open \"bringtofront.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 21:
		mciSendString("open \"bringtoback.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 22:
		mciSendString("open \"save.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 23:
		mciSendString("open \"load.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 24:
		mciSendString("open \"playmode.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 25:
		mciSendString("open \"playbyshape.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 26:
		mciSendString("open \"playbycolor.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 27:
		mciSendString("open \"playbyshape&color.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	case 28:
		mciSendString("open \"drawmode.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		break;
	}
	mciSendString("play mp3", NULL, 0, NULL);
	mciSendString("play mp3 wait", NULL, 0, NULL);
	mciSendString("close mp3", NULL, 0, NULL);
	return;
}