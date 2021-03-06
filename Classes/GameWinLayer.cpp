#include "GameWinLayer.h"
#include "CommonUtils.h"


Scene* GameWinLayer::createScene()
{
	log("GameWinLayer::createScene");
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameWinLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameWinLayer::init()
{
	if (!Layer::init()) {
		return false;
	}

	MenuItemFont* itemStartGame;
	Sprite* sprite = Sprite::create("pic/win.png");
	sprite->setPosition(Point(winSize.width * 0.5, winSize.height * 0.7));
	this->addChild(sprite, 10);

	itemStartGame = MenuItemFont::create("Challenge Next Level", [&](Ref* pSender)
	{
		auto transitions = TransitionFadeTR::create(0.4f, LevelLayer::createScene());
		Director::getInstance()->replaceScene(LevelLayer::createScene());
	});
	itemStartGame->setColor(Color3B::RED);
	itemStartGame->setFontName("font/Marker Felt");
	itemStartGame->setScale(2.0f);
	itemStartGame->setPosition(winSize.width / 2, winSize.height / 2);

	auto itemSetting = MenuItemFont::create("Exit Game", [&](Ref* pSender)
	{
		Director::getInstance()->end();
	});
	itemSetting->setFontName("font/Marker Felt");
	itemSetting->setScale(2.0f);
	itemSetting->setPosition(Point(winSize.width * 0.5, winSize.height * 0.25));

	auto menuSetting = Menu::create(itemSetting, itemStartGame, NULL);
	menuSetting->setPosition(Point::ZERO);
	this->addChild(menuSetting, 10);

	CommonUtil::getInstance()->m_currentWinner = WINNER_NONE;

	return true;
}