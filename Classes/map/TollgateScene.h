#pragma once
#ifndef __TollgateScene_H__
#define __TollgateScene_H__

#include"cocos2d.h"
using namespace cocos2d;
class Player;
class TollgateScene :public Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateScene)

		virtual void update(float delta);
private:
	void initBG();//初始化关卡场景
	void initIF();
	void initBeginning();
private://此private中全部为背景图中布景
	Sprite* Small_map;//背景精灵1
	Sprite* m_bgSprite2;//背景精灵2
	Sprite* m_blood;
	Sprite* bloodout;
	Sprite* start_Page;
	Sprite* border1;
	Sprite* border2;
	Sprite* border3;
	Sprite* border4;
	Sprite* box;
	Sprite* tree;
	Label* blood_label;
	Label* score_label;
	Label* time_label;
	Label* POBG;
	Label* STARTGAME;
	Label* CREATEROOM;
	Label* ENTERROOM;
	Label* Exit;

	Sprite* black1;
	std::map<cocos2d::EventKeyboard::KeyCode, bool>keys;
private:
	Player* m_player;//主角
};
#endif
