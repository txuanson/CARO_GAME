#include "Game.h"

void Game::continueGame()
{
	isExit = false;
	runGame();
}

void Game::newGame()
{
	scoreX = scoreO = 0; playerName[0] = ""; playerName[1] = "";
	resetData(); turn = 1; isExit = false;
	askForName();
	runGame();
}

void Game::askForLoad()
{
	// Declaire some objects
	RectangleShape tint(Vector2f((float)WINDOW_WIDTH, (float)WINDOW_HEIGHT));

	Text txt_title, txt_filename, txt_describe;

	txt_title.setFont(font_arial);
	txt_title.setFillColor(Color::White);
	txt_title.setCharacterSize(100);
	txt_title.setStyle(Text::Bold);
	txt_title.setPosition(Vector2f(150.f, 200.f));
	txt_title.setString("Directly Load Game");

	txt_filename.setFont(font_arial);
	txt_filename.setFillColor(Color::White);
	txt_filename.setCharacterSize(40);
	txt_filename.setPosition(Vector2f(150.f, 400.f));
	txt_filename.setString(".SGO");

	txt_describe.setFont(font_arial);
	txt_describe.setFillColor(Color::White);
	txt_describe.setCharacterSize(30);
	txt_describe.setStyle(Text::Bold);
	txt_describe.setPosition(Vector2f(20.f, 650.f));
	txt_describe.setString("When you're done, Press 'ENTER' to load. Or Press 'ESC' to return to the game...");

	// Dimming
	for (int i = 0; i <= 20; i++)
	{
		displayGame();
		tint.setFillColor(Color(0, 0, 0, i * 10)); window.draw(tint);
		window.display();
	}

	// Refresh event
	Event temp; window.pollEvent(temp);

	// Entering
	bool isDone = false;
	std::string filename = "";
	while (!isDone)
	{
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				exitGame();
				isDone = true;
			}

			if (e.type == Event::TextEntered)
			{
				switch (e.text.unicode)
				{
				case ASCII_BACKSPACE:
				{
					if (filename.length() > 0)
					{
						filename.pop_back();
						txt_filename.setString(filename + ".SGO");
					}
					break;
				}
				case ASCII_ENTER:
				{
					loadGame("savegame/" + filename + ".SGO");

					Text txt_status;
					txt_status.setFont(font_arial);
					txt_status.setCharacterSize(25);
					txt_status.setStyle(Text::Italic);
					txt_status.setString("Done!");

					for (int i = 0; i <= 25; i++)
					{
						txt_status.setFillColor(Color(0, 255, 0, i * 10));
						txt_status.setPosition(Vector2f(150.f, 400.f + 2.f * i));

						displayGame(); window.draw(tint);
						window.draw(txt_title); window.draw(txt_filename); window.draw(txt_status); window.draw(txt_describe);
						window.display();
					}

					sleep(milliseconds(1000));

					isDone = true;
					break;
				}
				case ASCII_ESC:
				{
					isDone = true;
					break;
				}
				default:
				{
					if ((('a' <= e.text.unicode) && (e.text.unicode <= 'z')) || (('A' <= e.text.unicode) && (e.text.unicode <= 'Z')) ||
						(('0' <= e.text.unicode) && (e.text.unicode <= '9')) || (e.text.unicode == '_') || (e.text.unicode == '-'))
					{
						filename += e.text.unicode;
						txt_filename.setString(filename + ".SGO");
					}
				}
				}
			}
		}

		displayGame(); window.draw(tint);
		window.draw(txt_title); window.draw(txt_filename); window.draw(txt_describe);
		window.display();
	}

	// Dimming
	for (int i = 20; i >= 0; i--)
	{
		displayGame();
		tint.setFillColor(Color(0, 0, 0, i * 10)); window.draw(tint);
		window.display();
	}
    //return; // Leave here, ill do it later
}

void Game::askForSave()
{
	// Declaire some objects
	RectangleShape tint(Vector2f((float)WINDOW_WIDTH, (float)WINDOW_HEIGHT));

	Text txt_title, txt_filename, txt_describe;

	txt_title.setFont(font_arial);
	txt_title.setFillColor(Color::White);
	txt_title.setCharacterSize(100);
	txt_title.setStyle(Text::Bold);
	txt_title.setPosition(Vector2f(150.f, 200.f));
	txt_title.setString("Directly Save Game");

	txt_filename.setFont(font_arial);
	txt_filename.setFillColor(Color::White);
	txt_filename.setCharacterSize(40);
	txt_filename.setPosition(Vector2f(150.f, 400.f));
	txt_filename.setString(".SGO");

	txt_describe.setFont(font_arial);
	txt_describe.setFillColor(Color::White);
	txt_describe.setCharacterSize(30);
	txt_describe.setStyle(Text::Bold);
	txt_describe.setPosition(Vector2f(20.f, 650.f));
	txt_describe.setString("When you're done, Press 'ENTER' to save. Or Press 'ESC' to return to the game...");

	// Dimming
	for (int i = 0; i <= 20; i++)
	{
		displayGame();
		tint.setFillColor(Color(0, 0, 0, i * 10)); window.draw(tint);
		window.display();
	}

	// Refresh event
	Event temp; window.pollEvent(temp);

	// Entering
	bool isDone = false;
	std::string filename = "";
	while (!isDone)
	{
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				exitGame();
				isDone = true;
			}

			if (e.type == Event::TextEntered)
			{
				switch (e.text.unicode)
				{
				case ASCII_BACKSPACE:
				{
					if (filename.length() > 0)
					{
						filename.pop_back();
						txt_filename.setString(filename + ".SGO");
					}
					break;
				}
				case ASCII_ENTER:
				{
					saveGame("savegame/" + filename + ".SGO");

					Text txt_status;
					txt_status.setFont(font_arial);
					txt_status.setCharacterSize(25);
					txt_status.setStyle(Text::Italic);
					txt_status.setString("Done!");

					for (int i = 0; i <= 25; i++)
					{
						txt_status.setFillColor(Color(0, 255, 0, i * 10));
						txt_status.setPosition(Vector2f(150.f, 400.f + 2.f * i));

						displayGame(); window.draw(tint);
						window.draw(txt_title); window.draw(txt_filename); window.draw(txt_status); window.draw(txt_describe);
						window.display();
					}

					sleep(milliseconds(1000));

					isDone = true;
					break;
				}
				case ASCII_ESC:
				{
					isDone = true;
					break;
				}
				default:
				{
					if ((('a' <= e.text.unicode) && (e.text.unicode <= 'z')) || (('A' <= e.text.unicode) && (e.text.unicode <= 'Z')) ||
						(('0' <= e.text.unicode) && (e.text.unicode <= '9')) || (e.text.unicode == '_') || (e.text.unicode == '-'))
					{
						filename += e.text.unicode;
						txt_filename.setString(filename + ".SGO");
					}
				}
				}
			}
		}

		displayGame(); window.draw(tint);
		window.draw(txt_title); window.draw(txt_filename); window.draw(txt_describe);
		window.display();
	}

	// Dimming
	for (int i = 20; i >= 0; i--)
	{
		displayGame();
		tint.setFillColor(Color(0, 0, 0, i * 10)); window.draw(tint);
		window.display();
	}
    //return; // Leave here, ill do it later
}

int Game::getType()
{
    return typeGame;
}

Game::Game(sf::Texture* bgTexture)
{
    background.setTexture(*bgTexture);
    cursorP = Vector2u(BOARD_SIZE / 2 - 1, BOARD_SIZE / 2 - 1);
    scoreX = scoreO = 0; playerName[0] = ""; playerName[1] = "";
    turn = 0; isExit = false;
}

Game::~Game()
{
}

bool Game::isContinue()
{
	return turn;
}

void Game::runGame()
{
	// Managing musics
	menuMusic.stop();
	gameMusic.play();

	// Game Window
	while (!isExit)
	{
		// Event
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) exitGame();

			if (e.type == Event::KeyPressed)
				processKeyPressed(e.key.code);
		}

		// Display
		displayGame();
		window.display();
	}

	// Managing musics after exiting the game
	gameMusic.stop();
	if (window.isOpen()) menuMusic.play();
}

void Game::resetData()
{
	b.resetBoard();
	cursorP.x = BOARD_SIZE / 2 - 1; cursorP.y = BOARD_SIZE / 2 - 1;
	turn = 0; isExit = false;
}

void Game::exitGame()
{
	turn = 0; isExit = true;
	gameMusic.stop(); menuMusic.stop();
	window.close();
}

void Game::saveGame(std::string fileName)
{
	std::vector <int> dataBoard = b.exportBoard();

	saveGameData data;
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE + 2; i++) data._board[i] = dataBoard[i];
	data._typeGame = this->typeGame;
	data._turn = turn;
	data.cursorP = this->cursorP;
	data._scoreX = scoreX; data._scoreO = scoreO;
	data._isExit = isExit;

	std::fstream fout(fileName, std::ios::out | std::ios::binary);
	fout.write((char*)&data, sizeof(saveGameData));
	fout.close();
}

void Game::loadGame(std::string fileName)
{
	saveGameData data;

	std::fstream fin(fileName, std::ios::in | std::ios::binary);
	fin.read((char*)&data, sizeof(saveGameData));
	fin.close();

	std::vector <int> dataBoard;
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE + 2; i++) dataBoard.push_back(data._board[i]);
	b.importBoard(dataBoard);
	this->typeGame = data._typeGame;
	turn = data._turn;
	this->cursorP = data.cursorP;
	scoreX = data._scoreX; scoreO = data._scoreO;
	isExit = data._isExit;
}

void Game::displayGame()
{
	// Loading some statistics
	Text txt_countX, txt_countO, txt_scoreX, txt_scoreO, txt_playerName[2];

	txt_countX.setFont(font_arial);
	txt_countX.setFillColor(Color::White);
	txt_countX.setCharacterSize(30);
	txt_countX.setPosition(Vector2f(20.f, 600.f));

	txt_countO.setFont(font_arial);
	txt_countO.setFillColor(Color::White);
	txt_countO.setCharacterSize(30);
	txt_countO.setPosition(Vector2f(950.f, 600.f));

	txt_scoreX.setFont(font_arial);
	txt_scoreX.setFillColor(Color::White);
	txt_scoreX.setCharacterSize(100);
	txt_scoreX.setPosition(Vector2f(100.f, 50.f));

	txt_scoreO.setFont(font_arial);
	txt_scoreO.setFillColor(Color::White);
	txt_scoreO.setCharacterSize(100);
	txt_scoreO.setPosition(Vector2f(1000.f, 50.f));

	for (int i = 0; i <= 1; i++)
	{
		txt_playerName[i].setFont(font_arial);
		txt_playerName[i].setFillColor(Color::White);
		txt_playerName[i].setCharacterSize(30);
		txt_playerName[i].setString(playerName[i]);
	}
	txt_playerName[0].setPosition(Vector2f(50.f, 0.f)); txt_playerName[1].setPosition(Vector2f(1000.f, 0.f));

	window.clear(Color::White);
	window.draw(background);

	b.displayBoard();

	txt_scoreX.setString(std::to_string(scoreX)); window.draw(txt_scoreX);
	txt_scoreO.setString(std::to_string(scoreO)); window.draw(txt_scoreO);

	txt_countX.setString(std::to_string(b.getCountX())); window.draw(txt_countX);
	txt_countO.setString(std::to_string(b.getCountO())); window.draw(txt_countO);

	window.draw(txt_playerName[0]); window.draw(txt_playerName[1]);

	if (turn == 1)
	{
		x_big.setColor(Color(255, 255, 255, 255)); o_big.setColor(Color(255, 255, 255, 100));
		cursor_X.setPosition(Vector2f(BOARD_LEFT + cursorP.y * 30, BOARD_TOP + cursorP.x * 30));
		window.draw(cursor_X);
	}
	else if (turn == -1)
	{
		x_big.setColor(Color(255, 255, 255, 100)); o_big.setColor(Color(255, 255, 255, 255));
		cursor_O.setPosition(Vector2f(BOARD_LEFT + cursorP.y * 30, BOARD_TOP + cursorP.x * 30));
		window.draw(cursor_O);
	}

	window.draw(x_big); window.draw(o_big);
}

void Game::changeTurn()
{
	if (turn == 1) turn = -1; else turn = 1;
}