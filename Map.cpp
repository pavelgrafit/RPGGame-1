#include "Map.h"
#include <vector>
Map::Map(sf::String ImageFolder, int heightMap, int widthMap, int amountTiledsMap)
{
	this->image.loadFromFile(ImageFolder);
	this->texture.loadFromImage(this->image);
	this->sprite.setTexture(this->texture);

	this->heightMap = heightMap;
	this->widthMap = widthMap;
	tieldsSettings(amountTiledsMap);
	//std::vector<std::vector<std::string>> mapMassive;
	//mapMassive.push_back()
}
Map::~Map()
{

}

bool Map::setPosBG(int w, int h)
{
	//this->sprite.setPosition(w - image.getSize().x / 2, h - image.getSize().y / 2);
	this->sprite.setPosition(w - 8192 / 2, h - 4096 / 2);
	return true;
}

void Map::loadLevel(const sf::String& mapTiledsPosition, const sf::String& tileds)
{
	this->image.loadFromFile(tileds);//��������� ���� ��� �����
	this->texture.loadFromImage(this->image);//�������� �������� ���������
	this->sprite.setTexture(this->texture);//�������� �������� ��������
}

void Map::updateMap(sf::RenderWindow* window)
{
	//tieldsSettings(7);
	magicTieldsVector.clear();
		/////////////////////////////������ �����/////////////////////
	for (int i = 0; i < heightMap; i++)
		for (int j = 0; j < widthMap; j++)
		{

			if (tieldMaps[i][j] == '5')  sprite.setTextureRect(sf::IntRect(0, 0, tieldWidth, tieldHeight));
			if (tieldMaps[i][j] == '1')  sprite.setTextureRect(sf::IntRect(tieldWidth, 0, tieldWidth, tieldHeight));
			if ((tieldMaps[i][j] == '2')) sprite.setTextureRect(sf::IntRect(tieldWidth * 2, 0, tieldWidth, tieldHeight));
			if (tieldMaps[i][j] == '3')  sprite.setTextureRect(sf::IntRect(tieldWidth * 3, 0, tieldWidth, tieldHeight));
			if (tieldMaps[i][j] == '4')  sprite.setTextureRect(sf::IntRect(tieldWidth * 4, 0, tieldWidth, tieldHeight));
			if ((tieldMaps[i][j] == ' ')) sprite.setTextureRect(sf::IntRect(tieldWidth * 5, 0, tieldWidth, tieldHeight));
			if (tieldMaps[i][j] == '0') 
			{ 
				sprite.setTextureRect(sf::IntRect(tieldWidth * 6, 0, tieldWidth, tieldHeight));
				//sprite.setPosition(j * tieldWidth, i * tieldHeight);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				//window->draw(sprite);//������ ���������� �� �����
				/*if (magicTieldsVector.empty())
				{
					magicTieldsVector.push_back(std::pair<int, int>(j * tieldWidth, i * tieldHeight));
					magicTieldsVector.push_back(std::pair<int, int>(j * tieldWidth, i * tieldHeight));
					return;
				}
				if (magicTieldsVector.back().second != i * tieldHeight)
				{

				}
				return;*/
				sprite.setPosition(j * tieldWidth, i * tieldHeight);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				magicTieldsVector.push_back(sprite);// ��, ���� � ��� �� ������?
				window->draw(sprite);
				continue;
			}
			if (tieldMaps[i][j] == '7')  sprite.setTextureRect(sf::IntRect(tieldWidth * 7, 0, tieldWidth, tieldHeight));
			if ((tieldMaps[i][j] == '8')) sprite.setTextureRect(sf::IntRect(tieldWidth * 8, 0, tieldWidth, tieldHeight));

			sprite.setPosition(j * tieldWidth, i * tieldHeight);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
			window->draw(sprite);//������ ���������� �� �����
		}
}

void Map::setSizeMap(int heightMap, int widthMap)
{
	this->heightMap = heightMap;
	this->widthMap = widthMap;
}

void Map::tieldsSettings(int amountTieldsMap)
{
	tieldWidth = texture.getSize().x / amountTieldsMap;
	tieldHeight = texture.getSize().y / 1;
}

void Map::setMap(sf::String* tieldMaps, int sizeWidht, int sizeHeight)
{
	this->tieldMaps = tieldMaps;
	//this->widthMap = sizeWidht;
	//this->heightMap = sizeHeight;
}

sf::Sprite Map::getSprite()
{
	return sprite;
}
