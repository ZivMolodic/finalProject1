#include "Resources.h"
#include <vector>
#include "Direction.h"

namespace
{
    AnimationData MissileData()
    {
        const auto size = sf::Vector2i(40, 40);
        const auto initSpace = sf::Vector2i(1, 2);
        const auto middleSpace = sf::Vector2i(0, 10);

        auto missile = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };

        missile.m_data[DirectionA::Right].emplace_back(currentStart, size);
        missile.m_data[DirectionA::Right].emplace_back(nextStart(), size);
        missile.m_data[DirectionA::Down].emplace_back(nextStart(), size);
        missile.m_data[DirectionA::Down].emplace_back(nextStart(), size);
        missile.m_data[DirectionA::Left].emplace_back(nextStart(), size);
        missile.m_data[DirectionA::Left].emplace_back(nextStart(), size);
        missile.m_data[DirectionA::Up].emplace_back(nextStart(), size);
        missile.m_data[DirectionA::Up].emplace_back(nextStart(), size);

        return missile;
    }

    AnimationData GuidedMissileData()
    {
        const auto size = sf::Vector2i(40, 40);
        const auto initSpace = sf::Vector2i(851, 2);
        const auto middleSpace = sf::Vector2i(0, 10);

        auto guidedMissile = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };

        guidedMissile.m_data[DirectionA::Right].emplace_back(currentStart, size);
        guidedMissile.m_data[DirectionA::Right].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Right].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Down].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Down].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Down].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Left].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Left].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Left].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Up].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Up].emplace_back(nextStart(), size);
        guidedMissile.m_data[DirectionA::Up].emplace_back(nextStart(), size);

        return guidedMissile;
    }

	AnimationData RaftManData()
	{
		auto size = sf::Vector2i(41, 57);
		auto initSpace = sf::Vector2i(0, 80);
		auto middleSpace = sf::Vector2i(0, 0);

		auto raftMan = AnimationData{};
		auto currentStart = initSpace;

		auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};

		raftMan.m_data[DirectionA::Right].emplace_back(currentStart, size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Right].emplace_back(nextStart(), size);
		size = sf::Vector2i(48.5, 57);
		currentStart = sf::Vector2i(0, 214);
		middleSpace = sf::Vector2i(0, 0);
		raftMan.m_data[DirectionA::Up].emplace_back(currentStart, size);
		raftMan.m_data[DirectionA::Up].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Up].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Up].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Up].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Up].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Up].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Up].emplace_back(nextStart(), size);
		size = sf::Vector2i(30, 56);
		currentStart = sf::Vector2i(0, 16);
		middleSpace = sf::Vector2i(0, 0);
		raftMan.m_data[DirectionA::Stay].emplace_back(currentStart, size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		raftMan.m_data[DirectionA::Stay].emplace_back(nextStart(), size);
		return raftMan;
	}
}

Resources::Resources()
    :m_animation(MAX)
{
	loadGraphics();
	loadSounds();
    m_animation[Missile] = MissileData();
    m_animation[GuidedMissile] = GuidedMissileData();
	m_animation[RaftMan] = RaftManData();
}

Resources& Resources::instance()
{
	static auto resources = Resources();
	return resources;
}

void Resources::loadGraphics()
{	 
	std::vector <std::string> pngNames = {"guided_missile.png",
        "missile.png", "down_raft_button.png",
			 "tennis_button.png", "up_raft_button.png",
			"guided_missile_button.png","grenade_button.png"
		,"missile_button.png", "menuBlock.png","minions.png" ,
		"main_background.png" ,"gameplay_background.png" ,
		"grenade.png", "grenade_launcher.png", "raft.png", "up_raft.png",
		"explosion.png", "volume.png", "mute.png"};

	std::vector <char> pngChars = {'S','s', 'd', 'T', 'U','M', 'G', 't', 'B', 'r', 'm', 'b','*', 'g','#', 'u', 'x','V', 'N' };
	sf::RenderWindow window;
	/*for (int i = 0; i < pngNames.size(); i++)
	{
		auto texture = sf::Texture();
		texture.loadFromFile(pngNames[i]);
		texture.setSmooth(true);
		m_textures.insert({ pngChars[i], texture });
		m_textures[pngChars[i]].loadFromFile(pngNames[i]);
		m_textures[pngChars[i]].setSmooth(true);
	}*/

	m_font.loadFromFile("C:/Windows/Fonts/Bauhs93.ttf");

	auto texture = sf::Texture();
	texture.loadFromFile("guided_missile.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[0], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("missile.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[1], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("down_raft_button.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[2], texture });


	//		auto texture = sf::Texture();
	texture.loadFromFile("tennis_button.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[3], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("up_raft_button.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[4], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("guided_missile_button.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[5], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("grenade_button.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[6], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("missile_button.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[7], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("menuBlock.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[8], texture });

	//		auto texture = sf::Texture();
	texture.loadFromFile("minions.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[9], texture });

	//	auto texture = sf::Texture();
	texture.loadFromFile("main_background.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[10], texture });

	//	auto texture = sf::Texture();
	texture.loadFromFile("gameplay_background.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[11], texture });

	//	auto texture = sf::Texture();
	texture.loadFromFile("grenade.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[12], texture });

	texture.loadFromFile("grenade_launcher.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[13], texture });

	texture.loadFromFile("raft.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[14], texture });

	texture.loadFromFile("up_raft.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[15], texture });

	texture.loadFromFile("explosion.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[16], texture });

	texture.loadFromFile("volume.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[17], texture });

	texture.loadFromFile("mute.png");
	texture.setSmooth(true);
	m_textures.insert({ pngChars[18], texture });

}

sf::Texture& Resources::getTexture(char c)
{
	if (auto search = m_textures.find(c); search != m_textures.end())
		return m_textures[c];
}

void Resources::loadSounds()
{
	//char sounds[][20] = { "timer.wav", "finish_level.wav", "game_over.wav", "pacman_dead.wav",
	//					  "ghost_eaten.wav", "present.wav", "eat_cookie.wav", "door_open.wav" };

	//for (int i = 0; i < 8; i++)
	//{
	//	sf::SoundBuffer sound;
	//	sound.loadFromFile(sounds[i]);
	//	m_sounds.push_back(sound);
	//}

	m_backGround.openFromFile("background.wav");
}


//void Resources::playMusic(enum Sounds i, int vol)
//{
//	m_backGround.setVolume(0);
//	m_sound.setBuffer(m_sounds[i]);
//	m_sound.setVolume(vol);
//	m_sound.play();
//	m_backGround.setVolume(50);
//}

void Resources::playBackGround()
{
	m_backGround.setVolume(50);
	m_backGround.play();
}

void Resources::volumeBackGround(int vol)
{
	m_backGround.setVolume(vol);
}

void Resources::stopBackGroundMusic()
{
	m_backGround.stop();
}

