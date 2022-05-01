#include "SFMLTextureManager.h"

SFMLTextureManager* SFMLTextureManager::Instance = nullptr;

SFMLTextureManager* SFMLTextureManager::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLTextureManager();
	}

	return Instance;
}

void SFMLTextureManager::AddTexture(const std::string& name,
									const std::string& filename)
{
	sf::Texture* Texture = new sf::Texture();
	Texture->loadFromFile(filename);
	Textures.insert(std::make_pair(name, Texture));
}

sf::Texture* SFMLTextureManager::GetTexture(const std::string& name)
{
	std::map<std::string, sf::Texture*>::iterator iter = Textures.find(name);
	return (iter != Textures.end()) ? iter->second : nullptr;
}

SFMLTextureManager::SFMLTextureManager()
	: Textures()
{
	//Nothing here...
}