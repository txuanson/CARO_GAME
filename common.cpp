#include "common.h"

void common::initGame()
{
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CARO GAME");

	t_menuBackground.loadFromFile("image/menu_background.png");
	menuBackground.setTexture(t_menuBackground);

	t_gameBackground.loadFromFile("image/game_background.png");
	gameBackground.setTexture(t_gameBackground);

	t_logo.loadFromFile("image/menu_logo.png");
	logo.setTexture(t_logo); logo.setPosition(Vector2f(450.f, 50.f));

	t_button_X.loadFromFile("image/X.png");
	button_X.setTexture(t_button_X);

	t_button_O.loadFromFile("image/O.png");
	button_O.setTexture(t_button_O);

	font_arial.loadFromFile("font/arial.ttf");
	font_courierNew.loadFromFile("font/courierNew.ttf");
	font_bebasNeueBold.loadFromFile("font/BebasNeue-Bold.ttf");

	menuMusic.openFromFile("sound/menu_music.ogg");
	menuMusic.setLoop(true);

	s_optionSound.loadFromFile("sound/optionSound.ogg");
	optionSound.setBuffer(s_optionSound);

	// Blue
	if (!t_blueButton_default.loadFromFile("image/Button/Blue/Button-default.png"))
		std::cout << "Can not load texture!\n";
	if (!t_blueButton_mouseOver.loadFromFile("image/Button/Blue/Button-mouseOver.png"))
		std::cout << "Can not load texture!\n";
	if (!t_blueButton_pressed.loadFromFile("image/Button/Blue/Button-pressed.png"))
		std::cout << "Can not load texture!\n";

	// Brown
	if (!t_brownButton_default.loadFromFile("image/Button/Brown/Button-default.png"))
		std::cout << "Can not load texture!\n";
	if (!t_brownButton_mouseOver.loadFromFile("image/Button/Brown/Button-mouseOver.png"))
		std::cout << "Can not load texture!\n";
	if (!t_brownButton_pressed.loadFromFile("image/Button/Brown/Button-pressed.png"))
		std::cout << "Can not load texture!\n";

	// Green
	if (!t_greenButton_default.loadFromFile("image/Button/Green/Button-default.png"))
		std::cout << "Can not load texture!\n";
	if (!t_greenButton_mouseOver.loadFromFile("image/Button/Green/Button-mouseOver.png"))
		std::cout << "Can not load texture!\n";
	if (!t_greenButton_pressed.loadFromFile("image/Button/Green/Button-pressed.png"))
		std::cout << "Can not load texture!\n";

	// Red
	if (!t_redButton_default.loadFromFile("image/Button/Red/Button-default.png"))
		std::cout << "Can not load texture!\n";
	if (!t_redButton_mouseOver.loadFromFile("image/Button/Red/Button-mouseOver.png"))
		std::cout << "Can not load texture!\n";
	if (!t_redButton_pressed.loadFromFile("image/Button/Red/Button-pressed.png"));

	// Yellow
	if (!t_yellowButton_default.loadFromFile("image/Button/Yellow/Button-default.png"))
		std::cout << "Can not load texture!\n";
	if (!t_yellowButton_mouseOver.loadFromFile("image/Button/Yellow/Button-mouseOver.png"))
		std::cout << "Can not load texture!\n";
	if (!t_yellowButton_pressed.loadFromFile("image/Button/Yellow/Button-pressed.png"))
		std::cout << "Can not load texture!\n";

}

void common::runGame()
{
	// Initializing
	game g;
	mainMenu m;
	Menu mainMenu(&t_menuBackground, Vector2f(window.getSize().x / 2.0f, MENU_TOP), MENU_BUTTON_SPACING);
	Menu newGameMenu(&t_menuBackground, Vector2f(window.getSize().x / 2.0f, MENU_TOP), MENU_BUTTON_SPACING);
	subMenu sm;
	int choice = 1;
	//Button btn(&t_blueButton_default, &t_blueButton_mouseOver, &t_blueButton_pressed, &s_optionSound, "NEW GAME", sf::Vector2f(500.0f, 50.0f));
	// Opening
	//m.displayOpeningScreen();

	// Init menu
	mainMenu.pushButton(2, "CONTINUE");
	mainMenu.pushButton(0, "NEW GAME");
	mainMenu.pushButton(1, "LOAD GAME");
	mainMenu.pushButton(1, "HIGH SCORE");
	mainMenu.pushButton(1, "ABOUT");
	mainMenu.pushButton(3, "QUIT");
	mainMenu.setActive(true);

	// Init newGameMenu
	newGameMenu.pushButton(2, "SINGLE PLAYER");
	newGameMenu.pushButton(0, "TWO PLAYERS");

	// Init fundamental

	// Choosing theme
	//m.chooseTheme();

	// Play mainMenu music
	menuMusic.play();

	// Opening Window
	while (window.isOpen())
	{
		Event e;
		/*while (window.pollEvent(e))
			if (e.type == sf::Event::Closed) window.close();*/
		while (mainMenu.onLoad())
		{
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
				{
					window.close();
					mainMenu.setActive(false);
				}
				if (e.type == sf::Event::MouseButtonPressed)
				{
					mainMenu.update(sf::Vector2f(e.mouseButton.x, e.mouseButton.y), true);
					if (e.mouseButton.button == sf::Mouse::Left )
					{
						switch (mainMenu.selectedItemIndex)
						{
						case 0:
						{
							g.startTwoPlayers();
							//mainMenu.setActive(false);
							break;
						}
						case 1:
						{
							newGameMenu.setActive(true);
							mainMenu.setActive(false);
							break;
						}
						case 2:
						{
							sm.loadGameMenu(g);
							mainMenu.setActive(false);
							break;
						}
						case 3:
						{
							sm.highScoreMenu();
							mainMenu.setActive(false);
							break;
						}
						case 4:
						{
							sm.aboutMenu();
							mainMenu.setActive(false);
							break;
						}
						case 5:
						{
							window.close();
							mainMenu.setActive(false);
							break;
						}
						}
					}
				}
				else if (e.type == sf::Event::MouseMoved)
					mainMenu.update(sf::Vector2f(e.mouseMove.x, e.mouseMove.y), false);
			}
			window.clear();
			mainMenu.draw();
			window.display();
		}
		while (newGameMenu.onLoad())
		{
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
				{
					window.close();
					newGameMenu.setActive(false);
				}
				if (e.type == sf::Event::MouseButtonPressed)
				{
					newGameMenu.update(sf::Vector2f(e.mouseButton.x, e.mouseButton.y), true);
					if (e.mouseButton.button == sf::Mouse::Left)
					{	
						switch (newGameMenu.selectedItemIndex)
						{
						case 0:

							break;
						case 1:
							break;
						}
					}
				}
				else if (e.type == sf::Event::MouseMoved)
					newGameMenu.update(sf::Vector2f(e.mouseMove.x, e.mouseMove.y), false);
			}
			window.clear();
			newGameMenu.draw();
			window.display();
		}
	}
}