#pragma once
#include <SFML/Graphics.hpp>

class Sprite
{
	Sprite(std::string urlTexture);
	~Sprite();

private:
	sf::Sprite sprite;


};