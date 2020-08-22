#pragma once

// Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

// Headers
#include "board.h"
#include "mainMenu.h"
#include "Menu.h"
#include "onePlayer.h"
#include "subMenu.h"
#include "twoPlayers.h"
#include "game.h"
#include "button.h"

// Define constants
#define WINDOW_WIDTH  1200
#define WINDOW_HEIGHT 700

#define MENU_TOP 250.0f
#define MENU_BUTTON_SPACING 75.0f

#define BOARD_SIZE 20

#define BOARD_LEFT 300.f
#define BOARD_TOP  50.f

#define THEME_MAX 3

// Namespace
using namespace sf;

// Environment Variables
extern RenderWindow window;

extern Texture t_menuBackground;
extern Sprite menuBackground;

extern Texture t_gameBackground;
extern Sprite gameBackground;

extern Texture t_logo;
extern Sprite logo;

extern Texture t_button_X, t_button_O;
extern Sprite button_X, button_O;

extern Font font_arial;
extern Font font_courierNew;
extern Font font_bebasNeueBold;

extern Music menuMusic;
extern SoundBuffer s_optionSound;
extern Sound optionSound;

extern int theme;

// Button
extern Texture t_blueButton_default;
extern Texture t_blueButton_mouseOver;

extern Texture t_brownButton_default;
extern Texture t_brownButton_mouseOver;

extern Texture t_greenButton_default;
extern Texture t_greenButton_mouseOver;

extern Texture t_redButton_default;
extern Texture t_redButton_mouseOver;

extern Texture t_yellowButton_default;
extern Texture t_yellowButton_mouseOver;


// Common methods
class common
{
public:
	static void initGame();
	static void runGame();
};