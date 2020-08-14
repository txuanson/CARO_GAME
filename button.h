#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>
class Button
{
private:
	sf::Sound soundEffect;

	sf::Sprite defaultPlaceHolder;
	sf::Sprite mouseOverPlaceHolder;
	sf::Sprite pressedPlaceHolder;
	sf::Text title;
	sf::Text titleShadow;
	sf::Sprite* currentSprite;
public:
	unsigned int currentState; // 0 : default | 1 : mouse over OR selected | 2 : pressed
public:
	// Constructors of Button
	//Button();
	Button(sf::Texture* defaultTexture,sf::Texture* mouseOverTexture,sf::Texture* pressedTexture,sf::SoundBuffer* soundBuffer, std::string title, sf::Vector2f position);
	Button(const Button& btn, sf::Vector2f position);
	// Destructor
	~Button();
	// Methods
	void updateState(sf::Vector2f mousePos, bool isClicked);
	void setText(std::string title);
	void setState(unsigned int state);
	unsigned int getState();
	void setPosition(sf::Vector2f position);
	void draw();
};
