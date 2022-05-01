#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class SFMLTextureManager
{
public:
	static SFMLTextureManager* GetInstance();

	void AddTexture(const std::string& name,
					const std::string& filename);

	sf::Texture* GetTexture(const std::string& name);

private:
	SFMLTextureManager();

	std::map<std::string, sf::Texture*> Textures;

	static SFMLTextureManager* Instance;
};